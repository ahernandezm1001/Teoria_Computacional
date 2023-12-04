/* 
Codigo Escrito por: Hernandez Mejia Alvaro
Contacto: noragamidrrr@gmail.com
*/

#ifndef _simpleList_
#define _simpleList_
#define TRUE 1
#define FALSE 0
#define STRUCT_S 2
#define STRUCT_T 3
#define STRUCT_D 4

typedef struct Data{
	int state;
	struct Data* next;
}Data;
typedef Data* DATA;

typedef struct Transition{
	int character;
	struct Data* transition;
	struct Transition* next;
}Transition;
typedef Transition* TRANSITION;

typedef struct State{
	struct Data* state;
	struct Transition* transition;
	struct State* next;
}State;
typedef State* STATE;

void* create_List(void);
int isEmpty_List(void*);
void validate_Creation(void*);
DATA create_Data_Node(void);
TRANSITION create_Transition_Node(void);
STATE create_State_Node(void);
DATA insert_Data(DATA, int);
TRANSITION insert_Transition(TRANSITION, DATA, int);
STATE insert_State(STATE, STATE);
void* insert_Data_List(void*, DATA, int);
void* remove_List(void*, int);
void display_List(void*, int);
void display_Transition(TRANSITION);
void display_Data(DATA);
void message_List(int);

#endif