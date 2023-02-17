#!/usr/bin/env bash

export FORK_ROOT=$(cd $(dirname -- "$0") && dirname -- "$(pwd)")
export INSTALL_DEPOT_TOOLS="true"

cd "$FORK_ROOT"
source scripts/env.sh

target="$1"
cpu="$2"

if [ ! -z "$target" ]; then
    shift
fi
if [ ! -z "$cpu" ]; then
    shift
fi

triple=$(scripts/platform-triple.sh "$cpu")

cd "$CHROMIUM_SRC"

autoninja -C out/$target chrome
