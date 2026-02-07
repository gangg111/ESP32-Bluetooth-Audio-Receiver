#include <Arduino.h>
#include <BluetoothA2DPSink.h>
#include <U8g2lib.h>
#include <Wire.h>

#define I2S_BCK    26
#define I2S_WS     25
#define I2S_DOUT   19
#define BUTTON_PIN 13

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, 22, 21);
BluetoothA2DPSink a2dp_sink;

String current_artist = "";
String current_title = "";
bool is_connected = false;

int bar_h[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
unsigned long last_eq_ms = 0;
unsigned long last_fade_ms = 0;

unsigned long button_press_ms = 0;
bool button_active = false;

int offset_a = 10, offset_t = 10;
int dir_a = -1, dir_t = -1;
unsigned long last_anim_a = 0;
unsigned long last_anim_t = 0;

void drawScrollingText(int y, String text, const uint8_t* font, int &offset, int &dir, unsigned long &last_ms) {
  u8g2.setFont(font);
  int width = u8g2.getUTF8Width(text.c_str());
  if (width <= 120) {
    u8g2.drawUTF8((128 - width) / 2, y, text.c_str());
    return;
  }
  u8g2.drawUTF8(offset, y, text.c_str());
  if (millis() - last_ms > 35) {
    offset += dir;
    if (offset <= -(width - 110)) dir = 1;
    else if (offset >= 10) dir = -1;
    last_ms = millis();
  }
}

void avrc_metadata_callback(uint8_t id, const uint8_t *text) {
  String val = String((char*)text);
  if (id == 0x1) { current_title = val; offset_t = 10; dir_t = -1; }
  if (id == 0x2) { current_artist = val; offset_a = 10; dir_a = -1; }
}

void connection_state_callback(esp_a2d_connection_state_t state, void *ptr) {
  is_connected = (state == ESP_A2D_CONNECTION_STATE_CONNECTED);
}

void setup() {
  u8g2.begin();
  u8g2.enableUTF8Print();
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  static i2s_pin_config_t my_pin_config = {
    .bck_io_num = I2S_BCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_DOUT,
    .data_in_num = I2S_PIN_NO_CHANGE
  };

  a2dp_sink.set_pin_config(my_pin_config);
  a2dp_sink.set_avrc_metadata_callback(avrc_metadata_callback);
  a2dp_sink.set_on_connection_state_changed(connection_state_callback);
  a2dp_sink.start("BT AUDIO");
}

void loop() {
  u8g2.clearBuffer();

  unsigned long current_ms = millis();
  bool button_now = (digitalRead(BUTTON_PIN) == LOW);

  if (button_now && !button_active) {
    button_press_ms = current_ms;
    button_active = true;
  }

  if (button_active && (current_ms - button_press_ms >= 3000) && is_connected) {
    u8g2.setFont(u8g2_font_helvB14_te);
    u8g2.drawUTF8((128 - u8g2.getUTF8Width("Unpairing!")) / 2, 25, "Unpairing!");
    u8g2.setFont(u8g2_font_helvR10_te);
    unsigned long hold_time = current_ms - button_press_ms;
    if (hold_time < 4000) u8g2.drawUTF8(55, 60, "2...");
    else if (hold_time < 5000) u8g2.drawUTF8(55, 60, "1...");
    else u8g2.drawUTF8(40, 60, "RELEASE");
  } 
  else if (!is_connected) {
    u8g2.setFont(u8g2_font_fub20_tr); 
    u8g2.drawUTF8((128 - u8g2.getUTF8Width("BT AUDIO")) / 2, 32, "BT AUDIO");
    
    if ((current_ms / 1000) % 2 == 0) {
      u8g2.setFont(u8g2_font_helvR10_te);
      u8g2.drawUTF8((128 - u8g2.getUTF8Width("connect phone")) / 2, 60, "connect phone");
    }
  } else {
    drawScrollingText(22, current_artist, u8g2_font_helvB14_te, offset_a, dir_a, last_anim_a);
    u8g2.drawHLine(15, 28, 98);
    drawScrollingText(46, current_title, u8g2_font_helvR10_te, offset_t, dir_t, last_anim_t);

    if (a2dp_sink.get_audio_state() == ESP_A2D_AUDIO_STATE_STARTED) {
      if (current_ms - last_eq_ms > 100) {
        for (int i = 0; i < 12; i++) bar_h[i] = random(8, 24);
        last_eq_ms = current_ms;
      }
    }
    if (current_ms - last_fade_ms > 30) {
      for (int i = 0; i < 12; i++) {
        if (bar_h[i] > 0) bar_h[i] -= 3;
        if (bar_h[i] < 0) bar_h[i] = 0;
      }
      last_fade_ms = current_ms;
    }
    for (int i = 0; i < 12; i++) {
      if (bar_h[i] > 0) {
        int h = (bar_h[i] > 30) ? 30 : bar_h[i];
        u8g2.drawBox(22 + (i * 7), 64 - h, 4, h);
      }
    }
  }

  if (!button_now && button_active) {
    unsigned long duration = current_ms - button_press_ms;
    if (duration >= 5000) a2dp_sink.disconnect();
    else if (duration > 50 && duration < 3000) {
      if (a2dp_sink.get_audio_state() == ESP_A2D_AUDIO_STATE_STARTED) a2dp_sink.pause();
      else a2dp_sink.play();
    }
    button_active = false;
  }

  u8g2.sendBuffer();
}