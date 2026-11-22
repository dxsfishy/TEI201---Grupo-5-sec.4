# Historial de Iteraciones
---

## Estructura de Carpetas

Cada iteración tiene su propia carpeta con documentación de esa versión:

```
iteraciones/
├── iteracion_1/    # Concepto inicial - Prototipo alpha
├── iteracion_2/    # Primera iteración - Avance #2
└── iteracion_3/    # Versión final - Avance #3
```

---

## Contenido de Cada Iteración

Cada carpeta debe incluir:

1. **README.md** - Descripción de la versión
2. **Fotos** - Imágenes del prototipo en ese estado
3. **Esquema** - Circuito de esa versión (si cambió)
4. **Código** - Versión del software (si cambió)
5. **Notas** - Problemas identificados y mejoras planificadas

---

## Tabla Comparativa de Iteraciones

| Aspecto | v1 | v2 | v3 |
|---------|----|----|----| 
| **Fecha** |24/08/26 | 28/10/26 |22/11/26 |
| **Sensores** | Humedad | Humedad |  Humedad y Luz |
| **Actuadores** | ❌ | Telegram | Telegram |
| **Conectividad** | Wifi | Wifi | Wifi |
| **Encapsulado** | ❌ | Prototipo | Finalizado |
| **Testing** | Solo equipo | 2 usuarios | 5+ usuarios |
| **Funcionalidad** | 60% | 80% | 100% |

---

### Evolución del Diseño

## Iteración 01 — Conceptualización de la solución
**Fecha:** 24 de agosto del 2026
-------
**Problema de partida**
* Los usuarios de agricultura urbana toman decisiones de riego con información limitada sobre las condiciones de su sustrato. El proyecto se orientó a entregar datos locales que apoyaran esas decisiones y permitieran disminuir el desperdicio de recursos.
---
**Solución planteada**
* Las primeras propuestas contemplaron un sistema IoT con microcontrolador ESP32 y sensores relacionados con las condiciones del suelo. En esa etapa se consideraron variables como humedad, temperatura y pH, además de alternativas de alimentación autónoma.
---
**Decisión para avanzar**
* Priorizar un prototipo realizable de monitoreo de humedad del suelo, con posibilidad de integrar otras variables ambientales posteriormente.

Evidencia: Informe de problemática y conceptualización y Entregable 2, Grupo 5.


### Iteración 02 — Prototipo Alpha funcional
**Fecha:** 28 de Octubre del 2026
---
La presentación Avance 2 — Sistema Inteligente de Monitoreo de Suelo documenta:
- Sensor capacitivo de humedad de suelo v1.2.
- Procesamiento mediante ESP32.
- Filtrado de lecturas analógicas usando un promedio de 10 muestras.
- Conversión de lecturas a una escala porcentual y clasificación de estado hídrico.
- Conexión Wi-Fi y alertas mediante un bot de Telegram.
**Resultado y limitaciones**
La presentación incluye una demostración de lectura del sensor y alertas. No proporciona, por sí sola, una base de datos o registros completos para verificar estabilidad a largo plazo.

Evidencia: presentación Avance 2, secciones «Componentes», «Documentación técnica» y «Demostración en vivo».

### Iteración 3 - Versión Final
**Fecha:** 22 de noviembre del 2026 

| Problema observado | Cambio descrito por el equipo | Propósito | Qué falta verificar |
|:--|:--|:--|:--|
| Lecturas analógicas con ruido y valores erráticos | Promedio de 10 lecturas y control de valores fuera del rango esperado | Evitar que una lectura aislada cambie el diagnóstico | Comparación de series de valores crudos y filtrados |
| Riesgo de cortocircuito durante pruebas de riego | Reubicación/protección experimental de la electrónica para exponerla menos a la humedad | Disminuir riesgo durante el ensayo | Fotografías y procedimiento de seguridad del montaje actual |
---

## Justificación de Cambios

### Hardware
**De v1 a v2:**
- Cambio: Reorganización del montaje y conexiones eléctricas.
- Razón: Reducir la exposición de los componentes a la humedad y evitar cortocircuitos.
- Impacto: Mayor seguridad y estabilidad del prototipo.

**De v2 a v3:**
- Cambio: Incorporación del sensor de luminosidad KY-018.
- Razón: Complementar las mediciones de humedad con información sobre la iluminación ambiental.
- Impacto: Monitoreo más completo de las condiciones del cultivo.

### Software
**De v1 a v2:**
- Se incorporó un filtro de lecturas para reducir el ruido y mejorar la estabilidad de las mediciones.

**De v2 a v3:**
- Se mejoró la clasificación de humedad y se incorporó el procesamiento de datos lumínicos.

### Diseño 3D
**De v1 a v2:**
- Se desarrolló un primer modelo de carcasa para organizar los componentes y protegerlos de factores externos.

**De v2 a v3:**
- Diseño 3D: Se ajustó el diseño para considerar la incorporación del sensor de luz y facilitar el acceso a los componentes internos.

---

## Métricas de Mejora

| Métrica | v1 | v2 | v3 |
|---------|----|----|----| 
| Medición de humedad | ✅| ✅ | ✅ |
| Envío al servidor | ❌ | ✅| ✅ |
| Comunicación WiFi | ❌ | ✅ | ✅ |
| Encapsulado | ❌ | Parcial | ✅ | 
| Medición de la luz|❌ |❌ |✅|

---

## Lecciones Aprendidas

### Técnicas
* Aprendimos a mejorar la estabilidad de las mediciones mediante filtros que reducen el ruido de los sensores.
* Comprendimos la importancia de calibrar los sensores y verificar las conexiones para obtener datos confiables.

### De Proceso
* Comprendimos que realizar pruebas periódicas permite detectar y corregir errores oportunamente.
* Aprendimos que documentar cada avance facilita el seguimiento del proyecto y sus futuras mejoras.

### De Trabajo en Equipo
* Reconocimos que una comunicación constante facilita la coordinación y evita retrasos.
* Aprendimos que distribuir las tareas según las habilidades de cada integrante mejora la eficiencia del grupo.
