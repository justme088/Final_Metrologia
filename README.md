# Proyecto Final de Metrología
## Modelo de Adquisición, Visualización y Análisis de Datos de Sensores (en tiempo real)

Este proyecto es un **modelo funcional e interactivo** que representa cómo se integran sensores reales, adquisición de datos, análisis y visualización dentro de un entorno técnico con orientación industrial.

No busca ser una solución industrial completa, sino una **maqueta demostrativa** que expone el rol fundamental de la **metrología** dentro de procesos automatizados. Se busca ilustrar cómo se gestionan los datos provenientes de sensores físicos y cómo estos datos permiten tomar decisiones informadas en un contexto de ingeniería.

## 🎯 Objetivo General
Desarrollar un sistema portátil de monitoreo y visualización en tiempo real de variables físicas captadas por sensores, utilizando un Arduino Mega conectado mediante puente Serial-TCP a un servidor Node-RED alojado en un dispositivo móvil, con el fin de simular una interfaz Hombre-Máquina (HMI) funcional que permita analizar, almacenar y exportar los datos, integrando principios metrológicos aplicables al entorno industrial para demostrar la importancia de la trazabilidad y la calibración en la Ingeniería Mecatrónica.

## 🛠️ Descripción técnica

### 📡 Adquisición de datos reales

- Un **Arduino Mega** está conectado a **tres sensores físicos**.
#### [GY-906 (temperatura)](https://naylampmechatronics.com/sensores-temperatura-y-humedad/330-sensor-de-temperatura-infrarrojo-mlx90614-gy-906.html)
![gy-906](https://github.com/user-attachments/assets/d78cdfa1-f6b3-49aa-a4ba-8a93025aa33f)
#### [HC-S04 (distancia)](https://naylampmechatronics.com/sensores-proximidad/10-sensor-ultrasonido-hc-sr04.html)
![hc-sr04](https://github.com/user-attachments/assets/75ad946d-f61c-4a7f-a283-80e545f00ce3)
#### [Sparkfun SHTC3 (humedad)](https://www.sparkfun.com/sparkfun-humidity-sensor-breakout-shtc3-qwiic.html)
![SHTC3](https://github.com/user-attachments/assets/9d52ccef-720e-41f9-8f4c-e4c2e126189d)

- Estos datos son enviados por **puerto serial** (usando un cable USB A de entrada - USB C de salida) del dispositivo móvil a través de un **puente Serial–TCP**, usando la aplicación [Communication Bridge Pro](https://play.google.com/store/apps/details?id=masar.bluetoothbridge.pro&hl=en_US) de Android, que une el puerto serial a un servidor TCP (puerto 5050) creada por la misma aplicación.
- El **servidor**, alojado en un **dispositivo móvil Android con [Node-RED](https://nodered.org/about/) en [Termux](https://play.google.com/store/apps/details?id=com.termux&hl=en_US)**, recibe los datos mediante una **conexión TCP directa** como cliente en el puerto 5050.

#### Específicaciones
**Termux**:
- python3 instalado y con librería de setuptools
- Añadir el repositorio tur -> pkg install -y tur-repo -> pkg install -y nodejs-18 | Este será instalado en /data/data/com.termux/files/usr/opt/nodejs-18, añade "/data/data/com.termux/files/usr/opt/nodejs-18/bin" a $PATH.

**Node-RED**:
- Versión usada de NodeJS: v18.20.8
- Tener instalado sqlite3 en Node-RED y añadirlo en contexto global dentro de settings.js
- Instalar en Palette: node-red-contrib-ui-led, node-red-contrib-zip, node-red-dashboard

**Librerías usadas en el Arduino Mega**:
- [https://github.com/sparkfun/SparkFun_SHTC3_Arduino_Library](https://github.com/sparkfun/SparkFun_SHTC3_Arduino_Library)
- [https://github.com/adafruit/Adafruit-MLX90614-Library](https://github.com/adafruit/Adafruit-MLX90614-Library)
- Wire

### 🔄 Procesamiento de datos

- Los datos son **interpretados, convertidos y transformados en tiempo real** dentro de Node-RED.
- Se realiza **análisis numérico**, como **cálculo de tendencias (regresión lineal)**, para observar el comportamiento de las variables medidas.

### 🖥️ Visualización e interfaz

- Se implementa una **pseudo-HMI (Interfaz Hombre-Máquina)** usando el **dashboard de Node-RED**.
- El usuario puede:
  - Visualizar **gráficas de evolución**.
  - Activar la **descarga de la base de datos** en formato CSV dentro de un ZIP.
  - Ver **estadísticas en tiempo real**.
  - Además, se utiliza la **cámara del celular** a través de la aplicación [IP Webcam Pro](https://play.google.com/store/apps/details?id=com.pas.webcam.pro&hl=en_US) de Android en el puerto 8989, para visualizar en vivo la ubicación y el entorno de los sensores, permitiendo observar visualmente lo que ocurre en sincronía con los valores mostrados en pantalla.


### 📂 Trazabilidad y exportación

- Todos los datos se almacenan en una base de datos **SQLite**.
- Se generan archivos **`.csv`** con los datos históricos, que luego pueden **comprimirse en `.zip`** y descargarse desde la interfaz.
- Esta funcionalidad representa el **respaldo y trazabilidad metrológica** en entornos reales.

### 🔌 Circuito
![Untitled Sketch 2_esquemático](https://github.com/user-attachments/assets/4ab355de-d68a-4549-bd30-0ae9be508e32)

![circuit_img](https://github.com/user-attachments/assets/7b7951a6-7aa3-43e5-b433-ab63f850c76a)

### 🗺️ Capturas de los flujos en Node-RED
#### Flow 0
![Flow0](https://github.com/user-attachments/assets/cee61567-c689-4439-a505-7d2c9884013c)

#### Flow 1
![Flow1](https://github.com/user-attachments/assets/79ce6c02-9e35-4703-82ec-841880a0daad)

#### Flow 2
![Flow2](https://github.com/user-attachments/assets/c01105ab-2618-461e-a0bf-84b8d9eb4abd)

### Captura de la infertaz
#### Pestaña príncipal
![Sensor](https://github.com/user-attachments/assets/46a1ac6d-45a2-4e42-abe4-123e44ff7706)

#### Pestaña de la cámara
![Camara](https://github.com/user-attachments/assets/f76f7399-90d1-47fc-bcd6-ea09ab57a098)



