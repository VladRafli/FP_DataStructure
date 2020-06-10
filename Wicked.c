/*--------------------------------------------------
 * Wicked App
 * 
 * App that used to secure your account information
 * by hashing, bcrypt, then encryption.
 * This is an example of Dropbox database
 * protection aginst hackers
 * 
 * Version of this app: v.1.0.0 (Alpha Test)
 ---------------------------------------------------*/

/*--------------------
 * Includes
 ---------------------*/
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "uttils.h"

/* --- If C++ --- */
#ifdef __cplusplus
extern "C" {
#endif

/*--------------------
 * Defines
 ---------------------*/

//Manual Debuging
#define DEBUG
//Data Size Limit
#define DATASIZ 100

/*--------------------
 * Typedef and Global Variables
 ---------------------*/

 //Typedef Struct Graph Structure
typedef struct Graph_Structure graph;
//Typedef of Struct Customer_Data
typedef struct Customer_Data node;
//Typedef of Struct Date Of Birth
typedef struct Date_Of_Birth dob;
//Typedef of Struct Input_Data
typedef struct Input_Data input;
//
graph *graphData[10];

/*--------------------
 * Data Structure
 ---------------------*/
struct Graph_Structure{
    node *heads;
};
struct Date_Of_Birth{
    int date;
    int month;
    int year;
};
struct Customer_Data{
    char fname[DATASIZ];
    char lname[DATASIZ];
    dob date;
    char username[DATASIZ];
    char password[DATASIZ];
    node *next;
};
struct Input_Data{
    char fname[DATASIZ];
    char lname[DATASIZ];
    dob date;
    char username[DATASIZ];
    char password[DATASIZ];
};

/*---------------------
 * Function Prototypes
 ----------------------*/

void store_data();
void edit_data();
void delete_data();
input inputData(input varIpt);
void printInput(input *varIpt);
node *createNode(input *inputedData, node *temp);
node *connectNode(node *temp);
void printGraph();
void querrySearch(char *src);
void deleteNode(char *src);

/*---------------------
 * Functions
 ----------------------*/

int main(int argc, char const *argv[]){
    static const char title[] = "Program Title Here!";
    char ans;
    int opt;
    do{
        header(strlen(title), title, "block");
        printf("1. Store Data to Database\n");
        printf("2. Edit Data on Database\n");
        printf("3. Delete Data on Database\n");
        printf("4. Exit\n\n");
        printf(">> Input Choice: ");
        do{
            ans = getch();
            fflush(stdin);
            if(ans >= '1' && ans <= '4'){
                printf("%c", ans);
                #ifdef DEBUG
                printf("\n\nAns Value: %d\n", (int) ans);
                #endif
                opt = (int) ans - 48;
                break;
            }
        } while (1);
        switch(opt){
            case 1:
                store_data();
                break;
            case 2:
                edit_data();
                break;
            case 3:
                delete_data();
                break;
            case 4:
                return 0;
            default:
                continue;
            }
    } while (1);
}
void store_data(){
    input input;
    node *temp;
    clrscr;
    input = inputData(input);
    temp = createNode(&input, temp);
    if(temp != NULL)
        temp = connectNode(temp);
    else{
        printf("Node Initialization Failed!");
        getch();
        return;
    }
    #ifdef DEBUG
    printGraph();
    #endif
    clrscr;
}
void edit_data(){
    char src[DATASIZ];
    clrscr;
    do{
        printf("Enter Username you want to search: ");
        gets(src);
        fflush(stdin);
    } while (strlen(src) == 0 || strlen(src) > DATASIZ);
    querrySearch(src);
    getch();
    clrscr;
}
void delete_data(){
    char src[DATASIZ];
    clrscr;
    do{
        printf("Enter Username you want to search: ");
        gets(src);
        fflush(stdin);
    } while (strlen(src) == 0 || strlen(src) > DATASIZ);
    deleteNode(src);
    getch();
    clrscr;
}
input inputData(input varIpt){
    int passlen;
    char dateInput[10];
    char pass[DATASIZ] = "";
    char repass[DATASIZ] = "";
    //Input User First Name
    do{
        printf("Input your first name: ");
        gets(varIpt.fname);
        fflush(stdin);
    } while (strlen(varIpt.fname) < 1 || strlen(varIpt.fname) > DATASIZ);
    printf("\n");
    //Input User Last Name
    do{
        printf("Input your last name: ");
        gets(varIpt.lname);
        fflush(stdin);
    } while (strlen(varIpt.lname) < 1 || strlen(varIpt.lname) > DATASIZ);
    printf("\n");
    //Input User Date of Birth
    do{
        printf("Input your date of birth [dd/mm/yyyy]: ");
        gets(dateInput);
        fflush(stdin);
        if(dateInput[2] == '/' && dateInput[5] == '/'){
            sscanf(dateInput, "%d/%d/%d", &varIpt.date.date, &varIpt.date.month, &varIpt.date.year);
            if(varIpt.date.date > 1 && varIpt.date.date < 30)
                if(varIpt.date.month > 1 && varIpt.date.month < 12)
                    if(varIpt.date.year > 1 && varIpt.date.year < 2020)
                        break;
        }
    } while (1);
    printf("\n");
    //Input User Username
    do{
        printf("Input your username: ");
        gets(varIpt.username);
        fflush(stdin);
    } while(strlen(varIpt.username) < 1 || strlen(varIpt.username) > DATASIZ);
    printf("\n");
    //Input User Password
    do{
        printf("Input your password: ");
        gets(varIpt.password);
        fflush(stdin);
    } while(strlen(varIpt.password) < 1 || strlen(varIpt.password) > DATASIZ);
    /* Failed attempt */
    /*
    do{
        printf("Input your password: ");
        for(int i = 0; ; i++){
            pass[i] = getch();
            fflush(stdin);
            if((int)pass[i] == 13 || i == DATASIZ){
                #ifdef DEBUG
                //puts(pass);
                #endif
                break;
            }
        }
        printf("\n\n");
        printf("Re-enter your password: ");
        for(int i = 0; ; i++){
            repass[i] = getch();
            fflush(stdin);
            if((int)repass[i] == 13 || i == DATASIZ){
                #ifdef DEBUG
                //puts(repass);
                #endif
                break;
            }
        }
        if(strcmp(varIpt->password, repass) != 0)
            printf("\n\nThe Input is not same! %d\n", strcmp(varIpt->password, repass));
            printf("%s %s\n\n", pass, repass);
        if(strcmp(varIpt->password, repass) == 0){
            strcpy(varIpt->password, pass);
            break;
        }
    } while(1);
    */
    printf("\n");
    printInput(&varIpt);
    return varIpt;
}

void printInput(input *varIpt){
    printf("Account Details:\n\n");
    printf("First Name: %s\n", varIpt->fname);
    printf("Last Name: %s\n", varIpt->lname);
    printf("Date of Birth: %d/%d/%d\n", varIpt->date.date, varIpt->date.month, varIpt->date.year);
    printf("Username: %s\n", varIpt->username);
    printf("Password: ");
    for(int i = 0; i < 3; i++)
        printf("%c", varIpt->password[i]);
    if(strlen(varIpt->password) > 3)
        for(int i = 0; i < strlen(varIpt->password) - 3; i++)
            printf("*");
    printf("\n\n");
}

node *createNode(input *inputedData, node *temp){
    temp = (node *) malloc(sizeof(node));
    if(!temp){
        perror("Error: ");
        return NULL;
    }
    #ifdef DEBUG
    printf("Username: %s\n", inputedData->username);
    #endif
    strcpy(temp->fname, inputedData->fname);
    strcpy(temp->lname, inputedData->lname);
    temp->date.date = inputedData->date.date;
    temp->date.month = inputedData->date.month;
    temp->date.year = inputedData->date.year;
    strcpy(temp->username, inputedData->username);
    strcpy(temp->password, inputedData->password);
    temp->next = NULL;
    return temp;
}
node *connectNode(node *temp){
    node *ptr;
    int n = 0;
    int index;
    #ifdef DEBUG
    printf("Username: %s\n",temp->username);
    #endif
    //Count the size of Username total ASCII Value
    for(int i = 0; i < strlen(temp->username); i++){
        n += (int) temp->username[i];
    }
    //Hash Calculation
    index = n % 10;
    #ifdef DEBUG
    printf("Index: %d, n: %d", index, n);
    getch();
    #endif
    /**
     * Logic Error Below! Crash Happened!
     * Need fixation!
     */
    /* Connect Node to Graph Representation */
    //If the head in Graph is Empty
    if(graphData[index]->heads == NULL){
        temp = graphData[index]->heads;
    } else{
        //Place Pointer to Head
        ptr = graphData[index]->heads;
        //Move Pointer if there is a node in ptr
        while(ptr->next != NULL)
            ptr = ptr->next;
        //Place temp node in Pointer Next
        temp = ptr->next;
    }
    return temp; //Return Function Result
}
void printGraph(){
    node *ptr;
    #ifdef DEBUG
    printf("printGraph is Executed!\n\n");
    #endif
    printf("Result Querry:\n");
    for(int i = 1; i <= 10; i++){
        printf("%d. ", i);
        //Place pointer to head and loop for print linked list in graph position
        for(ptr = graphData[i - 1]->heads; ptr != NULL; ptr = ptr->next){
            if(ptr->next != NULL)
                printf("%s -> ", ptr->username);
            else
                printf("%s\n", ptr->username);
        }
    }
    getch();
}
void querrySearch(char *src){
    node *ptr;
    int i;
    for(i = 0; i < 10; i++){
        //Place pointer to head and loop to search data in linked list
        for(ptr = graphData[i]->heads; ptr != NULL; ptr = ptr->next){
            if(strcmp(ptr->username, src) == 0)
                printf("Username: %s", graphData[i]->heads->username);
            printf("Data not found!");
        }
    }
}
void deleteNode(char *src){
    node *ptr, *preptr;
    int i;
    for(i = 0; i < 10; i++){
        //Place pointer to head and loop to search data in linked list
        for(ptr = graphData[i]->heads; ptr != NULL; ptr = ptr->next){
            preptr = ptr; //Place Pre-Pointer in Pointer Position
            if(strcmp(ptr->username, src) == 0){
                //Move Pre-Pointer before Pointer
                while(preptr->next != ptr)
                    preptr = preptr->next;
                //If there is no node in Pointer Next
                if(ptr->next != NULL){
                    preptr->next = ptr->next;
                    free(ptr);
                }
                //If there is node in Pointer Next
                else{
                    preptr->next = NULL;
                    free(ptr);
                }
            }   
            printf("Data not found!");
        }
    }
}
/* --- If C++ --- */
#ifdef __cplusplus
}
#endif