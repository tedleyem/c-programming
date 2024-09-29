/*
 system specs
 ------------
 A system report program to grab detailed information
 on each piece of hardware and Advanced PC insights.
 Inspired by apps like Speccy and Neofetch, the goal was to merge
 features of these tools into a smaller application.
 Author: Tedley Meralus
*/
#include <stdio.h>
#include <stdlib.h>
#include "termcolors.h"

/*
If an object that has automatic storage duration is not initialized explicitly, its value is indeterminate.
If you do not initialize a variable, its value is unspecified.
*/
// iint uname = 0;
int uptime = 0;
int whoami = 0;
int hostname = 0;
int checkmemory = 0;
int cpu_info = 0;
int logical_cores = 0;
int physical_cores = 0;

#ifdef __APPLE__
	// apple specific commands will go here
	// int cpu_info = system("sysctl -n machdep.cpu.brand_string");
    // int logical_cores = system("sysctl -n hw.logicalcpu_max");
    // int physical_cores = system("sysctl -n hw.physicalcpu_max");
#endif
#ifdef __linux
//	int cpuFile = "/proc/cpuinfo";
#endif

// USER INFO
void getUserInfo() {
	// https://man7.org/linux/man-pages/man2/gethostname.2.html 
	//char getUser = system("whoami"); 
	//char getHost = system("hostname");
	// https://man7.org/linux/man-pages/man2/gethostname.2.html 
	char getUser = system("hostname \n");
	char Infosplat = system("whoami \n"); 
} 

// OS INFO 
void getOsInfo() { 
	printf("OS: \n");
}
// HOST INFO
void getHostInfo() {
	char getHost = system("uname -s \n");
	printf("Host: \n", getHost);
}
// KERNEL VERSION
void getKernel() {
	//char kernel = system("uname -r \n");
	printf("Kernel: \n");
}
// UPTIME
void getUptime() {
	//char Upstill = system("uptime -p \n");
	printf("Uptime: \n");
}
// PACKAGES
void getPackages() {
	//char Upstill = system("dpkg --list | wc -l \n");
	printf("Packages: \n");	
}
// SHELL
void getShell() { 
	printf("Shell: \n");
}
// RESOLUTION
void getResolution() {
	//char pullRez = system("xdpyinfo | grep resolution");
	printf("Resolution: \n");
}
// DE
void getDeskEnv() { 
	printf("DE: \n");
}
// WM
void getWindowEnv() { 
	printf("WM: \n");
}
// THEMES 
void getTheme() {
	printf("Theme: \n");
}
// ICONS
void getIcons() { 
	printf("Icons: \n");
}
// TERMINAL
void getTerminal() { 
	printf("Terminal: \n");
}
// CPU
void getCPU() {
	printf("CPU: \n");
}
// RAM/MEMORY
void getRam() { 
	printf("Memory: \n");
}
// <-- add flag for --more or --full to get advanced details >

// MOTHERBOARD
void getMotherboard() {
	printf("Motherboard example \n");
}
// GRAPHICS
void getGraphics() {
	printf("GPU: \n");
}
// STORAGE
void getStorage() {
	printf("Storage example \n");
}
// OPTICAL DRIVE
void getOptical() {
	printf("Optical example \n");
}
// AUDIO
void getAudio() {
	printf("Audio example \n");
}
// PERIPHERALS
void getPeripherals() {
	printf("PERPH example \n");
}
// NETWORK
void getNetwork() {
	printf("NIC Card example");
}
void moreSpecs() {
	printf("NIC Card example");
}

/*  TODO: add flags for the following
 --c save to clipboard
 --s save as text,pdf, or rtx
 --h for help 
 --f full pc details

  printf("Speccy is a system information tool written in C\n");
  printf("Report bugs: https://github.com/tedleyem/speccy/issues\n");
*/

int main() { 
	printf("PC Specs \n");
	printf("-----------\n");
	getUserInfo();   
	printf("-----------\n");
	getOsInfo();
	getHostInfo();
	getKernel();
	getUptime();
	getPackages();
	getShell();
	getResolution();
	getDeskEnv();
	getWindowEnv();
	getTheme();
	getIcons();
	getTerminal();
	getCPU();
	getGraphics();
	getRam();
	// add logic to hide the bottom half of these print statements
	// <-- add flag for --more or --full to get advanced details >
	// MOTHERBOARD
	// printf("Motherboard: " );
	// GRAPHICS
	// printf("Graphics: " );
	// STORAGE
	// printf("Storage: " );
	// OPTICAL DRIVE
	// printf("Optical: " );
	// AUDIO
	// printf("Audio: " );
	// --c save to clipboard
	// --s save as text,pdf, or rtx
	//printf("----------------------------------------------\n");
	printf("\n");
	return 0;

}
