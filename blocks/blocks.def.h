// blocks.h

// Define the structure for a block
typedef struct {
    char *icon;     // optional icon/text
    char *command;  // shell command to run
    int interval;   // in seconds (0 = once)
    int signal;     // signal number for manual update
} Block;

// Define the blocks to show in the status bar
static const Block blocks[] = {
    { " \uf028 ", "pamixer --get-volume-human", 1, 10 },                     // Volume 🔊
    { "\uf2c9 ", "sensors | awk '/Package id 0:/ {print $4}'", 5, 11 },     // Temperature 🌡️
    { "\uf185 ", "brightnessctl | awk '/Current/ {print $4}' | tr -d '()'", 5, 12 }, // Brightness ☀️
    { "\uf017 ", "date '+%a %b %d %I:%M %p '", 10, 13 },                     // Clock 🕒
};

#define DELIMITER " | "
#define DELIMITERENDLEN 3

