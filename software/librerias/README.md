# Librerías

## Librerías Estándar (Arduino IDE)

Preparar el paquete de placas esp32 de Espressif Systems mediante el Gestor de placas de Arduino IDE y luego instalar las bibliotecas adicionales desde Programa / Sketch > Incluir librería > Administrar bibliotecas.
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
  
---

## Librerías Personalizadas/Modificadas

Si hay librerías modificadas o no disponibles en Arduino IDE, incluir en esta carpeta:

### Estructura
```
librerias/
├── MiLibreria/
│   ├── MiLibreria.h
│   ├── MiLibreria.cpp
│   ├── keywords.txt
│   └── README.md
```

### Instalación Manual
```bash
# Copiar carpeta a Arduino libraries
cp -r MiLibreria ~/Documents/Arduino/libraries/
```

---

## Dependencias Completas

Listar TODAS las librerías necesarias con versiones exactas:

| Librería | Versión | Fuente | Obligatoria |
|----------|---------|--------|-------------|
| WiFi | Built-in | ESP32 Core | ✅ |
| [Lib 1] | x.x.x | Arduino Library Manager | ✅ |
| [Lib 2] | x.x.x | GitHub | ❌ |
