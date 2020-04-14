# Dockerfile for Ubuntu Setup
FROM ubuntu:20.04

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -qq build-essential libtbb-dev

# Copy Content of Repository
COPY . .

ENTRYPOINT ["/bin/bash"]