#include <string.h>
#include <stdio.h>  
#include <time.h>  
  
int main() {  
    time_t currentTime;  
    struct tm *localTime;  
    char date[11]; // YYYY-MM-DD  
    time(&currentTime);  
    localTime = localtime(&currentTime);  
    strftime(date, sizeof(date), "%Y-%m-%d", localTime);  
  
    // Print the date  
    printf("The current date is: %s\n", date);  
  
    // Assign the date to variable 'a' (Assuming 'a' is a char array)  
    char a[9];  
    strcpy(a, date);  
  
    printf("The value of 'a' is: %s\n", a);  
  
    return 0;  
}
