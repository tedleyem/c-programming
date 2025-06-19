# Hello World Module 
my first character driver module during 
my understanding of kernel development and learning the C language. 

# Tested with linux kernel 6.12.30
* character_driver.c - a teste character driver 

# QUICK BUILD STEPS  
- sudo make -C /usr/src/linux-headers-6.12.30-amd64/ M=~/projects/c-programming/modules/character_driver/
- sudo dmesg -C #clear kernel log messages 
- sudo rmmod character_driver # confirm its not loaded already 
- sudo insmod character_driver.ko
- lsmod 
- grep character_driver /proc/modules 
- grep character_driver /proc/kallsyms 
- 