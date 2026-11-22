# Documentación de Software

## Contenido
Esta carpeta reúne los diagramas, la descripción de funciones y los procedimientos de instalación, operación y diagnóstico del sistema IoT de monitoreo de suelo del Grupo 5 (TEI201).

### Documentación de Funciones

#### Funciones Principales

`promediarLectura(int pin)`
- Propósito: reducir fluctuaciones de lectura mediante el promedio aritmético de 10 valores analógicos.
- Parámetros: pin (int): entrada analógica del sensor.
- Retorna: int: promedio de las 10 lecturas ADC.
- Ejemplo de uso:
  ```
  int lecturaHumedad = promediarLectura(PIN_HUMEDAD); int lecturaLuz = promediarLectura(PIN_LUZ);```

`calcularPorcentajeHumedad(int raw)`
- Propósito: convertir la lectura ADC a una escala estimada de 0 a 100 %.
- Parámetros: raw (int): lectura filtrada del sensor capacitivo.
- Retorna: int: porcentaje calculado a partir de las referencias RAW_SECO = 2965 y RAW_MOJADO = 2300.
- Ejemplo de uso:
  ```int humedadPorcentaje = calcularPorcentajeHumedad(lecturaHumedad);```

`obtenerCategoriaHumedad(int porcentaje, int& estadoIndex)`
- Propósito: clasificar el nivel de humedad y asignar un identificador de estado para detectar cambios.
- Parámetros: porcentaje (int): humedad estimada; estadoIndex (int&): variable modificada por referencia para indicar la categoría.
- Retorna: String: diagnóstico textual de humedad.
- Ejemplo de uso:
 ```int estadoActual = 0;String diagnostico = obtenerCategoriaHumedad(humedadPorcentaje, estadoActual);``` 

`setup()`
- Propósito: iniciar el Monitor Serial, configurar la conexión de red y preparar el bot de Telegram.
- Parámetros: ninguno.
- Retorna: `void`.
- Ejemplo de uso: Arduino ejecuta `setup()` automáticamente una sola vez al iniciar o reiniciar.

`loop()`
- Propósito: ejecutar periódicamente el ciclo de adquisición y notificar cambios de categoría de humedad.
- Parámetros: ninguno.
- Retorna: void.
- Ejemplo de uso: Arduino llama a `loop()` repetidamente después de `setup()`.

## Criterios de clasificación (humedad y luz ambiental)

| Humedad estimada | Estado |
|---|---|
| Menor que 25 % | Seco |
| 25–54 % | Óptimo |
| 55–74 % | Húmedo |
| 75–100 % | Empapado |


| Lectura ADC del KY-018 | Estado lumínico |
|---|---|
| Mayor que 3000 | Oscuro |
| 2001–3000 | Sombra |
| 1001–2000 | Luz moderada |
| 0–1000 | Sol directo |

## Manual de Instalación

1. Preparar el software: instalar Arduino IDE 2.x en el computador.

2. Añadir soporte ESP32: en el Gestor de placas del IDE, instalar el paquete esp32 de Espressif Systems.

3. Confirmar la placa: seleccionar el modelo exacto de ESP32 y el puerto USB. El informe menciona un ESP32 DevKit V1, mientras que las fotografías del proyecto muestran una placa identificada como ESP32-S3; no son intercambiables en la asignación de pines analógicos.

4. Verificar conexiones: comprobar alimentación, tierra común y correspondencia de los GPIO declarados con el modelo de placa. Mantener los conectores y la placa alejados del agua durante las pruebas.

5. Instalar dependencias: consultar [`../librerias/README.md`](../librerias/README.md). Se requiere la librería para Telegram y sus dependencias compatibles; WiFi.h y WiFiClientSecure.h se incluyen con el paquete ESP32.

6.Incorporar el firmware real: agregar a software/src/ el archivo .ino definitivo del equipo y abrirlo en Arduino IDE. El archivo no estaba presente en el ZIP revisado.

7.Configurar conexión y destinatario: completar en el entorno local los parámetros de Wi-Fi, token del bot y CHAT_ID. El código del informe utiliza una red WPA2 Enterprise; una red doméstica WPA2-Personal requiere adaptar la configuración según el tipo de autenticación.

8.Proteger credenciales: no publicar contraseñas, tokens ni identificadores privados en GitHub. Si se usa un archivo local de secretos, excluirlo del control de versiones.

9.Compilar y cargar: seleccionar placa y puerto correctos, compilar el programa y subirlo al dispositivo. Verificar compatibilidad de esp_wpa2.h con la versión del paquete ESP32 realmente instalada.

10.Comprobar funcionamiento: abrir el Monitor Serial a 115200 baudios, observar las lecturas y verificar que un cambio de estado de humedad genere la alerta esperada en Telegram.

---

## Manual de Operación

### Encendido del Sistema
1. Ubicar el sensor de humedad en el sustrato y el sensor KY-018 en una posición desde la que pueda registrar la iluminación ambiente, sin exponer la electrónica a salpicaduras.
2. Alimentar el ESP32 mediante una fuente adecuada a la placa y encender el dispositivo.
3. Abrir el Monitor Serial si se necesita supervisar el inicio y confirmar conexión Wi-Fi; revisar en Telegram la notificación de inicio o primer cambio de estado, según el firmware efectivamente instalado.

### Operación Normal
1. El ESP32 realiza el ciclo de lectura con un intervalo documentado de 10 segundos.
2. En cada ciclo obtiene el promedio de 10 muestras analógicas por sensor.
3. Calcula el porcentaje estimado de humedad y clasifica la luminosidad.
4. Cuando cambia la categoría de humedad, prepara una notificación de Telegram que incluye humedad, diagnóstico y nivel de luz.
5. El usuario interpreta el estado recibido y decide si corresponde revisar o ajustar el riego de la planta.

### Apagado del Sistema
1. Finalizar la observación y guardar los registros necesarios de la prueba.
2. Desconectar de forma segura la fuente de alimentación del ESP32.
3. Si se necesita modificar el cableado, hacerlo siempre con la placa desenergizada; mantener secos los componentes electrónicos.
---

## Troubleshooting
Problemas Comunes
Problema 1: No conecta a WiFi
- Causa probable: credenciales incorrectas, falta de cobertura o tipo de autenticación incompatible con la configuración del firmware (por ejemplo, WPA2 Enterprise frente a una red doméstica).
- Solución: verificar el SSID, las credenciales y el método de autenticación; revisar mensajes del Monitor Serial y probar con una red compatible. Comprobar también la versión del núcleo ESP32 y el código de autenticación utilizado.
Problema 2: Sensor no responde
- Causa probable: pines o cableado incorrectos, alimentación defectuosa o selección de una placa distinta a la utilizada en el código.
- Solución: desconectar la energía, revisar señal/VCC/GND y confirmar que los pines elegidos admiten lectura analógica en el microcontrolador real. No utilizar automáticamente GPIO 4 y 5 si la placa es un ESP32 clásico.
Problema 3: Las lecturas de humedad fluctúan demasiado
- Causa probable: ruido en la señal ADC, conexiones flojas, variaciones de alimentación o calibración insuficiente.
- Solución: revisar el cableado y la alimentación, verificar que se esté aplicando el promedio de 10 muestras y repetir la calibración en condiciones de referencia.

