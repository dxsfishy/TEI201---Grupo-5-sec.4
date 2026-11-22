Markdown
# Archivos Nativos - Fusion 360

Esta carpeta contiene el archivo fuente paramétrico del encapsulado 3D (`modelo_completo_v4.f3z`).

## 🔄 Justificación del Cambio de Modelo (v3.0 ➡️ v4.0)
El archivo anterior (`modelo_completo_v3.f3z`, de `120 × 80 mm`) fue reemplazado por la nueva versión hermética `modelo_completo_v4.f3z` (`80 × 80 mm`) por dos razones técnicas principales:
1. **Hermeticidad e impermeabilidad:** Se eliminaron las aberturas expuestas (puertos y rejillas abiertas) y se incorporó un cierre perimetral macho-hembra (*tongue-and-groove*) diseñado para alojar una junta/cordón de sellado de `2 mm`, comprimido mediante 4 tornillos M3 en las esquinas.
2. **Integración y distribución del hardware:** Se reorganizó la arquitectura en dos tapas independientes (*clamshell*) para alojar el `ESP32-S3-WROOM-1` en una mitad (mediante una cuna perimetral a presión sin tornillos que protege los pines soldados) y el portabaterías `4× AA` (`61.95 × 57.75 mm`) en la otra mitad con guías de retención.

---

## Estructura del Modelo

### Componentes (Components)
text
Ensamble_Principal
├── Tapa_Superior_ESP32        (Con cuna a presión y orificios pasantes avellanados M3)
├── Tapa_Inferior_Baterias     (Con guías de retención y tubos receptores roscados M3)
├── ESP32_S3_WROOM_1           (Agrupado mediante Rigid Group)
├── Portabaterias_4xAA         (61.95 mm × 57.75 mm)
└── Tornilleria_M3             (4 tornillos en postes integrados a las esquinas)

### Uniones (Joints) y Grupos
- **Grupo Rígido (`Rigid Group` - ESP32-S3-WROOM-1):** Bloquea todos los subcomponentes importados de la placa (PCB, módulo WROOM-1, conectores USB y pines) como un único cuerpo sólido para su posicionamiento exacto en la cuna.
- **Alineación de Cierre (`As-Built Joint` / `Rigid` entre tapas):** Restringe el encastre perimetral macho-hembra y alinea coaxialmente los 4 orificios avellanados de `Tapa_Superior_ESP32` con los tubos receptores de `Tapa_Inferior_Baterias`.

---

## Parámetros
Parámetros principales utilizados en el diseño:
- `ancho_total = 80 mm`
- `largo_total = 80 mm`
- `grosor_pared = 2 mm`
- `ancho_brida_sello = 5 mm`
- `diametro_junta = 2 mm`
- `holgura_esp32 = 0.25 mm`
- `holgura_baterias = 0.45 mm`

---

## Instrucciones de Apertura
1. Abrir **Autodesk Fusion** (Fusion 360).
2. Ir a **File > Open** (o *Archivo > Abrir*) y seleccionar el archivo `modelo_completo_v4.f3z`.
3. Verificar en el **Browser** (navegador izquierdo) que todos los componentes y grupos rígidos estén activos y sin advertencias.
4. Revisar el **Timeline** (historial inferior) y utilizar **Inspect > Section Analysis** para validar el encastre del canal hermético y el despeje interno entre los pines del ESP32-S3 y las baterías.

## Versiones

| Versión | Fecha | Cambios Principales |
| :--- | :--- | :--- |
| **v4.0** | 22/11/2026 | Rediseño completo a carcasa hermética de `80 × 80 mm` en dos tapas (*clamshell*): incorporación de cierre perimetral macho-hembra con junta de `2 mm`, 4 postes M3 en esquinas, cuna a presión para `ESP32-S3-WROOM-1` y guías internas para portabaterías `4× AA`. |
| **v3.0** | 27/10/2026 | Versión final para Avance #3 (`120 × 80 × 35 mm`): modelo no hermético con rejillas de ventilación y calado USB. |
| **v2.1** | — | Ajustes post Avance #2. |
| **v1.0** | — | Primera versión funcional. |
