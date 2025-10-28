#!/bin/bash
set -e

KERNEL_VERSION=6.12.30
CURL="https://mirrors.edge.kernel.org/pub/linux/kernel/v6.x/linux-$KERNEL_VERSION.tar.xz"
KFILE="linux-$KERNEL_VERSION.tar.xz"
KDIR="linux-$KERNEL_VERSION"
TARGETDIR="linux-kernel"

echo "-- Preparing linux-kernel directory ..."
mkdir -p "$KDIR"

echo "-- Downloading Linux kernel $KERNEL_VERSION ..."
wget -c --show-progress "$CURL"

echo "-- Extracting $KFILE"
tar -xf "$KFILE"

echo "-- Syncing files from $KDIR/ into $TARGETDIR/ "
rsync -av --delete-after "$KDIR"/ "$TARGETDIR"/

echo "-- Cleanup $KFILE and $KDIR"
rm -f "$KFILE"
rm -rf "$KDIR"

echo "Linux $KERNEL_VERSION synced into $TARGETDIR/"
