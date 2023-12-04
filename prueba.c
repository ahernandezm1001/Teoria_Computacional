#include<stdio.h>
#include<stdlib.h>
#include"simple_list.h"

int main(){
    DATA D = (DATA)create_List();
    DATA T = (DATA)create_List();
    //STATE S = create_State_Node();
    //TRANSITION T = create_Transition_Node();
    FILE* file = fopen("C:/Users/Foxx/Desktop/u/AND.txt", "r+");
    if(file == NULL){
        printf("Error de puntero FILE");
        exit(0);
    }
    D = insert_Data(D, 1);
    D = insert_Data(D, 2);
    D = insert_Data(D, 3);
    display_Data(D);
    display_Data(D);
    return 0;
}
