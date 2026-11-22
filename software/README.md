# Software - Documentación

## Contenido
Esta carpeta contiene todo el código y documentación del software del proyecto.

### 📁 Carpetas
sdsdsdsd
#### `src/`
Código fuente del proyecto (.ino para Arduino/ESP32)

#### `librerias/`
Librerías adicionales necesarias (no incluidas en Arduino IDE)

#### `docs/`
Documentación técnica del software

---

## Stack Tecnológico

*Plataforma:* Arduino / ESP32  
*Lenguaje:* C/C++  
*IDE:* Arduino IDE 2.x  
-----
**Librerías Principales**
| Librería | Función | Versión |
|---|---|---|
| `WiFi.h` | Conexión del ESP32 a una red Wi-Fi | Incluida en Arduino-ESP32; versión por confirmar |
| `WiFiClientSecure.h` | Cliente para comunicación HTTPS | Incluida en Arduino-ESP32; versión por confirmar |
| `UniversalTelegramBot.h` | Envío de mensajes mediante un bot de Telegram | Por confirmar |
| `esp_wpa2.h` | Autenticación WPA2 Enterprise, según el código del informe | Compatibilidad y versión por verificar |

---

## Instalación y Configuración

1. Instalar Arduino IDE
   1.Instalar Arduino IDE 2.x desde el sitio oficial de Arduino.
   2.Abrir el IDE y comprobar que permita detectar el puerto USB del microcontrolador.
2. Configurar ESP32/Arduino
   1.Abrir el Gestor de placas de Arduino IDE.
   2.Instalar el paquete esp32 by Espressif Systems.
   3.Conectar el ESP32 al computador mediante un cable USB que transfiera datos.
   4.Seleccionar en Herramientas > Placa el modelo que corresponda al dispositivo físico y elegir su puerto.
   5.Verificar la correspondencia de conexiones y pines con el montaje real.

### 3. Instalar Librerías
1. En **Programa > Incluir librería > Administrar bibliotecas**, buscar e instalar `UniversalTelegramBot`.
2. Verificar las dependencias que solicite esa versión de la librería, incluida ArduinoJson si corresponde.
3. `WiFi.h` y `WiFiClientSecure.h` se obtienen del paquete de placas ESP32.
4. Si el firmware utiliza la red WPA2 Enterprise, comprobar que las llamadas de autenticación sean compatibles con la versión instalada de Arduino-ESP32.
5. Registrar las versiones finalmente utilizadas en [`librerias/README.md`](librerias/README.md) y en [`../FUENTES.md`](../FUENTES.md).

### 4. Cargar Código
1. Abrir `src/main.ino`
2. Seleccionar placa y puerto
3. Compilar y subir

---

## Configuración de Parámetros

Editar las siguientes constantes en el código:

```cpp
// WiFi
#define WIFI_SSID "tu_red"
#define WIFI_PASS "tu_password"

// Sensores
#define SENSOR_PIN 4
#define SAMPLE_RATE 1000

// Otros parámetros
```

---

## Arquitectura del Software

[Incluir diagrama de flujo o arquitectura]

### Módulos Principales
1. **Inicialización** - Setup del sistema
2. **Lectura de Sensores** - Captura de datos
3. **Procesamiento** - Análisis y decisiones
4. **Actuación** - Control de actuadores
5. **Comunicación** - Envío de datos

---

## API / Endpoints (si aplica)

| Endpoint | Método | Descripción |
|----------|--------|-------------|
| `/status` | GET | Estado del sistema |
| `/data` | GET | Datos de sensores |
| `/control` | POST | Control de actuadores |
