/*
 goggles -- view hardware details
 ------------
 A system report program to grab detailed information
 on each piece of hardware and Advanced PC insights.
 Inspired by apps like Speccy and Neofetch, the goal was to merge
 features of these tools into a smaller application.
 Author: Tedley Meralus <tedley@meralus.com>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <unistd.h> // for hostname and login
#include <limits.h> // for HOST_NAME_MAX buffer

#if defined(__APPLE__)
	#include <sys/sysctl.h>
#endif

// added placeholder test varaible
#define test "placeholder"
 // Define a max length for all detailed specs
#define MAX_SPEC_LEN 256 

// Set variable for system name structure
struct utsname kername; 

// recurring function to easily run a system command in multiple functions
void command_output(const char *cmd, char *output, size_t max_len) {
    FILE *fp;
    
    // Run a command
    fp = popen(cmd, "r");
    if (fp == NULL) {
        strncpy(output, "Error executing command", max_len);
        output[max_len - 1] = '\0';
        return;
    }

    // Read the output line if command runs successfully
    if (fgets(output, max_len, fp) != NULL) {
        // Remove trailing newline characters
        output[strcspn(output, "\n")] = '\0';
    } else {
        strncpy(output, "Not found or No output", max_len);
        output[max_len - 1] = '\0';
    }

    // Close pointer
    pclose(fp);
}

// HOST INFO
void get_host_info() {
	//setting limits to the hostname 
	 char hostname[256];
	// Check systems
    #if defined(__linux__) || defined(__APPLE__)
        // gethostname writes the hostname string into the 'hostname' buffer
        if (gethostname(hostname, sizeof(hostname)) == 0) {
            // 'hostname' is an array, which becomes a char* pointer when passed 
            printf("Hostname: %s \n", hostname);
        } else {
            // Handle error, e.g., print a placeholder or an error message
            printf("Hostname: Error getting hostname\n");
        }
    #else
        printf("Host: Unknown\n");
    #endif
}

// OS INFO
void get_os_info() {
	printf("OS: %s \n", kername.sysname);
}

// USER INFO
void get_user_info() {
	printf("User: %s \n", getlogin());
}

// Serial Number
void get_serial_number() {
	char serial_num[MAX_SPEC_LEN] = "Unknown Serial Number";

    #ifdef __linux__
        // Linux: Attempt to read the System Serial Number directly from /sys.
        // This file is often world-readable, bypassing the need for 'sudo dmidecode'.
        command_output("cat /sys/class/dmi/id/product_serial", serial_num, MAX_SPEC_LEN);

    #elif defined(__APPLE__)
        // macOS: ioreg usually does NOT require sudo for this system-level serial.
        //command_output("ioreg -l | grep IOPlatformSerialNumber | awk '{print $4}' | tr -d '\"'", serial_num, MAX_SPEC_LEN);

    #else
        strncpy(serial_num, "Platform Not Supported", MAX_SPEC_LEN);
    #endif

    printf("Serial Number: %s \n", serial_num);
}
// Model Number
void get_model_number() {
	    char modelnumber[MAX_SPEC_LEN] = "Unknown Model";

    #ifdef __linux__
        // Linux: Attempt to read DMI info directly from the world-readable /sys files.
        // This is the preferred non-root method to get Baseboard Product Name.
        command_output("cat /sys/class/dmi/id/product_serial", modelnumber, MAX_SPEC_LEN);

        // Fallback: If board_name is empty or fails, try the vendor
        if (strcmp(modelnumber, "Not found or No output") == 0) {
            command_output("cat /sys/class/dmi/id/product_serial", modelnumber, MAX_SPEC_LEN);
            // Prepend a label if we only found the vendor
            char vendor_only[MAX_SPEC_LEN];
            snprintf(vendor_only, MAX_SPEC_LEN, "Vendor: %s", modelnumber);
            strncpy(modelnumber, vendor_only, MAX_SPEC_LEN);
        }
    #elif defined(__APPLE__)
        // macOS: Use ioreg to find the model identifier.
        // Command finds IOPlatformExpertDevice, filters for 'model', prints the 4th field (the value), and removes quotes.
        // command_output("ioreg -l | grep IOPlatformExpertDevice | grep model | awk '{print $NF}' | tr -d '\"'", modelnumber, MAX_SPEC_LEN);
    #else
        strncpy(modelnumber, "Platform Not Supported", MAX_SPEC_LEN);
    #endif
    printf("Model Number: %s \n", modelnumber);

}

// CPU DETAILS (model name/brand)
void get_cpu_details() {
    char cpu_model[MAX_SPEC_LEN] = "Unknown CPU Model";

    #ifdef __linux__
        // Linux: Grab the "Model name" line from /proc/cpuinfo and isolate the name.
        command_output("grep 'model name' /proc/cpuinfo | head -1 | cut -d ':' -f2 | sed 's/^[ \t]*//'", cpu_model, MAX_SPEC_LEN);

    #elif defined(__APPLE__)
        // macOS: Use sysctl command to get the CPU brand string.
        command_output("sysctl -n machdep.cpu.brand_string", cpu_model, MAX_SPEC_LEN);

    #else
        // Fallback for other systems
        strncpy(cpu_model, "Platform Not Supported", MAX_SPEC_LEN);
    #endif

    printf("CPU: %s \n", cpu_model);
}
// RAM/MEMORY DETAILS
void get_ram_details() {
	printf("Memory: %s \n", test);
}

