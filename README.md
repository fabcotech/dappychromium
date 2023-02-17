## Fetch

> Fetch Chromium's code.

```console
$ ./scripts/gclient.sh sync
```

## Configure

```console
$ ./scripts/gn.sh args out/Default
```

> `Default` is the target name, you can use multiple ones and pick any name you'd like, i.e.:
>
> ```console
> $ ./scripts/gn.sh args out/release
> $ ./scripts/gn.sh args out/debug
> # or if you'd like to build a multi-platform image
> $ ./scripts/gn.sh args out/arm64
> $ ./scripts/gn.sh args out/amd64
> ```

When prompted, enter the following arguments:

```gn
# import("//chromium_fork/src/browser/args.gn")

# uncomment this to build for arm64
# target_cpu = "arm64"

# comment this to disable ccache
# cc_wrapper = "env CCACHE_SLOPPINESS=time_macros ccache"

# comment this for a debug build
# is_debug = false
# symbol_level = 0
# is_official_build = true
```

## Build binaries

```console
$ ./scripts/build.sh Default
```