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
- Sensor de luz utilizado por el equipo.
- Cables y conectores compatibles.
- Cable USB y fuente de alimentación compatibles con la placa.
- Computador con el firmware del proyecto.
- Superficie seca, aislante y estable.
- Multímetro para comprobar voltajes y continuidad (recomendado).
## Procedimiento paso a paso
Paso 1 — Preparación. Organizar los componentes y verificar su integridad. Mantener el ESP32-S3 desconectado de la alimentación.

Paso 2 — Identificación de terminales. Revisar las etiquetas y la documentación de cada módulo para ubicar VCC, GND, salidas del sensor de humedad y terminales del sensor de luz.

Paso 3 — Compatibilidad eléctrica. Confirmar que las tensiones de alimentación y de señal sean compatibles con el ESP32-S3. No asumir que un pin acepta 5 V.

Paso 4 — Sensor de humedad. Unir la tierra del sensor a GND de la placa; conectar VCC a una alimentación compatible y la salida del sensor a un GPIO ADC previamente identificado.

Paso 5 — Sensor de luz. Conectar alimentación, tierra y señal(es) según su modelo exacto y los pines configurados en el firmware. Si es un sensor I²C, documentar SDA/SCL; si es analógico, documentar la salida y el ADC utilizado. No escoger conexiones al azar.

Paso 6 — Inspección del circuito. Revisar conectores, continuidad, posibles contactos accidentales, cables dañados y polaridad antes de energizar.

Paso 7 — Alimentación y programación. Conectar el cable USB compatible únicamente después de aprobar la inspección. Cargar el firmware del equipo en la placa.

Paso 8 — Verificación de lecturas. Comprobar en el monitor serial o interfaz disponible las lecturas del sensor de humedad y del sensor de luz. Registrar las condiciones de cada prueba.

Paso 9 — Organización del montaje. Evitar cables tirantes o sueltos y mantener la electrónica sobre una superficie seca y aislante.

Paso 10 — Documentación. Fotografiar el circuito desde al menos tres ángulos, actualizar el esquemático y completar la tabla de conexiones con los GPIO realmente utilizados.

### Precauciones
- ⚠️ [Precaución 1]
- ⚠️ [Precaución 2]

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
