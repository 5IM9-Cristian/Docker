# Algoritmo de ordenamiento de Burbuja usando Docker
En este proyecto se implementa el algoritmo de **Ordenamiento de Burbuja** en lenguaje C. El programa esta diseñado para ser ejecutado dentro de un contenedor Docker, asegurando un entorno de compilacion limpio y repetible mediante el uso de un Makefile

## Descripcion de las tareas del programa
1. **Lectura**: El programa carga una cantidad definida de numeros enteros desde un archivo de entrada `data/Numeros.txt`

2. **Procesamiento**: El algoritmo ordena el conjunto de datos leidos utilizando el algoritmo de burbuja.

3. **Escritura**: El programa guarda los datos ordenados en un archivo de salida `output/ordenados.txt`

## Requisitos 

- Es necesario tener Docker configurado (si se instala en un entorno Windows es importante activar WSL 2)

## Instrucciones de Uso

1. **_Construccion de la imagen_**: Para poder construir la imagen de Docker hay que ubicarse en el directorio donde se encuentra el Dockerfile, y desde la terminal ejecutar el siguiente:

```bash
docker build -t docker_burbuja .
```

![Imagen de creacion de la imagen de Docker](/img/Creacion%20del%20contenedor.png)

![Imagen de finalizacion de creacion del Docker](/img/Docker%20creado%20correctamente.png)

2. **_Ejecutar el Contenedor_**: Para ejecutar el makefile y que asi compile el codigo, procese los numeros y genere el archivo de salida con los datos ordenados es necesario ejecutar el siguiente comando:

```bash
docker run -ti --rm -v "${PWD}:/usr/src/app" docker_burbuja
```

![Imagen de ejecucion del Docker](/img/DockerBurbuja%20FInalizado.png)

3. **_Datos ordenados_**: Una vez que el codigo haya sido ejecutado obtendremos el dataset organizado. 

Datos originales:
![Imagen de los datos desordenados](/img/Numeros%20orginales.png)

Datos ordenados:
![Imagen de los datos ordenados](/img/Numeros%20ordenados.png)