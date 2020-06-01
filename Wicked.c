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

/*--------------------
 * Structure
 ---------------------*/

struct Data{

};

/*---------------------
 * Function Prototypes
 ----------------------*/

void store_data();
void edit_data();
void delete_data();

/*---------------------
 * Functions
 ----------------------*/

int main(int argc, char const *argv[]){
    static const char title[] = "Program Title Here!";
    char ans;
    int opt;
    do{
        clrscr;
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
                exit(0);
            default:
                continue;
            }
    } while (1);
}
void store_data(){
    clrscr;
    //input();
    //createGraph();
    //connectGraph();
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

/* --- If C++ --- */
#ifdef __cplusplus
}
#endif