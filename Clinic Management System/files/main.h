#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/** 
 * patient - store patient data
 */
typedef struct patient
{
    char name[50];
    int age;
    int gender;
    int id;
} patient;

/** 
 * slots - slots and it's reservations
 */
typedef struct slots
{
    char day[10];
    char hours[10];
    int id;
} slot;

/* MAIN FUNCTIONS */
int choose_mode(void);

/* ADMIN FUNCTIONS */
void login(void);
void features_picker(void);
patient *new_patient(void);
void edit_patient(void);
void book_slot(void);
void cancel_slot(void);
void show_all(void);

/* USER FUNCTION */
void hello_user(void);
void user_options(void);
patient *new_user(void);
void user_reserve(void);
void user_edit_reserve(void);
void user_cancel(void);

#endif

