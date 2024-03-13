#ifndef MORSE_CRYPT_H
#define MORSE_CRYPT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_COUNT 36
#define CEILS 2
#define MAX_LEN_STR 1025

typedef struct MorseDict {
    char *code;
    char latin;
} MorseDict;

static MorseDict morse_dict[ALPHABET_COUNT] = {
    {".-", 'A'},    {"-...", 'B'},  {"-.-.", 'C'},  {"-..", 'D'},   {".", 'E'},     {"..-.", 'F'},
    {"--.", 'G'},   {"....", 'H'},  {"..", 'I'},    {".---", 'J'},  {"-.-", 'K'},   {".-..", 'L'},
    {"--", 'M'},    {"-.", 'N'},    {"---", 'O'},   {".--.", 'P'},  {"--.-", 'Q'},  {".-.", 'R'},
    {"...", 'S'},   {"-", 'T'},     {"..-", 'U'},   {"...-", 'V'},  {".--", 'W'},   {"-..-", 'X'},
    {"-.--", 'Y'},  {"--..", 'Z'},  {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'},
    {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}};

void exception();
void validate_str(char *str);
void validate_morse(char *str);
void clear_str(char *str);
void input_str(char *str);
int input_mode();
void decrypt();
void encrypt();
void do_morse();

#endif