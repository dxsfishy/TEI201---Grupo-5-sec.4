# Diseño 3D - Documentación

## 1. ⚠️ Requisito Crítico y Estructura del Ensamble

**Archivo nativo:** `modelo_completo_v3.f3d` (ubicado en `fusion360/`)

El modelo 3D incluye **TODOS** los componentes del prototipo, cumpliendo con la rúbrica mediante el siguiente árbol de jerarquía:

  *  Ensamble_Principal
  *  Encapsulado_Inferior
  *  Encapsulado_Superior
  *  ESP32_DevKit (con orientación de pines hacia arriba)
  *  Sensor_DHT22 (en posición de instalación)
  *  Moisture Sensor
  *  LED_Indicador
  *  Batería / fuente de alimentación (espacio volumétrico)
  *  Tornilleria (fijaciones y sistema de montaje)

---

## 2. Carpetas del Módulo

* **`fusion360/`**: Archivos nativos de Fusion 360 (.f3d).
* **`renders/`**: Imágenes renderizadas de alta calidad.
* **`planos/`**: Planos técnicos con cotas.

---

## 3. Especificaciones y Parámetros de Diseño (Dimensionamiento)

**Software:** Autodesk Fusion 360  
**Unidades:** Milímetros (mm)  
**Escala:** 1:1 (dimensiones reales)

| Parámetro | Valor |
| :--- | :--- |
| **Dimensiones externas (Ancho x Alto x Prof)** | 120 mm × 80 mm × 35 mm |
| **Grosor de pared** | 2 mm |
| **Holgura de ensamble** | 0.2 mm |
| **Material propuesto** | PLA o PETG |

---

## 4. Justificación de Decisiones de Diseño (Rúbrica Avance #2)

* **Acomodo del hardware:** Las dimensiones volumétricas (120x80x35 mm) albergan holgadamente el ESP32, los sensores, el ruteo del cableado y la batería, evitando dobleces críticos o tensiones.
* **Decisión de orientación:** Se dispuso el microcontrolador ESP32 con los pines orientados hacia arriba. Esto facilita el conexionado interno, permite un testeo rápido con multímetro y otorga acceso cómodo durante la demostración.
* **Accesos e interfaces:** Se diseñó un calado exterior para el conector USB de programación/energía. Se incorporaron orificios y rejillas para el funcionamiento óptimo de los sensores y la visibilidad del LED.
* **Material y proceso propuesto:** El diseño está pensado para fabricación aditiva, manteniendo un espesor constante de 2 mm para garantizar rigidez mecánica estructural y un enfriamiento uniforme sin deformaciones.

---

## 5. Consideraciones de Diseño Cumplidas

### Funcionales
- [x] Acceso a puertos USB/alimentación
- [x] Ventilación adecuada (rejillas)
- [x] Protección de componentes
- [x] Fácil acceso para mantenimiento (testeo)
- [x] Resistencia a condiciones ambientales estándar

### Fabricación
- [x] Imprimible sin soportes excesivos
- [x] Tolerancias de ensamble (+0.2mm)
- [x] Grosor de pared mínimo 2mm
- [x] Sin ángulos imposibles (overhangs <45°)

---

## 6. Instrucciones de Apertura y Verificación

Para la correcta revisión de este modelo, el evaluador debe:
1. Descargar el archivo `modelo_completo_v3.f3d` desde la carpeta `fusion360/`.
2. Abrirlo en **Autodesk Fusion 360**.
3. Desplegar el **árbol de componentes** (Browser) para verificar la correcta estructura del ensamble descrita arriba.
4. Revisar el **Timeline** (historial de operaciones) en la parte inferior para comprobar el uso de buenas prácticas y parametrización.

---

## 7. Configuración de Impresión 3D (Parámetros Sugeridos)

**Impresora:** [Completar modelo, ej. Creality Ender 3]  
**Material:** PLA / PETG  
**Calidad de capa:** 0.2 mm  
**Relleno:** 20-30%  
**Soportes:** [Completar Sí/No - dónde]  
**Temperatura nozzle:** 200-210 °C (PLA) / 235 °C (PETG)  
**Temperatura cama:** 60 °C (PLA) / 70-80 °C (PETG)  
**Velocidad:** 50-60 mm/s  

*(Nota: Tiempos y peso final de material dependerán de los ajustes en el laminador/slicer definitivo).*

---

## 8. Tabla de Control de Versiones

| Versión | Fecha | Descripción del Cambio |
| :--- | :--- | :--- |
| **v3.0** | 27/10/2026 | Modelo conceptual Alpha: dimensionamiento volumétrico, fijaciones preliminares e integración espacial de hardware. |
