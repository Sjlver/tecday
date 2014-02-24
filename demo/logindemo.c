// TecDay Login

#include <stdio.h>
#include <unistd.h>
#include <string.h>

const char *SECRET = "youllneverguess";

int authorize() {
    char password[20];
    int c;
    int i = 0;

    printf("Enter Password: ");

    c = getchar();
    while (c != '\n' && c != EOF) {
        password[i] = c;
        i = i + 1;
        c = getchar();
    }
    password[i] = 0;

    return !strcmp(password, SECRET);
}

void start_shell() {
    execl("/bin/sh", "sh", (char*)0);
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
}
