#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
#include <unistd.h>
#include <sys/utsname.h>
#elif __APPLE__
#include <sys/sysctl.h>
#endif

void get_system_info() {
    printf("System Information:\n");

    // OS and Kernel Version
    #ifdef __linux__
    struct utsname sys_info;
    if (uname(&sys_info) == 0) {
        printf("OS: %s\n", sys_info.sysname);
        printf("Kernel Version: %s\n", sys_info.release);
    } else {
        perror("Error getting system information");
    }
    #elif __APPLE__
    char buffer[256];
    size_t size = sizeof(buffer);
    sysctlbyname("kern.ostype", buffer, &size, NULL, 0);
    printf("OS: %s\n", buffer);

    sysctlbyname("kern.osrelease", buffer, &size, NULL, 0);
    printf("Kernel Version: %s\n", buffer);
    #endif

    // CPU Information
    #ifdef __linux__
    printf("CPU: ");
    system("lscpu | grep 'Model name' | cut -d ':' -f2");

    #elif __APPLE__
    sysctlbyname("machdep.cpu.brand_string", buffer, &size, NULL, 0);
    printf("CPU: %s\n", buffer);
    #endif

    // Memory Information
    #ifdef __linux__
    printf("Memory: ");
    system("free -h | grep Mem | awk '{print $2, $3, $4}'");

    #elif __APPLE__
    sysctlbyname("hw.memsize", buffer, &size, NULL, 0);
    printf("Memory: %s bytes\n", buffer);
    #endif

    // Disk Information
    #ifdef __linux__
    printf("Disk: ");
    system("df -h --total | grep total | awk '{print $2, $3, $4}'");

    #elif __APPLE__
    system("df -h | grep '/dev/disk1' | awk '{print $2, $3, $4}'");
    #endif

    // Uptime
    printf("Uptime: ");
    system("uptime -p");
}

// Function to copy the result to clipboard
void copy_to_clipboard(const char *result) {
    FILE *fp;
    #ifdef __linux__
    // Using xclip for Linux
    fp = popen("xclip -selection clipboard", "w");
    if (fp != NULL) {
        fprintf(fp, "%s", result);
        fclose(fp);
    } else {
        printf("Failed to copy to clipboard. Make sure xclip is installed.\n");
    }
    #elif __APPLE__
    // Using pbcopy for macOS
    fp = popen("pbcopy", "w");
    if (fp != NULL) {
        fprintf(fp, "%s", result);
        fclose(fp);
    } else {
        printf("Failed to copy to clipboard. Make sure pbcopy is available.\n");
    }
    #endif
}

int main(int argc, char *argv[]) {
    // Allocate buffer to store system info output
    char sys_info_output[2048] = {0};

    // Check if we should copy to clipboard
    int copy_flag = 0;
    if (argc == 2 && strcmp(argv[1], "--copy") == 0) {
        copy_flag = 1;
    }

    // Capture system info and store it
    FILE *fp = popen("bash -c 'echo \"System Info:\n\"; "
                     "echo \"----------------------\"; "
                     "lscpu | grep \"Model name\" | cut -d \":\" -f2; "
                     "free -h | grep Mem | awk \"{print $2, $3, $4}\"; "
                     "df -h --total | grep total | awk \"{print $2, $3, $4}\"; "
                     "uptime -p;'", "r");

    if (fp == NULL) {
        perror("popen");
        return 1;
    }

    // Read and store output in sys_info_output
    size_t len;
    while ((len = fread(sys_info_output, 1, sizeof(sys_info_output) - 1, fp)) > 0) {
        sys_info_output[len] = '\0';
    }

    fclose(fp);

    // Print the system info
    printf("%s", sys_info_output);

    // If --copy argument is passed, copy to clipboard
    if (copy_flag) {
        copy_to_clipboard(sys_info_output);
        printf("\nSystem info copied to clipboard!\n");
    }

    return 0;
}
