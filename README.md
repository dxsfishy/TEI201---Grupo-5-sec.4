***Entregable Taller de diseño grupo 5***
-----------------------------------

### Equipo
 
| Integrantes     | Rol | **GitHub** |
| ------------ | -------- | ------- |
| Roberto Carabantes  | Hardware       | dxsfishy  |
| Martín León     | Iteraciones y pruebas        | martinch0-1  |
| Mariano Lara  | Diseño 3D       | SrCraneo  |
| Pedro Monserrat |  Software | pedrinho-qw
|Benjamín Nicuñir | Diseño 3D | baaingr
      
--- 
 
- **ODS Seleccionado**: 12 - Producción y Consumo Responsables
- **Problema a resolver**: Pérdida de semillas orgánicas, cultivos caseros y el desperdicio de agua 

### Descripción del Proyecto
Se propone un sistema de diagnóstico de suelo alimentado por energía solar y
equipado con un microcontrolador (ESP32) que integra sensores de temperatura, 
humedad y pH insertados directamente en el huerto. Indicará al usuario si el suelo
está apto para el cultivo o no.

### Estado del Proyecto
- Versión actual :v1.0
- Última actualización: 25/10/2026
- Estado: Prototipo básico (Incluye el sensor de humedad y envío de mensajes a Telegram)

---
## Arquitectura del prototipo 
Sensor de humedad M-SENS-V1.2 -> Procesamiento ESP32 -> Actuador -> Sincronización NTP -> Conectividad Wifi -> Mensaje al Telegram del usuario

## Tecnologías utilizadas
1. ESP32
2. Sensor de humedad  de sueo capacitivo voltio 1.2
3. Sensor de temperatura de suelo
4. Sensor de pH

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

## Estructura del repositorio (ideal)
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
