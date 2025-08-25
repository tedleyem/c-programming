# c-programming
A repo to document my journey with learning C and reading [C Programming Language, 2nd Edition](docs/pdf/the-C-programming-language-2nd-edition.pdf)

# Tested with linux kernel 6.12.30

## LEARNING AND OBJECTIVES 

# What Does a Linux Kernel Developer Do?
A Linux kernel developer uses computer code to create a program
 that functions as the core of a computer operating system. Your duties 
can include creating kernels for open-source operating systems for 
desktop computers, laptops, phones, and tablets. You can also develop 
programs for embedded systems for routers, smart devices, or automated 
machinery. Linux uses C programming languages, so you often write code 
in C and C++. In addition to your coding responsibilities, you also test
 and debug your programs. Your employer may ask you to develop 
applications, drivers, and other tools to use with your kernel.


# To land a C linux engineer job we need to capture these objectives in projects being created. 
[] Deep understanding of basic programming primitives 
[] Data Structures
[] Multi-threading 
[] Memory Management
[] Hardware access techniques and how to reason about them.
[] Developing and debugging on Linux (gdb, valgrind, etc).
[] Primitive Function Types 
[] Expert skills in operating systems internals (e.g. memory management & 
[] task scheduling
[] What are interrupts, can you share an example? 
[] Create a device drivers

# Projects 

## PROJECT #1 Goggles
a speccy inspired app to grab system hardware information
and copy to a clipboard  [*IN-PROGRESS*](https://github.com/tedleyem/c-programming/tree/main/apps/goggles)

## PROJECT #2 Kernel Module 
create and build a kernel module [*DONE*](https://github.com/tedleyem/kernel-hello-module)

## PROJECT #3 RAM DISK DRIVER - reddit idea
Write a simple RAM disk driver for linux. Basically, kmalloc a buffer, hook read and write up to the buffer so bytes written into the device file wind up in the buffer, and reading from the device file read out of the buffer. Maybe implement a dummy ioctl or two to enable fdisk and parted to work on it without complaining. I'm leaving out a ton of details obviously, but those are the details you're wanting to learn. This was exactly the project that got me into linux/unix device drivers. If you want a job doing that, you need to be working for a hardware company that needs such drivers. In my case, I was working at Compaq/HP, and we had a build process for SCO Unixware/Openserver drivers (1990s timeframe, before linux ate their lunch) and Openserver did not have a loopback device, and we needed to produce floppy disk images, and the process was to use an actual floppy disk in an actual floppy drive, which was slow and error prone. I wanted to learn about drivers, so I wrote a little driver that had a 1024 byte buffer that I could read and write to, and a lightbulb went off, and I thought, "what if I made the buffer 1.44M instead of 1024 bytes? It could act like a very reliable, very fast floppy disk!" So, I tried it, and initially it failed, needing some ioctl() I hadn't implemented. Dummied that up, and it worked. Cut the build time down from more than an hour to a few minutes, and no longer had to worry about wearing out floppy disks. 


# Kernel Driver implementer’s API guide
https://www.kernel.org/doc/html/latest/driver-api/index.html 

---
# KERNEL DEVELOPER JOB DESCRIPTION FROM INDEED 
## Preferred Qualifications
Strong understanding of Linux and UNIX fundamentals (standard libraries, services, networking, kernel/user-space interaction).
Thorough understanding of network protocols (TCP/IP, UDP, QUIC, etc.).
Developing and debugging on Linux (gdb, valgrind, etc).
Experience with packet decoding and analysis tools such as tcpdump and Wireshark.
Experience developing across the stack: OS/kernel, systems, containers, services, C, C++.
Experience building data pipelines to ship and collect data from multiple sources.
Familiarity with visualization tools and frameworks.


## Nice to Have
Familiarity with existing open source networking technologies - kernel (including eBPF, AF_XDP), Envoy, Istio, iwd, NetworkManager, etc.
Familiarity with data path hardware acceleration protocols and interfaces, such as RDMA, NVMe.
Familiarity with Kubernetes, Cloud-native Network Functions, and Container Network Interface plugins.
Performance engineering and security experience.
Passing familiarity with cross-GPU protocols (like GPUDirect or NVLink).


