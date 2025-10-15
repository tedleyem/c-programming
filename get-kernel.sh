#!/bin/bash
set -e

KERNEL_VERSION=6.12.30
CURL="https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-$KERNEL_VERSION.tar.xz"
KFILE="linux-$KERNEL_VERSION.tar.xz"
KDIR="linux-$KERNEL_VERSION"

echo "→ Downloading Linux kernel $KERNEL_VERSION ..."
wget -c --show-progress "$CURL"

if [ ! -d "$KDIR" ]; then
  echo "→ Extracting $KFILE ..."
  tar -xf "$KFILE"
else
  echo "→ $KDIR already exists, skipping extract."
fi

echo "→ Syncing files into $TARGETDIR ..."
mkdir -p "$TARGETDIR"
rsync -av --delete "$KDIR"/ "$TARGETDIR"/

echo "→ Cleaning up ..."
rm -f "$KFILE"
rm -rf "$KDIR"

echo "Linux $KVER synced into $TARGETDIR/"
