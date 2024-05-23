#!/usr/bin/env bash

set -x

_OS=$1
_ARCH=$2
_TARGET_DIR=$3


TMP_DIR=$(mktemp -d)

# Using benthos as placeholder
curl -L https://github.com/benthosdev/benthos/releases/download/v4.27.0/benthos_4.27.0_${_OS}_${_ARCH}.tar.gz -o ${TMP_DIR}/connect.tar.gz

tar zxvf "$TMP_DIR/connect.tar.gz" -C "$TMP_DIR"

cp "$TMP_DIR/benthos" "${_TARGET_DIR}"

exit 0

