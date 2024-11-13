#include <iostream>
#include <stdlib.h>
using namespace std;
#define CAP 100

typedef struct{
    int size;
    int data[CAP];
}List;

List* init(List *number){
    number = (List*)malloc(sizeof(List));
    
    for (int i = 0;i<CAP;i++){
        number->data[i] = -1;
    }

    number->size=0;
    return number;
}

int getLength(List* number){
    int l = 0;
    for (int i = 0;i<CAP;i++){
        if (number->data[i] != -1){
            l = i; //update l
        }
    }
    number->size = l;
    return l;
}

int sum(List* number){
    int s = 0;
    for (int i = 1;i<=number->size;i++){
        s += number->data[i];
    }
    cout << "The sum is " << s << endl;
    return s;
}

void display(List *number){
    if (number->data[0]=-1){
        cout << "-";
    }
    else{
        cout << "+";
    }

    for (int i = 1;i<=number->size;i++){
        if (number->data[i]!=-1){
            cout << number->data[i];
        }
        else{
            cout << "_";
        }
    }
    cout << endl;
}

void add(List *number, int target, int value){

    if (value < 0 || value >9){
        cout << "Invalid, please enter add a number that is from 0 to 9" <<endl;
        return;
    }
    number->data[target] = value;
    getLength(number);
}

void remove(List *number, int target){
    number->data[target] = -1;
    getLength(number);
}

int main(){
    List* n;
    List* number = init(n);
    
    // for (int i = 0;i<5;i++){
    //     if (i==0){
    //         cout<<"Enter the sign (1 for positive, -1 for negative): ";
    //         int temp;
    //         cin >> temp;
    //         while (abs(temp)!=1){
    //             cout << "Invalid, please enter 1 or -1 only: ";
    //             cin >> temp;
    //         }
    //         add(number,i,temp);

    //     }
    //     else{
    //         cout << "Enter the " << i << "th digit: ";
    //         int temp;
    //         cin >> temp;
    //         while (temp < 0 || temp > 9){
    //             cout << "Invalid, please enter digit in range from 0 to 9: ";
    //             cin >> temp;
    //         }
    //         add(number,i,temp);

    //     }
    // }

    add(number,0,1); //sign
    add(number,1,2);
    add(number,2,4);
    add(number,3,6);
    add(number,4,7);
    add(number,5,11); // this will throw an error

    display(number);
    sum(number);
    return 0;
}