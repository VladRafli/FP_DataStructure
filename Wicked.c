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
// #define DEBUG
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
void input_data(input *varIpt);
void createNode(input *inputedData, node *temp);
void connectNode(node *temp);
void printfGraph();

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
                //store_data();
                break;
            case 2:
                //edit_data();
                break;
            case 3:
                //delete_data();
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
    input_data(&input);
    createNode(&input, temp);
    connectNode(temp);
    //printGraph();
    clrscr;
}
void edit_data(){
    clrscr;
    //search();
    clrscr;
}
void delete_data(){
    clrscr;
    //search();
    clrscr;
}
void input_data(input *varIpt){
    //Input User Data here!
    do{
        printf("Input your first name: ");
        gets(varIpt->fname);
        fflush(stdin);
    } while (strlen(varIpt->fname) < 1 || strlen(varIpt->fname) > DATASIZ);
    //etc...
}
void createNode(input *inputedData, node *temp){
    temp = (node *) malloc(sizeof(node));
    strcpy(temp->fname, inputedData->fname);
    strcpy(temp->lname, inputedData->lname);
    temp->date.date = inputedData->date.date;
    temp->date.month = inputedData->date.month;
    temp->date.year = inputedData->date.year;
    strcpy(temp->username, inputedData->username);
    strcpy(temp->password, inputedData->password);
    temp->next = NULL;
}
void connectNode(node *temp){
    int index = (int) temp->username % 10;
    #ifdef DEBUG
    printf("Index: %d", index);
    #endif
    //Connect Node to Graph Representation
    graphData[index]->heads = temp;
}
void printGraph(){

}
/* --- If C++ --- */
#ifdef __cplusplus
}
#endif