#include "tools/hint.h"
#include "tools/color.h"
#include <stdio.h>

static const char* BANNER = "\
\t __    __     ______     __  __     ______     __   __     ______\n\
\t/\\ \"-./  \\   /\\  __ \\   /\\ \\_\\ \\   /\\  __ \\   /\\ \"-.\\ \\   /\\  ___\\\n\
\t\\ \\ \\-./\\ \\  \\ \\ \\/\\ \\  \\ \\____ \\  \\ \\  __ \\  \\ \\ \\-.  \\  \\ \\ \\__ \\\n\
\t \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_\\\"\\_\\  \\ \\_____\\\n\
\t  \\/_/  \\/_/   \\/_____/   \\/_____/   \\/_/\\/_/   \\/_/ \\/_/   \\/_____/\n\
";

static const char* INVALID = "\
\t        _____     ____________    ________    ________    ________    ________      _____\n\
\t   _____\\    \\_  /            \\  /        \\  /        \\  /        \\  /        \\   /      |_\n\
\t  /     /|     ||\\___/\\  \\___/||\\         \\/          /||\\         \\/         /| /         \\\n\
\t /     / /____/| \\|____\\  \\___|/| \\            /\\____/ || \\            /\\____/ ||     /\\    \\\n\
\t|     | |____|/        |  |     |  \\______/\\   \\     | ||  \\______/\\   \\     | ||    |  |    \\\n\
\t|     |  _____    __  /   / __   \\ |      | \\   \\____|/  \\ |      | \\   \\____|/ |     \\/      \\\n\
\t|\\     \\|\\    \\  /  \\/   /_/  |   \\|______|  \\   \\        \\|______|  \\   \\      |\\      /\\     \\\n\
\t| \\_____\\|    | |____________/|            \\  \\___\\                \\  \\___\\     | \\_____\\ \\_____\\\n\
\t| |     /____/| |           | /             \\ |   |                 \\ |   |     | |     | |     |\n\
\t \\|_____|    || |___________|/               \\|___|                  \\|___|      \\|_____|\\|_____|\n\
\t        |____|/\n\
";

void welcomeMessage() {
    printf("\n%s%sWelcome to%s\n", BOLD, FRONT_RED, RESET);
    printf("%s%s%s%s\n", FRONT_BLUE, BOLD, BANNER, RESET);
    printf("%sThis is WinterCode Project for C-Beginners.%s\n\n", FRONT_PURPLR, RESET);
}

void invalidMessage() { 
    printf("\n%s%s%s\a\n\n", FRONT_RED, INVALID, RESET);
    printf("\n%s%sThis Function is Waiting For you to Implement ...%s\n\n", \
FRONT_RED, BOLD, RESET);
}