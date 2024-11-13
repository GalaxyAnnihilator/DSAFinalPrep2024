#include <iostream>
#include <stdlib.h>
using namespace std;
#define CAP 100

typedef struct{
    int data[CAP];
    int top;
}Stack;

Stack* init(){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    st->top = -1;
    return st;
}

int isEmpty(Stack st){
    return (st.top<0);
}

int size(Stack st){
    return st.top+1;
}

void push(Stack *st, int val){
    st->top++;
    st->data[st->top] = val;
}

int pop(Stack *st){
    if (isEmpty(*st)){
        cout << "Stack empty" <<endl;
        return -1;
    }
    else{
        int temp = st->data[st->top];
        st->top--;
        return temp;
    }
}

int evaluatePostfix(string& expr) {
    Stack* st = init();
    
    for (char ch : expr) {
        if (isdigit(ch)) {
            push(st, ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val2 = pop(st);
            int val1 = pop(st);
            int result;
            
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            push(st, result);
        }
    }

    return pop(st);
}

int main() {
    string postfixExpr = "45*82/+";
    int result = evaluatePostfix(postfixExpr);
    cout << "Postfix: " << postfixExpr << " = " << result<<  endl;

    //This only works with number of 1 digit, if there's a 2-digit number, it wont work

    return 0;
}
