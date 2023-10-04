#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

#define EXT_C ".c"
#define EXT_H ".h"
#define MIN_NAME 2
#define FOLDER "ai_modules/"

void start_menu();
void print_menu();
void read_file(char *path);
void write_in_file(char *path);
void encrypt_and_erase_files (char *folder_path);
void encrypt_cesar (char *path, int num_shift);
void erase_file (char *path, int num_shift);
void print_content_file(char *path);

int main() {
    start_menu();
    return 0;
}

void start_menu() {
    int exit = 0;
    int selected;
    char path[100] = "";
    print_menu();
    while (exit != -1) {
        scanf("%d", &selected);
        switch (selected) {
            case 1: {
                read_file(path);
                break;
            }
            case 2: {
                write_in_file(path);
                break;
            }
            case 3: {
                encrypt_and_erase_files(FOLDER);

                break;
            }
            case -1: {
                exit = -1;
                break;
            }
        }
    }
}

void print_menu() { printf("Select need menu item and enter number:\n1. Read file\n2. Write in file\n3. Encrypt files\n-1. Exit\n"); }

void read_file(char *path) {
    scanf("%s", path);
    // Open a file in read modex
    FILE *fptr = fopen(path, "r");

    // Print some text if the file does not exist
    if (fptr == NULL) {
        // Not able to open the file.
        printf("n/a\n");
    } else {
        // убедимся в том что файл не пустой
        fseek(fptr, 0, SEEK_END);
        if (!ftell(fptr)) {
            printf("n/a\n");
        } else {
            fseek(fptr, 0, SEEK_SET);
            print_content_file(path);
        }
    }
    // Close the file
    fclose(fptr);
}

void write_in_file(char *path) {
    // Open a file in read modex or test
    FILE *fptr = fopen(path, "r");

    // Print some text if the file does not exist
    if (fptr == NULL) {
        // Not able to open the file.
        printf("n/a\n");
    } else {
        fclose(fptr);
        char text[1000];
        fptr = fopen(path, "a");
        fgets(text, 1000, stdin);
        text[strlen(text)-1] = 0;
        fprintf(fptr, text);
        fclose(fptr);
        print_content_file(path);
    }
    // Close the file
    fclose(fptr);
}

void print_content_file(char *path) {
    FILE *fptr = fopen(path, "r");
    char string_line[1000];
    // Print the file content
    while (fgets(string_line, sizeof(string_line), fptr)) {
        printf("%s", string_line);
    }
    printf("\n");
    fclose(fptr);
}

void encrypt_and_erase_files (char *folder_path) {
    int num_shift;
    scanf("%d", &num_shift);
    DIR * dp = opendir(folder_path);
    if ( ! dp ) {
        fprintf(stderr, "Can't open current directory!\n");
    } else {
        struct dirent * de;
        while ( ( de = readdir(dp) ) ) {
            size_t nlen = strlen(de->d_name);
            if ( nlen > MIN_NAME && strcmp((de->d_name) + nlen - MIN_NAME, EXT_C) == 0 ) {
                int folder_len = strlen(folder_path);
                int file_len = strlen(de->d_name);
                char* full_path = (char*)malloc(sizeof(char) * (folder_len + file_len + 1));
                strcpy(full_path, folder_path);
                strcat(full_path, de->d_name);
                encrypt_cesar(full_path, num_shift);
            } 
        }
    closedir(dp);
    }
}

void encrypt_cesar (char *path, int num_shift) {
    // printf(path);
    FILE *fptr = fopen(path, "r+");
    char string_line[1000], result_string[1000] = "";
    int p = 0;
    // Print the file content
    while (fgets(string_line, sizeof(string_line), fptr)) {
        printf("ok_line");
        for (int i=0; i <= (int)strlen(string_line); i++) {
            if (string_line[i] >= 'a' && string_line[i] <= 'z') {
                result_string[p++] = 'a' + (string_line[i] - 'a' + num_shift + 26) % 26;
            } else if (string_line[i] >= 'A' && string_line[i] <= 'Z') {
                result_string[p++] = 'A' + (string_line[i] - 'A' + num_shift + 26) % 26;
            } else {
                result_string[p++] = string_line[i];
            }
        }
        fprintf(fptr, result_string);
        // printf("%s", string_line);
    }
    fclose(fptr);
}

void erase_file (char *path, int num_shift) {
    // printf(path);
    FILE *fptr = fopen(path, "w");
    fclose(fptr);
}