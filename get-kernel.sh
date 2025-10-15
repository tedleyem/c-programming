#!/bin/bash
set -e

KERNEL_VERSION=6.12.30
CURL="https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-$KERNEL_VERSION.tar.xz"
KFILE="linux-$KERNEL_VERSION.tar.xz"
KDIR="linux-$KERNEL_VERSION"
TARGETDIR="linux-kernel"

echo "→ Downloading Linux kernel $KERNEL_VERSION ..."
wget -c --show-progress "$CURL"

echo "→ Preparing linux-kernel directory ..."
mkdir -p linux-kernel

echo "→ Extracting $KFILE ..."
tar -xf "$KFILE" #--strip-components=1 -C linux-kernel

echo "→ Syncing files into $TARGETDIR ..."
mkdir -p "$TARGETDIR"
rsync -av --delete-after "$KDIR"/ "$TARGETDIR"/

echo "→ Cleaning up ..."
rm -f "$KFILE"
rm -rf "$KDIR"

echo "Linux $KERNEL_VERSION synced into $TARGETDIR/"
