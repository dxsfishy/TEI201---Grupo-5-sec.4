# Esquemas de Circuito

## Archivos Incluidos
- Circuito Wokwi con su respectivo diagrama
- [`wokwi_link.txt`](https://wokwi.com/projects/481438650871320577) - URL del proyecto online de wokwi

Los potenciómetros representan las señales analógicas del sensor capacitivo de humedad v1.2 y del sensor de luminosidad KY-018. Esta simulación permite visualizar las conexiones, pero no reproduce el comportamiento físico exacto de ambos sensores.

---

## Notas de Diseño
* Se emplearon dos entradas analógicas independientes para monitorear humedad y luminosidad.
* Se definió una alimentación común de 3.3V y conexiones GND para los módulos.
* Se priorizó la simplicidad del circuito y la facilidad de reproducción.
* La simulación representa las conexiones eléctricas, mientras que el funcionamiento del sistema depende del firmware desarrollado.
* El modelo y las conexiones deben verificarse con la placa física utilizada antes de energizar el montaje.

---
#Software Utilizado
* Wokwi (simulación y validación del circuito).
* Arduino IDE 2.x (desarrollo y carga del firmware).
