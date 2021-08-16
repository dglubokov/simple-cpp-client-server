FROM alpine:latest

RUN apk add make g++ openssl-dev git cmake

COPY . /client
WORKDIR /client
RUN git clone https://github.com/yhirose/cpp-httplib

RUN mkdir ./build
RUN cd ./build && cmake ..
RUN cd ./build && make
RUN g++ client.cpp -o client.out -L /usr/lib -l ssl -l crypto
RUN chmod a+x client.out
