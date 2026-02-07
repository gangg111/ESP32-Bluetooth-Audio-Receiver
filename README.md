# ESP32 Bluetooth Audio Receiver

**ESP32 Bluetooth Audio Receiver** is a high-quality Bluetooth A2DP audio sink (receiver) based on the ESP32. It features an external I2S DAC for superior sound quality and an OLED display for status and metadata.

## ✨ Features
* **High-Fidelity Audio:** Uses I2S protocol with PCM5102 DAC.
* **OLED Visuals:** Real-time track information and status.
* **Custom Splash Screen:** Features the "BLYNDY" logo with polished animations.
* **Single Button Control:** Integrated Play/Pause and connection management.

## 🔌 Connection Diagram (Pinout)

<div style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Arial, sans-serif; max-width: 550px; color: #e6edf3; background-color: #0d1117; border: 1px solid #30363d; border-radius: 12px; overflow: hidden; box-shadow: 0 12px 28px rgba(0,0,0,0.45);">
  
  <div style="background-color: #161b22; padding: 18px; border-bottom: 1px solid #30363d; text-align: center;">
    <span style="color: #58a6ff; font-size: 22px; font-weight: bold; letter-spacing: 1.2px;"> • Schemat Połączeń • </span>
  </div>

  <table style="width: 100%; border-collapse: collapse; font-size: 14px;">
    <thead>
      <tr style="background-color: #21262d; color: #8b949e; text-transform: uppercase; font-size: 11px; letter-spacing: 1px;">
        <th style="padding: 12px 15px; border-bottom: 1px solid #30363d; text-align: left;">Moduł / Urządzenie</th>
        <th style="padding: 12px 15px; border-bottom: 1px solid #30363d; text-align: left;">Pin Funkcja</th>
        <th style="padding: 12px 15px; border-bottom: 1px solid #30363d; text-align: center;">Połączenie ESP32</th>
      </tr>
    </thead>
    <tbody>
      <tr style="background-color: rgba(255, 123, 114, 0.03);">
        <td rowspan="3" style="padding: 15px; border-bottom: 1px solid #30363d; font-weight: bold; color: #ff7b72; vertical-align: top;">PCM5102 (DAC)</td>
        <td style="padding: 8px 15px; color: #c9d1d9;">BCK (Bit Clock)</td>
        <td style="padding: 8px 15px; text-align: center; font-family: monospace; font-weight: bold; color: #ff7b72; background-color: rgba(255, 123, 114, 0.1);">GPIO 26</td>
      </tr>
      <tr style="background-color: rgba(255, 123, 114, 0.03);">
        <td style="padding: 8px 15px; color: #c9d1d9;">LRCK (Word Select)</td>
        <td style="padding: 8px 15px; text-align: center; font-family: monospace; font-weight: bold; color: #ff7b72; background-color: rgba(255, 123, 114, 0.1);">GPIO 25</td>
      </tr>
      <tr style="background-color: rgba(255, 123, 114, 0.03);">
        <td style="padding: 8px 15px; border-bottom: 1px solid #30363d; color: #c9d1d9;">DIN (Data In)</td>
        <td style="padding: 8px 15px; border-bottom: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #ff7b72; background-color: rgba(255, 123, 114, 0.1);">GPIO 19</td>
      </tr>

      <tr style="background-color: rgba(121, 192, 255, 0.03);">
        <td rowspan="2" style="padding: 15px; border-bottom: 1px solid #30363d; font-weight: bold; color: #79c0ff; vertical-align: top;">SSD1306 (OLED)</td>
        <td style="padding: 8px 15px; color: #c9d1d9;">SCL (Clock)</td>
        <td style="padding: 8px 15px; text-align: center; font-family: monospace; font-weight: bold; color: #79c0ff; background-color: rgba(121, 192, 255, 0.1);">GPIO 22</td>
      </tr>
      <tr style="background-color: rgba(121, 192, 255, 0.03);">
        <td style="padding: 8px 15px; border-bottom: 1px solid #30363d; color: #c9d1d9;">SDA (Data)</td>
        <td style="padding: 8px 15px; border-bottom: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #79c0ff; background-color: rgba(121, 192, 255, 0.1);">GPIO 21</td>
      </tr>

      <tr style="background-color: rgba(126, 231, 135, 0.03);">
        <td style="padding: 15px; border-bottom: 1px solid #30363d; font-weight: bold; color: #7ee787;">PRZYCISK</td>
        <td style="padding: 12px 15px; border-bottom: 1px solid #30363d; color: #c9d1d9;">Sterowanie<br><small style="color: #8b949e;">(Zwieraj do GND)</small></td>
        <td style="padding: 12px 15px; border-bottom: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #7ee787; background-color: rgba(126, 231, 135, 0.1);">GPIO 13 ↔ GND</td>
      </tr>

      <tr style="background-color: rgba(210, 168, 255, 0.02);">
        <td rowspan="3" style="padding: 15px; font-weight: bold; color: #d2a8ff; vertical-align: top;">ZASILANIE</td>
        <td style="padding: 8px 15px; color: #8b949e;">VCC PCM5102</td>
        <td style="padding: 8px 15px; text-align: center; font-weight: bold; color: #ffa657;">5V / VIN</td>
      </tr>
      <tr style="background-color: rgba(210, 168, 255, 0.02);">
        <td style="padding: 8px 15px; color: #8b949e;">VCC OLED</td>
        <td style="padding: 8px 15px; text-align: center; font-weight: bold; color: #ffa657;">3.3V</td>
      </tr>
      <tr style="background-color: rgba(210, 168, 255, 0.02);">
        <td style="padding: 8px 15px; color: #8b949e;">Wspólna Masa</td>
        <td style="padding: 8px 15px; text-align: center; font-weight: bold; color: #8b949e;">GND (Wszystkie)</td>
      </tr>
    </tbody>
  </table>

  <div style="background-color: #161b22; padding: 12px; font-size: 11px; color: #8b949e; text-align: center; border-top: 1px solid #30363d; line-height: 1.5;">
    Przycisk wykorzystuje wewnętrzny rezystor podciągający (PULLUP).<br>
    Wymagane połączenie pinu 13 bezpośrednio do masy (GND) przy wciśnięciu.
  </div>
</div>

## 🛠 Power Supply
* **PCM5102:** Connect to **5V (VIN)**.
* **OLED:** Connect to **3.3V**.
* **Common Ground:** Ensure all GND pins are connected together.

## 📦 Required Libraries
* [ESP32-A2DP](https://github.com/pschatzmann/ESP32-A2DP)
* [U8g2](https://github.com/olikraus/u8g2)
