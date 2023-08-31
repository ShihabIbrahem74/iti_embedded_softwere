#include "main.h"
/**
 * choose_mode - choose wether admin or user
 * return: The selected mode.
 */
int choose_mode(void)
{
    int mode;
	int c;
    printf("Hello Sir\nPlease Enter Number To choose your mode:\nADMIN:[0].     USER:[1].\n");
    jump:
    scanf("%d", &mode); 
    while ((c = getchar()) != '\n' && c != EOF);
    
    switch(mode)
    {
        case 0: printf("Hello ADMIN, "); break;
        case 1: printf("Hello USER. \n"); break;
        default: printf("Please Enter a valid Number 0 or 1.\nADMIN:[0].     USER:[1].\n");goto jump; break;
    }
    return (mode);
}