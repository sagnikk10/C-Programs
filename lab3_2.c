#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n, int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void readFile(const char *filename, int arr[], int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    *n = 0;
    while (fscanf(file, "%d", &arr[*n]) != EOF) {
        (*n)++;
    }
    
    fclose(file);
}

void writeFile(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    
    fclose(file);
}

int main() {
    while (1) {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        
        int choice;
        printf("Enter option: ");
        scanf("%d", &choice);
        
        const char *inputFilename, *outputFilename;
        
        switch (choice) {
            case 1:
                inputFilename = "inAsce.dat";
                outputFilename = "outInsAsce.dat";
                break;
            case 2:
                inputFilename = "inDesc.dat";
                outputFilename = "outInsDesc.dat";
                break;
            case 3:
                inputFilename = "inRand.dat";
                outputFilename = "outInsRand.dat";
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                continue;
        }
        
        int arr[500];
        int n;
        readFile(inputFilename, arr, &n);
        
        printf("Before Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        int comparisons = 0;
        insertionSort(arr, n, &comparisons);
        
        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nNumber of Comparisons: %d\n", comparisons);
        
        writeFile(outputFilename, arr, n);
        printf("Sorted data has been written to %s\n", outputFilename);
        
        if (comparisons == 0) {
            printf("Scenario: Best-case\n");
        } else {
            printf("Scenario: Worst-case\n");
        }
        
        printf("\n");
    }

    return 0;
}