## Infix to Postfix Converter Using Stack

```

#ifndef CONVPOST_H
#define CONVPOST_H
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Computes precedence or the operators
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
    
    // Create a stack of capacity equal to the expression size 
    STACK* s = createStack(strlen(tokens));
    
    // Check if the stack is created successfully
    if (s == NULL) {
        printf("Error exit: failure in stack creation\n");
        return 0; // Returns prematurely 
    }
   
    for (i = 0, k = -1; tokens[i]; ++i) {
        
        // If the scanned character is an operand, add it to output.
        if (isOperand(tokens[i]))
            tokens[++k] = tokens[i];
        
        else if (tokens[i] == '(') {
            item.type = CHAR;
            item.itemval.cval = '(';
            push(s, &item);
        } 
        // If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘.
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

    // Pop all operators from the stack
    while (!isEmpty(s)) 
        tokens[++k] = pop(s).itemval.cval;

    tokens[++k] = '\0';
    return 1;
}
```
