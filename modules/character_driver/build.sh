#!/bin/bash 
#rm *.ko
#rm *.o.cmd 
#rm *.Modules*
#rm *.module
#rm *..module
#rm *.mod
#rm *.symvers
#rm *.order
sudo make -C /usr/src/linux-headers-6.12.30-amd64/ M=~/projects/c-programming/modules/character_driver/