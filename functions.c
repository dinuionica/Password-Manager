#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to display menu 

void display_menu() {
     
    system("clear");
    printf("--------------------------------------------------\n");
    printf("----------------PASSWORD MANAGER------------------\n\n");
    printf("ADD A NEW ACCOUNT -------------------------PRESS A\n\n");
    printf("DISPLAY INFORMATION OF AN ACCOUNT----------PRESS D\n\n");
    printf("EXIT---------------------------------------PRESS E\n");
    printf("--------------------------------------------------\n\n");
    printf("PLEASE ENTER AN OPTION...  \n");
    

}

//function to encode a string

void encode_data(char *string) {
    for (int i = 0; i < strlen(string); ++i) {
        string[i] += 3;
    }
}

//function to decode a string

void decode_data(char *string) {
    for (int i = 0; i < strlen(string); ++i) {
        string[i] -= 3;
    }
}

//function to make database file

void make_data() {

    FILE *file ;
    file = fopen("database.txt", "wart");
    fclose(file);
}

//add an account to database

void add_account(account_t *account) {

    
    FILE* file_in;
	int type_exist = 0;
	char *type = (char *)malloc(sizeof(char) * 100);
	printf("ENTER THE TYPE OF ACCOUNT : ");
	scanf("%s",type);
    encode_data(type);

	char *line = (char *)malloc(sizeof(char) * 255);
	file_in = fopen("database.txt", "r");
	while(fgets(line, 255, file_in))
	{
		char *ptr = strstr(line, type);
		if (ptr != NULL) 
		{
			type_exist = 1;
			break;
		}
	}
	fclose(file_in);

    //if the user exist in system
	if (type_exist == 1)
	{   
		printf("THIS ACCOUNT ALREADY EXIST IN SYSTEM...!\n");
        sleep(5);
        return;

    //if the user don't exist in system
	} else {
		printf("PLEASE ENTER AGAIN FOR THE TYPE OF THIS ACCOUNT... : ");
        account -> type = malloc(sizeof(account_t));
        scanf ("%s", account -> type);
        printf("\n");

        printf("PLEASE ENTER THE USERNAME OF THIS ACCOUNT... : ");
        account -> user = malloc(sizeof(account_t));
        scanf ("%s", account -> user);
        printf("\n");
        
        printf("PLEASE ENTER THE PASSWORD OF THIS ACCOUNT... : ");
        account -> passwd = malloc(sizeof(account_t));
        scanf ("%s", account -> passwd);
        
        FILE *file;
        file = fopen("database.txt", "at");
        if (file == NULL) {
            printf("FILE WITH ERROR...\n");
            return;
        }

        encode_data(account -> type);
        encode_data(account -> user);
        encode_data(account -> passwd);

        fprintf(file, "%s\n", account -> type);
        fprintf(file, "%s\n", account -> user);
        fprintf(file, "%s\n", account -> passwd);
        fclose(file);
        
        printf("YOUR ACCOUNT WAS ADDED WITH SUCCES ! \n");
        sleep(5);
	}

    free(type);
    free(line);

}

//display informations of an account

void display_info(account_t *account) {


    FILE *file;
    file = fopen("database.txt", "rt");
    if (file == NULL) {
        printf("FILE WITH ERROR...\n");
        return;
    }
    printf("ENTER THE NAME OF USER ACCOUNT: ");
    char *username = (char *)malloc(sizeof(char) * 255);
    scanf("%s", username);
    encode_data(username);

    account -> type = malloc(sizeof(account_t));
    account -> user = malloc(sizeof(account_t));
    account -> passwd = malloc(sizeof(account_t));

    //check if the user and password are correct
    int exist = 0;
    while (!feof(file)) {
        fscanf(file, "%s", account -> type);
        fscanf(file, "%s", account -> user);
        fscanf(file, "%s", account -> passwd);
        if (strcmp(username, account -> user) == 0) {

            decode_data(account -> type);
            decode_data(account -> passwd);
            decode_data(account -> user);

            system("clear");
            printf("---------------ACCOUNT INFORMATIONS----------------\n\n");
            printf("TYPE OF ACCOUNT : %s\n\n", account -> type);
            printf("USERNAME : %s\n\n", account -> user);
            printf("PASSWORD : %s\n\n", account -> passwd);
            sleep(5);
            exist = 1;
        } 
    }
    if (exist == 0) {
        printf("THIS ACCOUNT DON'T EXIST IN SYSTEM...!\n");
    }

    fclose(file);
    free(username);
    sleep(5);
}

//function to free memory

void free_memory(account_t *account) {

    free(account -> type);
    free(account -> user);
    free(account -> passwd);

}
