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
// #include <termcolors.h>
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

#define BLUE(string) "\x1b[34m" string "\x1b[0m"


// Summary Page
// OS INFO <-- Show name and color with ASCII logo art

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
	return printf("hello, world \n");
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
	printf("PC Insights");
	printf("\n----------\n");
	// HOST INFO
	printf(BLUE("%s"), "user: \n");
	// OS INFO <-- Show name and color with ASCII logo art
	printf(BLUE("%s"),"os:  \n");
	// KERNEL VERSION
	printf(BLUE("%s"),"kernel:  \n");
	// GET UPTIME
	printf(BLUE("%s"),"uptime:  \n");
	// PACKAGES
	printf(BLUE("%s"),"packages:  \n");
	// SHELL
	printf(BLUE("%s"),"shell:  \n");
	// RESOLUTION
	printf(BLUE("%s"),"resolution: \n");
	// DE
	printf(BLUE("%s"),"deskenv: \n");
	// WM
	printf(BLUE("%s"),"windowenv: \n");
 	// TERMINAL
	printf(BLUE("%s"),"termshow: \n");
	 // CPU
	printf(BLUE("%s"),"cpu: \n");
	// RAM/MEMORY
	printf(BLUE("%s"),"memory: \n");
	// add logic to hide the bottom half of these print statements
	// <-- add flag for --more or --full to get advanced details >
	// MOTHERBOARD
	printf(BLUE("%s"),"motherboard: \n");
	// GRAPHICS
	printf(BLUE("%s"),"graphics: \n");
	// STORAGE
	printf(BLUE("%s"),"storage: \n");
	// OPTICAL DRIVE
	printf(BLUE("%s"),"optical: \n");
	// AUDIO
	printf(BLUE("%s"),"audio: \n");
	// PERIPHERALS
	printf(BLUE("%s"),"peripherals: \n");
	// NETWORK
	printf(BLUE("%s"),"network: \n");
	// --c save to clipboard
	// --s save as text,pdf, or rtx
	printf("\n-----------------------------------------------");
	printf("\nTip: --c save to clipboard | --f full pc details\n\n");

	return 0;
}