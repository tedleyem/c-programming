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
	int cpu_info = system("sysctl -n machdep.cpu.brand_string");
    int logical_cores = system("sysctl -n hw.logicalcpu_max");
    int physical_cores = system("sysctl -n hw.physicalcpu_max");
#endif
#ifdef __linux
//	int cpuFile = "/proc/cpuinfo";
#endif

// USER INFO
void getUserInfo() {
	// https://man7.org/linux/man-pages/man2/gethostname.2.html 
	//char getUser = system("whoami"); 
	//char getHost = system("hostname");
	char Infosplat = system("whoami \n");
} 

// OS INFO 
void getOsInfo() {
	// https://man7.org/linux/man-pages/man2/gethostname.2.html 
	char getUser = system("whoami \n");
}
// HOST INFO
void getHostInfo() {
	char getHost = system("uname -s \n");
}
// KERNEL VERSION
void getKernel() {
	char kernel = system("uname -r \n");
}
// UPTIME
void getUptime() {
	char Upstill = system("uptime -p \n");
}
// PACKAGES
void getPackages() {
	char Upstill = system("dpkg --list | wc -l \n");
	
}
// SHELL
void getShell() {
	printf("Shell example \n");
}
// RESOLUTION
void getResolution() {
	printf("Resolution example \n");
}
// DE
void getDeskEnv() {
	printf("DE example \n");
}
// WM
void getWindowEnv() {
	printf("WE example \n");
}
// THEMES 
void getTheme() {
	printf("THEME example \n");
}
// ICONS
void getIcons() {
	printf("ICONS examples \n");
}
// TERMINAL
void getTerminal() {
	printf("Terminal example \n");
}
// CPU
void getCPU() {
	printf("CPU example \n");
}
// RAM/MEMORY
void getRam() {
	printf("Memory example \n");
}
// <-- add flag for --more or --full to get advanced details >

// MOTHERBOARD
void getMotherboard() {
	printf("Motherboard example \n");
}
// GRAPHICS
void getGraphics() {
	printf("Graphics example \n");
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
*/

int main() { 
	printf("PC Insights \n" RESET); 
	printf("-----------\n" RESET);
	printf("user@hostname\n" RESET);
	//  INFO 
	// getUserInfo();   
	printf("-----------\n" RESET);
	printf("OS: " RESET);
	getOsInfo();
	printf("Host: " RESET);
	getHostInfo();
	printf("Kernel: " RESET);
	getKernel();
	printf("Uptime: " RESET);
	getUptime();
	printf("Packages: " RESET);
	getPackages();
	printf("Shell: " RESET);
	getShell();
	printf("Resolution: " RESET);
	getResolution();
	printf("DE: " RESET);
	getDeskEnv();
	printf("WM: " RESET);
	getWindowEnv();
	printf("Theme: " RESET);
	getTheme();
	printf("Icons: " RESET);
	getIcons();
	printf("Terminal: " RESET);
	getTerminal();
	printf("CPU: " RESET);
	getCPU();
	printf("GPU: " RESET);
	getGraphics();
	printf("Memory: " RESET);
	getRam();
	// add logic to hide the bottom half of these print statements
	// <-- add flag for --more or --full to get advanced details >
	// MOTHERBOARD
	// printf("Motherboard: " RESET);
	// GRAPHICS
	// printf("Graphics: " RESET);
	// STORAGE
	// printf("Storage: " RESET);
	// OPTICAL DRIVE
	// printf("Optical: " RESET);
	// AUDIO
	// printf("Audio: " RESET);
	// --c save to clipboard
	// --s save as text,pdf, or rtx
	printf("\n-----------------------------------------------\n");

}
