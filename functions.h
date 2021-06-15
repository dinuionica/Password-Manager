#ifndef FUNCTIONS__H
#define FUNCTIONS__H

// struct of an account
typedef struct {

    char *type;
    char *user;
    char *passwd;
    
    } account_t;


extern account_t account;

// function to create database
void make_data();

// function to display menu
void display_menu();

// function to add an account
void add_account(account_t *account);

// function to display informations
void display_info(account_t *account);

// function the free memory
void free_memory(account_t *account);

#endif
