#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }


    int sum = 0;
    int score = 0;

    char buffer[256];
    while(fgets(buffer,sizeof(buffer),fp) != NULL) {
        int i=0;
        int judge=1;
        while(buffer[i] != '\n') {
            if(!(buffer[i] >= '0' && buffer[i] <= '9')) {
                judge = 0;
                break;
            }
            i++;
        }
        if(judge == 0) fprintf(stderr, "invalid input %s",buffer);
        else sum += atoi(buffer);
    }


    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
