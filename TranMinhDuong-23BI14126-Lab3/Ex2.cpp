#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define CAP 100

typedef struct{
    char url[50];
    char title[50];
}Website;

Website* createWeb(const char url[50],const char title[50]){
    Website* w = (Website*)malloc(sizeof(Website));
    strcpy(w->url,url);
    strcpy(w->title,title);
    return w;
}

typedef struct{
    Website *data;
    int top;
}Stack;

Stack* initStack(){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    st->data = (Website*)malloc(CAP * sizeof(Website));
    st->top = -1;
    return st;
}

int isEmpty(Stack st){
    return (st.top<0);
}

int size(Stack st){
    return st.top+1;
}

void push(Stack *st, Website newweb){
    st->top++;
    st->data[st->top] = newweb;
}

Website pop(Stack *st){
    if (isEmpty(*st)){
        cout << "Stack is empty" << endl;
        Website empty = {"", ""};
        return empty;
    }
    else{
        Website temp = st->data[st->top];
        st->top--;
        return temp;
    }
}

void display(Stack *forward, Stack *backward) {
    cout << "\nBackward: ";
    if (isEmpty(*backward)) {
        cout << "[Empty]";
    } else {
        for (int i = 0; i <= backward->top; i++) {
            cout << backward->data[i].title << " (" << backward->data[i].url << "), ";
        }
    }

    cout << "\nForward: ";
    if (isEmpty(*forward)) {
        cout << "[Empty]";
    } else {
        for (int i = 0; i <= forward->top; i++) {
            cout << forward->data[i].title << " (" << forward->data[i].url << "), ";
        }
    }
    cout << endl <<endl;
}

void lastWeb(Stack *forward, Stack *backward) {
    if (isEmpty(*backward)) {
        cout << "No more websites to go back to!" << endl;
        return;
    }
    Website web = pop(backward);
    push(forward, web);
    cout << " <-- Moved backward to: " << web.title << " (" << web.url << ")" << endl;
    display(forward,backward);
}

void nextWeb(Stack *forward, Stack *backward) {
    if (isEmpty(*forward)) {
        cout << " -!- No more websites to go forward to!" << endl <<endl;
        return;
    }
    Website web = pop(forward);
    push(backward, web);
    cout << " --> Moved forward to: " << web.title << " (" << web.url << ")" << endl;
    display(forward,backward);
}

int main() {
    Website* w1 = createWeb("usth.edu.vn","USTH main page");
    Website* w2 = createWeb("google.com","Google");
    Website* w3 = createWeb("facebook.com","Facebook");
    Website* w4 = createWeb("youtube.com","Youtube");

    Stack *backward = initStack();
    Stack *forward = initStack();

    push(backward,*w1);
    push(backward,*w2);
    push(backward,*w3);
    push(backward,*w4);

    display(forward,backward);

    nextWeb(forward,backward);

    lastWeb(forward,backward);

    lastWeb(forward,backward);

    lastWeb(forward,backward);

    lastWeb(forward,backward);

    lastWeb(forward,backward);

    return 0;
}
