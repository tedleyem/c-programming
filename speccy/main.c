/*
 system specs
 ------------
 A system report program to grab detailed information
 on each piece of hardware and Advanced PC insights.
 Inspired by apps like Speccy and Neofetch, the goal was to merge
 features of these tools into a smaller application.
 Author: Tedley Meralus <tmeralus@protonmail.com>
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h> //geting kernel and host name info
#include "termcolors.h"  
#ifdef __FreeBSD__
	#include <time.h>
#elif __linux__
	#include <sys/sysinfo.h>
#elif __APPLE__
	// apple specific commands will go here
	// int cpu_info = system("sysctl -n machdep.cpu.brand_string");
    // int logical_cores = system("sysctl -n hw.logicalcpu_max");
    // int physical_cores = system("sysctl -n hw.physicalcpu_max");
#endif
/*
If an object that has automatic storage duration is not initialized explicitly, its value is indeterminate.
If you do not initialize a variable, its value is unspecified.
*/ 

#define test "placeholder"
#define NORM "\x1B[37m"
#define NORM2 "\033[0m"
#define BOLD "\033[1m"
#define BLINK "\033[5m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"

struct utsname kername; //set variable for system name structure 

// USER INFO
void getUserInfo() {
	// https://man7.org/linux/man-pages/man2/gethostname.2.html 
	// test popen 
	// https://man7.org/linux/man-pages/man3/popen.3.html
	printf("%s@%s \n" , test, test);
} 

// OS INFO 
void getOsInfo() { 
	printf("OS: %s \n", test);
}
// HOST INFO
void getHostInfo() {
	//char getHost = system("uname -s \n");
	 FILE *fptr;
	// Open a file in read mode
	fptr = fopen("/etc/hostname", "r"); 
	printf("Host: %s \n", test);
	fclose(fptr);
}
// KERNEL VERSION
void getKernel() {
	printf("Kernel: %s\n", kername.release);
}
// UPTIME
void getUptime() {
	//char Upstill = system("uptime -p \n");
	printf("Uptime: %s \n", test);
}
// PACKAGES
void getPackages() {
	//char Upstill = system("dpkg --list | wc -l \n");
	printf("Packages: %s \n", test);	
}
// SHELL
void getShell() { 
	printf("Shell: %s \n", test);
}
// RESOLUTION
void getResolution() {
	//char pullRez = system("xdpyinfo | grep resolution");
	printf("Resolution: %s \n", test);
}
// DE
void getDeskEnv() { 
	printf("DE: %s \n", test);
}
// WM
void getWindowEnv() { 
	printf("WM: %s \n", test);
}
// WM THEME
void getWindowTheme() { 
	printf("WM Theme: %s \n", test);
}
// THEMES 
void getTheme() {
	printf("Theme: %s \n", test);
}
// ICONS
void getIcons() { 
	printf("Icons: %s \n", test);
}
// TERMINAL
void getTerminal() { 
	printf("Terminal: %s \n", test);
}
// CPU
void getCPU() {
	printf("CPU: %s \n", test);
}
// RAM/MEMORY
void getRam() { 
	printf("Memory: %s \n", test);
}
// <-- add flag for --more or --full to get advanced details >
// Serial Number
void getSerialNumber() {
	printf("Motherboard: %s \n", test);
}
// Model Number 
void getModelNumber() {
	printf("Motherboard: %s \n", test);
}
// MOTHERBOARD
void getMotherboard() {
	printf("Motherboard: %s \n", test);
}
// GRAPHICS
void getGraphics() {
	printf("GPU: %s \n", test);
}
// STORAGE
void getStorage() {
	printf("Storage %s \n", test);
}
// OPTICAL DRIVE
void getOptical() {
	printf("Optical: %s \n", test);
}
// AUDIO
void getAudio() {
	printf("Audio: %s \n", test);
}
// PERIPHERALS
void getPeripherals() {
	printf("Perpiherals: %s \n", test);
}
// NETWORK
void getNetwork() {
	printf("NIC Card: %s \n", test);
}

void core_specs(){ 
	getUserInfo();
	getOsInfo();
	getHostInfo();
	getKernel();
	getUptime();
	getPackages();
	getShell();
	getResolution();
	getDeskEnv();
	getWindowEnv();
	getWindowTheme();
	getTheme();
	getIcons();
	getTerminal();
	getCPU();
	getGraphics();
	getRam();
}

void more_specs(){
	printf("MORE SYSTEM SPECS");
	getSerialNumber();
	getModelNumber();
	getMotherboard();
	getGraphics();
	getStorage();
	getOptical();
	getAudio();
	getPeripherals();
	getNetwork();
}

/*  TODO: add flags for the following
 --c save to clipboard
 --s save as text,pdf, or rtx
 --h for help 
 --f full pc details

 // add logic to hide the bottom half of these print statements
 // <-- add flag for --more or --full to get advanced details >

  printf("Speccy is a system information tool written in C\n");
  printf("Report bugs: https://github.com/tedleyem/speccy/issues\n");
*/

int main(int argc, char *argv[]) { 
	printf("Speccy \n");
	printf("-------\n");
	core_specs();
	//printf("%s  %s", core_specs(), more_specs() );
	// creates empty space on return
	printf("\n");
	return 0;
}
