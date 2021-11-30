FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt update && apt upgrade -y && \
    apt install -y git \
    gpg gnupg gpg-agent \
    build-essential cmake