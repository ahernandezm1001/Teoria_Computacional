/* 
Codigo Escrito por: Hernandez Mejia Alvaro
Contacto: noragamidrrr@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>
#include"simple_list.h"

///////////////////////////////////////////////////////////////////////////////// UTILIDADES DE VERIFICACION

void* create_List(void){
	return NULL;
}

int isEmpty_List(void* L){
	if(!L) return TRUE;
	else return FALSE;
}

void validate_Creation(void* node){
    if(node == NULL){
        message_List(0);
        exit(0);
    }
}

///////////////////////////////////////////////////////////////////////////////// CREACION DE CONTENEDORES

DATA create_Data_Node(void){
    DATA new = (DATA)malloc(sizeof(Data));
    validate_Creation(new);
    new->state = -1;
    new->next = NULL;
    return new;
}

TRANSITION create_Transition_Node(void){
    TRANSITION new = (TRANSITION)malloc(sizeof(Transition));
    validate_Creation(new);
    new->character = -1;
    new->transition = create_Data_Node();
    new->next = NULL;
    return new;
}

STATE create_State_Node(void){
    STATE new = (STATE)malloc(sizeof(State));
    validate_Creation(new);
    new->state = create_Data_Node();
    new->transition = create_Transition_Node();
    new->next = NULL;
}

///////////////////////////////////////////////////////////////////////////////// INSERCION DE DATOS

DATA insert_Data(DATA D , int state){
    DATA new = create_Data_Node();
    new->state = state;
	if(isEmpty_List(D)) D = new;
	else{
        DATA current = D;
		DATA previous = D;
		while(current != NULL){//Si pongo !current por alguna razon no me inserta mas qeu el primer y ulitmo elemente
			previous = current;
			current = current->next;
		}
		previous->next = new;
	}
    return D;
}

TRANSITION insert_Transition(TRANSITION T, DATA tran_states ,int character){
    TRANSITION new = create_Transition_Node();
    new->character = character;
    new = (TRANSITION)insert_Data_List(new, tran_states, STRUCT_T);
    if(isEmpty_List(T)) T =  new;
    else{
        TRANSITION current = T;
        TRANSITION previous = T;
        while(current != NULL){
            previous = current;
            current = current->next;
        }
        previous->next = new;
    }
    return T;
}

STATE insert_State(STATE S1, STATE S2){
    if(isEmpty_List(S2)){
        message_List(1);
        exit(0);
    }
    if(isEmpty_List(S1)) S1 = S2;
    else{
        STATE current = S1;
        STATE previous = S1;
        while(current != NULL){
            previous = current;
            current = current->next;
        }
        previous->next = S2;
    }
    return S1;
}

///////////////////////////////////////////////////////////////////////////////// INSERCION DE CONTENEDORES EN OTROS CONTENEDORES

void* insert_Data_List(void* L, DATA data, int OPC){
    if(isEmpty_List(data)){
        message_List(1);
        exit(0);
    }
    if(OPC == STRUCT_T) ((TRANSITION)L)->transition = data;
    else if(OPC == STRUCT_S) ((STATE)L)->state = data;
    else {
        message_List(2);
        exit(0);
    }
    return L;
}

///////////////////////////////////////////////////////////////////////////////// ELIMINACION DE CONTENEDORES

void* remove_List(void* L, int OPC){
    if(isEmpty_List(L)){
        message_List(1);//Intenta eliminar un elemento de una lista vacia
        exit(0);
    }
    switch(OPC){
        case 2: L = ((STATE)L)->next;
                return L;
        break;
        case 3: L = ((TRANSITION)L)->next;
                return L;
        break;
        case 4: L = ((DATA)L)->next;
                return L;
        break;
        default: message_List(5);
        break;
    }
    
}

///////////////////////////////////////////////////////////////////////////////// VISUALIZACION DE LISTAS

void display_List(void* L, int OPC){
    switch(OPC){
        case 2:;
            STATE aux1 = create_List();
            while(!isEmpty_List(L)){
                aux1 = (STATE)L;
                display_Data(aux1->state);
                display_Transition(aux1->transition);
                L = (STATE)remove_List(L, 2);
            }
        break;
        case 3:;
            TRANSITION aux2 = (TRANSITION)create_List();
            while(!isEmpty_List(L)){
                aux2 = (TRANSITION)L;
                display_Transition(aux2);
                L = (TRANSITION)remove_List(L, 3);
            }
        break;
        case 4:;
            DATA aux3 = (DATA)create_List();
            while(!isEmpty_List(L)){
                aux3 = (DATA)L;
                display_Data(aux3);
                L = (DATA)remove_List(L, 4);
            }
        break;
        default: break;
    }
}

void display_Transition(TRANSITION L){
    TRANSITION aux_node;

    while(!isEmpty_List(L)){
        aux_node = L;
        printf("%d-" , aux_node->character);
        display_Data(aux_node->transition);
        L = (TRANSITION)remove_List(L, 3);
    }
}

void display_Data(DATA L){
    DATA aux_node;
    while(!isEmpty_List(L)){
        aux_node = L;
        printf("%d-" , aux_node->state);
        L = (DATA)remove_List(L, 4);
    }
}

///////////////////////////////////////////////////////////////////////////////// CONTROL DE ERRORES

void message_List(int number){
    char* error[6] = {" ERROR DE LISTA '0': No se ha podido reservar memoria D: !!",
                    "ERROR DE LISTA '1': Intenta eliminar un elemento de una lista vacia D: !!",
                    "ERROR DE LISTA '2': La lista a insertar esta vacia D: !!",
                    "ERROR DE LISTA '3': Lista NO compatible para insertar datos D: !!",
                    "ERROR DE LISTA '4': No hay elementos para mostrar en la lista D: !!",
                    "ERROR DE LISTA '5': Opcion no valida D: !!"};
    printf("\n\n %s\n\n", error[number]);
}
