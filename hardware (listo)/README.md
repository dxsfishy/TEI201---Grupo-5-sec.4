### Hardware - Documentación ###

## Contenido
Esta carpeta contiene toda la documentación técnica del hardware del proyecto.

### 📁 Carpetas

#### `esquemas/`
Diagramas de circuitos y esquemáticos del sistema

#### `bom/`
Bill of Materials (Lista de materiales)

#### `fotos/`
Fotografías de alta resolución del prototipo ensamblado

---

## Instrucciones de Ensamble

### Componentes Principales
Estas instrucciones describen el procedimiento recomendado para reproducir y verificar el montaje, sujeto a completar el pinout de la sección 3. No se afirma que cada paso haya sido ensayado y validado en el montaje actual.
## Materiales y herramientas
- Placa ESP32-S3.
- Sensor capacitivo de humedad de suelo v1.2.
- Sensor de luz Ky018 utilizado por el equipo.
- Cables y conectores compatibles.
- Cable USB y fuente de alimentación compatibles con la placa.
- Computador con el firmware del proyecto.
- Superficie seca, aislante y estable.
- Multímetro para comprobar voltajes y continuidad (recomendado).
## Procedimiento paso a paso
1. Preparación. Organizar los componentes y verificar su integridad. Mantener el ESP32-S3 desconectado de la alimentación.

2. Identificación de terminales. Revisar las etiquetas y la documentación de cada módulo para ubicar VCC, GND, salidas del sensor de humedad y terminales del sensor de luz.

3. Compatibilidad eléctrica. Confirmar que las tensiones de alimentación y de señal sean compatibles con el ESP32-S3. No asumir que un pin acepta 5 V.

4. Sensor de humedad. Unir la tierra del sensor a GND de la placa; conectar VCC a una alimentación compatible y la salida del sensor a un GPIO ADC previamente identificado.

5. Sensor de luz. Conectar alimentación, tierra y señal(es) según su modelo exacto y los pines configurados en el firmware. 

6. Inspección del circuito. Revisar conectores, continuidad, posibles contactos accidentales, cables dañados y polaridad antes de energizar.

7. Alimentación y programación. Conectar el cable USB compatible únicamente después de aprobar la inspección. Cargar el firmware del equipo en la placa.

8. Verificación de lecturas. Comprobar en el monitor serial o interfaz disponible las lecturas del sensor de humedad y del sensor de luz. Registrar las condiciones de cada prueba.

9. Organización del montaje. Evitar cables tirantes o sueltos y mantener la electrónica sobre una superficie seca y aislante.

### Precauciones ⚠️
| Riesgo | Precaución |
|---|---|
| Cortocircuitos | Realizar modificaciones solo con la placa desconectada. Revisar aislamiento y terminales. |
| Alimentación incorrecta | Comprobar las tensiones admitidas; **no aplicar 5 V a los GPIO ni al pin de 3,3 V del ESP32-S3**. |
| Contacto con humedad | Mantener secas la placa y las conexiones; insertar en la tierra únicamente la zona apta de la sonda. |
| Desconexión accidental | Ordenar cables y evitar tensión mecánica sobre conectores. |
---

## Especificaciones Técnicas

**Alimentación:** [Voltaje y corriente]  
**Consumo:** [Watts/mA]  
**Dimensiones:** [mm x mm x mm]  
**Peso:** [gramos]

---

## Troubleshooting

## Troubleshooting

| Problema | Posible Causa | Solución |
|----------|---------------|----------|
| Lecturas de humedad inestables | Ruido eléctrico en las señales analógicas del sensor. | Aplicar el filtro de promedio de 10 muestras y revisar las conexiones. |
| Riesgo de cortocircuito | Exposición de la placa y conexiones a la humedad durante el riego. | Mantener la electrónica alejada del agua y proteger las conexiones. |
| El sensor de humedad no entrega datos | Cableado incorrecto, alimentación insuficiente o conexión defectuosa. | Verificar VCC, GND y el pin de señal configurado en el ESP32. |
| El sensor de luz no detecta cambios | Conexión incorrecta del KY-018 o configuración errónea del pin. | Revisar alimentación, conexión de señal y lectura analógica. |
| El dispositivo no envía alertas | Conexión Wi-Fi inestable o configuración incorrecta de Telegram. | Verificar conexión de red, credenciales y configuración del bot. |
| Las alertas no se repiten | El programa envía notificaciones únicamente cuando cambia el estado de humedad. | Comprobar si se produjo un cambio de categoría antes de considerar que existe una falla. |
| El ESP32 se reinicia inesperadamente | Alimentación inestable o posible problema de cableado. | Verificar la fuente de alimentación y revisar las conexiones con el equipo desconectado. |

## Archivos incluidos

## Estructura de archivos

```text
hardware/
├── README.md
├── bom/
├── diagramas/
│   └── esquematico_final.png     # Pendiente
└── evidencias/
    ├── montaje_actual.png
    ├── vista_lateral.jpg         # Pendiente
    ├── conexiones.jpg           # Pendiente
    └── reparabilidad.jpg        # Pendiente
```
