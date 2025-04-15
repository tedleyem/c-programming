/*
 Goggles -- view hardware details
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
#include <string.h>

/* added placeholder test varaible */
#define test "placeholder"
 
struct utsname kername; //set variable for system name structure

// arg parsing functions 
void print_help() {
    printf("Usage: goggles [option]... \n");
    printf("--c\tSave to clipboard\n");
    printf("--f\tSave as text, pdf, or rtx\n");
    printf("--f\tSave as text, pdf, or rtx\n");
    printf("--h\tDisplay this help message\n"); 
}

// clipboard function
void save_to_clipboard() {
    printf("Saving to clipboard...\n");
    // save content to the clipboard (platform-specific)
}

void save_as_filetype(char *format) {
    if (strcmp(format, "text") == 0) {
        printf("Saving as text...\n");
    } else if (strcmp(format, "pdf") == 0) {
        printf("Saving as PDF...\n");
    } else if (strcmp(format, "rtx") == 0) {
        printf("Saving as RTF...\n");
    } else {
        printf("Invalid format. Supported formats are: text, pdf, rtx.\n");
    }
}

// PC INSIGHTS 
struct utsname kername; //set variable for system name structure

// USER INFO
void get_user_info() {
	// https://man7.org/linux/man-pages/man2/gethostname.2.html
	// test popen
	// https://man7.org/linux/man-pages/man3/popen.3.html
	printf("%s@%s \n" , test, test);
}

// OS INFO
void get_os_info() {
	printf("OS: %s \n", test);
}
// HOST INFO
void get_host_info() {
	//char getHost = system("uname -s \n");
	 FILE *fptr;
	// Open a file in read mode
	fptr = fopen("/etc/hostname", "r");
	printf("Host: %s \n", test);
	fclose(fptr);
}
// KERNEL VERSION
void get_kernel() {
	printf("Kernel: %s\n", kername.release);
}
// UPTIME
void get_uptime() {
	//char Upstill = system("uptime -p \n");
	printf("Uptime: %s \n", test);
}
// PACKAGES
void get_packages() {
	//char Upstill = system("dpkg --list | wc -l \n");
	printf("Packages: %s \n", test);
}
// SHELL
void get_shell() {
	printf("Shell: %s \n", test);
}
// RESOLUTION
void get_resolution() {
	//char pullRez = system("xdpyinfo | grep resolution");
	printf("Resolution: %s \n", test);
}
// DE
void get_desktop_env() {
	printf("DE: %s \n", test);
}
// WM
void get_window_env() {
	printf("WM: %s \n", test);
}
// WM THEME
void get_window_theme() {
	printf("WM Theme: %s \n", test);
}
// THEMES
void get_theme() {
	printf("Theme: %s \n", test);
}
// ICONS
void get_icons() {
	printf("Icons: %s \n", test);
}
// TERMINAL
void get_terminal() {
	printf("Terminal: %s \n", test);
} 
// CPU
void get_cpu() {
	printf("CPU: %s \n", test);
}
// CPU DETAILS
void get_cpu_details() {
	printf("CPU: %s \n", test);
}
// RAM/MEMORY
void get_ram() {
	printf("Memory: %s \n", test);
}
// RAM/MEMORY DETAILS
void get_ram_details() {
	printf("Memory: %s \n", test);
}
// Serial Number
void get_serial_number() {
	printf("Serial Number: %s \n", test);
}
// Model Number
void get_model_number() {
	printf("Model Number: %s \n", test);
}
// MOTHERBOARD
void get_motherboard() {
	printf("Motherboard: %s \n", test);
}
// GRAPHICS
void get_graphics() {
	printf("GPU: %s \n", test);
}
// STORAGE
void get_storage() {
	printf("Storage %s \n", test);
}
// OPTICAL DRIVE
void get_optical() {
	printf("Optical: %s \n", test);
}
// AUDIO
void get_audio() {
	printf("Audio: %s \n", test);
}
// PERIPHERALS
void get_peripherals() {
	printf("Perpiherals: %s \n", test);
}
// NETWORK
void get_network() {
	printf("Network: %s \n", test);
}

void core_specs() {  
	printf("---------------------\n");
	printf("- Hardware details - \n");
	printf("---------------------\n");
	get_os_info(); 
	get_serial_number();
	get_model_number();
	get_motherboard();
	get_cpu_details();
	get_ram_details();
	get_graphics();
	get_storage();
	get_optical();
	get_audio();
	get_peripherals();
	get_network();
}

void full_specs() {
	printf("-------------------\n");
	printf("- System details - \n");
	printf("-------------------\n");
	get_user_info();
	get_os_info();
	get_host_info();
	get_kernel();
	get_uptime();
	get_packages();
	get_shell();
	get_resolution();
	get_desktop_env();
	get_window_env();
	get_window_theme();
	get_theme();
	get_icons();
	get_terminal();
	get_cpu();
	get_graphics();
	get_ram();
	core_specs();
}
 

int main(int argc, char *argv[]) {
	// printf(" Goggles \n");
	//printf("---------\n");
    // Check if no arguments are provided
    if (argc == 1) {
		// Loop through each argument
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "--c") == 0) {
				save_to_clipboard();
			} else if (strcmp(argv[i], "--f") == 0) {
				save_as_filetype(argv[i]);
			} else if (strcmp(argv[i], "--full") == 0) {
				full_specs(argv[i]);
			} else if (strcmp(argv[i], "--h") == 0) {
				print_help();
			} else {
				//printf("Unknown option: %s\n", argv[i]);
				core_specs();
			}
		}
	}
	core_specs();
	//printf("\n use --h for help option \n");
	  
	return 0;
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
