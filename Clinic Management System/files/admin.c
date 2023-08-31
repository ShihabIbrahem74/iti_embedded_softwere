#include "main.h"
extern patient *arr_patient[25];
extern int counter;
/**
 * login - asks for password to log admin into the system
 * return: void
 */
void login(void)
{
    int Password;
    int trails = 3;
    printf("\nPlease Enter Your Password.\n");
    jump:
    scanf("%d", &Password);
    if (Password == 1234)
    {
        printf("\nPassword is Correct, Your are successfully logged in.\n");
        return;
    }
    else if (trails != 1)
    {
        trails--;
        printf("\nPassword is Wrong, YOU have %d trails left\n", trails);
        goto jump;
    }
    else
    {
        printf("\nPassword is Wrong, YOU have 0 trails left\nClosing System Now!!");
        exit (1);
    }
}

/**
 * features_picker - choose which feature you want to use
 * return: void
 */
void features_picker(void)
{
    int feature;
    patient *buffer;
    int n;
    again:
    printf("\nWhat do you want to do for today?\n\n[1]Add new patient record\n"
    "[2]Edit patient record.\n[3]Reserve a slot with the doctor.\n[4]Cancel reservation.\n"
    "[5]Show all records and reservations.\n[6]Return\n");
    jump:
    scanf("%d", &feature);
    switch (feature)
    {
        case 1:
        n = 1;
            while(n == 1)
            {
                buffer = new_patient();
                if (buffer){
                arr_patient[counter] = buffer;
                counter++;}
                printf("\nDo You want to add more record ?\n[1]YES    [0]NO");
                scanf("%d", &n);
            }
        break;
        case 2: edit_patient()  ;break;
        case 3: book_slot()     ;break;
        case 4: cancel_slot()   ;break;
        case 5: show_all()      ;break;
        case 6: return;         ;break;
        default: printf("\nPlease Enter a correct Number\n[1]Add new patient record\n"
    "[2]Edit patient record.\n[3]Reserve a slot with the doctor.\n[4]Cancel reservation.\n[5]Show all records.\n"
    "[6]Return.\n");
        goto jump; 
        break;
    }
    goto again;
}