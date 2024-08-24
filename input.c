#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char getChoice () {
    char choice;
    printf ("Translate (m/e): ");
    scanf ("%c", &choice);
    getchar(); //removes new line character which interfered 
    choice = tolower(choice);
    if (choice == 'm' || choice == 'e') {
        return choice;
    } else {
        printf ("Invalid Input! \n");
        return '\0';
    }
}
void getMorse (char* input, int size) {
    printf ("\nMorse is written with dots (.) and dashes (-).\nUse a space ( ) for seperation between letters.\nUse a slash (/) for seperation between words\n\n");
    printf ("Usage: .... . .-.. .-.. --- / .-- --- .-. .-.. -..\n");
    printf ("Translates to: HELLO WORLD\n\n");
    printf ("Your Morse code: ");
    fgets (input, size-1,stdin);
}
void getLetter (char* input, int size) {
    char* temp_buffer = malloc (2*size*sizeof(char));
    if (temp_buffer == NULL) {
        printf("Memory Allocation Failed! \n");
        exit (1);
    }
    printf ("Your Message in English: ");
    //defensively doubling the input handling
    //To DO: improve input handling to prevent buffer overflow
    fgets (temp_buffer, 2*(size-1),stdin);
    if (strlen(temp_buffer) >=  size - 1) {
        printf ("Input was too long! Shortened to %d characters!",size-1);
        strncpy(input, temp_buffer,size);
        input [size-1] = '\0';
    } else {
    strncpy(input, temp_buffer,size);
    }
    free(temp_buffer);
    
    // printf ("Your English letters: ");
    // fgets (input, size-1,stdin);
}
