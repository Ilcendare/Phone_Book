/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 18 April 2023                     *
 *  Description : Phone book program.               *
 *                To save information about friends,*
 *                families, and people.             *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#ifndef PHONE_BOOK_PHONE_BOOK_H
#define PHONE_BOOK_PHONE_BOOK_H


/* =========== Function prototypes =========== */
void Phone_Book_Init(void);
void Phone_Book_SaveData(void);
int Phone_Book_LoadData(void);
void Phone_Book_Menu(void);
void Phone_Book_AddContact(void);
void Phone_Book_DeleteContact(void);
void Phone_Book_EditContact(void);
void Phone_Book_ListContactData(void);



#endif //PHONE_BOOK_PHONE_BOOK_H