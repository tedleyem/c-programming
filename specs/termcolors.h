#include <stdio.h>
/*
 ASCI terminal colors by definition
 source: https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
-------------
FG  BG  COLOR
-------------
30	40	Black
31	41	Red
32	42	Green
33	43	Yellow
34	44	Blue
35	45	Magenta
36	46	Cyan
37	47	White
90	100	Gray
91	101	Bright Red
92	102	Bright Green
93	103	Bright Yellow
94	104	Bright Blue
95	105	Bright Magenta
96	106	Bright Cyan
97	107	Bright White
*/

// Foreground colors
#define FG_BLACK   "\x1b[30m"
#define FG_RED     "\x1b[31m"
#define FG_GREEN   "\x1b[32m"
#define FG_YELLOW  "\x1b[33m"
#define FG_BLUE    "\x1b[34m"
#define FG_MAGENTA "\x1b[35m"
#define FG_CYAN    "\x1b[36m"
#define FG_WHITE   "\x1b[37m"
#define FG_GRAY   "\x1b[90m"
#define FG_BRIGHT_RED   "\x1b[91m"
#define FG_BRIGHT_GREEN   "\x1b[92m"
#define FG_BRIGHT_YELLOW   "\x1b[93m"
#define FG_BRIGHT_BLUE   "\x1b[94m"
#define FG_BRIGHT_MAGENTA   "\x1b[95m"
#define FG_BRIGHT_CYAN   "\x1b[96m"
#define FG_BRIGHT_WHITE   "\x1b[97m"
#define FG_RESET   "\x1b[0m"
// Background colors
#define BG_BLACK   "\x1b[30m"
#define BG_RED     "\x1b[31m"
#define BG_GREEN   "\x1b[32m"
#define BG_YELLOW  "\x1b[33m"
#define BG_BLUE    "\x1b[34m"
#define BG_MAGENTA "\x1b[35m"
#define BG_CYAN    "\x1b[36m"
#define BG_WHITE   "\x1b[37m"
#define BG_GRAY   "\x1b[90m"
#define BG_BRIGHT_RED   "\x1b[91m"
#define BG_BRIGHT_GREEN   "\x1b[92m"
#define BG_BRIGHT_YELLOW   "\x1b[93m"
#define BG_BRIGHT_BLUE   "\x1b[94m"
#define BG_BRIGHT_MAGENTA   "\x1b[95m"
#define BG_BRIGHT_CYAN   "\x1b[96m"
#define BG_BRIGHT_WHITE   "\x1b[97m"
#define BG_RESET   "\x1b[0m"