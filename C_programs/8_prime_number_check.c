#include<stdio.h>
#include<math.h>

int main(){
    int num;
    printf("enter a number which you want to check for prime number");
    scanf("%d",&num);

    for(int i=1;i<sqrt(num);i++){
        if(num%i == 0){
            printf("number is not-Prime");
            return;
        }
    }

    printf("Number is Prime");
    return 0;
}