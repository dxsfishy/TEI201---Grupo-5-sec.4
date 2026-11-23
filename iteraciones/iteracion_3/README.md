# Iteración 3 - Versión Final

## Información General

**Fecha:** 04 / 11 / 2026  
**Versión:** v3.0  
**Estado:** Prototipo final  
**Avance asociado:** Avance #3

---

## Descripción
La tercera iteración corresponde a la versión final del sistema **Monitor Inteligente de Plantas IoT**, en la cual se integraron el hardware, el firmware definitivo, el encapsulado impreso en 3D y la interfaz de notificaciones remotas mediante un Bot de Telegram. El sistema diagnostica en tiempo real la humedad del sustrato y la exposición lumínica de la planta, enviando alertas inteligentes al teléfono del usuario únicamente cuando ocurre un cambio relevante en el estado de riego.

### Objetivos alcanzados
- Integración completa del ESP32-S3, sensor capacitivo v1.2 y sensor KY-018 dentro del encapsulado final.
- Encapsulado definitivo diseñado en Fusion 360 e impreso en 3D con exposición directa para el sensor de luz y ranura estanca para la sonda de suelo.
- Comunicación WiFi estable con reconexión automática (`WiFi.setAutoReconnect(true)`).
- Sistema de notificaciones inteligentes en Telegram basado en cambios de estado (`SECO`, `ÓPTIMO`, `HÚMEDO`, `EMPAPADO`) con formato HTML enriquecido

---

## Cambios Respecto a v2

- Integración completa del ESP32-S3, sensor capacitivo v1.2 y sensor KY-018 dentro del encapsulado final.
- Encapsulado definitivo diseñado en Fusion 360 e impreso en 3D con exposición directa para el sensor de luz y ranura estanca para la sonda de suelo.
- Comunicación WiFi estable con reconexión automática (`WiFi.setAutoReconnect(true)`).
- Sistema de notificaciones inteligentes en Telegram basado en cambios de estado (`SECO`, `ÓPTIMO`, `HÚMEDO`, `EMPAPADO`) con formato HTML enriquecido.

---

## Cambios Respecto a v2

### Hardware

#### Mejoras implementadas

#### Integración definitiva dentro del encapsulado 3D

**Razón**  
Proteger la electrónica del polvo y salpicaduras de agua durante el riego, manteniendo el sensor KY-018 expuesto a la luz ambiental.
**Impacto**  
Mayor durabilidad, estética limpia y facilidad para instalar el dispositivo directamente junto a la maceta.

---

#### Estabilización de conexiones internas

**Razón**  
Evitar falsos contactos en los pines `GPIO 4` y `GPIO 5` al manipular o trasladar el prototipo.
**Impacto**  
Lecturas consistentes sin desconexiones accidentales durante las pruebas de campo.

---

### Software

#### Nuevas funcionalidades
- **Detección inteligente por cambio de estado (`estadoAnteriorHumedad`):** El bot envía reportes únicamente cuando la tierra transiciona entre categorías, eliminando el spam de mensajes.
- **Formateo enriquecido en HTML:** Mensajes estructurados con negritas, cursivas e indicadores visuales (`🥵`, `🌱`, `💧`, `🌊`, `🌙`, `⛅`, `☀️`) para lectura rápida desde el celular.
- **Diagnóstico combinado:** Cada alerta de humedad incluye además el porcentaje y clasificación de luz ambiente en ese instante.


**Optimizaciones finales:**
- Ciclo de muestreo cada 3 segundos (`delay(3000)`) con promedio de 10 lecturas por sensor para respuesta rápida ante eventos de riego.
- Reconexión automática ante microcortes de la red WiFi doméstica.

#### Manejo de errores
- Validación del envío del mensaje mediante `bot.sendMessage()` con registro de confirmación o fallo en el Monitor Serial.
- Restricción de rangos porcentuales mediante `constrain(..., 0, 100)` para evitar valores fuera de escala.

---

### Diseño Mecánico

#### Encapsulado Final
- Diseño optimizado para impresión 3D en PLA.
- Apertura superior calibrada para el fotorresistor del módulo KY-018.
- Ranura inferior para el paso de cables hacia el sensor capacitivo v1.2 enterrado en la maceta.
- Acceso lateral al puerto USB-C del ESP32-S3 para alimentación y depuración.


---

## Fotos del Prototipo Final

Incluir en esta carpeta:
- `v3_prototipo_final_frontal.jpg`
- `v3_prototipo_final_posterior.jpg`
- `v3_interior_componentes.jpg`
- `v3_instalado_contexto.jpg`
- `v3_detalle_sensores.jpg`
- `v3_testing_usuarios.jpg` (múltiples)

---

## Resultados Finales

