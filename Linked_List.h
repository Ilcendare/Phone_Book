/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 18 April 2023                     *
 *  Description : Phone book program.               *
 *                To save information about friends,*
 *                families, and people.             *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#ifndef PHONE_BOOK_LINKED_LIST_H
#define PHONE_BOOK_LINKED_LIST_H


/* =========== Defining the structure of lists and nodes =========== */
typedef struct ListNode {
    DATA *dataPtr;
    struct ListNode *NextNode;
} lnode_t;

typedef struct List {
    lnode_t *first;
    lnode_t *last;
}list_t;


/* =========== Function prototypes =========== */
void Linked_List_Init(list_t *List);
void Linked_List_AddNode(list_t *List, DATA *NewData);
int Linked_List_DeleteNode(list_t *List, char firstName[], char lastName[]);
void* Linked_List_FindNode(list_t *List, char firstName[], char lastName[]);
void Linked_List_ListNodes(list_t *List, void (*DisplayFormatFunction) (lnode_t*));


#endif //PHONE_BOOK_LINKED_LIST_H
