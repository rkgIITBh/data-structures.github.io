## Evaluation of Infix Expression Using Two Stacks

```
#ifndef INFIX_H
#define INFIX_H

int pri(char ch) {
    switch (ch) {
    	case '(':
    		return 1;
	    case '+':
	    case '-':
	        return 2;

	    case '*':
	    case '/':
	        return 3;

	    case '^':
	        return 4;
    }
    return -1;
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

ITEMS compute(ITEMS optr, ITEMS opnd1, ITEMS opnd2) {
    ITEMS temp;
    int a = opnd1.itemval.ival;
    int b = opnd2.itemval.ival;
    char c = optr.itemval.cval;

    temp.type = INT;
    
    switch (c) {
        case  '+': 
		    temp.itemval.ival = a + b;
            break;
	    case '-':
		    temp.itemval.ival = a - b ;
            break;
        case '*': 
		    temp.itemval.ival = a * b;
            break;
	    case '/':
		    if(b > 0){
		    	temp.itemval.ival = a/b;
		    } else 
                temp.itemval.ival =0;
		    break ;
	    case '^':
		    temp.itemval.ival = power(a,b);
            break;
        default:
	        temp.itemval.ival = -1;
    }
    return temp;
}


int isOperator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': 
            return 1;
        default:
            return 0;
    }
}


int evalInfixExpr(char *tokens) {
    STACK * s1; // Operand stack
    STACK * s2; // Operator stack

    ITEMS item, p, q, op; // Local variables 
    int i, ICP, num; // Local variables

    s1 = createStack(30); // Create operands stack
    s2 = createStack(30); // Create operator stack
    
    i=0; // Initialize the index of expression string

	printf("InFix Expression: %s\n", tokens);

	while(tokens[i] != '\0') {
		if(tokens[i] == '(') {
            item.type = CHAR;
            item.itemval.cval = tokens[i];
			push(s2,&item);
		} else if(tokens[i] == ')') {
			while(peek(s2).itemval.cval != '(') {
                // Evaluate expression within parentheses 
                // Compute and push temporary value to operands stack  
				q = pop(s1); // Operand 1
				p = pop(s1); // Operand 2
                op = peek(s2); // Operator
                item = compute(op,p,q); // Compute 
				push(s1, &item); // Push the computed value 
			    pop(s2); 
			}
			pop(s2);
		} else if(isOperator(tokens[i])) {
			ICP = pri(tokens[i]); // Incoming operator's priority 
			while(!isEmpty(s2) && pri(peek(s2).itemval.cval) >= ICP) {
                // On stack priority equal and greater
                // Compute and push temporary value to operands stack  
				q = pop(s1); 
				p = pop(s1); 
                op = peek(s2); 
                item = compute(op,p,q); 
				push(s1,&item);
				pop(s2); // Discard the operator 
			}
            item.type = CHAR;
            item.itemval.cval = tokens[i]; 
			push(s2,&item);
		} else {
            // Compute the operand value ASCII value of digits 
            num = 0;
            while (isdigit(tokens[i])) {
                num = num*10 + (tokens[i] - 48); 
                i++; // Increment index to the next digit
            }
            i--; // Reset index to kill extra increment on loop exit 
           
			item.type = INT;
            item.itemval.ival = num; 
			push(s1, &item);
		}
		i++;
	}

	while(!isEmpty(s2)) {
        // Compute the rest of the expression on operand stack
		q = pop(s1);
		p = pop(s1);
        op = peek(s2);
		item = compute(op,p,q);
		push(s1,&item);
		pop(s2); 
	}

	return peek(s1).itemval.ival;

}
#endif
```
The driver program or the main() function will require "multistack.h" apart from "infix.h" file. A small sample code for main() function is given below for the
reader's reference.
```
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "multiStack.h"
#include "infixExpression.h"

int main(){
	char str[] = "((3^2+14)*(15*(4+1))-24/(2+10))";
        int result = evalInfixExpr(str);
	printf("\nResult: %d\n", result);
}
```

[Back to Index](../index.md)
