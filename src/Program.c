#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Knot Knot;

struct Knot{
    int data;
    Knot *next;
    Knot *previous;
}*start=NULL, *end=NULL;

int menu(){
    int op;
    printf("Choose: \n1 - Push. \n2 - Pop. \n3 - Show. \n0 - Finish. \nOption: ");
    scanf("%d", &op);
    return op;
}

void push(int num){
    Knot *new;
    new = (Knot*) malloc(sizeof(Knot));
    new->data = num;

    if(start == NULL){
        new->next = start;
        new->previous = end;
        start = end = new;
    }else{
        new->next = end;
        new->previous = NULL;
        new->next->previous = new;
        end = new;
    }
    printf("\nNUMBER SUCCESSFULLY ENTERED.\n\n");
}

void show(){
    Knot *aux = start;
        
    printf("\n+----------------------------------------------------------------------+\n| List:");
    while (aux != NULL){
        printf(" %d ", aux->data);
        aux = aux->previous;
    }
    printf("\n+----------------------------------------------------------------------+\n\n");
}

void pop(){
    if(start != end){
        Knot *aux = start;
        start = aux->previous;
        start->next = NULL;
        aux = NULL;
    }else{
        start = NULL; 
        end = NULL;
    }
    printf("\nNUMBER SUCCESSFULLY DELETED.\n\n");
}

int check_list(){
    if(end)
        return 1;
    else{
        printf("\nEMPTY LIST.\n\n");
        return 0;
    }
}

int main(){
    system("cls");
    int op, num;
    do{
        op=menu();
        switch (op){
        case 1: // PUSH
            printf("\nEnter a number to be inserted in the list: ");
            scanf("%d", &num);
            push(num);
            break;

        case 2: // POP
            if(check_list())
                pop();
            break;

        case 3: // PRINTS THE LIST
            if(check_list())
                show();
            break;

        case 0: // EXIT THE SYSTEM
            printf("\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("|         EXITING THE SYSTEM          |\n");
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\n");
            sleep(2);
            break;
        default:
            printf("\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("|           INVALID OPTION            |\n");
            printf("|   ENTER AN OPTION BETWEEN 0 AND 3   |\n");
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\n");
            break;
        }
    }while(op);
}