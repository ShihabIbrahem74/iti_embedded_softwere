#include "main.h"
extern patient *arr_patient[25];
extern int counter;
extern slot *slots[15];
/**
 * new_patient - add new patient record
 * return: void
 */
patient *new_patient(void)
{
    patient *ptr = malloc(sizeof(patient));
    ptr->gender = 0;
    printf("\nPlease Enter The patient ID: ");
    scanf("%d", &ptr->id);
    for (int x = 0; x < counter; x++) //loop to search for id
    {
        if (ptr->id == arr_patient[x]->id)
        {
            printf("\nThis ID is already registered\n");
            free(ptr);
            return (NULL);
        }
    }
    printf("\nPlease Enter The patient Name: ");
    getchar();
    scanf("%[^\n]", ptr->name);
    printf("Please Enter The patient age: ");
    scanf("%d", &ptr->age);
    printf("Please Enter The patient gender:\n[1]Male   [0]Female");
    jump:
    scanf("%d", &ptr->gender);
    if (ptr->gender != 0 && ptr->gender != 1)
    {printf("Please Type in an EXISTING Gender\n[1]Male   [0]Female"); goto jump;}
    return (ptr);
}

/**
 * edit_patient - to edit registered record
 * return void
 */
void edit_patient(void)
{
    int id;
    int flag = 1;
    printf("\nPlease Enter The patient ID: ");
    scanf("%d", &id);
    for (int x = 0; x < counter; x++) //loop to search for id
    {
        if (id == arr_patient[x]->id)
        {
            printf("patient old name: %s\nPlease Enter New name: ",arr_patient[x]->name);
            getchar();
            scanf("%[^\n]", arr_patient[x]->name);
            printf("patient old Age: %d\nPlease Enter New Age: ",arr_patient[x]->age);
            scanf("%d", &arr_patient[x]->age);
            flag = 0;
        }
    }
    if(flag)
    {
        printf("\nIncorrect ID.... Returning to main menu now!\n");
        return;
    }
}

void book_slot(void)
{
    int id;
    int flag = 1;
    int id_index;
    int day_choose;
    int days_index;
    int hour_choose;
    
    printf("\nPlease Enter Patient ID.\n");
    scanf("%d", &id);
    for (int x = 0; x < counter; x++) //loop to search for id
    {
        if (id == arr_patient[x]->id)
        {
            flag = 0;
            id_index = x; //Stores the struct which matches the id
            break;
        }
    }
    if(flag)
    {
        printf("\nThis ID doesn't exist, Please Signup the patient first.\nReturning to main menu now...\n");
        return;
    }
    printf("Patient Name is %s\n", arr_patient[id_index]->name);
    
    for (int i = 0; i < 15; i++)
    {
        if (slots[i]->id == id)
        {
            printf("This Patient already have a %s appointment at %s\nYou can't reserve two slots for the"
            " same patient.\nReturning to main menu now.\n", slots[i]->day, slots[i]->hours);
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
        printf("%d",days_index);
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

void cancel_slot(void)
{
    int id;
    int flag = 1;
    int slot_index;
    int confirm;

    printf("\nPlease Enter Patient ID.\n");
    scanf("%d", &id);
    
    for (int i = 0; i < 15; i++)
    {
        if (slots[i]->id == id)
        {
            flag = 0;
            slot_index = i;
            
        }
    }
    if (flag)
    {
        printf("There are no slots registered with this ID, or the ID doesn't exist\n");
        return;
    }
    printf("Patient with ID %d has a %s appointment at %s.\nAre you Sure you Want to cancel?\n[1]Yes   [0]No", 
    slots[slot_index]->id,slots[slot_index]->day, slots[slot_index]->hours);
    jump_cancel:
    scanf("%d", &confirm);
    if (confirm != 1 && confirm != 0)
    {
        printf("\nPlease Type either [1] to confirm cancelation or [0] to back.\n");
        goto jump_cancel;
    }
    if (confirm == 0)
        return;
    slots[slot_index]->id = -54321;
    printf("\ncancelation done successfully. Returning to main menu now.\n");
}

void show_all(void)
{
    int flag = 1;
    if (counter == 0)
    printf("\nThere are no records in the system !\n");
    for (int x = 0; x < counter; x++)
    {
        printf("patient(%d) name: %s\n"
        "ID: %d\nAge :%d\nGender: %s\n", x+1, arr_patient[x]->name,arr_patient[x]->id,arr_patient[x]->age,
        (arr_patient[x]->gender == 1)?"Male":"Female");
        
        for (int i = 0; i < 15; i++)
        {
            if (slots[i]->id == arr_patient[x]->id)
            {
                printf("Patient have a %s appointment at %s.\n\n", slots[i]->day, slots[i]->hours);
                flag = 0;
            }
        }
        if (flag)
            {
                printf("Patient doesn't have any upcoming appointments\n\n");
            }
            flag = 1;

    }
}