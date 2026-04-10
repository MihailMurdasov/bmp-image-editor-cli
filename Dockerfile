FROM ubuntu:24.04 AS builder

RUN apt-get update && apt-get install -y --no-install-recommends \
    g++ \
    make \
    && rm -rf /var/lib/apt/lists/*

ENV LANG=C.UTF-8
ENV LC_ALL=C.UTF-8

WORKDIR /project
COPY . .

RUN make -C src


FROM ubuntu:24.04

LABEL org.opencontainers.image.source="https://github.com/MihailMurdasov/bmp-image-editor-cli"

RUN apt-get update && apt-get install -y --no-install-recommends \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

ENV LANG=C.UTF-8
ENV LC_ALL=C.UTF-8

WORKDIR /work
COPY --from=builder /project/src/cw /usr/local/bin/cw

ENTRYPOINT ["cw"]