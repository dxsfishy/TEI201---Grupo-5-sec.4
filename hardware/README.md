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

| Problema | Posible Causa | Solución |
|----------|---------------|----------|
| [Problema 1] | [Causa] | [Solución] |
| [Problema 2] | [Causa] | [Solución] |

## Archivos incluidos
hardware/
│
├── esquemas/
│   ├── esquema_electrico.pdf
│   ├── conexiones.png
│   └── README.md
│
├── bom/
│   ├── BOM.xlsx
│   ├── BOM.pdf
│   └── README.md
│
├── fotos/
│   ├── prototipo_frontal.jpg
│   ├── prototipo_lateral.jpg
│   ├── interior.jpg
│   └── README.md
│
└── README.md
