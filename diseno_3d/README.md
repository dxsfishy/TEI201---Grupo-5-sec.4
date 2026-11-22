# Diseño 3D - Documentación

## 1. ⚠️ Requisito Crítico y Estructura del Ensamble

**Archivo nativo:** `modelo_completo_v4.f3z` (ubicado en `fusion360/`)

El modelo 3D incluye los siguientes componentes del prototipo, cumpliendo con la rúbrica mediante el siguiente árbol de jerarquía:
- `Ensamble_Principal`
  - `Tapa_Superior_ESP32` (con alojamiento tipo cuna y orificios pasantes avellanados M3)
  - `Tapa_Inferior_Baterias` (con guías de retención y postes receptores M3)
  - `ESP32_S3_WROOM_1` (ensamblado como grupo rígido en su soporte)
  - `Portabaterias_4xAA` (61.95 mm × 57.75 mm en posición de instalación)

## 2. Carpetas del Módulo

- `fusion360/`: Archivos nativos de Fusion 360 (`.f3z`) y ensamblajes exportados (`.step`).
- `stl/`: Mallas listas para laminar e imprimir en 3D (`.stl`).
- `renders/`: Imágenes renderizadas de alta calidad y vistas de sección del sello hermético.
- `planos/`: Planos técnicos con cotas y tolerancias.

## 3. Especificaciones y Parámetros de Diseño (Dimensionamiento)

- **Software:** Autodesk Fusion
- **Unidades:** Milímetros (mm)
- **Escala:** 1:1 (dimensiones reales)

| Parámetro | Valor |
| :--- | :--- |
| **Dimensiones externas (Ancho × Largo)** | `80 mm × 80 mm` (con esquinas redondeadas) |
| **Grosor de pared / brida de unión** | `2 mm` (pared base) / `5 mm` (borde de sellado) |
| **Holgura de montaje de componentes** | `0.25 mm` (ESP32-S3) / `0.45 mm` (Portabaterías) |
| **Sistema de sellado hermético** | Cierre macho-hembra (*tongue-and-groove*) para junta/cordón de `2 mm` |
| **Fijación de cierre** | 4 tornillos **M3** en postes internos integrados a las esquinas |
| **Material propuesto** | PETG o ASA (carcasa) / TPU 95A o cordón de silicona (sello) |

## 4. Justificación de Decisiones de Diseño (Rediseño Hermético v4.0)

El modelo anterior (`v3.0` de `120 × 80 × 35 mm`) fue reemplazado por esta nueva arquitectura compacta de dos mitades (`80 × 80 mm`) por dos motivos críticos detectados durante la integración:

- **Hermeticidad e impermeabilidad:** El diseño anterior contaba con aberturas abiertas para USB y rejillas que exponían la electrónica a filtraciones de humedad y polvo. En la `v4.0` se eliminaron las aberturas expuestas y se diseñó un cierre perimetral macho-hembra (canal hembra de `2.2 × 1.6 mm` y lengüeta macho de `2.0 × 1.2 mm`) que comprime una junta tórica/cordón de goma de `2 mm` alrededor de todo el perímetro.
- **Acomodo y sujeción dedicada del hardware:** Se dividió el montaje en dos tapas independientes (*clamshell*) para optimizar el volumen interno (`80 × 80 mm`) y evitar interferencias entre componentes:
  - **Alojamiento del ESP32-S3-WROOM-1:** Dado que esta placa no cuenta con agujeros de montaje en sus esquinas y tiene los pines muy próximos a los bordes largos, se diseñó una cuna perimetral a presión con escalones de apoyo únicamente en los extremos cortos de la PCB, manteniendo los pines soldados elevados y libres de contacto con el fondo.
  - **Alojamiento del portabaterías (4× AA):** Se incorporaron guías laterales centradas en la tapa opuesta ajustadas a las dimensiones reales del portapilas (`61.95 × 57.75 mm`), con rebaje para el paso seguro del cableado de alimentación.
- **Sistema de cierre mecánico uniforme:** Se integraron 4 columnas en las esquinas interiores (orificios pasantes avellanados de `3.2 mm` en la tapa superior y tubos receptores de `2.7 mm` en la inferior) para aplicar presión homogénea sobre el sello hermético sin interrumpir el canal de la junta.

## 5. Consideraciones de Diseño Cumplidas

**Funcionales**
- [x] Estanqueidad y protección ambiental (cierre hermético perimetral comprimido por 4 tornillos M3)
- [x] Sujeción mecánica segura para el `ESP32-S3-WROOM-1` y el portabaterías `4× AA`
- [x] Optimización volumétrica (`80 × 80 mm`) con despeje vertical entre los pines y las baterías
- [x] Fácil acceso para mantenimiento (apertura mediante 4 tornillos exteriores para cambio de pilas)

**Fabricación**
- [x] Imprimible sin soportes complejos (orientación plana sobre la cama de impresión para ambas tapas)
- [x] Tolerancias calibradas para FDM (`+0.25 mm` a `+0.45 mm` en encastres y `+0.2 mm` en el canal de sellado)
- [x] Grosor de pared estructural mínimo `2 mm` con múltiples perímetros para evitar porosidad entre capas

## 6. Instrucciones de Apertura y Verificación

Para la correcta revisión de este modelo, el evaluador debe:
1. Descargar el archivo `modelo_completo_v4.f3z` desde la carpeta `fusion360/`.
2. Abrirlo en **Autodesk Fusion**.
3. Desplegar el árbol de componentes (*Browser*) para verificar la correcta estructura del ensamble descrita arriba.
4. Revisar el *Timeline* (historial de operaciones) en la parte inferior y activar **Inspeccionar > Análisis de sección (Section Analysis)** para comprobar el encastre del sello hermético y el despeje interno entre el ESP32-S3 y las baterías.

## 7. Configuración de Impresión 3D (Parámetros Sugeridos)

- **Impresora:** [Completar modelo, ej. Creality Ender 3]
- **Material:** PETG (recomendado por resistencia a la humedad y temperatura) / TPU 95A (para junta opcional)
- **Calidad de capa:** `0.20 mm`
- **Perímetros (Paredes):** `4 a 5 líneas` (indispensable para garantizar estanqueidad entre capas)
- **Relleno (Infill):** `20 - 30%` (patrón Giroide o Cúbico)
- **Flujo (Flow):** `102%` (mejora la fusión entre paredes y reduce micro-poros)
- **Soportes:** No requiere (ambas tapas se imprimen apoyadas sobre su base exterior)
- **Temperatura nozzle:** `235 °C` (PETG) / `205 °C` (PLA)
- **Temperatura cama:** `75-80 °C` (PETG) / `60 °C` (PLA)
- **Velocidad:** `45 - 55 mm/s`

*(Nota: Tiempos y peso final de material dependerán de los ajustes en el laminador/slicer definitivo).*

## 8. Tabla de Control de Versiones

| Versión | Fecha | Descripción del Cambio |
| :--- | :--- | :--- |
| **v3.0** | 27/10/2026 | Modelo conceptual Alpha (`120 × 80 × 35 mm`): dimensionamiento volumétrico, fijaciones preliminares e integración espacial de hardware con rejillas abiertas. |
| **v4.0** | 22/11/2026 | Rediseño completo a carcasa hermética de `80 × 80 mm` en dos mitades: incorporación de cierre perimetral macho-hembra con junta de `2 mm`, 4 postes M3 en esquinas, cuna a presión para `ESP32-S3-WROOM-1` y guías internas para portabaterías `4× AA`. |
