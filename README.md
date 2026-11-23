***Entregable Taller de diseño grupo 5***
-----------------------------------

### Equipo
 
| Integrantes     | Rol | **GitHub** |
| ------------ | -------- | ------- |
| Roberto Carabantes  | Hardware       | dxsfishy  |
| Martín León     | Iteraciones y pruebas        | martinch0-1  |
| Mariano Lara  | Diseño 3D       | SrCraneo  |
| Pedro Monserrat |  Software | pedrinho-wq
|Benjamín Nicuñir | Diseño 3D | baaingr
      
--- 
 
- **ODS Seleccionado**: 12 - Producción y Consumo Responsables
- **Problema a resolver**: Pérdida de semillas orgánicas, cultivos caseros y el desperdicio de agua 

### Descripción del Proyecto
El proyecto propone un dispositivo IoT para apoyar el cuidado de plantas y huertos domésticos mediante la lectura de humedad del suelo y luminosidad ambiental. El prototipo documentado combina un microcontrolador ESP32, un sensor capacitivo de humedad de suelo v1.2 y un sensor de luz KY-018. El programa descrito en el informe filtra lecturas analógicas, clasifica los estados de humedad y envía avisos mediante un bot de Telegram.

### Estado del Proyecto
- Versión actual :v3.0
- Última actualización: 22/11/2026
- Estado: Prototipo en documentación e integración final.

---
## Arquitectura del prototipo 
Sensor de humedad M-SENS-V1.2 -> Procesamiento ESP32 -> Actuador -> Sincronización NTP -> Conectividad Wifi -> Mensaje al Telegram del usuario

## Tecnologías utilizadas
1. Microcontrolador: ESP32-S3
2. Sensor de humedad: sonda capacitiva de suelo v1.2.
3. Sensor de luz: módulo KY-018.
4. Entorno de desarrollo documentado: Arduino IDE / framework Arduino para ESP32.
5. Comunicación: Wi-Fi y bot de Telegram, según el informe técnico.
6. Diseño mecánico: Autodesk Fusion.
---

##  Inicio Rápido

### Requisitos Previos
- Arduino IDE 2.x
- Fusion 360

### Instalación del firmware
1. Clonar el repositorio
2. Instalar librerías (ver `software/librerias/`)
3. Configurar credenciales de la red Wifi
4. Conectar la ESP32 mediante USB
5. Compilar y ejecutar programa

## Estructura del repositorio 
- diseno-3d/ — Modelos de Fusion 360, renders y planos técnicos.
- docs/ — Informes y documentación del proyecto.
- hardware/ — Esquemático, BOM y selección de componentes.
- iteraciones/ — Evidencia del desarrollo e iteraciones del diseño.
- software/ — Código fuente del ESP32, servidor web y dashboard.
- testing/ — Protocolos de prueba y evidencias experimentales.
- FUENTES.md — Bibliografía, datasheets y referencias utilizadas.

---

##  Licencia
Este proyecto es desarrollado como parte del curso TEI201 - Facultad de Ingenieria y Ciencias - Universidad Adolfo Ibañez
