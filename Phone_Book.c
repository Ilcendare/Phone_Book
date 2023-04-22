/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 18 April 2023                     *
 *  Description : Phone book program.               *
 *                To save information about friends,*
 *                families, and people.             *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List_config.h"
#include "Linked_List.h"
#include "Phone_Book.h"


/* ========== Important declarations ========== */
list_t *ContactList = NULL;


/* ========== Functions declarations ========== */
void ContactDisplayFormat(lnode_t* node) {
    printf("\nName: %s %s\nPhone number: %s\nAddress: %s\nE-mail: %s\n",
           node->dataPtr->FirstName, node->dataPtr->LastName, node->dataPtr->PhoneNumber, node->dataPtr->Address,
           node->dataPtr->Email);
}


void Phone_Book_Init(void) {
    ContactList = (list_t *) malloc(sizeof(list_t));
    Linked_List_Init(ContactList);
}


void Phone_Book_SaveData(void) {
    FILE *ContactFile;
    lnode_t *ptr = ContactList->first;
    int counter = 0;
    ContactFile = fopen("Phone_Book.txt","w");
    while(ptr != NULL) {
        fseek(ContactFile,(long)(counter * sizeof(DATA)),SEEK_SET);
        fwrite(ptr->dataPtr, sizeof(DATA),1,ContactFile);
        counter++;
        ptr = ptr->NextNode;
    }
    fclose(ContactFile);
}


int Phone_Book_LoadData(void) {
    FILE *ContactFile;
    ContactFile = fopen("Phone_Book.txt","r");
    if(ContactFile == NULL) return 0;
    DATA *DataLoaded;
    while(!feof(ContactFile)) {
        DataLoaded = (DATA *) malloc(sizeof(DATA));
        int res = (int) fread(DataLoaded,sizeof(DATA),1,ContactFile);
        if(res != 0) {
            Linked_List_AddNode(ContactList,DataLoaded);
        }
    }
    fclose(ContactFile);
    return 1;
}


void Phone_Book_Menu(void) {
    char select;
    _Bool QUIT = 0;

    printf("===============================================================\n");
    printf("###############            Phone Book            ##############\n");
    printf("===============================================================\n");
    printf("#############   Please Choose from the following   ############\n");
    printf("===============================================================\n\n");
    printf("\t(+)\ta) Add a contact \t\t\t(+)\n");
    printf("\t(+)\td) Delete a contact\t\t\t(+)\n");
    printf("\t(+)\tl) List a contact's information\t\t(+)\n");
    printf("\t(+)\tL) List all contacts' information\t(+)\n");
    printf("\t(+)\te) Edit a contact's information\t\t(+)\n");
    printf("\t(+)\tq) Quit program\t\t\t\t(+)\n");

    do {
        char Continue;
        printf("\nType Here: ");
        scanf("%c", &select);
        switch (select) {
            case 'L':
                Linked_List_ListNodes(ContactList,ContactDisplayFormat);
                break;
            case 'a':
                do {
                    Phone_Book_AddContact();
                    printf("The contact has added successfully.\n");
                    printf("Do you want to add another contact? (y - yes, n - no)\n");
                    do {
                        printf(">");
                        fflush(stdin);
                        scanf("%c", &Continue);
                        if ((Continue != 'y') && (Continue != 'n')) {
                            printf("Please enter a valid answer.\n");
                        }
                    } while((Continue != 'y') && (Continue != 'n'));
                } while(Continue == 'y');
                break;
            case 'd':
                do {
                    Phone_Book_DeleteContact();
                    printf("Do you want to delete another contact? (y - yes, n - no)\n");
                    do {
                        printf(">");
                        fflush(stdin);
                        scanf("%c", &Continue);
                        if ((Continue != 'y') && (Continue != 'n')) {
                            printf("Please enter a valid answer.\n");
                        }
                    } while((Continue != 'y') && (Continue != 'n'));
                } while(Continue == 'y');
                break;
            case 'l':
                do {
                    Phone_Book_ListContactData();
                    printf("Do you want to list another contact? (y - yes, n - no)\n");
                    do {
                        printf(">");
                        fflush(stdin);
                        scanf("%c", &Continue);
                        if ((Continue != 'y') && (Continue != 'n')) {
                            printf("Please enter a valid answer.\n");
                        }
                    } while((Continue != 'y') && (Continue != 'n'));
                } while(Continue == 'y');
                break;
            case 'e':
                do {
                    Phone_Book_EditContact();
                    printf("Do you want to edit another contact? (y - yes, n - no)\n");
                    do {
                        printf(">");
                        fflush(stdin);
                        scanf("%c", &Continue);
                        if ((Continue != 'y') && (Continue != 'n')) {
                            printf("Please enter a valid answer.\n");
                        }
                    } while((Continue != 'y') && (Continue != 'n'));
                } while(Continue == 'y');
                break;
            case 'q':
                printf("Are you sure you want to quit? (y - yes, n - no)\n");
                do {
                    printf(">");
                    fflush(stdin);
                    scanf("%c", &Continue);
                    if ((Continue != 'y') && (Continue != 'n')) {
                        printf("Please enter a valid answer.\n");
                    }
                } while((Continue != 'y') && (Continue != 'n'));
                if(Continue == 'y') QUIT = 1;
                else QUIT = 0;
                break;
            default:
                printf("Please enter one of the shown settings (a, d, l, e, or q lowercase)\n");
        }
        fflush(stdin);
    } while(!QUIT);
}


