#include <stdio.h>
int main(){
    int num1, num2, result, choice;
    scanf("%d", &num1); 
    scanf("%d", &num2);
    printf("choice: 1: Addition\n"); 
    printf("choice: 2: Substraction\n");
    printf("choice: 3: Multiplication\n");
    printf("choice: 4: Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
        result= num1+num2;
        printf("%d", result);
        break;
        case 2:
        result= num1-num2;
        printf("%d", result);
        break;
        case 3:
        result= num1*num2;
        printf("%d", result);
        break;
        case 4:
        if(num2 != 0){
        result= num1/num2;
        printf("%d", result);}
        else{
            printf("Number is not be divisible by 0");
        }
        break;
        default: 
        printf("Invalid choice number entered");
    }
}