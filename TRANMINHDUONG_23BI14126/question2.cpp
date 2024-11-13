#include <iostream>
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


void display(List *number){
    for (int i = 0;i<=number->size;i++){
        if (number->data[i]!=-1){
            cout << number->data[i];
        }
    }
    cout << endl;
}

void add(List *number, int value){
    if (value < 0 || value >9){
        cout << "Invalid, please enter add a number that is from 0 to 9" <<endl;
        return;
    }
    int target = 0;
    //Find the first spot that has not been filled yet (spot with value -1)
    while (target < CAP){
        if (number->data[target] == -1){
            number->data[target] = value;
            break;
        } 
        target ++;
    }
    getLength(number);
}

void remove(List *number, int target){
    number->data[target] = -1;
    getLength(number);
}

void bubbleSort(List *number){
    for (int i = 0;i<number->size;i++){
        for (int j = 0; j <number->size-1;j++){
            if (number->data[i] > number->data[i+1]){
                int temp = number->data[i];
                number->data[i] = number->data[i+1];
                number->data[i+1] = temp;
            }
        }
    }
    
    //Deal with the first number being 0:
    if (number->data[0] == 0){
        int i = 1;
        while (i < number->size){
            if (number->data[i]!=0){
                break;
            }
            i++;
        }
        
        number->data[0] = number->data[i];
        number->data[i] = 0;
    }

}

int main(){
    int N = 2014;

    List* n;
    List* number = init(n);

    int M = N; //create a copy for N, first later on when we print
    while (M){
        add(number,M%10);
        M=M/10;
    }

    bubbleSort(number);
    cout << "The minimum permutation of " << N << " is ";
    display(number);

    return 0;
}