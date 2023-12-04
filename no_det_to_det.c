/* 
Codigo Escrito por: Hernandez Mejia Alvaro
Contacto: noragamidrrr@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>
#include"simple_list.h"
//#include"program_funtions.h"

//void convert_to_determinist();

int main(){
    int c;
    FILE* file = fopen("/home/escom/Escritorio/xd/AND.txt", "r+");
    if(file == NULL){
        printf("Error de puntero FILE");
        exit(0);
    }
    printf("  -----AUTOMATA NO DETERMINISTA----- \n");
    while(!feof(file)) printf("%c", fgetc(file));
    fclose(file);
    convert_to_determinist();

    return 0;
}


/*void convert_to_determinist(){
    printf("\n  -----CONVIRTIENDO A DETERMINISTA----- \n");
    FILE* file = fopen("/home/escom/Escritorio/xd/AND.txt", "r+");
    if(file == NULL){
        printf("Error de puntero FILE");
        exit(0);
    }
    int c = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int* states = (int*)malloc(sizeof(int)*10);
    while(c != '\n'){
        c = fgetc(file);
        if((c != ',') && (c != '\n') && (c != '\xd')){
            states[i] = c;
            i++;
        }else continue;
    }
    states[i] = '\0'; 
    c = 0;
    i = 0;
    int* transicion = (int*)malloc(sizeof(int)*10);
    while(c != '\n'){
        c = fgetc(file);
        if((c != ',') && (c != '\n') && (c != '\xd')){
            transicion[i] = c;
            i++;
        }else continue;
    }
    transicion[i] = '\0';

    int l_state = long_String(states);
    int l_transicion = long_String(transicion);
    LIST L = create_List();
    int* aux = (int*)malloc(sizeof(int)*2);
    for(i = 0 ; i < l_state ; i++){
        aux[0] = states[i];
        aux[i+1] = '\0';
        L = insert_List(L, aux, transicion);
    }
    display_List(L, l_state, l_transicion);
    fseek(file, 6, SEEK_CUR);
    c = fgetc(file);
    int* next_state = (int*)malloc(sizeof(int)*10);
    LIST aux3 = (LIST)malloc(sizeof(L));
    LIST aux2 = create_List();
    aux3 = L;
    while(!isEmpty_List(aux3) || feof(file)){
        aux2 = aux3;
        if(c == aux2->state[0]){
            fgetc(file);
            c = fgetc(file);
            for(i = 0, j = 0; transicion[i] != '\0' ; i++){
                if(c == transicion[i]){
                    fgetc(file);
                    c = fgetc(file);
                    next_state[j] = c;
                    j++;
                    aux3 = add_transition(aux2, c, transicion[i]);
                }else{
                    next_state[j+1] = '\0';
                    continue;
                }
                fseek(file, 2, SEEK_CUR);
                c = fgetc(file);
                
            }
        }else {
            aux3 = remove_List(aux3);
        }
    }
    display_List(L, l_state, l_transicion);

}*/