#!/bin/bash
KERNEL_VERSION=$(uname -r)
KERNEL_HEADERS="linux-headers-$KERNEL_VERSION"
MODULE_DIR="~/projects/c-programming/modules/hellomodule/"

# remove exisitng kernel file 
rm -f *.ko *.o.cmd *.Modules* *.module *..module *.mod *.symvers *.order

echo "$KERNEL_VERSION"
# check and install linux-header files 
if dpkg -l | grep -q "^ii.*${KERNEL_HEADERS}\s";then
    echo "Linux Headers $KERNEL_HEADERS already installed, Skipping install"
else
    echo "Installing $KERNEL_HEADERS" && sleep 1
    sudo apt install -y $KERNEL_HEADERS 
fi

# Build 
echo "Kernel module compilation"
make -C /usr/src/"$KERNEL_HEADERS"/ M="$MODULE_DIR"

