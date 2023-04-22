/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 18 April 2023                     *
 *  Description : Phone book program.               *
 *                To store information about        *
 *                friends, families, and people.    *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#include <stdio.h>
#include "Phone_Book.h"

int main() {
    Phone_Book_Init();
    Phone_Book_LoadData();
    Phone_Book_Menu();
    Phone_Book_SaveData();

    return 0;
}