void Phone_Book_AddContact(void) {
    char firstName[21];
    char lastName[21];
    char email[31];
    char address[31];
    char phoneNumber[13];
    printf("Please enter the first and last name:");
    scanf("%20s %20s",firstName,lastName);
    fflush(stdin);
    printf("Please enter the Phone number:");
    /* This step is done to check if the phone number entered is already registered in the system or not */
    int Abort = 0;
    lnode_t *ptr = ContactList->first;
    while(!Abort) {
        fflush(stdin);
        scanf("%s",phoneNumber);
        Abort = 1;
        while (ptr != NULL) {
            if ((strcmp(ptr->dataPtr->PhoneNumber, phoneNumber)) == 0) {
                printf("You've entered that phone number before, try another phone number.\n>>");
                Abort = 0;
                break;
            }
            ptr = ptr->NextNode;
        }
    }
    /* End of checking step */
    printf("Please enter the address:");
    fflush(stdin);
    scanf("%s",address);
    printf("Please enter the E-mail: ");
    /* This step is done to check if the E-mail entered is already registered in the system or not */
    Abort = 0;
    ptr = ContactList->first;
    while(!Abort) {
        fflush(stdin);
        scanf("%s",email);
        Abort = 1;
        while (ptr != NULL) {
            if ((strcmp(ptr->dataPtr->Email, email)) == 0) {
                printf("You've entered that E-mail before, try another E-mail.\n>>");
                Abort = 0;
                break;
            }
            ptr = ptr->NextNode;
        }
    }
    /* End of checking step */
    DATA *NewAccount;
    NewAccount = (DATA *) malloc(sizeof(DATA));
    strcpy(NewAccount->FirstName, firstName);
    strcpy(NewAccount->LastName, lastName);
    strcpy(NewAccount->Address, address);
    strcpy(NewAccount->Email, email);
    strcpy(NewAccount->PhoneNumber, phoneNumber);
    Linked_List_AddNode(ContactList,NewAccount);
}


void Phone_Book_DeleteContact(void) {
    char firstName[21], lastName[21];
    int result;
    printf("Please enter the name number of the contact:");
    fflush(stdin);
    scanf("%20s %20s",firstName, lastName);

    result = Linked_List_DeleteNode(ContactList, firstName, lastName);
    if(result)
        printf("The contact has deleted successfully.\n");
    else
        printf("The contact is not included.\n");
}


void Phone_Book_EditContact(void) {
    char firstNameSearch[21], lastNameSearch[21];
    lnode_t *Contact;
    printf("Please enter the name number of the contact:");
    fflush(stdin);
    scanf("%20s %20s",firstNameSearch, lastNameSearch);

    Contact = Linked_List_FindNode(ContactList, firstNameSearch, lastNameSearch);
    if (Contact != NULL) {
        char firstName[21] = "0";
        char lastName[21] = "0";
        char email[11] = "0";
        char address[31] = "0";
        char phoneNumber[12] = "0";

        printf("Enter the new contact's info you want to edit in the following order: first name, last name, email,"
               " address, and phone number.\nIf one of the mentioned you don't want to alter,"
               "enter 0 instead.");
        scanf("%20s %20s %10s %30s %11s", firstName, lastName, email, address, phoneNumber);
        if(strcmp(firstName, "0") != 0) {
            strcpy(Contact->dataPtr->FirstName , firstName);
        }
        if(strcmp(lastName, "0") != 0) {
            strcpy(Contact->dataPtr->LastName , lastName);
        }
        if(strcmp(address, "0") != 0) {
            strcpy(Contact->dataPtr->Address , address);
        }
        if(strcmp(email, "0") != 0) {
            strcpy(Contact->dataPtr->Email , email);
        }
        if(strcmp(phoneNumber, "0") != 0) {
            strcpy(Contact->dataPtr->PhoneNumber , phoneNumber);
        }
    }
    else printf("The contact is not included.\n");
}


void Phone_Book_ListContactData(void) {
    char firstNameSearch[21], lastNameSearch[21];
    lnode_t *Contact;
    printf("Please enter the name number of the contact:");
    fflush(stdin);
    scanf("%20s %20s",firstNameSearch, lastNameSearch);

    Contact = Linked_List_FindNode(ContactList,firstNameSearch, lastNameSearch);
    if (Contact != NULL) ContactDisplayFormat(Contact);
    else printf("The contact is not included.\n");
}