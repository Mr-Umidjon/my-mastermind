#include "mastermind.h"
int str_to_int(char *param){
     return atoi(param);
     }

void* my_strcpy(char* param_1, char* param_2)
{
    int i;
    i = 0;
    while (param_2[i] != '\0') {
        param_1[i] = param_2[i];
        i++;
    }
}

int str_len(char *param_1){
    int count = 0;
    for(int i=0; param_1[i] != '\0'; i++) count++;
        return count;
}

int my_strcmp(char* param_1, char* param_2){  
    while((* param_1 != '\0' && *param_2 != '\0') &&  *param_1 - *param_2 == 0){
        param_1++;
        param_2++;
    }return *param_1 - *param_2; 
}

bool my_isdigit_real (char *param_1){
    for(int i=0; param_1[i] != '\0'; i++)
        if(!(param_1[i] >= '0' && param_1[i] <= '9')) return false;
    return true;
}

bool my_isdigit(char *param_1){
    for(int i=0; param_1[i] != '\0'; i++)
        if(!(param_1[i] >= '0' && param_1[i] <= '7')) return false;
    return true;
}

int *integer_array(char *param){
    int *res = malloc(4);
    int num = str_to_int(param);
    res[0] = num / 1000;
    res[1] = (num - res[0]*1000)/100;
    res[2] = (num - res[0]*1000 - res[1]*100)/10;
    res[3] = (num - res[0]*1000 - res[1]*100 - res[2]*10);
    return res;
}

int *secret_code(char *param){
    int *res = malloc(4);
    if(param == NULL) {
        srand (time(NULL));
        res[0] = rand() % 8;
        res[1] = rand() % 8;
        res[2] = rand() % 8;
        res[3] = rand() % 8;

    } else {
        res = integer_array(param);
    } return res;
}

int wellplaced_pieces(int *array, int *answers){
    int count=0;
    for(int k=0; k<4; k++){
        if(answers[k] == array[k]) count++;
    } return count;
}

int misplaced_pieces(int *array, int *answers){
    int res_count = 0, count[4] = {0, 0, 0, 0};;
    for (int i = 0; i < 4; i++)
    {
        for (int k=0; k<4; k++){
            if (answers[i] == array[k]) count[i]++;
        }
    }
    for (int k=0; k < 4; k++){
        if(count[k]>=1) res_count++;
    } return res_count - wellplaced_pieces(array, answers);    
}

void mastermind(int t, int *array){
    printf("Will you find the secret code?\n");
    for (int k=0; k < t; k++){
        char *answer;
        printf("Round %d\n> ", k);
        scanf("%s", answer);
        if(my_isdigit(answer) && str_len(answer) == 4){
            int *answers = integer_array(answer);
            int wellplaced_count = wellplaced_pieces(array, answers);
            int misplaced_count = misplaced_pieces(array, answers);
            if(wellplaced_count == 4){
                printf("Congratz! You did it!");
                break;
            }else{
                printf("Well placed pieces: %d\n", wellplaced_count);
                printf("Misplaced pieces: %d\n\n", misplaced_count);
            }
        } else {
            printf("Wrong input!\n\n");
        }
    }
}

void main(int ac, char **argv){
    if(ac == 1) mastermind(10, secret_code(NULL));
    if(ac == 3) {
        if(my_strcmp("-c", argv[1]) == 0 && my_isdigit(argv[2]) && str_len(argv[2]) == 4){
            mastermind(10, secret_code(argv[2]));
        } else mastermind(10, secret_code(NULL));
    }
    if(ac == 5){
        if(my_strcmp("-c", argv[1]) == 0 && my_isdigit(argv[2]) && str_len(argv[2]) == 4){
            if(my_strcmp("-t", argv[3]) == 0 && my_isdigit_real(argv[4])){
                mastermind(str_to_int(argv[4]), secret_code(argv[2]));
            } else mastermind(10, secret_code(argv[2]));   
        } else mastermind(10, secret_code(NULL));
    }
}    
        

