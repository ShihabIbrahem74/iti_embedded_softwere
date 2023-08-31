#include "main.h"
patient *arr_patient[25];
int counter = 0;
slot *slots[15];

int main()
{
    /* SETUP */
    const char *days_array[] = {"Sunday", "Tuesday", "Thursday"};
    const char *hours_array[] = {"2pm", "2:50pm", "3pm", "4pm", "4:50pm"};
    int mode;
    
    /* FILLING THE SLOTS ARRAY WITH DATA */
    int slot_counter = 0;
    for (int days = 0; days < 3; days++)
    {
        for (int hours = 0; hours < 5; hours++)
        {
            slots[slot_counter] = (slot *)malloc(sizeof(slot));
            strcpy(slots[slot_counter]->day, days_array[days]);
            strcpy(slots[slot_counter]->hours, hours_array[hours]);
            slots[slot_counter]->id = -54321; //It's just a random number.
            slot_counter++;
        }
    }

    /* MAIN PROGRAM */
    while(1){
    mode = choose_mode(); //choose mode
    
    if (mode == 0) //ADMIN mode
    {
        login(); //ADMIN PASSWORD LOGIN
        features_picker();	//ADMIN FEATURES PICKER
    }
    else if (mode == 1)
    {
       user_options(); //USER FEATURES PICKER
    }
}}
