#include "morse_crypt.h"

int main() {
    do_morse();
    exit(EXIT_SUCCESS);
}

void exception() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}

void validate_str(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if ((str[i] >= 97 && str[i] <= 122)) {
            str[i] = str[i] - 32;
        } else if ((str[i] < 48 && str[i] != 32 && str[i] != 9 && str[i] != 10) ||
                   (str[i] > 57 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122)) {
            exception();
        }
    }
}

void validate_morse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] != 32 && str[i] != 9 && str[i] != 10 && str[i] != 46 && str[i] != 45) {
            exception();
        }
    }
}

void input_str(char *str) { fgets(str, MAX_LEN_STR - 1, stdin); }

int input_mode() {
    int mode;
    scanf("%d\n", &mode);
    return mode;
}

void clear_str(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = 0;
    }
}

void decrypt() {
    char str[MAX_LEN_STR] = {0};
    input_str(str);
    validate_morse(str);
    int i = 0;
    int len = strlen(str);
    char morse_symbol[6] = {0};
    int counter = 0;
    while (i < len) {
        if (str[i] == ' ' || str[i] == '\t') {
            for (int j = 0; j < ALPHABET_COUNT; j++) {
                if (strcmp(morse_symbol, morse_dict[j].code) == 0) {
                    printf("%c", morse_dict[j].latin);
                    break;
                }
            }
            if (str[i] == '\t') {
                printf(" ");
            }
            i++;
            clear_str(morse_symbol);
            counter = 0;
        } else {
            morse_symbol[counter] = str[i];
            i++;
            counter++;
        }
    }
    if (counter != 0) {
        for (int j = 0; j < ALPHABET_COUNT; j++) {
            if (strcmp(morse_symbol, morse_dict[j].code) == 0) {
                printf("%c", morse_dict[j].latin);
                break;
            }
        }
    }
}
void encrypt() {
    char str[MAX_LEN_STR] = {0};
    input_str(str);
    validate_str(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            printf("\t");
            continue;
        }
        for (int j = 0; j < ALPHABET_COUNT; j++) {
            if (str[i] == morse_dict[j].latin) {
                printf("%s", morse_dict[j].code);
            }
        }
        if (i != len - 1 && str[i + 1] != ' ') {
            printf(" ");
        }
    }
}

void do_morse() {
    int mode = input_mode();
    switch (mode) {
        case 1:
            encrypt();
            break;
        case 2:
            decrypt();
            break;
        default:
            exception();
            break;
    }
}