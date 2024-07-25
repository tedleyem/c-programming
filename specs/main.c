/*
 system specs
 ------------

// A system report program to grab detailed information
 on each piece of hardware and Advanced PC insights.
 Inspired by apps like Speccy and Neofetch, the goal was to merge
 features of these tools into a smaller application.
 2024 by Tedley Meralus
*/
#include <stdio.h>
#include "termcolors.h"
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/utsname.h>
// #include <string.h>
// #include <inttypes.h>
/*
#ifdef __FreeBSD__
	#include <time.h>
#elif __linux__
	#include <sys/sysinfo.h>
#endif
*/

// #define BLUE(string) "\x1b[34m" string "\x1b[0m"


// Summary Page
// OS INFO <-- Show name and color with ASCII logo art

// HOST INFO
char getUserInfo(){
	return printf("user@system \n");
}

// HOST INFO
char getHostInfo(){
	return printf("hello, world \n");
}
// KERNEL VERSION
char getKernel(){
	return printf("hello, world \n");
}
// UPTIME
char getUptime(){
	return printf("hello, world \n");
}
// PACKAGES
char getPackages(){
	return printf("hello, world \n");
}
// SHELL
char getShell(){
	return printf("hello, world \n");
}
// RESOLUTION
char getResolution(){
	return printf("hello, world \n");
}
// DE
char getDeskEnv(){
	return printf("hello, world \n");
}
// WM
char getWindowEnv(){
	return printf("hello, world \n");
}
// TERMINAL
char getTerminal(){
	return printf("hello, world \n");
}
// CPU
char getCPU(){
	return printf("hello, world \n");
}
// RAM/MEMORY
char getMemory(){
	return printf("hello, world \n");
}
// OR
char getRam(){
	return printf("hello, world \n");
}
// <-- add flag for --more or --full to get advanced details >

// MOTHERBOARD
char getMotherboard(){
	return printf("hello, world \n");
}
// GRAPHICS
char getGraphics(){
	return printf("hello, world \n");
}
// STORAGE
char getStorage(){
	return printf("hello, world \n");
}
// OPTICAL DRIVE
char getOptical(){
	return printf("hello, world \n");
}
// AUDIO
char getAudio(){
	x = printf("hello, world \n");
}
// PERIPHERALS
char getPeripherals(){
	return printf("hello, world \n");
}
// NETWORK
char getNetwork(){
	return printf("hello, world \n");
}
// --c save to clipboard
// --s save as text,pdf, or rtx

// help links:
// * https://www.tutorialspoint.com/unix_system_calls/sysinfo.htm


// <-- add flag for --more or --full to get advanced details >
// --c save to clipboard
// --s save as text,pdf, or rtx

int main(){
	// Summary Page
	printf("PC Insights \n" RESET);
	printf("%s", BLUE"user@hostname \n" RESET);
	printf("-----------\n" RESET);
	// HOST INFO
	printf("%s", BLUE"Host \n" RESET);
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
	getAudio;

	// --c save to clipboard
	// --s save as text,pdf, or rtx
	printf("\n-----------------------------------------------");
	printf("\nTip: --c save to clipboard --f full pc details\n\n");

	return 0;
}