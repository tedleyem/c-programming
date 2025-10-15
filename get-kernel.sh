#!/bin/bash
set -e

KERNEL_VERSION=6.12.30
CURL="https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-$KERNEL_VERSION.tar.xz"
KFILE="linux-$KERNEL_VERSION.tar.xz"
KDIR="linux-$KERNEL_VERSION"
TARGETDIR="linux-kernel"

echo "→ Checking for existing $KFILE ..."
if [ -f "$KFILE" ]; then
    echo "→ $KFILE already exists, skipping download."
else
    echo "→ Downloading Linux kernel $KERNEL_VERSION ..."
    wget -c --show-progress "$CURL"
fi

echo "→ Preparing linux-kernel directory ..."
mkdir -p "$TARGETDIR"

echo "→ Extracting $KFILE ..."
tar -xf "$KFILE"

echo "→ Syncing files into $TARGETDIR ..."
rsync -av --delete-after "$KDIR"/ "$TARGETDIR"/

echo "→ Cleaning up ..."
#echo "→ Removing $KFILE ..."
#rm -f "$KFILE"
echo "→ Removing $KDIR ..."
rm -rf "$KDIR"

echo "Linux $KERNEL_VERSION synced into $TARGETDIR/"
