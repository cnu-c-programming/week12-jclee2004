#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE * fp = fopen("config.txt","r");
    
    char buffer[256];
    char * ptr[4];
    char * ptr2;
    for(int i=0;i<4;i++) {
        fgets(buffer, sizeof(buffer), fp);
        ptr2 = strchr(buffer,'=')+1;
        switch(i) {
            case 0:
                ptr2[strlen(ptr2) - 1] = '\0';
                strcpy(config_ptr->InputFileName,ptr2);
                break;
            case 1:
                config_ptr->Options = atoi(ptr2);
                break;
            case 2:
                ptr2[strlen(ptr2) - 1] = '\0';
                strcpy(config_ptr->SectionName,ptr2);
                break;
            case 3:
                config_ptr->Address = (unsigned long long)strtol(ptr2,NULL,16);
                break;
        }
        
    }
    fclose(fp);
    
}

int main(int argc, const char* argv[]) {
    Config config;  
    config_parser(&config);

    printf("config: %s %d %s %llu\n", 
        config.InputFileName, 
        config.Options,
        config.SectionName,
        config.Address);
    return 0;
}

