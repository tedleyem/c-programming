# Hello World Module 
my first character driver module during 
my understanding of kernel development and learning the C language. 

# Tested with linux kernel 6.12.30
* character_driver.c - a test character driver 

line 30: 
	register_chrdev(200, "Test Character Driver", &my_char_file_operations);	
creates a character driver using ID of 200 and can be checked with this command 

```
$ cat /proc/devices 
```

# QUICK BUILD STEPS  
#### these are specific to linux kernel 6.12 and my dev environment 
$ sudo mknod /dev/my_test_driver c 200 5 ## CREATE TEST DRIVER CHARACTER DRIVER FILE 
$ sudo make -C /usr/src/linux-headers-6.12.30-amd64/ M=~/projects/c-programming/modules/character_driver/
$ sudo dmesg -C #clear kernel log messages 
$ sudo rmmod character_driver # confirm its not loaded already 
$ sudo insmod character_driver.ko
$ lsmod 
$ grep character_driver /proc/modules 
$ grep character_driver /proc/kallsyms 

