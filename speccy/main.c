/*
 goggles -- view system and hardware specs
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
#include <argp.h> 

/* Colors */
#define NORM "\x1B[37m"
#define NORM2 "\033[0m"
#define BOLD "\033[1m"
#define BLINK "\033[5m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"

/* Foreground colors */
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define GRAY "\x1b[90m"
#define BRIGHT_RED "\x1b[91m"
#define BRIGHT_GREEN "\x1b[92m"
#define BRIGHT_YELLOW "\x1b[93m"
#define BRIGHT_BLUE "\x1b[94m"
#define BRIGHT_MAGENTA "\x1b[95m"
#define BRIGHT_CYAN "\x1b[96m"
#define BRIGHT_WHITE "\x1b[97m"
#define RESET "\x1b[0m"
/* Background colors */
#define BG_BLACK "\x1b[30m"
#define BG_RED "\x1b[31m"
#define BG_GREEN "\x1b[32m"
#define BG_YELLOW "\x1b[33m"
#define BG_BLUE "\x1b[34m"
#define BG_MAGENTA "\x1b[35m"
#define BG_CYAN "\x1b[36m"
#define BG_WHITE "\x1b[37m"
#define BG_GRAY "\x1b[90m"
#define BG_BRIGHT_RED "\x1b[91m"
#define BG_BRIGHT_GREEN "\x1b[92m"
#define BG_BRIGHT_YELLOW "\x1b[93m"
#define BG_BRIGHT_BLUE "\x1b[94m"
#define BG_BRIGHT_MAGENTA "\x1b[95m"
#define BG_BRIGHT_CYAN "\x1b[96m"
#define BG_BRIGHT_WHITE "\x1b[97m"
#define BG_RESET "\x1b[0m"

/* added placeholder test varaible */
#define test "placeholder"

/* ARG PARSING */
int full; /* The -f flag */
const char *argp_program_version = "goggles 1.0";
const char *argp_program_bug_address = "<tmeralus@protonmail.com>";

static char doc[] = "View system and hardware specs.";
static char args_doc[] = "[FILENAME]...";

static struct argp_option options[] = {
    { "--full", '-f', 0, 0, "Get full system specs"},
    { "--help", '-h', 0, 0, "Print this text and exit"},
    { 0 }
};

struct arguments {
    enum { CHARACTER_MODE, WORD_MODE, FULL_DETAILS } mode;
    bool isCaseInsensitive;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    switch (key) {
    case '-f': arguments->mode = FULL_DETAILS; break;
    case 'h': arguments->mode = WORD_MODE; break;
    case '-v': arguments->isCaseInsensitive = true; break;
    case 'i': arguments->isCaseInsensitive = true; break;
    case ARGP_KEY_ARG: return 0;
    default: return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };


/* END ARG PARSING */

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
	printf("goggles \n");
	printf("-------\n");
	core_specs();
	//printf("%s  %s", core_specs(), more_specs() );
	// creates empty space on return
	printf("\n");
	return 0;
}
