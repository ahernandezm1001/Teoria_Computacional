int long_String(int* string);
int long_String(int* string){
    int i = 0;
    while(string[i] != '\0') i++;
    return i;
}


int rewindTxT_5file(FILE file);
int rewindTxT_5file(FILE file){
    int i, k = 1;
    rewind(file);
    c = getc(file);
    for(i = 0; i < 4 ; i++){
        c = getc(file);
        while (c != 10){
            c = getc(file);
            k++;
        } 

    }
    return k;
}

DATA readTxT_States(FILE file, DATA D);
DATA readTxT_States(FILE file, DATA D){
    int buf[100];
    rewind(file);
    while (fscanf(file, "%d,", buf) == 1) D = insert_Data(D, *buf);
    return D;
}

DATA readTxT_Alphabet(FILE file, DATA D){
    char buf[100];
    int c;
    rewind(file);
    c = getc(file):
    while (c != 13) c = fgetc(file);//insertar en lista de estados
    c = getc(file); 
    while (c != 13){ //Lee solo una linea sin comas
        if(c != ',') D = insert_Data(D, c);
        c = getc(file);
    }
    return D;
}


while (fscanf(file, "%d,", buf) == 1) printf("%d", *buf); //insertar en lista de estados
c = getc(file); 
while (c != 13){ //Lee solo una linea sin comas
    if(c != ','){
            printf("%c", c); 
    }
    c = getc(file);
}