FROM ubuntu:22.04

ENV DEBIAN_FRONTEND = noninteractive

RUN apt-get update && apt-get install -y \
build-essential \
gcc \
make \
&& rm -rf /var/lib/apt/lists/*

WORKDIR /usr/src/app

COPY . .

ARG MAKE_TARGET=all
ENV TARGET=$MAKE_TARGET

CMD make ${TARGET}