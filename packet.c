#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    struct pkt packet;
    unsigned int num;

    printf("Enter a number: ");
    scanf("%u", &num);

    // Store the number across the structure
    packet.ch1 = (num >> 16) & 0xFF;
    packet.ch2[0] = (num >> 8) & 0xFF;
    packet.ch2[1] = num & 0xFF;
    packet.ch3 = (num >> 24) & 0xFF;

    // Print the content of each member of the structure
    printf("ch1: %c\n", packet.ch1);
    printf("ch2: %c%c\n", packet.ch2[0], packet.ch2[1]);
    printf("ch3: %c\n", packet.ch3);

    // Aggregate each member of the structure to form the original number
    num = ((unsigned int)packet.ch3 << 24) | ((unsigned int)packet.ch1 << 16) | ((unsigned int)packet.ch2[0] << 8) | packet.ch2[1];

    // Print the original number
    printf("Original number: %u\n", num);

    return 0;
}