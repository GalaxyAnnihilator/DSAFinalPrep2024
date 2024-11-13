/*
A complex number is given in the form:
    z = a + bi
where a is the real part, b is the imaginary part
A size of a complex number is determined by its modulo:
    |z| = sqrt(a^2 + b^2)
Given an array of complex number
d) Sort this array using recursion + linked list   


*/
#include <iostream>
#include <cmath>
using namespace std;

typedef struct{
    float real;
    float imaginary; 
} Complex;

void swap(Complex* x, Complex* y){
    Complex temp = *x;
    *x = *y;
    *y = temp;
}

void displayComplex(Complex c){
    float a = c.real, b = c.imaginary;
    cout<<a<<" + " <<b<<"i  ";
}

float modulo(Complex c){
    float a,b,modulo;
    a = c.real;
    b = c.imaginary;
    modulo = sqrt(a*a+b*b);
    return modulo;
}

//Linked List
struct Node{
    Complex data;
    Node *next;
};

Node *createNode(float a, float b){
    Node *newNode = new Node;
    Complex c;
    c.real = a;
    c.imaginary =b;
    newNode->data = c;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, float a, float b){
    Node *newNode = createNode(a,b);
    if (*head == NULL){
        *head = newNode;
    }
    else{
        Node *temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node *head){
    Node *temp = head;
    while (temp!=NULL){
        displayComplex(temp->data);
        temp = temp->next;
    }
    cout <<endl;
}

void bubbleSort(Node *head, bool swapped=false){
    if (head == NULL || head->next == NULL){
        return;
    }
    Node* j = head;
    swapped = false;

    while (j->next != NULL){
        if (modulo(j->data) > modulo(j->next->data)){
            swap(&j->data,&j->next->data);
            swapped = true;
        }
        j = j->next;
    }

    if (swapped){
        bubbleSort(head,swapped);
        //bubbleSort(head,swapped = true);
        //bubbleSort(head,swapped = true);
        //...
        //bubbleSort(head,swapped = false); --> Terminate recursion
    }
}

int main(){
    Node *head = NULL;
    
    insertNode(&head,1,2);
    insertNode(&head,3,4);
    insertNode(&head,6,8);
    insertNode(&head,5,2);
    insertNode(&head,11,20);
    insertNode(&head,9,1);
    insertNode(&head,10,0);
    insertNode(&head,2,2);

    printList(head);

    bubbleSort(head);

    printList(head);
}
