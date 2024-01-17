#include<stdio.h>

int main(){
    int num1, num2, num3;
    printf("enter 3 numbers one by one");
    scanf("%d",&num1);
    scanf("%d",&num2);
    scanf("%d",&num3);

    if(num1 > num2 && num1>num3){
        printf("Largest number is %d",num1);
    }
    else if(num2 > num1 && num2 > num3){
        printf("Largest number is %d",num2);
    }
    else{
        printf("Largest number is %d",num3);
    }

    return 0;
}