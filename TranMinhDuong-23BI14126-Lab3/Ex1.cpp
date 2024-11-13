#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#define CAPACITY 100

typedef struct {
    char name[50];
    int k;
} Customer;

Customer* create(const char nameAssign[50], int k) {
    Customer* c = (Customer*)malloc(sizeof(Customer));
    strcpy(c->name, nameAssign);
    c->k = k;
    return c;
}

void buy(Customer *cli, string item, int quantity, int &pizzaCount, int &hamburgerCount) {
    if (cli->k < quantity) {
        cout << cli->name << " wants to buy more than they are allowed!" << endl;
        return;
    }

    if (item == "pizza") {
        if (pizzaCount < quantity) {
            cout << "Not enough pizza for " << cli->name << " to buy." << endl;
            return;
        }
        pizzaCount -= quantity;
        cout << cli->name << " bought " << quantity << " pizza(s)." << endl;
    } 
    else if (item == "hamburger") {
        if (hamburgerCount < quantity) {
            cout << "Not enough hamburgers for " << cli->name << " to buy." << endl;
            return;
        }
        hamburgerCount -= quantity;
        cout << cli->name << " bought " << quantity << " hamburger(s)." << endl;
    } 
    else {
        cout << "Unknown item!" << endl;
    }
}

typedef struct {
    int capacity;
    int front, back;
    Customer *data;
} Queue;

Queue* init(int N) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->back = 0;
    q->front = 0;
    q->capacity = N;
    q->data = (Customer*)malloc(q->capacity * sizeof(Customer));
    return q;
}

int isEmpty(Queue *q) {
    return (q->back == q->front);
}

int length(Queue *q) {
    return q->back - q->front;
}

int enqueue(Queue *q, Customer newCus) {
    if (length(q) == q->capacity) {
        cout << "Queue is full!" << endl;
        return 0;
    }
    q->data[q->back++] = newCus;
    return 1;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue is empty!" << endl;
        return 0;
    }
    q->front++; //no shifting
    return 1;
}

void displayItems(int pizzaCount, int hamburgerCount) {
    cout << endl << "Pizza remaining: " << pizzaCount << endl;
    cout << "Hamburger remaining: " << hamburgerCount << endl << endl;
}

int main() {
    int pizzaCount = 5, hamburgerCount = 7;

    Queue *q = init(CAPACITY);

    Customer *c1 = create("tmd", 5);
    Customer *c2 = create("tranminhduong", 8);

    enqueue(q, *c1);
    enqueue(q, *c2);

    // Customer 1 buys
    buy(c1, "pizza", 2, pizzaCount, hamburgerCount);
    buy(c1, "hamburger", 3, pizzaCount, hamburgerCount);

    displayItems(pizzaCount, hamburgerCount);

    dequeue(q); //remove customer 1

    // Customer 2 buys
    buy(c2, "hamburger", 6, pizzaCount, hamburgerCount);
    buy(c2, "pizza", 9, pizzaCount, hamburgerCount); // Not enough pizza

    displayItems(pizzaCount, hamburgerCount);

    dequeue(q); //remove customr2

    free(c1);
    free(c2);
    free(q->data);
    free(q);

    return 0;
}
