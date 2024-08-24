#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int saveToFile(char* name, char* input, char* output) {
    FILE* file = fopen(name, "a");
    if (file == NULL) {
        return 1;
    }
    // Get time, lots of abstractions here but it gets time in s then converts to a readable format
    time_t rawt;
    struct tm * tinfo; //to hold
    time(&rawt); //in seconds
    tinfo = localtime(&rawt); //readable format


    fprintf(file, "Time: %s \n Input: %s \n Output: %s", asctime(tinfo),input,output);
    fprintf(file, "====================\n");
    fclose(file);
    return 0;
}