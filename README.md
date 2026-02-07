## 🔌 Connection Diagram / Schemat Połączeń

<table style="width: 100%; border-collapse: collapse; font-family: sans-serif; background-color: #0d1117; color: #e6edf3; border: 1px solid #30363d;">
  <thead>
    <tr style="background-color: #161b22; color: #58a6ff;">
      <th style="padding: 12px; border: 1px solid #30363d; text-align: left;">Moduł / Urządzenie</th>
      <th style="padding: 12px; border: 1px solid #30363d; text-align: left;">Pin Funkcja</th>
      <th style="padding: 12px; border: 1px solid #30363d; text-align: center;">Połączenie ESP32</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="3" style="padding: 12px; border: 1px solid #30363d; font-weight: bold; color: #ff7b72;">PCM5102 (DAC)</td>
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
      <td rowspan="2" style="padding: 12px; border: 1px solid #30363d; font-weight: bold; color: #79c0ff;">SSD1306 (OLED)</td>
      <td style="padding: 8px; border: 1px solid #30363d;">SCL (Clock)</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #79c0ff;">GPIO 22</td>
    </tr>
    <tr>
      <td style="padding: 8px; border: 1px solid #30363d;">SDA (Data)</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #79c0ff;">GPIO 21</td>
    </tr>
    <tr>
      <td style="padding: 12px; border: 1px solid #30363d; font-weight: bold; color: #7ee787;">PRZYCISK</td>
      <td style="padding: 12px; border: 1px solid #30363d;">Sterowanie (GND)</td>
      <td style="padding: 12px; border: 1px solid #30363d; text-align: center; font-family: monospace; font-weight: bold; color: #7ee787;">GPIO 13 ↔ GND</td>
    </tr>
    <tr style="background-color: #161b22;">
      <td rowspan="3" style="padding: 12px; border: 1px solid #30363d; font-weight: bold; color: #d2a8ff;">ZASILANIE</td>
      <td style="padding: 8px; border: 1px solid #30363d;">VCC PCM5102</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-weight: bold; color: #ffa657;">5V / VIN</td>
    </tr>
    <tr>
      <td style="padding: 8px; border: 1px solid #30363d;">VCC OLED</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-weight: bold; color: #ffa657;">3.3V</td>
    </tr>
    <tr>
      <td style="padding: 8px; border: 1px solid #30363d;">Wspólna Masa</td>
      <td style="padding: 8px; border: 1px solid #30363d; text-align: center; font-weight: bold; color: #8b949e;">GND (All)</td>
    </tr>
  </tbody>
</table>
