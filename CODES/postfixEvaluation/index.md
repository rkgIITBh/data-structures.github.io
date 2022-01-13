## Evaluation of a Postfix Expression

```
#include "stack.h"

int isOperator(char c) {
    return (c=='+'||c=='-'||c=='/'||c=='*'||c=='^');
}

int isOperand(char c) {
    return (1-isOperator(c));
}

int power(int base, int exp) {
    if (exp == 0)
        return 1;
    else if (exp % 2)
        return base * power(base, exp - 1);
    else {
        int temp = power(base, exp / 2);
        return temp * temp;
    }
}

int priority(char c) {
    switch (c) {
        case '+':
        case '-':
             return 0;
        case '*':
        case '/':
             return 1;
        case '^':
             return 2;
     }
     return -2;
}

int compute(int a, int b, char op) {
    switch (op) {
        case '+':
           return a + b;
        case '-':
           return a - b;
        case '*':
           return a * b;
        case '/':
           if (a == 0) {
                printf("Exception: division by zero\n");
                return 0;
           }
           return a / b;
        case '^':
           return power(a,b);
     }
     return 0;
}

int evalPostfix(char* tokens) {
    int i, k,t1,t2,tnew;
    char op;
    
    // Create a stack of capacity equal to expression size 
    STACK* s = createStack(strlen(tokens));
    
    // Exists prematurely if creation of stack is unsuccessful
    if (s == NULL) {
        printf("Error exit: stack creation failed\n");
        exit(1); // Returns prematurely 
    } 
    for (i = 0; tokens[i] != '\0'; i++) {
       if (isOperator(tokens[i])) {
            op = tokens[i]; 
            t2 = pop(s); 
            t1 = pop(s);
            printf("operator:  %c\n",op);
            tnew = compute(t1,t2,op);
            printf("value = %d\n",tnew);
            push(s, tnew);
        } 
        else { 
            printf("Enter value of %c: ",tokens[i]);
            scanf("%d",&t1);
            push(s,t1);
        }
    }
     
    return tnew;
}


int main() {
    char * expression = "ab+c*db/-ab+b^+";
    printf("Value of expression = %d\n",evalPostfix(expression));
}
```
The code works for any expression given in postfix form. However, it requires the operand value to given several times. The readers are encouraged to 
modify the code to seek input only once for each operand.  

[Back to Index](../../index.md)
