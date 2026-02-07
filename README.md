# ESP32 Bluetooth Audio Receiver

**ESP32 Bluetooth Audio Receiver** is a high-quality Bluetooth A2DP audio sink (receiver) based on the ESP32. It features an external I2S DAC for superior sound quality and an OLED display for status and metadata.

## ✨ Features
* **High-Fidelity Audio:** Uses I2S protocol with PCM5102 DAC.
* **OLED Visuals:** Real-time track information and status.
* **Custom Splash Screen:** Features the "BLYNDY" logo with polished animations.
* **Single Button Control:** Integrated Play/Pause and connection management.

## 🔌 Connection Diagram (Pinout)

<div style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Arial, sans-serif; max-width: 550px; color: #e6edf3; background-color: #0d1117; border: 1px solid #30363d; border-radius: 12px; overflow: hidden;">
  <table style="width: 100%; border-collapse: collapse; font-size: 13px;">
    <thead>
      <tr style="background-color: #161b22; color: #58a6ff;">
        <th style="padding: 12px; border-bottom: 1px solid #30363d; text-align: left;">Module</th>
        <th style="padding: 12px; border-bottom: 1px solid #30363d; text-align: left;">Function</th>
        <th style="padding: 12px; border-bottom: 1px solid #30363d; text-align: center;">ESP32 GPIO</th>
      </tr>
    </thead>
    <tbody>
      <tr style="background-color: rgba(255, 123, 114, 0.03);">
        <td rowspan="3" style="padding: 10px; border-bottom: 1px solid #30363d; font-weight: bold; color: #ff7b72;">PCM5102 DAC</td>
        <td style="padding: 5px 10px;">BCK</td>
        <td style="padding: 5px 10px; text-align: center; font-family: monospace; font-weight: bold; color: #ff7b72;">26</td>
      </tr>
      <tr style="background-color: rgba(255, 123, 114, 0.03);">
        <td style="padding: 5px 10px;">LRCK</td>
        <td style="padding: 5px 10px; text-align: center; font-family: monospace; font-weight: bold; color: #ff7b72;">25</td>
      </tr>
      <tr style="background-color: rgba(255, 123, 114, 0.03);">
        <td style="padding: 5px 10px; border-bottom: 1px solid #30363d;">DIN</td>
        <td style="padding: 5px 10px; border-bottom: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #ff7b72;">19</td>
      </tr>
      <tr style="background-color: rgba(121, 192, 255, 0.03);">
        <td rowspan="2" style="padding: 10px; border-bottom: 1px solid #30363d; font-weight: bold; color: #79c0ff;">OLED Display</td>
        <td style="padding: 5px 10px;">SCL</td>
        <td style="padding: 5px 10px; text-align: center; font-family: monospace; font-weight: bold; color: #79c0ff;">22</td>
      </tr>
      <tr style="background-color: rgba(121, 192, 255, 0.03);">
        <td style="padding: 5px 10px; border-bottom: 1px solid #30363d;">SDA</td>
        <td style="padding: 5px 10px; border-bottom: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #79c0ff;">21</td>
      </tr>
      <tr style="background-color: rgba(126, 231, 135, 0.03);">
        <td style="padding: 10px; font-weight: bold; color: #7ee787;">Control Button</td>
        <td style="padding: 10px;">Push to GND</td>
        <td style="padding: 10px; text-align: center; font-family: monospace; font-weight: bold; color: #7ee787;">13</td>
      </tr>
    </tbody>
  </table>
</div>

## 🛠 Power Supply
* **PCM5102:** Connect to **5V (VIN)**.
* **OLED:** Connect to **3.3V**.
* **Common Ground:** Ensure all GND pins are connected together.

## 📦 Required Libraries
* [ESP32-A2DP](https://github.com/pschatzmann/ESP32-A2DP)
* [U8g2](https://github.com/olikraus/u8g2)
