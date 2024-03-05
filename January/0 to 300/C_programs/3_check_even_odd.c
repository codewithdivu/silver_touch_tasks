#include<stdio.h>

int main(){
    int num;
    printf("enter a number which you want to check");
    scanf("%d",&num);
    if(num%2 == 0){
        printf("Number is Even");
    }
    else{
        printf("Number is Odd");
    }
    return 0;
}