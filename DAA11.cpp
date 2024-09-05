#include <stdio.h>
#include <string.h>

int main() {
    char source[100], destination[100];
    
    printf("Enter the source string: ");
    scanf("%s", source);
    
    strcpy(destination, source);
    
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    
    return 0;
}

