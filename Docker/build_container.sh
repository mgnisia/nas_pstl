#!/usr/bin/env bash
# Usage ./build_container.sh ubuntu or interactive ./build_container.sh

# Set input to sys
[ -z "$1" ]; sys=$1 

# Decision which image to build
[ -z "$sys" ] && read -p "Which image would you like to build? type: arch or ubuntu: " sys

# Build Container
[ "$sys" = "ubuntu" ] && /usr/bin/docker build -f Ubuntu.Dockerfile -t nas_docker:ubuntu . && exit 0
[ "$sys" = "arch" ] && /usr/bin/docker build -f Arch.Dockerfile -t nas_docker:arch . && exit 0

echo "The provided image doesn't match with arch or ubuntu" && exit 1


