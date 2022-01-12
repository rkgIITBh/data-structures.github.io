## Infix to Postfix Converter Using Stack

```
#ifndef CONVPOST_H
#define CONVPOST_H

// Returns true if the character is an operand
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Computes precedence of the operators
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

int postfixConverter(char* tokens) {
    int i, k;
    ITEMS item;
    
    // Create a stack of capacity equal to expression size 
    STACK* s = createStack(strlen(tokens));
    
    // Exists prematurely if creation of stack is unsuccessful
    if (s == NULL) {
        printf("Error exit: stack creation failed\n");
        exit(1); // Returns prematurely 
    } 
    for (i = 0, k = -1; tokens[i]; ++i) {
        
        // Send operands directly to the output 
        if (isOperand(tokens[i]))
            tokens[++k] = tokens[i];
        
        else if (tokens[i] == '(') {
            item.type = CHAR;
            item.itemval.cval = '(';
            push(s, &item);
        } 
        // If current scanned symbol is an ‘)’, continue popping 
        // characters from the stack to output until encountering ‘(‘. 
        else if (tokens[i] == ')') {
            while (!isEmpty(s) && peek(s).itemval.cval != '(')
                tokens[++k] = pop(s).itemval.cval;
            if (!isEmpty(s) && peek(s).itemval.cval != '(')
                return -1; // invalid expression             
            else
                pop(s);
        }
        else { 
            // An operator is encountered 
            while (!isEmpty(s) && pri(tokens[i]) <= pri(peek(s).itemval.cval))
                tokens[++k] = pop(s).itemval.cval;
            item.type = CHAR;
            item.itemval.cval = tokens[i];
            push(s, &item);
        }

    }

    // Pop and send all the operators from the stack to output
    while (!isEmpty(s)) 
        tokens[++k] = pop(s).itemval.cval;

    tokens[++k] = '\0';
    return 1;
}
#endif

```
The main function is quite simple to write. We leave to the reader. 

[Back to Index](../../index.md)
