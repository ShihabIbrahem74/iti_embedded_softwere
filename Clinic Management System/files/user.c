#include "main.h"
extern patient *arr_patient[25];
extern int counter;

/**
 * features_picker - choose which feature you want to use
 * return: void
 */
void user_options(void)
{
    int feature;
    patient *buffer;
    int n;
    again:
    printf("\nWhat do you want to do for today?\n\n[1]Show your record and reservation.\n"
    "[2]Sign up as a new user.\n[3]Reserve a slot with the doctor.\n[4]Edit a reservation.\n[5]Cancel reservation.\n"
    "[6]Return\n");
    jump:
    scanf("%d", &feature);
    switch (feature)
    {
        case 1: hello_user()      ;break;
        case 2: 
            buffer = new_user() ;
            if (buffer)
            {
                arr_patient[counter] = buffer;
                counter++;
            }
            ;break;
        case 3: user_reserve()          ;break;
        case 4: user_edit_reserve()     ;break;
        case 5: cancel_slot()           ;break;
        case 6: return;                 ;break;
        default: printf("\nPlease Enter a correct Number\n[1]Show your record.\n"
    "[2]Sign up as a new user.\n[3]Reserve a slot with the doctor.\n[4]Edit a reservation.\n[5]Cancel reservation.\n"
    "[6]Return.\n");
        goto jump; 
        break;
    }
    goto again;
}
