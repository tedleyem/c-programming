get build script or make command to build character_driver
on existing linux kernel

create script to test both drivers. 

- use dmesg to catch the driver when it gets installed/inserted 
- sudo insmod character_driver.ko 
- cat /proc/devices (check registered driver number)
- ls /dev/my_test_driver (check that the test driver file was created)
- test file operations (cat /dev/my_test_driver)
- write with character driver "echo "test" /dev/my_test_driver > /dev/my_test_driver" --run with sudo, find the invalid argument 

