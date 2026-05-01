# Visualizacion del conjunto de Julia utilizando Docker

En este proyecto se utiliza el ejemplo utilizado anteriormente que genera una representacion grafica del **Conjunto de Julia** que es un fractal matematico, mediante **C++23** para generar el set de datos y **Gnuplot** para generar la imagen .PNG final.

Esto mediante un entorno de desarrollo que esta dentro de un contenedor usando **Docker** para asi asegurar la compatibilidad entre sistemas y equipos.

Se utilizo Docker optimizado para Windows mediante **WSL 2** por lo que dichos codigos estan escritos para Linux.

## Requisitos previos:
- **Docker Desktop**: Necesario para poder crear los contenedores, es necesario buscar la compatibilidad de la arquitectura de la PC a usar y asegurarse que si se trata de un equipo con sistema operativo Windows, activar el motor de Windows Subsystem for Linux 2 (WSL 2) 

## Estructura del Proyecto 📁

- `src/` : Contiene el codigo fuente (`main.cpp`), el cual genera los calculos matematicos para el fractal que se plasman en un archivo con extension `.txt`.
- `scripts/`: Scripts de Gnuplot
- `output/`: Carpeta donde se guardaran todos los resultados obtenidos (.txt y .png).
`Makefile`: Archivo de automatizacion de la compilacion, ejecucion y ploteo dentro del Docker.
`Dockerfile`: En este archivo se definen las caracteristicas del contenedor, como la imagen de Ubuntu y todas las dependencias necesarias para que nuestro proyecto funcione

## Instrucciones de uso

1. `Construir la imagen del contenedor`:
Para iniciar, tenemos que construir el ambiente de trabajo mediante el siguiente comando, el cual debera de ser ejecutado en la misma carpeta donde se encuentra el archivo `Dockerfile`:
```bash
docker build -t ambiente julia .
```
2. `Ejecutar el Proyecto del contenedor`:
Para realizar el proceso de compilacion y ejecucion de codigo mediante el Makefile escribimos el siguiente comando:

```bash
docker run -ti --rm -v "${PWD}:/usr/src/app" ambiente_julia
```
![Ejecucion en la terminal](/img/Julia%20ejecucion.png)

3. Una vez realizado esto se generaran las carpetas correspondientes con los binarios, outputs y objetos necesarios para el procedimiento:

![Imagen del directorio](/img/Carpetas.png)

En el directorio `output/` se encontraran los archivos de salida donde uno de ellos sera la imagen final:

![Imagen Final](/img/julia_set.png)
