#!/usr/bin/env bash
set -euo pipefail

IMAGE="${IMAGE:-bmp-cli-editor}"

docker run --rm \
  --user "$(id -u):$(id -g)" \
  -v "$(pwd)":/work \
  "$IMAGE" \
  "$@"