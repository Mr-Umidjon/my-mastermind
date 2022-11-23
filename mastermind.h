#include <stdio.h>
#include <stdlib.h>     
#include <time.h>       
#include <string.h>
#include <stdbool.h>

#ifndef MY_MASTERMIND_C
#define MY_MASTERMIND_C

int str_to_int(char *);
void *my_strcpy(char *, char *);
int str_len(char *);
int my_strcmp(char* , char *);
bool my_isdigit_real (char *);
bool my_isdigit(char *);
int *integer_array(char *);
int *secret_code(char *);
int wellplaced_pieces(int *, int *);
int misplaced_pieces(int *, int *);
void mastermind(int, int *);

#endif
