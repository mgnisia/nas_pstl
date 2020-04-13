#!/usr/bin/env bash

# Decision which image to build
read -p "Which image would you like to build? type: arch or ubuntu: " sys

# Test if sys variable is empty
[ -z "$sys" ] && echo "provided string is empty" && exit 1

# Build Container
[ "$sys" = "ubuntu" ] && /usr/bin/docker build -f ubuntu.Dockerfile -t nas_docker:ubuntu . && exit 0
[ "$sys" = "arch" ] && /usr/bin/docker build -f arch.Dockerfile -t nas_docker:arch . && exit 0

echo "The provided image doesn't match with arch or ubuntu" && exit 1