// MOTHERBOARD (Baseboard Name)
void get_motherboard_details() {
    char motherboard[MAX_SPEC_LEN] = "Unknown";

    #ifdef __linux__
        // Linux: Attempt to read DMI info directly from the world-readable /sys files.
        // This is the preferred non-root method to get Baseboard Product Name.
        command_output("cat /sys/class/dmi/id/board_name", motherboard, MAX_SPEC_LEN);

        // Fallback: If board_name is empty or fails, try the vendor
        if (strcmp(motherboard, "Not found or No output") == 0) {
            command_output("cat /sys/class/dmi/id/board_vendor", motherboard, MAX_SPEC_LEN);
            // Prepend a label if we only found the vendor
            char vendor_only[MAX_SPEC_LEN];
            snprintf(vendor_only, MAX_SPEC_LEN, "Vendor: %s", motherboard);
            strncpy(motherboard, vendor_only, MAX_SPEC_LEN);
        }
    #elif defined(__APPLE__)
        // macOS: Use ioreg to find the board ID. This is a more specific identifier 
        // than the general machine model, making it a better proxy for the Motherboard.
        //command_output("ioreg -l | grep board-id | awk '{print $NF}' | tr -d '\"<>'", motherboard, MAX_SPEC_LEN);
    	//printf("Motherboard: ** coming soon for mac * * \n");

    #else
        strncpy(motherboard, "Platform Not Supported", MAX_SPEC_LEN);
    #endif

    printf("Motherboard: %s \n", motherboard);
}
// GRAPHICS CARD DETAILS IF ANY 
void get_graphics_details() {
	printf("GPU: %s \n", test);
}

// STORAGE
void get_storage_details() {
	printf("Storage %s \n", test);
}
// OPTICAL DRIVE
void get_optical_details() {
	printf("Optical: %s \n", test);
}
// AUDIO
void get_audio_details() {
	printf("Audio: %s \n", test);
}

/* 
----------------------------------------------------------------------------------------------------------------------------------/
----------------------------------------------------------------------------------------------------------------------------------/
 				SPECCY INSPIRED PC DETAILS   
----------------------------------------------------------------------------------------------------------------------------------/
----------------------------------------------------------------------------------------------------------------------------------/
*/

// Get user@hostname
void get_user_and_hostname() { 
	// set buffer for hostname and pointers for username
	char hostname[256];
	char *username = NULL;
	// 1. Get the username
    // getlogin() is usually sufficient for desktop applications
    username = getlogin();
    
    if (username == NULL) {
        username = "unknown_user";
    }
    // get the hostname
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        // Handle error by setting a fallback
        strcpy(hostname, "unknown_host");
    }

	printf("---------------------\n");
	printf("%s@%s \n" , username, hostname);
	printf("---------------------\n");
}

// GET ARCHITECTURE 
void get_arch_info() {
	printf("arch: %s\n", kername.machine);
}

// KERNEL INFO
void get_kernel_info() {
	printf("Kernel: %s\n", kername.release);
}

void get_kernel_version() {
	printf("Kernel Version: %s\n", kername.version);
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

// DESKTOP ENV
void get_desktop_env() {
	printf("DE: %s \n", test);
}
// Window Manage THEME
void get_window_manager() {
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
// GRAPHICS
void get_graphics() {
	printf("GPU: %s \n", test);
}
// RAM/MEMORY
void get_memory() {
	printf("Memory: %s \n", test);
}

// print hardware banner
void print_banner() { 
	printf("  \n");
	printf("-  Hardware Insights - \n"); 
	printf("----------------------\n"); 
} 

// print FULL banner
void print_full_banner() {
	printf("- FULL PC Specs - \n");
} 

void core_specs() {  
	print_banner();
	get_host_info();
	get_os_info();
	get_serial_number();
	get_model_number(); 
	get_cpu_details();
	get_ram_details();
	get_motherboard_details();
	get_graphics_details();
	get_storage_details();
	get_optical_details();
	get_audio_details();
	printf("\n");
}

// GET FULL DETAILS
void full_details() {
	print_full_banner();
	get_user_and_hostname();
	get_os_info();
	get_host_info();
	get_arch_info();
	get_kernel_info(); 
	get_uptime();
	get_packages();
	get_shell();
	get_resolution();
	get_desktop_env();
	get_window_manager();
	get_theme();
	get_icons();
	get_terminal();
	get_cpu();
	get_graphics();
	get_memory(); 
	core_specs();
	printf("\n");
}

// arg parsing functions 
void print_help() {
  	printf("Goggles is a system information tool written in C\n");
  	printf(" \n");
    printf("Usage: goggles [option]... \n");
    // printf("--c\tSave to clipboard\n");
    printf("--f\tPrint Full PC Details\n");
    printf("--h\tDisplay this help message\n");
  	printf(" \n");
  	printf("Report bugs: https://github.com/tedleyem/goggles/issues\n");
}

// clipboard function
void save_to_clipboard() {
    printf("Saving to clipboard...\n");
    // save content to the clipboard (platform-specific)
} 

int main(int argc, char *argv[]) {
	// 1. Check and call uname() at the start of main()
    if (uname(&kername) != 0) {
        perror("uname failed");
        return 1; // Exit if the function call fails
    }
    // Check if arguments are provided. 
	// argc (argument count) is 1 when only the program name is given (no options).
    if (argc > 1) {
		// Loop through each argument
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "--c") == 0) {
				save_to_clipboard();
			} else if (strcmp(argv[i], "--f") == 0) {
				full_details();
			} else if (strcmp(argv[i], "--h") == 0) {
				print_help();
			} else {
				printf("Unknown option: %s\n", argv[i]);
			}
		}
	}
	else {
		// If no argument run the default option
		core_specs();
	}
	return 0;
}

/*  TODO:
 
 // 

*/
