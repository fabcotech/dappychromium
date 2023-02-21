#!/usr/bin/env bash

export FORK_ROOT=$(cd $(dirname -- "$0") && dirname -- "$(pwd)")

source "$FORK_ROOT/scripts/env.sh"

cd "$CHROMIUM_SRC"

chromium_upstream="4e2ca2e180bcca4e20aa1def4668065c9ad4ebce"

if [[ "$1" == "apply" ]]; then
    echo "Stashing Chromium changes.."
    git add -A .
    git stash

    echo "Applying Chromium patches.."
    git checkout "$chromium_upstream"
    git am --committer-date-is-author-date "$FORK_ROOT/chromium/patches/chromium"/*
    "$FORK_ROOT/scripts/restore-mtime.sh" "$chromium_upstream"

    echo "Patches successfully applied"
elif [[ "$1" == "save" ]]; then
    echo "Updating Chromium patches.."
    rm -rf "$FORK_ROOT/chromium/patches/chromium"
    git format-patch --no-signature --output-directory "$FORK_ROOT/chromium/patches/chromium" "$chromium_upstream"

    echo "Patches successfully updated"
else
    echo "Unknown argument: $1"

    exit 2
fi
