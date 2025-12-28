#!/bin/bash
#KERNEL_VERSION="6.12.30"
KERNEL_VERSION=$(uname -r)
KERNEL_HEADERS="linux-headers-$KERNEL_VERSION"
MODULE_DIR="."

# remove exisitng kernel file 
echo "--- Clearing existing kernel module objects and mess ---"
rm -f *.ko *.o.cmd *.Modules* *.module *..module *.mod *.symvers *.order

echo "$KERNEL_VERSION"
echo "--- Check and install linux-header files ---"
if dpkg -l | grep -q "^ii.*${KERNEL_HEADERS}\s";then
    echo "Linux Headers $KERNEL_HEADERS already installed, Skipping install"
else
    echo "Installing $KERNEL_HEADERS" && sleep 1
    sudo apt install -y $KERNEL_HEADERS 
fi

# Build 
echo "--- Compiling kernel module --- "
echo "make -C /usr/src/"$KERNEL_HEADERS"/ M="$MODULE_DIR" "
make -C /usr/src/"$KERNEL_HEADERS"/ M="$MODULE_DIR"

