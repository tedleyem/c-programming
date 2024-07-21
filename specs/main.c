#include <stdio.h>
/* #include <stdlib.h> */
/* #include <unistd.h> */
/* #include <sys/utsname.h> */
/* #include <string.h> */
/* #include <inttypes.h> */
/*
#ifdef __FreeBSD__
	#include <time.h>
#elif __linux__
	#include <sys/sysinfo.h>
#endif
*/

/* A system report program to grab detailed information
 on each piece of hardware and Advanced PC insights */

/* Summary Page */
/* OS INFO <-- Show name and color with ASCII logo art  */

/* HOST INFO  */
char getHostInfo(){
	printf("hello, world \n");
}
/* KERNEL VERSION  */
char getKernel(){
	printf("hello, world \n");
}
/* UPTIME  */
char getUptime(){
	printf("hello, world \n");
}
/* PACKAGES  */
char getPackages(){
	printf("hello, world \n");
}
/* SHELL  */
char getShell(){
	printf("hello, world \n");
}
/* RESOLUTION  */
char getResolution(){
	printf("hello, world \n");
}
/* DE  */
char getDeskEnv(){
	printf("hello, world \n");
}
/* WM  */
char getWindowEnv(){
	printf("hello, world \n");
}
/* TERMINAL  */
char getTerminal(){
	printf("hello, world \n");
}
/* CPU  */
char getCPU(){
	printf("hello, world \n");
}
/* RAM/MEMORY */
char getMemory(){
	printf("hello, world \n");
}
/* OR */
char getRam(){
	printf("hello, world \n");
}
/* <-- add flag for --more or --full to get advanced details > */

/* MOTHERBOARD  */
char getMotherboard(){
	printf("hello, world \n");
}
/* GRAPHICS  */
char getGraphics(){
	printf("hello, world \n");
}
/* STORAGE  */
char getStorage(){
	printf("hello, world \n");
}
/* OPTICAL DRIVE  */
char getOptical(){
	printf("hello, world \n");
}
/* AUDIO  */
char getAudio(){
	printf("hello, world \n");
}
/* PERIPHERALS  */
char getPeripherals(){
	printf("hello, world \n");
}
/* NETWORK  */
char getNetwork(){
	printf("hello, world \n");
}
/* --c save to clipboard  */
/* --s save as text,pdf, or rtx  */

/* help links:
 * https://www.tutorialspoint.com/unix_system_calls/sysinfo.htm
 */

/* <-- add flag for --more or --full to get advanced details > */
/* --c save to clipboard  */
/* --s save as text,pdf, or rtx  */

int main(){
	/* Summary Page */
	printf("\033[1m\033[36m%s@\033[1m\033[37m%s\n", "@Hostname pc insights");
	/* HOST INFO  */
	printf("\033[1m\033[36m%s@\033[1m\033[37m%s\n", "USER");
	/* OS INFO <-- Show name and color with ASCII logo art  */
	printf("\033[1m\033[36mos\t\033[0;37m%s\n", "OS");
	/* KERNEL VERSION  */
	printf("\033[1m\033[36mkernel\t\033[0;37m%s\n", "Kernel");
	/* GET UPTIME */
	printf("\033[1m\033[36muptime\t\033[0;37m%s\n", "Uptime");
	/* PACKAGES  */
	printf("\033[1m\033[36mpackages\t\033[0;37m%s\n", "Packages");
	/* SHELL  */
	printf("\033[1m\033[36mshell\t\033[0;37m%s\n", "SHELL");
	/* RESOLUTION  */
	printf("\033[1m\033[36mresolution\t\033[0;37m%s\n", "RESOLUTION");
	/* DE  */
	printf("\033[1m\033[36mdeskenv\t\033[0;37m%s\n", "DESKENV");
	/* WM  */
	printf("\033[1m\033[36mwindowenv\t\033[0;37m%s\n", "WINDOWENV");
 	/* TERMINAL  */
	printf("\033[1m\033[36mtermshow\t\033[0;37m%s\n", "TERMSHOW");
	 /* CPU  */
	printf("\033[1m\033[36mcpu\t\033[0;37m%s\n", "CPU");
	/* RAM/MEMORY */
	printf("\033[1m\033[36mmemory\t\033[0;37m%s\033[0m\n", "MEMORY");
	/* add logic to hide the bottom half of these print statements */
	/* <-- add flag for --more or --full to get advanced details > */
	/* MOTHERBOARD  */
	printf("\033[1m\033[36mmotherboard\t\033[0;37m%s\033[0m\n", "MOTHERBOARD");
	/* GRAPHICS  */
	printf("\033[1m\033[36mgraphics\t\033[0;37m%s\033[0m\n", "GRAPHICS");
	/* STORAGE  */
	printf("\033[1m\033[36mstorage\t\033[0;37m%s\033[0m\n", "STORAGE");
	/* OPTICAL DRIVE  */
	printf("\033[1m\033[36moptical\t\033[0;37m%s\033[0m\n", "Optical");
	/* AUDIO  */
	printf("\033[1m\033[36maudio\t\033[0;37m%s\033[0m\n", "AUDIO");
	/* PERIPHERALS  */
	printf("\033[1m\033[36mperipherals\t\033[0;37m%s\033[0m\n", "PERIPHERALS");
	/* NETWORK  */
	printf("\033[1m\033[36mnetwork\t\033[0;37m%s\033[0m\n", "NETWORK");
	/* --c save to clipboard  */
	/* --s save as text,pdf, or rtx  */
	printf("\nTip: --c save to clipboard | --f full pc details\n");

	return 0;
}