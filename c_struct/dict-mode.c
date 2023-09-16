#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <time.h>

int main(void) {  
    char word[100];  
    char dir[100];  
    time_t currentTime;  
    struct tm *localTime;  
    char date[20]; // YYYY-MM-DD  
    time(&currentTime);  
    localTime = localtime(&currentTime);  
    strftime(date, sizeof(date), "%Y-%m-%d", localTime);  
    sprintf(dir, "~/word/%s", date);
    FILE *file = fopen(&dir[0],"r");
    if (file == NULL)
      {
	char command[130];
	sprintf(command, "touch %s", dir);
	system(command);
      }
    fclose(file);
    while (1) {  
        printf("Please enter your word: ");  
        scanf("%s", word);  
          
        if (strcmp(word, "exit") == 0) {  
            break;  
        }  
          
        char command[300];  
        sprintf(command, "dict %s", word);  
        system(command);  
        sprintf(command, "dict %s >> %s", word, dir);  
        system(command);  
    }  
      
    return 0;  
}
