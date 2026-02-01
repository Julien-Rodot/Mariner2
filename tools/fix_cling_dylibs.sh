#!/bin/sh
set -e
FRAMEWORKS="$1"
CLING_DIR="$2"
CLING_LIB_DIR="$3"
CLING_LIBEXEC_DIR="$4"
MARN_PATH="$5"

# ensure destination exists (this uses the build-time provided FRAMEWORKS arg)
mkdir -p "$FRAMEWORKS"

# copy libMariner.dylib (source provided as MARN_PATH)
if [ -f "$MARN_PATH" ]; then
  cp -f "$MARN_PATH" "$FRAMEWORKS/"
fi

# copy dylibs from CLING_LIB_DIR and CLING_LIBEXEC_DIR (if present)
for d in "$CLING_LIB_DIR" "$CLING_LIBEXEC_DIR"; do
  if [ -d "$d" ]; then
    for lib in "$d"/*.dylib; do
      [ -f "$lib" ] || continue
      cp -f "$lib" "$FRAMEWORKS/"
    done
  fi
done

# set id and rewrite internal deps for each copied dylib
for f in "$FRAMEWORKS"/*.dylib; do
  [ -f "$f" ] || continue
  name=$(basename "$f")
  /usr/bin/install_name_tool -id "@rpath/${name}" "$f" || true
  otool -L "$f" | sed -n '2,$p' | cut -d ' ' -f1 | while read -r dep; do
    case "$dep" in
      "$CLING_LIB_DIR"/*|"$CLING_DIR"/*|"$CLING_LIBEXEC_DIR"/* )
        dn=$(basename "$dep")
        /usr/bin/install_name_tool -change "$dep" "@rpath/${dn}" "$f" || true
      ;;
    esac
  done
done

# Fix libMariner.dylib internal refs (if present in FRAMEWORKS)
MARN="$FRAMEWORKS/$(basename "$MARN_PATH")"
if [ -f "$MARN" ]; then
  otool -L "$MARN" | sed -n '2,$p' | cut -d ' ' -f1 | while read -r dep; do
    case "$dep" in
      "$CLING_LIB_DIR"/*|"$CLING_DIR"/*|"$CLING_LIBEXEC_DIR"/* )
        dn=$(basename "$dep")
        /usr/bin/install_name_tool -change "$dep" "@rpath/${dn}" "$MARN" || true
      ;;
    esac
  done
fi
