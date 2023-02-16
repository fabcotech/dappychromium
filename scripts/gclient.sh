#!/usr/bin/env bash

export FORK_ROOT=$(cd $(dirname -- "$0") && dirname -- "$(pwd)")
export INSTALL_DEPOT_TOOLS="true"

source "$FORK_ROOT/scripts/env.sh"

(
    cd "$CHROMIUM_ROOT" &&
    gclient "$@"
)
