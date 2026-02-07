# ESP32 Bluetooth Audio Receiver

This is a high-quality Bluetooth A2DP audio sink (receiver) based on the ESP32. It is designed to turn any vintage radio or speaker system into a modern wireless device with high-fidelity sound and a visual interface.

## ✨ Features
* **Premium Sound:** Utilizes the I2S protocol with an external **PCM5102 DAC** for 24-bit audio quality.
* **Custom Interface:** Features a polished OLED splash screen with the BLUETOOTH logo and localized status messages (*"connect phone"*).
* **Metadata Display:** Shows real-time track title and artist information on the SSD1306 OLED display.
* **Simple Control:** Single-button interface for playback control and connection management.

---

## 🏗 Hardware Requirements
* **Microcontroller:** ESP32-WROOM-32U WiFi Bluetooth Module ESP32 CP2102 U.FL (or compatible ESP32 board).
* **Audio DAC:** PCM5102A I2S Module.
* **Display:** SSD1306 OLED 128x64 px (I2C).
* **Control:** 1x Push Button.

---

## 🔌 Connection Diagram

<table style="width: 100%; border-collapse: collapse; font-family: sans-serif; background-color: #0d1117; color: #e6edf3; border: 1px solid #30363d;">
  <thead>
    <tr style="background-color: #161b22; color: #58a6ff;">
      <th style="padding: 12px; border: 1px solid #30363d; text-align: left;">Module / Device</th>
      <th style="padding: 12px; border: 1px solid #30363d; text-align: left;">Pin Function</th>
      <th style="padding: 12px; border: 1px solid #30363d; text-align: center;">ESP32 Connection</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="3" style="padding: 12px; border: 1px solid #30363d; font-weight: bold; color: #ff7b72; vertical-align: top;">PCM5102 (DAC)</td>
      <td style="padding: 8px; border: 1px solid #30363d;">BCK (Bit Clock)</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #ff7b72;">GPIO 26</td>
    </tr>
    <tr>
      <td style="padding: 8px; border: 1px solid #30363d;">LRCK (Word Select)</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #ff7b72;">GPIO 25</td>
    </tr>
    <tr>
      <td style="padding: 8px; border: 1px solid #30363d;">DIN (Data In)</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #ff7b72;">GPIO 19</td>
    </tr>
    <tr>
      <td rowspan="2" style="padding: 12px; border: 1px solid #30363d; font-weight: bold; color: #79c0ff; vertical-align: top;">SSD1306 (OLED)</td>
      <td style="padding: 8px; border: 1px solid #30363d;">SCL (Clock)</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #79c0ff;">GPIO 22</td>
    </tr>
    <tr>
      <td style="padding: 8px; border: 1px solid #30363d;">SDA (Data)</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #79c0ff;">GPIO 21</td>
    </tr>
    <tr>
      <td style="padding: 12px; border: 1px solid #30363d; font-weight: bold; color: #7ee787;">BUTTON</td>
      <td style="padding: 12px; border: 1px solid #30363d;">Control<br><small style="color: #8b949e;">(Short to GND)</small></td>
      <td style="padding: 12px; border: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #7ee787;">GPIO 13 ↔ GND</td>
    </tr>
    <tr style="background-color: #161b22;">
      <td rowspan="3" style="padding: 12px; border: 1px solid #30363d; font-weight: bold; color: #d2a8ff; vertical-align: top;">POWER SUPPLY</td>
      <td style="padding: 8px; border: 1px solid #30363d;">VCC PCM5102</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-weight: bold; color: #ffa657;">5V / VIN</td>
    </tr>
    <tr style="background-color: #161b22;">
      <td style="padding: 8px; border: 1px solid #30363d;">VCC OLED</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-weight: bold; color: #ffa657;">3.3V</td>
    </tr>
    <tr style="background-color: #161b22;">
      <td style="padding: 8px; border: 1px solid #30363d;">Common Ground</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-weight: bold; color: #8b949e;">GND (All)</td>
    </tr>
  </tbody>
</table>

<div style="background-color: #161b22; padding: 12px; font-size: 11px; color: #8b949e; text-align: center; border: 1px solid #30363d; border-top: none; line-height: 1.5; font-family: sans-serif;">
  The button uses an internal PULLUP resistor.<br>
  Pin 13 must be connected directly to GND when pressed.
</div>

---

## 🛠 Required Libraries
To compile this project, you need to install the following libraries in your Arduino IDE:
1. [ESP32-A2DP](https://github.com/pschatzmann/ESP32-A2DP) by Phil Schatzmann
2. [U8g2](https://github.com/olikraus/u8g2) by oliver

## 📝 Usage
1. Power up the ESP32.
2. Search for **"ESP32 BT"** in your phone's Bluetooth settings.
3. Once connected, the OLED will display the track title and artist.
4. Use the button on **GPIO 13** to pause/play music or manage the connection.