### Funcionalidad Completa
- ✅ Medición filtrada de humedad volumétrica relativa del sustrato (`GPIO 4`).
- ✅ Medición filtrada de luminosidad ambiente con KY-018 (`GPIO 5`).
- ✅ Conexión WiFi estable con reconexión automática.
- ✅ Envío inteligente de alertas por cambio de estado mediante Bot de Telegram.
- ✅ Formato visual claro en HTML con indicadores de estado de tierra y luz.
- ✅ Encapsulado completamente ensamblado y operativo en maceta real.


## Validación del Sistema
Durante esta iteración se realizaron pruebas funcionales completas para verificar:

- Lectura precisa en sustrato seco (`< 25%` → alerta `SECO 🥵`).
- Transición inmediata tras el riego hacia el rango ideal (`25% - 54%` → alerta `ÓPTIMO 🌱`).
- Detección de exceso de agua (`55% - 74%` → `HÚMEDO 💧` y `>= 75%` → `EMPAPADO 🌊`).
- Clasificación correcta de iluminación diurna, semisombra y nocturna mediante el KY-018.
- Ausencia de mensajes repetidos mientras el estado de la planta permanece estable.

Todas las funciones principales operaron correctamente durante las pruebas del prototipo final.


---

## Comparación de las 3 Iteraciones

| Característica | v1 | v2 | v3 |
|---------------|:--:|:--:|:--:|
| Lectura de humedad (GPIO 4) | ✅ | ✅ | ✅ |
| Lectura de luz KY-018 (GPIO 5) | ✅ | ✅ | ✅ |
| Filtrado digital (promedio 10 muestras) | ❌ | ✅ | ✅ |
| Clasificación automática de estados | ❌ | ✅ | ✅ |
| Comunicación WiFi con auto-reconexión | ❌ | Parcial | ✅ |
| Alertas por Bot de Telegram | ❌ | Continuo | Inteligente (por cambio) |
| Formato HTML e iconos de diagnóstico | ❌ | ❌ | ✅ |
| Encapsulado 3D ensamblado | ❌ | Modelado | Finalizado |


---

## Fortalezas del Prototipo Final

### Notificaciones sin saturación

Al comparar cada lectura con `estadoAnteriorHumedad`, el usuario recibe información únicamente cuando la planta requiere atención o cambia su condición tras el riego.

---

### Diagnóstico integral de entorno

Combina dos variables críticas para el cuidado doméstico de plantas (humedad radicular e incidencia de luz) en un único reporte legible desde cualquier lugar.

---

### Diseño modular y replicable

El uso de sensores estándar (capacitivo v1.2 y KY-018) junto con un encapsulado impreso en 3D permite replicar o mantener el dispositivo con bajo costo y facilidad.

---

## Limitaciones Identificadas

### Dependencia de alimentación por cable USB

El sistema requiere conexión continua a una fuente de 5V por USB.

**Posible mejora**  
Incorporar una batería LiPo con módulo de carga TP4056 y modo *Deep Sleep* en el ESP32-S3 para autonomía inalámbrica.

---

### Monitoreo pasivo (unidireccional)

El bot envía alertas automáticas ante cambios de estado, pero no responde a consultas bajo demanda del usuario.

**Posible mejora**  
Implementar comandos interactivos en Telegram como `/estado` para consultar las métricas en cualquier momento.

---

## Aprendizajes

### Técnicos

- La calibración empírica con el sustrato real del proyecto (`2965` en seco y `2300` en mojado) es indispensable para evitar falsas alarmas de riego.
- El promediado de lecturas ADC elimina eficazmente el ruido propio de sensores analógicos económicos.

### Diseño

- El modelado 3D en Fusion 360 permitió integrar el sensor KY-018 en la carcasa sin obstruir su fotorresistor.

### Trabajo en Equipo

- La división de responsabilidades entre calibración de sensores, programación del bot, diseño 3D y documentación permitió iterar de forma ordenada y validar cada avance antes de la integración final.

---

## Trabajo Futuro

### Mejoras a Corto Plazo

- [ ] Agregar soporte para comandos de consulta manual en Telegram (`/estado`, `/luz`).
- [ ] Incorporar historial diario de riego y horas de luz recibidas.

### Mejoras a Mediano Plazo

- [ ] Integrar alimentación por batería recargable y gestión de bajo consumo (*Deep Sleep*).
- [ ] Añadir sensor de temperatura ambiente/sustrato (DS18B20 o DHT22).

### Escalabilidad

- [ ] Monitorear múltiples macetas desde un mismo bot identificando cada planta por nombre.
- [ ] Conectar el sistema a una electroválvula para automatizar el riego cuando el estado pase a `SECO`.

---

## Archivos en esta Carpeta

- `v3_codigo_final.ino` - Código final documentado
- `v3_esquema_final.png` - Esquema definitivo del circuito
- `v3_modelo3d_final.f3d` - Diseño 3D completo en Fusion 360
- `v3_fotos/` - Fotografías del prototipo final
- `v3_testing_completo.pdf` - Reporte de testing con usuarios
- `v3_comparativa_versiones.xlsx` - Datos comparativos v1-v2-v3
