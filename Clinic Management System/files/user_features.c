#include "main.h"
extern patient *arr_patient[25];
extern int counter;
extern slot *slots[15];

/** hello_user - welcomes the user 
 * return: void
 */
void hello_user(void)
{
    int id;
    int flag = 1;
    int flag_slot = 1;
    printf("Hello User, Please Enter your ID :\n");
    scanf("%d", &id);
    for (int x = 0; x < counter; x++) //loop to search for id
    {
        if (id == arr_patient[x]->id)
        {
            printf("Hello %s %s\n"
            "ID: %d\nAge :%d\nGender: %s\n",(arr_patient[x]->gender == 1)?"Mr/":"Ms/", arr_patient[x]->name,arr_patient[x]->id,arr_patient[x]->age,
            (arr_patient[x]->gender == 1)?"Male":"Female");
            flag = 0;
        }
    }
    if(flag)
    {
        printf("Incorrect ID.... Returning to main menu now!\n");
        return;
    }
    for (int i = 0; i < 15; i++)
    {
        if (slots[i]->id == id)
        {
            printf("You have a %s appointment at %s\n", slots[i]->day, slots[i]->hours);
            flag_slot = 0;
        }
    }
    if(flag_slot)
    {
        printf("You don't have any appointments with the doctor\n");
        return;
    }
}

/**
 * new_user - add new patient record
 * return: void
 */
patient *new_user(void)
{
    patient *ptr = malloc(sizeof(patient));
    ptr->gender = 0;
    again:
    printf("Please choose an ID for you: ");
    scanf("%d", &ptr->id);
    for (int x = 0; x < counter; x++) //loop to search for id
    {
        if (ptr->id == arr_patient[x]->id)
        {
            printf("This ID is already registered, Please choose another one.\n");
            goto again;
        }
    }
    printf("Please Enter your Name: ");
    getchar();
    scanf("%[^\n]", ptr->name);
    printf("Please Enter your age: ");
    scanf("%d", &ptr->age);
    printf("Please choose your gender:\n[1]Male   [0]Female");
    jump:
    scanf("%d", &ptr->gender);
    if (ptr->gender != 0 && ptr->gender != 1)
    {printf("Please Type in an EXISTING Gender\n[1]Male   [0]Female"); goto jump;}
    return (ptr);
}

/**
 * user_reserve - unable the user to reserve a slot
 * return void
 */

void user_reserve(void)
{
    int id;
    int flag = 1;
    int id_index;
    int day_choose;
    int days_index;
    int hour_choose;
    
    printf("\nPlease Enter Your ID.\n");
    scanf("%d", &id);
    for (int x = 0; x < counter; x++) //loop to search for id
    {
        if (id == arr_patient[x]->id)
        {
            flag = 0;
            id_index = x;
            break;
        }
    }
    if(flag)
    {
        printf("\nThis ID doesn't exist, Please Signup a new user first.\nReturning to main menu now...\n");
        return;
    }
    printf("Hello %s %s\n",(arr_patient[id_index]->gender == 1)?"Mr/":"Ms/", arr_patient[id_index]->name);
    
    for (int i = 0; i < 15; i++)
    {
        if (slots[i]->id == id)
        {
            printf("You already have a %s appointment at %s\nYou can't reserve two slots within the same"
            " week.\nReturning to main menu now.\n", slots[i]->day, slots[i]->hours);
            return;
        }
    }
    
    printf("Please Choose a day\n");
    for (int i = 0; i < 15; i+=5) 
        printf("[%d]%s.\n", (i / 5) + 1, slots[i]->day);
    jump_days:
    scanf("%d", &day_choose);
    if (day_choose > 3 || day_choose < 1)
    {
        printf("\nPlease Choose a correct Day.\n");
        goto jump_days;
    }
    switch (day_choose)
    {
        case 1: days_index = 0; break;
        case 2: days_index = 5; break;
        case 3: days_index = 10; break;
    }
    jump_hours2:
    for (int i = days_index; i < days_index + 5; i++)
    {
        if (slots[i]->id == -54321)
            printf("[%d]%s.\n", i, slots[i]->hours);
    }
    jump_hours:
    scanf("%d", &hour_choose);
    if (hour_choose < days_index || hour_choose > (days_index + 4))
    {
        printf("\nPlease Choose a correct hour.\n");
        goto jump_hours;
    }
    if (slots[hour_choose]->id != -54321)
    {
        printf("This Slot is already registered, please choose only from these slots\n");
        goto jump_hours2;
    }
    slots[hour_choose]->id = id;
    printf("\nRegistering Done. Returning to main menu now.\n");
}

/**
 * user_edit_reserve - edit the user reservetion
 * return void
 */
void user_edit_reserve(void)
{
    int id;
    int id_index;
    int flag = 1;
    int flag_slot = 1;
    int confirm;
    int slot_index;
    int day_choose;
    int days_index;
    int hour_choose;
    
    printf("\nPlease Enter Your ID.\n");
    scanf("%d", &id);
    for (int x = 0; x < counter; x++) //loop to search for id
    {
        if (id == arr_patient[x]->id)
        {
            flag = 0;
            id_index = x;
            break;
        }
    }
    if(flag)
    {
        printf("\nThis ID doesn't exist.\nReturning to main menu now...\n");
        return;
    }
    printf("Hello %s %s\n",(arr_patient[id_index]->gender == 1)?"Mr/":"Ms/", arr_patient[id_index]->name);
    
    for (int i = 0; i < 15; i++)
    {
        if (slots[i]->id == id)
        {
            printf("You already have a %s appointment at %s\nAre you sure You want to edit it?\n"
            "[1]Yes     [0]No\n", slots[i]->day, slots[i]->hours);
            flag_slot = 0;
            slot_index = i;
        }
    }
    
    if(flag_slot)
    {
        printf("You don't have any registered appointments with the doctor\nReturning to main menu now.");
        return;
    }
    jump_cancel:
    scanf("%d", &confirm);
    if (confirm != 1 && confirm != 0)
    {
        printf("\nPlease Type either [1] to confirm edititng or [0] to back.\n");
        goto jump_cancel;
    }
    if (confirm == 0)
        return;
    slots[slot_index]->id = -54321;
    
    printf("Please Choose a day\n");
    for (int i = 0; i < 15; i+=5) 
        printf("[%d]%s.\n", (i / 5) + 1, slots[i]->day);
    jump_days:
    scanf("%d", &day_choose);
    if (day_choose > 3 || day_choose < 1)
    {
        printf("\nPlease Choose a correct Day.\n");
        goto jump_days;
    }
    switch (day_choose)
    {
        case 1: days_index = 0; break;
        case 2: days_index = 5; break;
        case 3: days_index = 10; break;
    }
    jump_hours2:
    for (int i = days_index; i < days_index + 5; i++)
    {
        if (slots[i]->id == -54321)
            printf("[%d]%s.\n", i, slots[i]->hours);
    }
    jump_hours:
    scanf("%d", &hour_choose);
    if (hour_choose < days_index || hour_choose > (days_index + 4))
    {
        printf("\nPlease Choose a correct hour.\n");
        goto jump_hours;
    }
    if (slots[hour_choose]->id != -54321)
    {
        printf("This Slot is already registered, please choose only from these slots\n");
        goto jump_hours2;
    }
    slots[hour_choose]->id = id;
    printf("\nRegistering Done. Returning to main menu now.\n");
}