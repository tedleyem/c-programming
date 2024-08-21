/*
 system specs
 ------------
 A system report program to grab detailed information
 on each piece of hardware and Advanced PC insights.
 Inspired by apps like Speccy and Neofetch, the goal was to merge
 features of these tools into a smaller application.
 Author:cc ma	 Tedley Meralus
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for getting hostname info
#include "termcolors.h"

/*
If an object that has automatic storage duration is not initialized explicitly, its value is indeterminate.
If you do not initialize a variable, its value is unspecified.
*/
#define uname 0
#define uptime 0
#define whoami 0
#define hostname 0
#define checkmemory 0
#define cpu_info 0
#define logical_cores 0
#define physical_cores 0

#ifdef __APPLE__
	// apple specific commands will go here
#endif
#ifdef __linux
	int cpuFile = "/proc/cpuinfo";
#endif

// Summary Page
// OS INFO <-- Show name and color with ASCII logo art

// HOST INFO
char getUserInfo() {
	// https://man7.org/linux/man-pages/man2/gethostname.2.html
	p =  printf("user@system from function\n");
	return p;
}

// HOST INFO
char getHostInfo() {
	return printf("hostname");
}
// KERNEL VERSION
char getKernel() {
	return printf("example");
}
// UPTIME
char getUptime() {
	return printf("example");
}
// PACKAGES
char getPackages() {
	return printf("example");
}
// SHELL
char getShell() {
	return printf("example");
}
// RESOLUTION
char getResolution() {
	return printf("example");
}
// DE
char getDeskEnv() {
	return printf("example");
}
// WM
char getWindowEnv() {
	return printf("example");
}
// TERMINAL
char getTerminal() {
	return printf("example");
}
// CPU
char getCPU() {
	int cpu_info = system("sysctl -n machdep.cpu.brand_string");
    int logical_cores = system("sysctl -n hw.logicalcpu_max");
    int physical_cores = system("sysctl -n hw.physicalcpu_max");
	return printf("example");
}
// RAM/MEMORY
char getMemory() {
	return printf("example");
}
// OR
char getRam() {
	return printf("example");
}
// <-- add flag for --more or --full to get advanced details >

// MOTHERBOARD
char getMotherboard() {
	return printf("example");
}
// GRAPHICS
char getGraphics() {
	return printf("example");
}
// STORAGE
char getStorage() {
	return printf("example");
}
// OPTICAL DRIVE
char getOptical() {
	return printf("example");
}
// AUDIO
char getAudio() {
	return printf("example");
}
// PERIPHERALS
char getPeripherals() {
	return printf("example");
}
// NETWORK
char getNetwork() {
	return printf("example");
}
// --c save to clipboard
// --s save as text,pdf, or rtx

// help links:
// * https://www.tutorialspoint.com/unix_system_calls/sysinfo.htm


// <-- add flag for --more or --full to get advanced details >
// --c save to clipboard
// --s save as text,pdf, or rtx

int main() {
	// Summary Page
	printf("PC Insights \n" RESET);
	printf("%s", BLUE"user@hostname \n" RESET);
	printf("-----------\n" RESET);
	// HOST INFO
	printf("%s", BLUE"Host: \n" RESET); getHostInfo;
	// OS INFO <-- Show name and color with ASCII logo art
	printf("%s", BLUE"OS:  \n" RESET);
	// KERNEL VERSION
	printf("%s", BLUE"Kernel:  \n" RESET);
	// GET UPTIME
	printf("%s", BLUE"Uptime:  \n" RESET);
	// PACKAGES
	printf("%s", BLUE"Packages:  \n" RESET);
	// SHELL
	printf("%s", BLUE"Shell:  \n" RESET);
	// RESOLUTION
	printf("%s", BLUE"Resolution: \n" RESET);
	// DE
	printf("%s", BLUE"DE: \n" RESET);
	// WM
	printf("%s", BLUE"WM: \n" RESET);
 	// THEME
	printf("%s", BLUE"Theme: \n" RESET);
 	// ICONS
	printf("%s", BLUE"Icons: \n" RESET);
 	// TERMINAL
	printf("%s", BLUE"Terminal: \n" RESET);
	 // CPU
	printf("%s", BLUE"CPU: \n" RESET);
	 // GPU
	printf("%s", BLUE"GPU: \n" RESET);
	// RAM/MEMORY
	printf("%s", BLUE"Memory: \n" RESET);
	// add logic to hide the bottom half of these print statements
	// <-- add flag for --more or --full to get advanced details >
	// MOTHERBOARD
	printf("%s", BLUE"Motherboard: \n" RESET);
	// GRAPHICS
	printf("%s", BLUE"Graphics: \n" RESET);
	// STORAGE
	printf("%s", BLUE"Storage: \n" RESET);
	// OPTICAL DRIVE
	printf("%s", BLUE"Optical: \n" RESET);
	// AUDIO
	printf("%s", BLUE"Audio: \n" RESET);
	// --c save to clipboard
	// --s save as text,pdf, or rtx
	printf("\n-----------------------------------------------");
	printf("\nTip: --c save to clipboard --f full pc details\n\n");

	return 0;
}