#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Car{
    int passenger;
    char id[50];
    struct Car *next;
} Car;

Car* initCar(int passenger,char* id){
    Car *newCar = (Car*)malloc(sizeof(Car));
    newCar->passenger = passenger;
    strcpy(newCar->id,id);
    newCar->next = NULL;
    return newCar;
}

void attachCar(Car **head,int passenger, char *id){
    Car *newCar = initCar(passenger,id);
    newCar->next = *head; //Create new car and attach to the head (first element)
    *head = newCar;
}   

void removeEmptyCar(Car **head){
    //Using item removal algo for Linked List
    Car *cur = *head;
    Car *prev = NULL;
    while (cur!= NULL){
        if (cur->passenger == 0){ //car empty => remove
            if (prev == NULL){ //case when first car is empty
                *head = cur->next;
            }
            else{
                prev->next = cur->next; //Connect the previous node to the next node, skipping the current - removed node
            }
            Car *temp = cur;
            cur = cur->next;
            free(temp);
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    }
}

int lengthTrain(Car *head){
    int length = 0;
    Car *current = head;
    while (current!=NULL){
        length-=-1;
        current = current->next;
    }
    return length;
}

void displayCar(Car *head) {
    Car *current = head;
    while (current != NULL) {
        printf(" _______________ ");
        current = current->next;
    }
    printf("\n");
    
    current = head;
    while (current != NULL) {
        printf("|    %-10s |", current->id);
        current = current->next;
    }
    printf("\n");

    current = head;
    while (current != NULL) {
        printf("| %2d passengers |", current->passenger);
        current = current->next;
    }
    printf("\n");

    current = head;
    while (current != NULL) {
        printf(" ¯O¯¯¯¯¯¯¯¯¯¯¯O¯ ");
        current = current->next;
    }
    printf("\n");
}

void promptHandler(Car *head, int active) {
    while (active) {
        printf("\n>==========COMMANDS TABLE ============<\n");
        printf("1. Add new car\n2. Remove empty cars\n3. Display train\n4. Exit program\n");
        printf("=> Enter the actions you want to perform: ");
        
        int ask;
        scanf("%d", &ask);
        printf(">=====================================<\n\n");

        if (ask == 1) {
            int passenger;
            char id[50];
            printf("Enter the id of the car to add: ");
            scanf("%s",id);
            printf("Enter the number of passenger: ");
            scanf("%d",&passenger);
            attachCar(&head,passenger,id);
            printf("Successfully added!\n");
        } else if (ask == 2) {
            printf("Removing all empty cars...\n");
            removeEmptyCar(&head);
        } else if (ask == 3) {
            displayCar(head);
        } else if (ask == 4) {
            printf("Program ended\n");
            active = 0;
        }
    }
}

int main(){
    Car *train = NULL;
    attachCar(&train,10,"tmduong1");
    attachCar(&train,2,"tmd2");
    attachCar(&train,0,"tmd3");
    attachCar(&train,5,"23BI14126");

    displayCar(train);

    int active = 1;
    promptHandler(train,active);
    return 0;
}