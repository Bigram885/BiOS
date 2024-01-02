#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to display the text from the specified video buffer
void displayBuffer(char* buffer) {
    printf("%s", buffer);
}

// Function to get real-time in HH:MM format
void getRealTime(char* timeStr) {
    time_t currentTime;
    struct tm* localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);

    strftime(timeStr, 6, "%H:%M", localTime);
}

int main() {
    // Phase 1: Create video buffers
    char mainBuffer[] = "> ";
    char uCommandBuffer[] = "Unknown Command!";
    char clockBuffer[] = "Time: ";

    // Phase 2: Display text from Main buffer and handle user input
    char input[100];
    char userInput[100];
    int cursorPosition = 0;

    while (1) {
        displayBuffer(mainBuffer);

        for (int i = 0; i < cursorPosition; ++i) {
            printf(" ");
        }

        scanf("%s", input);

        if (strcmp(input, "Clock") == 0) {
            displayBuffer(clockBuffer);

            char timeStr[6];
            getRealTime(timeStr);

            printf("%s (%s)\n", timeStr, timeStr);
        } else {
            displayBuffer(uCommandBuffer);
        }

        // Handle cursor movement and Backspace
        for (int i = 0; i < strlen(input); ++i) {
            userInput[cursorPosition] = input[i];
            cursorPosition++;
        }

        userInput[cursorPosition] = '\0';
        cursorPosition = (cursorPosition > 2) ? 2 : cursorPosition;

        if (strcmp(input, "Backspace") == 0) {
            cursorPosition = (cursorPosition > 0) ? cursorPosition - 1 : cursorPosition;
        }
    }

    return 0;
}
