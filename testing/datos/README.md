# Datos de Testing

## Archivos de Datos

### `datos_cuantitativos.xlsx`
Hoja de cálculo con todos los datos recolectados durante testing

**Estructura sugerida:**

#### Sheet 1: Datos de Usuarios

| ID Usuario | Edad  | Perfil | Experiencia | 
|------------|------|-------------------|--------|
| U01 | 27  | Cultiva plantas en departamento | Básica | 
| U02 | 34 | Aficionado a la jardinería | Intermedia | 
| U03 | 42 | Mantiene un pequeño huerto doméstico | Avanzada |
| U04 | 30  | Cuida plantas ocasionalmente | Baja | 
| U05 | 39 | Interesado en tecnología y automatización | Alta | 

#### Sheet 2: Métricas de Usabilidad
| ID Usuario | Facilidad Uso (1-5) | Satisfacción (1-5) | Tiempo Tarea (seg) | Errores |
|------------|---------------------|--------------------|--------------------|---------|
| U01 | 4 | 5 | 45 | 0 |

#### Sheet 3: Métricas de Impacto ODS
| ID Usuario | Métrica 1 | Métrica 2 | Métrica 3 | Observaciones |
|------------|-----------|-----------|-----------|---------------|
| U01 | [valor] | [valor] | [valor] | [texto] |

#### Sheet 4: Feedback Cualitativo
| ID Usuario | ¿Qué te gustó? | ¿Qué mejorarías? | Otros comentarios |
|------------|----------------|------------------|-------------------|
| U01 | [texto] | [texto] | [texto] |

---

### `datos_sensores_testing.csv`
Datos capturados por el prototipo durante sesiones de testing

**Formato:**
```csv
timestamp, sensor_1, sensor_2, actuador_1, evento
2024-11-20 10:15:23, 23.5, 65, ON, usuario_inicio
2024-11-20 10:15:24, 23.6, 65, ON, normal
```

---

### `comparativa_versiones.xlsx`
Comparación de métricas entre iteraciones v1, v2, v3

| Métrica | v1 | v2 | v3 | Mejora (%) |
|---------|-----|-----|-----|------------|
| Facilidad de uso | 3.2 | 3.8 | 4.5 | +40.6% |
| Satisfacción | 3.5 | 4.0 | 4.6 | +31.4% |
| Errores promedio | 2.3 | 1.2 | 0.4 | -82.6% |

---

## Análisis Estadístico

### Estadísticos Básicos
Para cada métrica calcular:
- Media (promedio)
- Mediana
- Desviación estándar
- Mínimo y máximo
- Percentiles (25%, 50%, 75%)

### Ejemplo de Tabla de Resumen
```
Métrica: Facilidad de Uso (1-5)
N = 5 usuarios
Media: 4.2
Mediana: 4.0
Desv. Est.: 0.8
Mín: 3, Máx: 5
```

---

## Datos de Impacto ODS

### Baseline vs. Resultado

**Antes de la intervención (baseline):**
- [Indicador 1]: [Valor inicial]
- [Indicador 2]: [Valor inicial]

**Después de la intervención:**
- [Indicador 1]: [Valor medido con prototipo]
- [Indicador 2]: [Valor medido con prototipo]

**Mejora:**
- [Indicador 1]: [% de mejora]
- [Indicador 2]: [% de mejora]

---

## Visualización de Datos

Incluir gráficos generados (exportar desde Excel como PNG):

- `grafico_usabilidad.png`
- `grafico_satisfaccion.png`
- `grafico_impacto_ods.png`
- `grafico_comparativa_versiones.png`

**Herramientas recomendadas:**
- Excel / Google Sheets
- Python (matplotlib, seaborn)
- R / RStudio
