# Iteración 2 - Primera Mejora Significativa

## Información General

**Fecha:** 28 / 09 / 2026  
**Versión:** v2.0  
**Estado:** Prototipo funcional mejorado  
**Avance asociado:** Avance #2

---

## Descripción

En esta segunda iteración se unificó la lectura de ambos sensores en un único firmware modular, se incorporó el filtrado digital de señales para eliminar el ruido eléctrico y se estableció la conexión WiFi junto con las primeras pruebas de comunicación hacia la API de Telegram. Asimismo, se inició el diseño mecánico del encapsulado en Fusion 360.


**Objetivos de esta iteración:**
- Unificar el sensor de humedad (`GPIO 4`) y el sensor de luz KY-018 (`GPIO 5`) en un mismo código.
- Implementar el promediado de lecturas analógicas para estabilizar las mediciones.
- Definir umbrales agronómicos para clasificar automáticamente la humedad (`SECO`, `ÓPTIMO`, `HÚMEDO`, `EMPAPADO`) y la luz.
- Conectar el ESP32-S3 a la red WiFi e integrar la librería `UniversalTelegramBot`.
- Desarrollar el primer modelado 3D del encapsulado.


---

## Cambios Respecto a v1

### Hardware

#### Componentes agregados
- Primer prototipo de encapsulado diseñado en Autodesk Fusion 360.

#### Componentes modificados
- Consolidación de ambos sensores en una misma línea de alimentación de 3.3V del ESP32-S3.
- Ajuste fino de constantes de calibración (`RAW_SECO = 2965`, `RAW_MOJADO = 2300`, `RAW_LUZ_OSCURO = 3800`, `RAW_LUZ_SOL = 500`).

#### Componentes removidos
- Ninguno.


### Software
#### Nuevas funcionalidades
- Conexión del ESP32-S3 a WiFi en modo estación (`WIFI_STA`) con reconexión automática.
- Clasificación automática del estado de la tierra y nivel de luz ambiente.
- Integración de cliente seguro (`WiFiClientSecure`) y envío inicial de mensajes de prueba a Telegram.

#### Optimizaciones
- Creación de la función `leerAnalogicoFiltrado()` (promedio de 10 muestras cada 10 ms).
- Modularización del código en funciones independientes (`obtenerEstadoLuz()` y `obtenerEstadoHumedad()`).

#### Problemas corregidos
- Eliminación de saltos erráticos en el porcentaje de humedad y luz gracias al filtro de promedio móvil.

---

### Diseño Mecánico
- Modelado de la carcasa base y tapa superior en Fusion 360.
- Definición de ranura para salida del sensor capacitivo hacia la maceta y ventana superior para exposición del sensor KY-018.


---

## Fotos del Prototipo v2

Incluir en esta carpeta:
- `v2_prototipo_completo.jpg`
- `v2_circuito_integrado.jpg`
- `v2_encapsulado_inicial.jpg`
- `v2_testing_usuario.jpg`

---

## Resultados de Testing

### Funcionalidad Lograda

✅ Lectura filtrada y simultánea de humedad y luz.
✅ Clasificación automática en 4 categorías de humedad y 3 de luminosidad.
✅ Conexión estable a red WiFi local.
✅ Envío exitoso de mensajes de prueba a Telegram.
⚠️ Envío repetitivo de mensajes en cada ciclo del `loop()` (generaba spam en el chat).
⚠️ Encapsulado aún en fase de ajuste de tolerancias para impresión 3D.

---

## Problemas Pendientes

### Problema 1
**Descripción**
El sistema enviaba notificaciones de Telegram en cada iteración mientras se mantuviera una condición, saturando el chat del usuario.
**Prioridad**
Alta.
**Plan para v3**
Implementar una variable de memoria de estado (`estadoAnteriorHumedad`) para enviar alertas únicamente cuando exista una transición real de categoría.

---

### Problema 2
**Descripción**
El encapsulado requería ajustes en las holguras internas para alojar cómodamente los cables Dupont y permitir el acceso al puerto USB-C del ESP32-S3.
**Prioridad**
Alta.
**Plan para v3**
Refinar las tolerancias del modelo 3D, imprimir la carcasa definitiva y ensamblar el prototipo final.


---

## Comparación v1 vs v2

| Aspecto | v1 | v2 |
|---------|----|----|
| Sensor de humedad (GPIO 4) | ✅ | ✅ |
| Sensor de luz KY-018 (GPIO 5) | ✅ | ✅ |
| Filtrado digital de ruido | ❌ | ✅ |
| Clasificación automática de estado | ❌ | ✅ |
| Comunicación WiFi | ❌ | ✅ |
| Integración Bot de Telegram | ❌ | Parcial (envío continuo) |
| Encapsulado 3D | ❌ | Modelado inicial |


---

## Plan para Iteración 3 (Versión Final)

### Mejoras Críticas

### Hardware
- [ ] Realizar el montaje final de todos los componentes dentro del encapsulado impreso en 3D.

### Software
- [ ] Implementar lógica de detección de cambio de estado (`textoHum != estadoAnteriorHumedad`) para evitar notificaciones duplicadas.
- [ ] Formatear los reportes de Telegram con etiquetas HTML y emojis descriptivos.

### Diseño
- [ ] Imprimir en 3D la versión definitiva del encapsulado con ventana superior para el KY-018 y salida inferior para la sonda de humedad.

### Validación
- [ ] Ejecutar pruebas prolongadas en una maceta real verificando cambios entre tierra seca, riego óptimo y exceso de agua.


---

## Archivos en esta Carpeta

- `v2_codigo.ino` - Código de esta versión
- `v2_esquema.png` - Esquema del circuito actualizado
- `v2_modelo3d.f3d` - Primer diseño en Fusion 360
- `v2_fotos/` - Fotografías del prototipo
- `v2_feedback.pdf` - Compilación de comentarios recibidos
