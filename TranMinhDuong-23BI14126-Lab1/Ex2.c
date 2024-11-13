#include <stdio.h>

void findMax(int *max,int a){
    if (a>*max){
        *max = a;
    }
}

int main(){
    int x = 10, y = 20;
    int *max;
    findMax(max,x);
    findMax(max,y);

    printf("%d\n",*max);
    return 0;
}