#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[] = "names.txt";
    char buffer[1000]; // Adjust the buffer size as needed

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Read and print the file contents line by line
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(fp);

    return 0;
}
