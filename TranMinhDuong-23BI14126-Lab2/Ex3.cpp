#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *createNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isPrime(int x){
    if (x<=1){
        return false;
    }
    if (x<=3){
        return true;
    }
    for(int i = 2;i*i<=x;i++){
        if (x%i==0){
            return false;
        }
    }
    return true;
}

bool condition(int a, int b) {
    if (isPrime(a)&&isPrime(b)&&(a-b == 2 || b-a==2)){

        return true;
    }
    return false;
}

void loop(Node *head, int ind_a, int ind_b, int length) {
    Node *temp = head;
    int a, b;
    for (int i = 0; i < ind_a; i++) {
        temp = temp->next;
    }
    a = temp->data;
    for (int i = 0; i < ind_b - ind_a; i++) {
        temp = temp->next;
    }
    b = temp->data;
    if (condition(a,b)) {
        cout << a << " " << b << endl;
    }
    if (ind_b < length - 1) {
        loop(head, ind_a, ind_b + 1, length);
    } else if (ind_a < length - 2) {
        loop(head, ind_a + 1, ind_a + 2, length);
    }
}

int main()
{
  Node *head = NULL;
  insertNode(&head, 3);
  insertNode(&head, 101);
  insertNode(&head, 96);
  insertNode(&head, 47);
  insertNode(&head, 41);
  insertNode(&head, 7);
  insertNode(&head, 65);
  insertNode(&head, 9);
  insertNode(&head, 13);
  insertNode(&head, 5);
  insertNode(&head, 79);
  insertNode(&head, 45);
  insertNode(&head, 30);
  insertNode(&head, 11);
  insertNode(&head, 43);
  printList(head);
  loop(head, 0, 1, 15);
}