#include "input.c"
#include "translate.c"
#include "output.c"
#include <string.h>
#include <ctype.h>

int main () 
{
    printf ("\n");
    printf("==============-- --- .-. ... .===============\n");
    printf("|           WELCOME TO PROJECT M!           |\n");
    printf("|         THE MORSE CODE TRANSLATOR!        |\n");
    printf("==============-.-. --- -.. .=================\n");
    printf("|  [m] Morse Code to English Alphabet       |\n");
    printf("|  [e] English Alphabet to Morse Code       |\n");
    printf("=====- .-. .- -. ... .-.. .- - --- .-.=======\n");
    printf("\n");
    
    char choice = getChoice();
    #define size 256
    char in [size];
    char out [size];
    
    if (choice == 'm') {
        getMorse(in,size);
        int len = strlen(in);
        printf("Your message in English: ");

        if (len > 0 && in [len-1]=='\n') {
            in[len-1] = '\0'; 
            } //removing new line character

        char* word = strtok(in," "); //tokenizing the string
        while (word != NULL) {
            char result = morseToAlpha(word);
            if (result != '?') {
                char r [2] = {result,'\0'}; //strcat or strncat can only concatinate strings so making a temporary one.
                strncat(out,r,1); //only the first character and spcae
                printf("%c", result);
            }
            else {
                strncat(out,"?(Invalid)",10); //invalid morse code is treated as ?  
                printf("ERROR! Invalid input detected \n"); //can opt to not print or print an error message
            }
            word = strtok(NULL, " ");
        }
    strcat (out, "\n");
    printf("\n");
    saveToFile("log.txt",in, out);

    } 
    else if (choice == 'e'){
        getLetter(in,size);
        int len = strlen(in);
        printf ("Your Message in Morse: ");
        if (len > 0 && in [len-1]=='\n') {
            in[len-1] = '\0'; 
        } //null termination
        char temp_in [size];
        strcpy(temp_in,in); //temporary buffer
        int word_count = 0;
        char *temp = strtok(temp_in, " ");
        while (temp != NULL) {
            word_count ++;
            temp = strtok (NULL, " ");
        }
        char* word = strtok(in," ");
        int words_processed = 0;
        while (word != NULL) {
            words_processed++;
            for (int i = 0; i < strlen(word); i++) {
                char* result = alphaToMorse(toupper(word[i]));
                if (result != NULL) {                   
                    printf ("%s ",result);
                    strncat(out, result, strlen(result));
                    strcat(out, " ");
                } else {
                    strcat(out, "? (Invalid)");
                    printf("invalid\n");
                    return 1;
                }
            }
        if (words_processed < word_count)   {
            strncat(out,"/ ",1);
            printf("%c ",'/');
        }  
        word = strtok(NULL," ");
    }
        strcat (out, "\n");
        printf("\n");
        saveToFile("log.txt",in, out);
    }
    else {
        return 1;
    }
    printf("Check the log.txt file for history and validity! \n");
    printf("\n");
    return 0;
}