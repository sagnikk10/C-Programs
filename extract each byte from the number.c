#include <stdio.h>

int main() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    // Extract each byte from the number
    unsigned char byte1 = (num >> 24) & 0xFF;
    unsigned char byte2 = (num >> 16) & 0xFF;
    unsigned char byte3 = (num >> 8) & 0xFF;
    unsigned char byte4 = num & 0xFF;

    // Print the content of the variables
    printf("Byte 1: %c\n", byte1);
    printf("Byte 2: %c\n", byte2);
    printf("Byte 3: %c\n", byte3);
    printf("Byte 4: %c\n", byte4);

    return 0;
}