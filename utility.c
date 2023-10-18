nclude <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

int interactive(int readfd);
int is_delim(char c, const char *delim);
int _isalpha(int c);
int _atoi(char *s);

int main() {
    // Your main code goes here
    return 0;
}

int interactive(int readfd) {
    return (isatty(STDIN_FILENO) && readfd <= 2);
}

int is_delim(char c, const char *delim) {
    while (*delim)
        if (*delim++ == c)
            return 1;
    return 0;
}

int _isalpha(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int _atoi(char *s) {
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++) {
        if (s[i] == '-')
            sign *= -1;

        if (s[i] >= '0' && s[i] <= '9') {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        } else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return output;
}

