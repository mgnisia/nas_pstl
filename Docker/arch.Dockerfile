# Dockerfile for Arc Setup
FROM archlinux:latest

RUN pacman -Sy && \
    pacman -S --noconfirm gcc make intel-tbb libffi

ENTRYPOINT ["/bin/sh"]