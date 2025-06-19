# Hello World Module 
my first kernel module during 
my understanding of kernel development and learning the C language. 

# Tested with linux kernel 6.12.30

* hello_module.c - a hello world module  

# QUICK BUILD STEPS  
- sudo make -C /usr/src/linux-headers-6.12.30-amd64/ M=~/projects/c-programming/hellomodule/
- sudo dmesg -C #clear kernel log messages 
- sudo rmmod hello_module # confirm its not loaded already 
- sudo insmod hello_module.ko
- lsmod 
- grep hello_module /proc/modules 
- grep hello_module /proc/kallsyms 
- 