# Testing y Validación

## Objetivo
Validar el funcionamiento del prototipo con usuarios reales y medir el impacto cuantitativo en la problemática ODS seleccionada.

---

## 📁 Carpetas

#### `reportes/`
Documentos con resultados del testing

#### `evidencias/`
Fotos y videos de sesiones con usuarios

#### `datos/`
Datos cuantitativos recolectados

---

## Metodología de Testing

### Grupo Objetivo
* **Perfil de usuarios:** Adultos de 25 a 45 años interesados en la jardinería doméstica y el cuidado de plantas, con conocimientos tecnológicos básicos.

* **Cantidad mínima:** 5 usuarios.

* **Ubicación:** Hogares y espacios de agricultura urbana de la Región Metropolitana, principalmente balcones, terrazas y jardines domésticos.

### Protocolo de Testing
1. **Briefing** (5 min)
* Explicar el propósito del sistema de monitoreo de suelo.

* Presentar los sensores de humedad y luminosidad.

* Contextualizar su utilidad para optimizar el riego doméstico.

2. **Sesión de Uso** (15-20 min)
* El usuario interactúa con el sistema y consulta las mediciones.

* Interpreta los estados de humedad y las alertas de Telegram.

* Se registran dificultades, dudas y comportamientos relevantes.
3. **Entrevista Post-Testing** (10 min)
* Consultar sobre la facilidad de uso del dispositivo.

* Evaluar la claridad de las mediciones y notificaciones.

* Recoger opiniones sobre su utilidad para el cuidado de plantas.

* Solicitar sugerencias de mejora.

4. **Encuesta Cuantitativa** (5 min)
* Aplicar una escala Likert de 1 a 5.

* Evaluar la facilidad de uso, claridad de las alertas, utilidad percibida y satisfacción general.

* Registrar las respuestas individuales para calcular los promedios y analizar los resultados.
---

## Testing con Usuarios

### 1. Perfil de los participantes

Se realizó una evaluación de usabilidad con cinco usuarios ficticios de distintos niveles de experiencia en jardinería y tecnología.

| Usuario | Edad | Perfil | Experiencia |
|---|---:|---|---|
| U01 | 27 | Cultiva plantas en departamento | Básica |
| U02 | 34 | Aficionado a la jardinería | Intermedia |
| U03 | 42 | Mantiene un pequeño huerto doméstico | Avanzada |
| U04 | 30 | Cuida plantas ocasionalmente | Baja |
| U05 | 39 | Interesado en tecnología y automatización | Alta |

### 2. Resultados de las sesiones

**Usuario 01 — Experiencia positiva**

El usuario consideró útil recibir notificaciones de humedad en su teléfono, especialmente porque suele olvidar cuándo regar sus plantas. Encontró comprensibles las alertas de Telegram, aunque manifestó interés en visualizar el historial de mediciones.

- **Aspecto positivo:** Facilidad para interpretar las alertas.
- **Dificultad:** Falta de visualización histórica.
- **Sugerencia:** Incorporar gráficos de humedad.

**Usuario 02 — Experiencia positiva con observaciones**

Valoró la incorporación del sensor de luminosidad, considerando que permite conocer mejor las condiciones ambientales de sus plantas. Sin embargo, indicó que los estados de humedad podrían complementarse con recomendaciones más específicas.

- **Aspecto positivo:** Monitoreo de humedad y luz.
- **Dificultad:** Información poco personalizada.
- **Sugerencia:** Incorporar recomendaciones según el tipo de planta.

**Usuario 03 — Experiencia crítica**

El usuario manifestó preocupación por la exposición de los componentes electrónicos y los cables, especialmente al utilizar el prototipo cerca de tierra húmeda. Consideró que el sistema tiene potencial, pero requiere mejorar su protección física.

- **Aspecto positivo:** Utilidad de las mediciones.
- **Dificultad:** Ausencia de encapsulado protector.
- **Sugerencia:** Incorporar una carcasa resistente a salpicaduras.

**Usuario 04 — Experiencia intermedia**

El usuario encontró interesante el sistema, pero presentó dificultades para comprender inicialmente los porcentajes de humedad y su relación con las necesidades de la planta. Consideró que las notificaciones deberían utilizar un lenguaje más sencillo.

- **Aspecto positivo:** Información accesible mediante Telegram.
- **Dificultad:** Interpretación de algunos indicadores.
- **Sugerencia:** Añadir instrucciones sencillas de riego.

**Usuario 05 — Experiencia técnica**

Valoró la integración del ESP32 y la comunicación inalámbrica. Sin embargo, señaló que depender de la conectividad Wi-Fi puede limitar el funcionamiento del sistema y que sería útil disponer de almacenamiento de datos para consultar mediciones anteriores.

- **Aspecto positivo:** Integración de sensores y conectividad.
- **Dificultad:** Dependencia de la conexión inalámbrica.
- **Sugerencia:** Incorporar almacenamiento histórico y recuperación ante desconexiones.

### 3. Encuesta cuantitativa simulada

Escala Likert de 1 a 5, donde 1 representa una evaluación muy negativa y 5 una muy positiva.

| Usuario | Facilidad de uso | Claridad de alertas | Utilidad percibida | Satisfacción general |
|---|---:|---:|---:|---:|
| U01 | 5 | 5 | 5 | 5 |
| U02 | 4 | 4 | 5 | 4 |
| U03 | 3 | 4 | 4 | 3 |
| U04 | 3 | 2 | 4 | 3 |
| U05 | 4 | 4 | 4 | 3 |

### 4. Hallazgos

**Fortalezas identificadas:**
- Las alertas de Telegram pueden facilitar el seguimiento de la humedad.
- La combinación de sensores permite contextualizar mejor las condiciones del cultivo.
- El sistema ofrece una alternativa al riego basado únicamente en la intuición.

**Aspectos por mejorar:**
- Incorporar una carcasa protectora.
- Facilitar la interpretación de las mediciones.
- Implementar o mejorar la visualización histórica.
- Evaluar el comportamiento ante fallas de conectividad.

### 5. Conclusión de la simulación

En base al estudio se sugiere que el prototipo podría resultar útil para usuarios interesados en el cuidado doméstico de plantas, particularmente por su capacidad de monitoreo y notificación.

No obstante, también permiten identificar limitaciones en la protección física, interpretación de datos y disponibilidad de información histórica.

Estas observaciones constituyen hipótesis para orientar futuras pruebas reales y el desarrollo del prototipo definitivo.

---

## Validación de Impacto ODS

**ODS Seleccionado:** ODS 12 — Producción y Consumo Responsables.

**Meta específica del proyecto:** Promover el uso eficiente del agua en la agricultura urbana mediante el monitoreo de humedad y luminosidad del suelo, reduciendo el riego innecesario.

**Indicadores de impacto:**
1. Reducción del consumo de agua: Baseline: 0% de ahorro respecto al riego convencional, Meta: 20%, Alcanzado: 32% reportado en el informe final (pendiente de verificar con registros experimentales).
2. Tiempo en condiciones óptimas de humedad: Meta: 80%, Alcanzado: 88% reportado en el informe final.

**Proyección de impacto a escala:**
Si el sistema se implementara en 1.000 hogares y cada uno consumiera 100 litros mensuales en riego, una reducción hipotética del 32% permitiría ahorrar aproximadamente 32.000 litros de agua al mes, equivalentes a 384.000 litros anuales.
