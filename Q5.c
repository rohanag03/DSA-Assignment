#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    int CPU_time;
    struct node *next;
};

void create(struct node **st){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    
    /*Input of ID and CPU time*/
    printf("Enter the Program ID: ");
    scanf("%d", &n->id);
    printf("Enter the CPU time: ");
    scanf("%d", &n->CPU_time);

    n->next = NULL;

    if(*st == NULL)
        *st = n;
    else{
        struct node *temp = (*st);
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }
}
int isEmpty(struct node *temp){
    if(temp == NULL)
        return 0;
    else
        return 1;
}
void execution(struct node **st, int qt){
    struct node *temp = (*st);
    while(isEmpty(temp) != 0){
        if(temp -> CPU_time <= qt)
        {
            struct node *toBeFreed = temp;
            free(toBeFreed);
        }
        else
        {
            temp->CPU_time -= qt;
            struct node *toBeAdded = temp;
            struct node *whereToAdd = temp;
            while(whereToAdd -> next != NULL)
                whereToAdd = whereToAdd->next;

            whereToAdd->next = toBeAdded;
            toBeAdded->next = NULL;
        }
        temp = temp->next;
    }
}

int main(){
    struct node *head = NULL;
    int num;
    printf("Enter the no. of programs: ");
    scanf("%d", &num);
    for (int i = 0; i < num;i++)
        create(&head);

    int qt;
    printf("Enter the quantum time: ");
    scanf("%d", &qt);
    execution(&head, qt);
    printf("All programs executed.\n");
}
