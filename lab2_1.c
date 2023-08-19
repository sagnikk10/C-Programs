#include<stdio.h>

// Recursive function to convert decimal to binary
void decToBin(int decimal, FILE *outputFile) {
    if (decimal > 0) {
        decToBin(decimal / 2, outputFile);
        fprintf(outputFile, "%d", decimal % 2);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int n, val, i;

    inputFile = fopen("lab2_in1.dat", "r");
    if (!inputFile) {
        printf("Error opening input file\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);
    printf("\nn = %d", n);

    outputFile = fopen("lab2_out1.dat", "w");
    if (!outputFile) {
        printf("Error creating output file\n");
        fclose(inputFile);
        return 1;
    }

    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &val);
        printf("\na[%d] = %d", i, val);

        fprintf(outputFile, "The binary equivalent of %d is ", val);
        decToBin(val, outputFile);
        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}