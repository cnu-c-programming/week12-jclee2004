#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");

    if(fp==NULL) return 0;

    int c;
    char ch;
    char alphabet[26] = {}; 
    while ((c = fgetc(fp)) != EOF)
    {
        alphabet[c-'a'] += 1;
    }
    for(int i=0;i<26;i++) {
        printf("%c: %d\n",'a'+i,alphabet[i]);
    }
    fclose(fp);
}

