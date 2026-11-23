## FUENTES — Dependencias, código externo e inteligencia artificial ##

Este archivo declara las fuentes identificables en la documentación del equipo. Antes de la entrega debe cotejarse con el código fuente efectivamente subido al repositorio y con los aportes de cada integrante. No se asignan versiones ni autorías que no hayan sido comprobadas.


## Librerías y dependencias

| Librería / componente | Versión usada | Función declarada | Fuente de referencia | Estado de verificación |
|:--|:--|:--|:--|:--|
| `WiFi.h` (Arduino-ESP32) | **Por confirmar** | Conexión Wi-Fi del ESP32 | [Espressif: Arduino-ESP32](https://github.com/espressif/arduino-esp32) | Mencionada en el anexo; cotejar con firmware actual |
| `WiFiClientSecure.h` (Arduino-ESP32) | **Por confirmar** | Cliente de conexión segura para Telegram | [Espressif: Arduino-ESP32](https://github.com/espressif/arduino-esp32) | Mencionada en el anexo |
| `UniversalTelegramBot.h` | **Por confirmar** | Comunicación con la API de bots de Telegram | [Universal Arduino Telegram Bot](https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot) | Mencionada en el anexo |
| `esp_wpa2.h` / soporte WPA2 Enterprise | **Por confirmar** | Autenticación en red empresarial, según la versión del framework | [Espressif: Arduino-ESP32](https://github.com/espressif/arduino-esp32) | Mencionada en el anexo; revisar compatibilidad real |


-----------
## Código externo usado o reutilizado

| Función o parte del proyecto | Procedencia | Adaptación realizada |
|:--|:--|:--|
| Lectura con promedio de 10 muestras | **Por confirmar con autores del firmware** | El informe presenta un promedio de lecturas analógicas y su uso en el sensor de suelo | 
| Mapeo de calibración de humedad | **Por confirmar con autores del firmware** | Conversión de valores `RAW_SECO` y `RAW_MOJADO` a una escala porcentual | 
| Mensajería y notificaciones Telegram | **Por confirmar con autores del firmware** | El anexo incluye envío por cambio de estado |
| Conexión Wi-Fi con WPA2 Enterprise | **Por confirmar con autores del firmware** | Se muestra autenticación para la red universitaria | 

---------------
## Documentación del proyecto — ChatGPT ##
- Herramienta: ChatGPT (OpenAI).
- Fecha: noviembre de 2026.
- Finalidad: asistencia en la organización y redacción de documentación Markdown para GitHub, especialmente en hardware/README.md, iteraciones/README.md y este FUENTES.md; revisión de requisitos de la pauta y propuesta de tablas, listas de verificación e instrucciones explicativas.
- Interacción utilizada (resumen fiel, no cita textual de un único prompt): solicitud de crear y mejorar README con formato de GitHub, tomando como referencia la pauta de TEI201, el montaje fotografiado, el informe del proyecto y los antecedentes entregados por el equipo.
- Aporte del equipo y límites: componentes, fotografías, problemas del Alpha y documentos de avance aportados por los integrantes; la asistencia ayudó a ordenar esa información. El equipo debe revisar la precisión técnica de cada declaración, completar los campos pendientes y comprobar que la documentación coincida con el dispositivo real.
- Comprensión: las decisiones de cableado, calibración, alimentación, pruebas y seguridad deben poder ser explicadas por los integrantes; una redacción generada no sustituye esa verificación.





| Material | Uso dentro del proyecto |
|:--|:--|
| *Avance 3 — Prototipo IoT Completo* (pauta de TEI201) | Requisitos de código, hardware, pruebas, GitHub e integridad académica |
| [Repositorio de ejemplo proporcionado por el profesor](https://github.com/jgarcia-dec/sensor-calidad-suelo-TEI201) | Referencia de organización y nivel de documentación; **no implica reutilización de código** |
| *Avance 2 — Sistema Inteligente de Monitoreo de Suelo* | Antecedentes técnicos del prototipo Alpha y problemas detectados |
| *Informe Final Proyecto: Agricultura urbana inteligente* (22/11/2026) | Arquitectura declarada, variables, calibración, sensores y anexo de código |

