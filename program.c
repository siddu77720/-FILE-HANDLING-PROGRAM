#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(fp);
}

void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    char data[100];
    printf("Enter data to write to the file: ");
    getchar(); // Clear buffer
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    printf("Data written successfully.\n");
    fclose(fp);
}

void appendFile(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }
    char data[100];
    printf("Enter data to append to the file: ");
    getchar(); // Clear buffer
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    printf("Data appended successfully.\n");
    fclose(fp);
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    char ch;
    printf("Contents of the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

int main() {
    char filename[50];
    int choice;

    printf("Enter filename to operate on: ");
    scanf("%s", filename);

    do {
        printf("\nFile Handling Menu:\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Append to File\n");
        printf("4. Read File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createFile(filename); break;
            case 2: writeFile(filename); break;
            case 3: appendFile(filename); break;
            case 4: readFile(filename); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
