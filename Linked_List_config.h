/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 18 April 2023                     *
 *  Description : Phone book program.               *
 *                To save information about friends,*
 *                families, and people.             *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#ifndef PHONE_BOOK_LINKED_LIST_CONFIG_H
#define PHONE_BOOK_LINKED_LIST_CONFIG_H


/* =========== Define the data structure for each node =========== */
typedef struct Contact {
    char FirstName[21];
    char LastName[21];
    char Address[31];
    char PhoneNumber[13];
    char Email[31];
} contact_t;


/* =========== Configure important macros for the Linked List's functions =========== */
#define DATA        contact_t           // The list node's data it holds


#endif //PHONE_BOOK_LINKED_LIST_CONFIG_H
