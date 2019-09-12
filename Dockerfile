############################################################
# Dockerfile to build LLVM environment to build llvm pass
# based on Ubuntu 18.04
# Usage:
# 
#   $ docker build -t hrocha/llvm6tuto --no-cache -f Dockerfile .
#   $ docker run -it --name=llvm6tuto -v $(pwd):/home/tryllvm/dev/clone:Z --user $(id -u):$(id -g) hrocha/llvm6tuto /bin/bash
#
# The docker user is "tryllvm" and the password is "tryllvm"
# Docker tips:
#  You can check that the container still exists by running: $ docker ps -a
#  You can restart the container by running: docker start -ai llvm6tuto
############################################################
FROM ubuntu:18.04

# Metadata indicating an image maintainer.
MAINTAINER <herberthb12@gmail.com>

# Update the repository sources list
RUN apt-get update

# Devel packages
RUN apt-get install -y sudo \	
    build-essential \    
    python-minimal \
    cmake \
    llvm-6.0-dev \
    clang-6.0 \
    nano \
    graphviz 
    
# Clean packages installation
RUN apt-get clean

RUN useradd -m tryllvm && \
    echo tryllvm:tryllvm | chpasswd && \
    cp /etc/sudoers /etc/sudoers.bak && \
    echo 'tryllvm ALL=(root) NOPASSWD: ALL' >> /etc/sudoers

USER tryllvm
RUN mkdir /home/tryllvm/dev
WORKDIR /home/tryllvm/dev/

RUN cd /home/tryllvm/dev/

RUN sudo chown -R tryllvm:tryllvm .

VOLUME /home/tryllvm/dev/
# Revoke password-less sudo and Set up sudo access for the ``tryllvm`` user so it
# requires a password
USER root
RUN mv /etc/sudoers.bak /etc/sudoers && \
    echo 'tryllvm  ALL=(root) ALL' >> /etc/sudoers

USER tryllvm

##################### INSTALLATION END #####################
