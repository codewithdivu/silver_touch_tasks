
// recursive way
#include<stdio.h>

int factorial(int num){
    if(num==1 || num==0){
        return 1;
    }
    return num*factorial(num-1);
}


int main(){
    int num;
    printf("enter a number which you want factorial");
    scanf("%d",num);
    int fact = factorial(num);
    printf("factorial of given number is %d",fact);
    return 0;
}




// iterative way



int main(){
    int num;
    printf("enter a number which you want factorial");
    scanf("%d",num);
    int fact = 1;
    for(int i=1;i<=num;i++){
        fact = fact*i;
    }
    printf("factorial of given number is %d",fact);
    return 0;
}