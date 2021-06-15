// Copyright 2020 Dinu Ion Irinel
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

#define true 1

int main(void) {

    account_t *account = malloc(sizeof(account_t));
    
    make_data();
    
    while (true) {
        
        display_menu();

        char option;
        scanf("%c", &option);

        switch(option) {
            case 'A':  {
                add_account(account);
                break;
            }
            case 'D': {
                display_info(account);
                break; 
            }
            case 'E': {
                printf("THE PROGRAM WAS CLOSED !\n");
                return 0;
            }
        }
    }
    
     free_memory(account);

     free(account);
     
    return 0;
}
