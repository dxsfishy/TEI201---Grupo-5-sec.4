Markdown
# Archivos Nativos - Fusion 360

Esta carpeta contiene el archivo fuente paramétrico del encapsulado 3D (`modelo_completo_v4.f3d`).

## 🔄 Justificación del Cambio de Modelo (v3.0 ➡️ v4.0)
El archivo anterior (`modelo_completo_v3.f3d`, de `120 × 80 mm`) fue reemplazado por la nueva versión hermética `modelo_completo_v4.f3d` (`80 × 80 mm`) por dos razones técnicas principales:
1. **Hermeticidad e impermeabilidad:** Se eliminaron las aberturas expuestas (puertos y rejillas abiertas) y se incorporó un cierre perimetral macho-hembra (*tongue-and-groove*) diseñado para alojar una junta/cordón de sellado de `2 mm`, comprimido mediante 4 tornillos M3 en las esquinas.
2. **Integración y distribución del hardware:** Se reorganizó la arquitectura en dos tapas independientes (*clamshell*) para alojar el `ESP32-S3-WROOM-1` en una mitad (mediante una cuna perimetral a presión sin tornillos que protege los pines soldados) y el portabaterías `4× AA` (`61.95 × 57.75 mm`) en la otra mitad con guías de retención.

---

## Estructura del Modelo

### Componentes (Components)
```text
Ensamble_Principal
├── Tapa_Superior_ESP32        (Con cuna a presión y orificios pasantes avellanados M3)
├── Tapa_Inferior_Baterias     (Con guías de retención y tubos receptores roscados M3)
├── ESP32_S3_WROOM_1           (Agrupado mediante Rigid Group)
├── Portabaterias_4xAA         (61.95 mm × 57.75 mm)
└── Tornilleria_M3             (4 tornillos en postes integrados a las esquinas)

---
