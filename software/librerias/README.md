# Librerías

## Librerías Estándar (Arduino IDE)

Preparar el paquete de placas esp32 de Espressif Systems mediante el Gestor de placas de Arduino IDE y luego instalar las bibliotecas adicionales desde **Programa / Sketch > Incluir librería > Administrar bibliotecas.**
1. `WiFi.h `— Incluida en el núcleo Arduino-ESP32
   - Propósito: establecer y gestionar la conexión Wi-Fi del dispositivo.
   - Instalación: se distribuye con el paquete de placas esp32 de Espressif Systems; no se instala normalmente como biblioteca adicional.
   - Versión: depende de la versión del paquete ESP32 instalada; por confirmar.
2. `WiFiClientSecure.h` — Incluida en el núcleo Arduino-ESP32
   - Propósito: disponer de un cliente de conexión segura para servicios HTTPS, como la API de Telegram.
   - Instalación: se incluye con el paquete de placas esp32.
   - Versión: depende del núcleo ESP32; por confirmar.
3. `UniversalTelegramBot.h` — Librería adicional
   - Propósito: enviar notificaciones al usuario mediante un bot de Telegram (`bot.sendMessage(...)`).
   - Instalación: abrir el Gestor de bibliotecas, buscar `UniversalTelegramBot` e instalar una versión compatible.
   - Versión: por confirmar.
   - Repositorio de referencia: Universal Arduino Telegram Bot — Brian Lough.
4. `ArduinoJson` — Dependencia de Telegram
   - Propósito: procesar los mensajes JSON utilizados por la biblioteca de Telegram.
   - Instalación: buscar `ArduinoJson` en el Gestor de bibliotecas e instalar la versión compatible con UniversalTelegramBot.
   - Versión: por confirmar.
5. `esp_wpa2.h` — Encabezado específico del soporte ESP32 utilizado en el informe
   - Propósito: configurar la autenticación de una red WPA2 Enterprise, según el ejemplo de conexión del grupo.
   - Instalación: no corresponde instalarlo como biblioteca independiente sin comprobar compatibilidad. Su disponibilidad y la API de autenticación dependen de la versión del núcleo Arduino-ESP32 / ESP-IDF.
   - Versión: compatibilidad por verificar con el firmware y la placa reales.
  

## Librerías Personalizadas/Modificadas ## 
Para el desarrollo del prototipo no se utilizaron librerías persnalizadas


## Dependencias Completas

| Librería / componente | Versión | Fuente | Obligatoria |
|---|---|---|---|
| `WiFi.h` | Núcleo ESP32: por confirmar | Paquete `esp32` de Espressif Systems | Sí |
| `WiFiClientSecure.h` | Núcleo ESP32: por confirmar | Paquete `esp32` de Espressif Systems | Sí, para el código Telegram documentado |
| `UniversalTelegramBot` | Por confirmar | Arduino Library Manager / [GitHub](https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot) | Sí, para el código Telegram documentado |
| `ArduinoJson` | Por confirmar | Arduino Library Manager / [GitHub](https://github.com/bblanchon/ArduinoJson) | Dependencia de UniversalTelegramBot; confirmar compatibilidad |
| `esp_wpa2.h` | Por confirmar | Soporte ESP32 / ESP-IDF de la versión utilizada | Solo si se mantiene la implementación WPA2 Enterprise del informe |
