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

/* GET UPTIME */
getUptime(){
        #ifdef __FreeBSD__
                struct timespec time_spec;

                if (clock_gettime(CLOCK_UPTIME_PRECISE, &time_spec) != 0)
                	return 0;

		uint64_t uptime = time_spec.tv_sec;

		return uptime;
	#elif __linux__
        	struct sysinfo sys;

		sysinfo(&sys);

		return sys.uptime;
	#endif
}
/* HOST INFO  */
char *getHostInfo(){
	return res;
}
/* KERNEL VERSION  */
char *getKernel(){
	FILE *osr;
	char buff[70];
	return res;
}
/* UPTIME  */
char *getUptime(){
	FILE *osr;
	char buff[70];
	return res;
}
/* PACKAGES  */
char *getPackages(){
	FILE *osr;
	char buff[70];
	return res;
}
/* SHELL  */
char *getShell(){
	FILE *osr;
	char buff[70];
	return res;
}
/* RESOLUTION  */
char *getResolution(){
	FILE *osr;
	char buff[70];
	return res;
}
/* DE  */
char *getDeskEnv(){
	FILE *osr;
	char buff[70];
	return res;
}
/* WM  */
char *getWindowEnv(){
	FILE *osr;
	char buff[70];
	return res;
}
/* TERMINAL  */
char *getTerminal(){
	FILE *osr;
	char buff[70];
	return res;
}
/* CPU  */
char *getCPU(){
	FILE *osr;
	char buff[70];
	return res;
}
/* RAM/MEMORY */
char *getMemory(){
	FILE *osr;
	char buff[70];
	static char *res;

	if(!(osr = fopen("/etc/os-release", "r")))
		{ return "Unable to find OS"; }

	fgets(buff, 70, (FILE*)osr);
	fclose(osr);

	res = getSecondToken(buff, "=");
	remove_all_chars(res, '\"');
	remove_all_chars(res, '\n');

	return res;
}
/* OR */
char *getRam(){
  	FILE *meminfo;
	char buff[255], buff2[255];
	static char res[30];

	if(!(meminfo = fopen("/proc/meminfo", "r")))
		{ return "Unable to get memory stats"; }

	fgets(buff, 255, (FILE*)meminfo);
	fgets(buff2, 255, (FILE*)meminfo);
	fgets(buff2, 255, (FILE*)meminfo);
	fclose(meminfo);

	int total = atoi(getSecondToken(buff, " ")) / 1024;
	int free = atoi(getSecondToken(buff2, " ")) / 1024;

	sprintf(res, "%dM / %dM", total - free, total);
	return res;
}


/* <-- add flag for --more or --full to get advanced details > */


/* MOTHERBOARD  */
char *getMotherboard(){
	FILE *osr;
	char buff[70];
	return res;
}
/* GRAPHICS  */
char *getGraphics(){
	FILE *osr;
	char buff[70];
	return res;
}
/* STORAGE  */
char *getStorage(){
	FILE *osr;
	char buff[70];
	return res;
}
/* OPTICAL DRIVE  */
char *getOptical(){
	FILE *osr;
	char buff[70];
	return res;
}
/* AUDIO  */
char *getAudio(){
	FILE *osr;
	char buff[70];
	return res;
}
/* PERIPHERALS  */
char *getPeripherals(){
	FILE *osr;
	char buff[70];
	return res;
}
/* NETWORK  */
char *getNetwork(){
	FILE *osr;
	char buff[70];
	return res;
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
	struct utsname name;
	uname(&name);
/* Summary Page */
/* HOST INFO  */
	printf("\033[1m\033[36m%s@\033[1m\033[37m%s\n", getenv("USER"),name.nodename);
/* OS INFO <-- Show name and color with ASCII logo art  */
	printf("\033[1m\033[36mos\t\033[0;37m%s\n", getOS());
/* KERNEL VERSION  */
	printf("\033[1m\033[36mkernel\t\033[0;37m%s\n", name.release);
/* GET UPTIME */
	printf("\033[1m\033[36muptime\t\033[0;37m%"PRIu64"h %"PRIu64"m\n", getUptime()/60/60, getUptime()/60 % 60);
/* PACKAGES  */
	printf("\033[1m\033[36mpackages\t\033[0;37m%s\n", getPackages());
/* SHELL  */
	printf("\033[1m\033[36mshell\t\033[0;37m%s\n", getenv("SHELL"));
/* RESOLUTION  */
	printf("\033[1m\033[36mresolution\t\033[0;37m%s\n", getenv("RESOLUTION"));
/* DE  */
	printf("\033[1m\033[36mdeskenv\t\033[0;37m%s\n", getenv("DESKENV"));
/* WM  */
	printf("\033[1m\033[36mwindowenv\t\033[0;37m%s\n", getenv("WINDOWENV"));
 /* TERMINAL  */
	printf("\033[1m\033[36mtermshow\t\033[0;37m%s\n", getenv("TERMSHOW"));
 /* CPU  */
	printf("\033[1m\033[36mcpu\t\033[0;37m%s\n", getenv("CPU"));
/* RAM/MEMORY */
	printf("\033[1m\033[36mmemory\t\033[0;37m%s\033[0m\n", getRam("MEMORY"));
/* add logic to hide the bottom half of these print statements */
/* <-- add flag for --more or --full to get advanced details > */
/* MOTHERBOARD  */
	printf("\033[1m\033[36mmotherboard\t\033[0;37m%s\033[0m\n", getMotherbord("MOTHERBOARD"));
/* GRAPHICS  */
	printf("\033[1m\033[36mgraphics\t\033[0;37m%s\033[0m\n", getGraphics("GRAPHICS"));
/* STORAGE  */
	printf("\033[1m\033[36mstorage\t\033[0;37m%s\033[0m\n", getStorage("STORAGE"));
/* OPTICAL DRIVE  */
	printf("\033[1m\033[36moptical\t\033[0;37m%s\033[0m\n", getOptical("Optical"));
/* AUDIO  */
	printf("\033[1m\033[36maudio\t\033[0;37m%s\033[0m\n", getAudio("AUDIO"));
/* PERIPHERALS  */
	printf("\033[1m\033[36mperipherals\t\033[0;37m%s\033[0m\n", getPeripherals("PERIPHERALS"));
/* NETWORK  */
	printf("\033[1m\033[36mnetwork\t\033[0;37m%s\033[0m\n", getNetwork("NETWORK"));
/* --c save to clipboard  */
/* --s save as text,pdf, or rtx  */

	return 0;
}