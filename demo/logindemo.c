// TecDay Login

#include <stdio.h>
#include <unistd.h>
#include <string.h>

const char *SECRET = "youllneverguess";

void start_shell() {
    printf("Have a lot of fun!\n");
    execl("/bin/sh", "sh", "-i", (char*)0);
    printf("After execl...\n");
}

void read_password(char *password) {
    int c;
    int i = 0;

    c = getchar();
    while (c != '\n' && c != EOF) {
        password[i] = c;
        i = i + 1;
        c = getchar();
    }
    password[i] = 0;
}

int authorize() {
    char password[16];

    printf("Enter Password: ");
    read_password(password);

    return !strcmp(password, SECRET);
}

int main() {
    printf("Welcome to TecDay Login\n");

    if (authorize()) {
        printf("Login successful\n");
        start_shell();
    } else {
        printf("Login failed\n");
        return 1;
    }

    return 0;
}
