# Iteración 1 - Concepto Inicial

## Información General

**Fecha:** 24 / 08 / 2026  
**Versión:** v1.0  
**Estado:** Prototipo alpha - Prueba de concepto  
**Avance asociado:** Avance #1


---

## Descripción

Primera versión del prototipo del sistema de diagnóstico de plantas IoT, enfocada en validar la adquisición de datos analógicos mediante un ESP32-S3, un sensor capacitivo de humedad del suelo v1.2 y un módulo fotorresistor KY-018.
El objetivo principal fue comprobar la viabilidad técnica del proyecto, verificar la estabilidad de las lecturas ADC y establecer una base funcional para futuras iteraciones.
## Objetivos de esta iteración ##
- Validar la lectura analógica del sensor capacitivo de humedad v1.2 (`GPIO 4`).
- Validar la lectura analógica del sensor de luminosidad KY-018 (`GPIO 5`).
- Realizar una calibración experimental inicial (valores en seco, mojado, oscuridad y luz directa).
- Visualizar las mediciones crudas (RAW) y porcentuales mediante el Monitor Serial.

---

## Componentes Utilizados

### Hardware
**Microcontrolador:** 
- ESP32-S3

**Sensores:**
- Sensor capacitivo de humedad del suelo v1.2
- Sensor fotorresistor de luz KY-018 (LDR)

**Otros**
- Protoboard
- Cables Dupont
- Cable USB-C de datos y alimentación


### Software
- Arduino IDE 2.x
- Arduino Core para ESP32
**Versión del firmware:** v1.0

---

## Fotos del Prototipo

Incluir en esta carpeta:
- `v1_circuito_protoboard.jpg`
- `v1_vista_general.jpg`
- `v1_detalle_conexiones.jpg`

---

## Resultados de Testing Inicial

### Funcionalidad Lograda
✅ Lectura individual y simultánea del sensor capacitivo de humedad y del KY-018.
✅ Comunicación estable entre el ESP32-S3 y el Monitor Serial a 115200 baudios.
✅ Obtención de valores crudos de referencia para calibración.
❌ Conectividad WiFi.
❌ Envío de alertas remotas (Bot de Telegram).

### Problemas Identificados

1. **Problema 1:**
   - Descripción: Las lecturas analógicas del ADC presentaban fluctuaciones puntuales debido al ruido eléctrico en el protoboard.
   - Causa probable: Lectura única directa del pin analógico sin filtrado digital ni estabilización de muestra.
   - Solución propuesta: Implementar una función de promediado de múltiples lecturas (`leerAnalogicoFiltrado()`) en la Iteración 2.

2. **Problema 2:**
   - Descripción: El monitoreo dependía exclusivamente de mantener el ESP32 conectado por cable USB al computador.
   - Causa probable: Falta de módulo de comunicación inalámbrica y plataforma de notificación remota en esta etapa.
   - Solución propuesta: Integrar conectividad WiFi y configurar un Bot de Telegram para recibir reportes en el teléfono móvil.

---
## Aprendizajes

### Técnicos
- Comprender el comportamiento inverso de ambos sensores analógicos: mayor humedad o mayor luz disminuyen el valor crudo leído por el ADC de 12 bits (`0–4095`).
- Identificar los pines ADC adecuados en el ESP32-S3 (`GPIO 4` y `GPIO 5`).


### De Diseño
- La longitud de los cables Dupont debía planificarse considerando que el sensor capacitivo va enterrado en el sustrato y el KY-018 debe quedar expuesto a la luz ambiente.


---

## Plan para Iteración 2

### Mejoras Planificadas

**Hardware:**
- [ ] Mejorar el orden del cableado en protoboard.
- [ ] Refinar los valores de calibración experimental (`RAW_SECO`, `RAW_MOJADO`, `RAW_LUZ_OSCURO`, `RAW_LUZ_SOL`).

**Software:**
- [ ] Implementar filtrado por promedio de 10 muestras.
- [ ] Agregar funciones de clasificación del estado del suelo y nivel de iluminación.
- [ ] Implementar la conexión WiFi del ESP32-S3.


**Diseño:**
- [ ] Iniciar el modelado 3D del encapsulado protector en Fusion 360.

---

## Archivos en esta Carpeta

- `v1_codigo.ino` - Código de esta versión
- `v1_esquema.png` - Esquema del circuito
- `v1_fotos/` - Fotografías del prototipo
- `v1_notas.txt` - Notas adicionales del equipo
