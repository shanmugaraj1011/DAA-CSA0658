#include <stdio.h>
#include <string.h>
void recursiveStrCopy(char *source, char *destination) {
    if (*source == '\0') {
        *destination = '\0';
        return;
    }
    *destination = *source; 
    recursiveStrCopy(source + 1, destination + 1);  
}

int main() {
    char source[100], destination[100];

    printf("Enter the source string: ");
    fgets(source, sizeof(source), stdin);
    size_t length = strlen(source);
    if (length > 0 && source[length - 1] == '\n') {
        source[length - 1] = '\0';
    }

    recursiveStrCopy(source, destination);

    printf("The copied string is: %s\n", destination);

    return 0;
}

