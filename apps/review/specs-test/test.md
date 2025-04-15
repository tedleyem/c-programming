Creating a C program to display system and hardware specifications, similar to Speccy, and optionally copy the output to the system clipboard on macOS and Linux requires a few steps:

    Gathering system information using system calls or libraries.
    Displaying the information in a readable format.
    Using platform-specific methods to copy the output to the clipboard (e.g., xclip for Linux and pbcopy for macOS).

Below is an implementation of such a program in C:

Explanation:

    System Information:
        The program gathers system information using platform-specific commands:
            Linux: Uses uname, lscpu, free, and df commands to gather OS, CPU, memory, disk, and uptime.
            macOS: Uses sysctl to get system and CPU info and df for disk info.

    Copying to Clipboard:
        On Linux, it uses xclip to copy the system info to the clipboard.
        On macOS, it uses pbcopy to copy the system info to the clipboard.
        You must have either xclip installed on Linux or pbcopy available on macOS to use the clipboard functionality.

    Handling Command Line Arguments:
        The script accepts a single argument --copy. If passed, it copies the output to the system clipboard.

    Output:
        The program prints the system information in a human-readable format.
        If --copy is passed, it will also copy the output to the clipboard.

Building and Running:

    Save the Program:
        Save the C code to a file, for example system_info.c.

    Compile the Program:
        Use the following command to compile the C program:

gcc system_info.c -o system_info

Run the Program:

    To view system information:

./system_info

    To view system information and copy it to the clipboard:

    ./system_info --copy

Notes:

    Linux: Make sure xclip is installed. You can install it using sudo apt-get install xclip (for Ubuntu/Debian).
    macOS: The pbcopy command is available by default, so no additional installation is required.
    Permissions: The program uses popen() to execute shell commands and retrieve system information. Make sure the user running the program has sufficient permissions to execute these commands.

Let me know if you need further adjustments or explanations!