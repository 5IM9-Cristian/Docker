# 1. Imagen base estable
FROM ubuntu:22.04

# 2. Configuración de entorno no interactivo
ENV DEBIAN_FRONTEND=noninteractive

# 3. Dependencias gráficas y de compilación
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    gnuplot \
    xdg-utils \
    libx11-dev \
    && rm -rf /var/lib/apt/lists/*

# 4. Directorio de trabajo genérico
WORKDIR /usr/src/app

# 5. Copiamos el contenido del proyecto
COPY . .

# 6. Variable para el comando por defecto (Ej: 'all', 'run', etc.)
ARG MAKE_TARGET=all
ENV TARGET=$MAKE_TARGET

# 7. Variable de entorno para X11
ENV XDG_RUNTIME_DIR=/tmp

# 8. Ejecutamos el Makefile con el target deseado
CMD make ${TARGET}