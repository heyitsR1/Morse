
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define s 52 //only for alphabets,punctuations, numbers

typedef struct {
    char * morse;
    char letter;
} Table;

Table morseTable[] = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, 
    {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, 
    {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'}, 
    {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'}, 
    {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'}, 
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, 
    {"-.--", 'Y'}, {"--..", 'Z'}, {"--..--", ','}, {".-.-.-", '.'}, 
    {"-.-.--", '!'}, {"-.-.-.", ';'}, {"---...", ':'},{"..--..", '?'},
    {"-....-", '-'},{"-..-.", '/'},{".--.-.", '@'},{".-.-.", '+'},
    {"-...-", '='},{".-...", '&'},{"-.--.", '('},{"-.--.-", ')'},
    {"-----", '0'}, {".----", '1'}, {"..---", '2'}, {"...--", '3'},
    {"....-", '4'}, {".....", '5'}, {"-....", '6'}, {"--...", '7'},
    {"---..", '8'}, {"----.", '9'}, {"-....-",'-'},{"/", ' '},
};
char morseToAlpha(char* in) {
    for (int i =0; i < s; i++) {
        if (strcmp(in,morseTable[i].morse) == 0) {
            return morseTable[i].letter;
        }
    }
    return '?';
}
char *alphaToMorse(char a) {
    for (int i =0; i < s; i++) {
        if (a == morseTable[i].letter) {
            return morseTable[i].morse;
        }
        //printf("%c %c",a,morseTable[i].letter);
    }
    return NULL;
}