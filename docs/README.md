# 1. Introducción
Hablar sobre la importancia de la metrología en mecatrónica, y cómo el proyecto busca mostrarla mediante el uso de sensores y visualizaciones automáticas que ayudan a tomar decisiones técnicas.

# 2. Importancia de la metrología en mecatrónica
Desarrollar por qué la metrología es clave en sistemas modernos. Mencionar cómo se integra en la automatización, el control de calidad, y por qué no se puede ignorar si se busca precisión y confiabilidad.

# 3. Fundamentos del proyecto
Explicar por qué se hace el proyecto, cuál fue la necesidad que se detectó y cómo este trabajo intenta reflejar procesos invisibles que hacen los sistemas reales industriales.

# 4. Descripción del proyecto
Resumen técnico general: sistema de adquisición con Arduino Mega, puente de comunicación hacia Node-RED en el celular, procesamiento y visualización de datos.

# 5. Objetivos del proyecto
Listar y explicar brevemente objetivos técnicos y metrológicos: adquisición, análisis, visualización, decisión automática, y trazabilidad.

# 6. Propósito del proyecto
Mostrar cómo un sistema automatizado puede usar la metrología para tomar decisiones inteligentes y confiables antes de ejecutar acciones.

# 7. Funcionalidad del proyecto
Evaluar si este tipo de sistema puede implementarse en la industria. Analizar si es realista su aplicación.

# 8. Aspectos técnicos

## 8.1. Parte electrónica
- Describir sensores utilizados (tipo, cómo miden, incertidumbre).
- Describir el Arduino Mega (qué es y por qué se eligió).

## 8.2. Parte software
- Explicar protocolos usados: I2C, UART, puente Serial-TCP.
- Explicar qué es un servidor TCP, qué es una webcam IP, y qué rol cumplen.
- Dar una buena explicación de Node-RED (flujo, nodos, funciones).
- Breve explicación sobre Termux.

## 8.3. ¿Cómo funciona?
Usar la documentación del repositorio y parafrasearla. Deben explicar paso a paso cómo fluye el dato desde el sensor hasta la visualización.

# 9. Uso de la metrología
Explicar cómo la metrología guía todo: desde la medición hasta la decisión. Incluir conceptos como incertidumbre, repetibilidad, outliers, trazabilidad y visualización de márgenes de error.

# 10. Aplicaciones industriales
Describir en qué áreas reales se puede aplicar este modelo: producción, SCADA, monitoreo ambiental, mantenimiento predictivo, etc.

# 11. Indicadores estadísticos usados
Breves descripciones de cada indicador clave usado en el análisis de datos, para qué se usan, qué significan los valores de estos, fórmulas de los que tengan:

- Incertidumbre de sensor
- Gráfico de tiempo, abajo de este se muestra:
  - el dato actual
  - el dato con +incertidumbre
  - el dato con –incertidumbre
- Distribución de Mediciones (Campana de Gauss)
  - Campana real, con los datos de entrada
  - Gauss teórica, usando la incertidumbre del sensor
- Desviación estándar
- Error absoluto medio
- Incertidumbre estándar de la media
- Incertidumbre relativa de la media (porcentual)
- Gráfico de Frecuencia por rangos
  - Se muestra abajo de la gráfica el valor mínimo y valor máximo
- Mediana
- Moda (pero de rango)
- MAD (mean absolute deviation o en español, desviación media absoluta)
- Outlier ±2σ, ±3σ
- Gráfica de Tendencia lineal:
  - línea de tendencia principal
  - línea de tendencia +incertidumbre
  - línea de tendencia –incertidumbre
  - abajo del gráfico: ecuación de la línea de tendencia principal
- Gráfico de caja:
  - abajo del gráfico: Q1, Q2, Q3, mínimo y máximo

# 12. Conclusiones
Responder:
- ¿Se logró lo que se buscaba?
- ¿Qué tan aplicable es el sistema?
- ¿Qué aprendimos sobre metrología aplicada en sistemas automatizados?
