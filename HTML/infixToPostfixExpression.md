## Converting an Infix Expression to a Equivalent Postfix form
Evaluation of arithmetic expressions was introduced in an earlier blog on 
the stack. The operators we are familiar with are binary, i.e., each requires two operands. It is, therefore, natural to represent arithmetic expressions 
using binary trees. The leaf nodes store operands in a binary expression tree, and internal nodes store operators. A binary expression tree appears in the figure below. 
<p align="center">
<img src="../images/expressionTree.jpg">
</p>
Traversals of the tree may give different forms of the expression:

- Preorder traversal list gives the prefix form of the expression,
- Postorder traversal list gives the postfix form of the expression,
- Inorder traversal list gives the infix form of the expression.

We are familiar with the infix form of an arithmetic expression. Evaluation infix expression is complicated. 
It requires managing precedence of operators and evaluating parenthetic expressions inside out.  
If we need to evaluate a few arithmetic expressions in a program repeatedly. It will be better to use an expression form that is 
simpler to evaluate. The evaluation is simpler provided:

- If the expression requires one single scan which preserves the rules of evaluation.
- If it does not require any complicated data structure
- If it does not require memory space over the order of expression length
- If it does not require time over the order of expression length

The postfix form of an arithmetic expression satisfies the properties stated above. Before discussing postfix expression, let us briefly examine if
the prefix form of an arithmetic expression can meet the state properties. In prefix form, an operator appears before its operands. 
Consider the following expression given in conventional infix form. 
<p align="center">
  <img src="https://latex.codecogs.com/svg.image?(a&plus;b)*c-d/b&plus;(a&plus;b)^{b}" title="(a+b)*c-d/b+(a+b)^{b}" />
</p>
We can get the prefix form from the preorder list of the corresponding expression tree. However, we can also transform the infix form of an 
expression into its prefix form in the following way.

- Fully parenthesize the expression according to desired evaluation order
- Replace each opening parenthesis by its closest operator to right
- Remove all closing parentheses.

For example, the fully parenthesized form of the expression 
<p align="center">
<img src="https://latex.codecogs.com/svg.image?(a&plus;b)*c&space;-&space;d/e&space;&plus;&space;(a&plus;b)^b" title="(a+b)*c - d/e + (a+b)^b" /> 
</p>
is given by 
<p aling="center">
<img src="https://latex.codecogs.com/svg.image?((((a&plus;b)*c)&space;-&space;(d/b))&space;&plus;&space;(a&plus;b)^b)" title="((((a+b)*c) - (d/b)) + (a+b)^b)" />.
</p>
After replacing each opening parenthesis by its closest operator to right, we get
<p align="center">
<img src="https://latex.codecogs.com/svg.image?&plus;&space;-&space;*&space;&plus;&space;a&space;b&space;c&space;/&space;d&space;e\&space;\&space;\widehat{}&space;&plus;&space;a&space;b&space;b." title="+ - * + a b c / d e\ \ \widehat{} + a b b." />
  </p>
The prefix expression can be evaluated by scanning from right end. In the following evaluation procedure, we denote the intermediate values by the temporaries <img src="https://latex.codecogs.com/svg.image?t_i,&space;i=1.2.\ldots" title="t_i, i=1.2.\ldots" />

- Set <img src="https://latex.codecogs.com/svg.image?t_1&space;=&space;(a&plus;b)" title="t_1 = (a+b)" /> the modified expression becomes: <img src="https://latex.codecogs.com/svg.image?&plus;&space;-&space;*&space;&plus;&space;a&space;b&space;c&space;/&space;d&space;e\&space;\&space;\widehat{}&space;t_1&space;b." title="+ - * + a b c / d e \widehat{} t_1 b." />

- Set <img src="https://latex.codecogs.com/svg.image?t_2=t_1^b" title="t_2=t_1^b" /> modified expression become: <img src="https://latex.codecogs.com/svg.image?&plus;&space;-&space;*&space;&plus;&space;a&space;b&space;c&space;/&space;d&space;e&space;t_2." title="+ - * + a b c / d e t_2." />

- Set <img src="https://latex.codecogs.com/svg.image?t_3=d/e" title="t_3=d/e" /> , modified expression is: <img src="https://latex.codecogs.com/svg.image?&plus;&space;-&space;*&space;&plus;&space;a&space;b&space;c&space;t_3&space;t_2." title="+ - * + a b c t_3 t_2." />
 
- Set <img src="https://latex.codecogs.com/svg.image?t_4=a+b" title="t_4=a+b" /> modified expression is: <img src="https://latex.codecogs.com/svg.image?&plus;&space;-&space;*&space;t_4&space;c&space;t_3&space;t_2." title="+ - * t_4 c t_3 t_2." />
 
- Set <img src="https://latex.codecogs.com/svg.image?t_5=t_4*c" title="t_5=t_4*c" /> modified expression is: <img src="https://latex.codecogs.com/svg.image?&plus;&space;-&space;t_5&space;t_3&space;t_2." title="+ - t_5 t_3 t_2." />
 
- Set <img src="https://latex.codecogs.com/svg.image?t_6=t_5-t_3" title="t_6=t_5-t_3" />  modified expression is <img src="https://latex.codecogs.com/svg.image?&plus;&space;t_6&space;t_2." title="+ t_6 t_2." />
 

- The final result is: <img src="https://latex.codecogs.com/svg.image?t_7=t_6 + t_2" title="t_7=t_6+t_2" />    

The process requires backward and forward scanning of the expression. Therefore, the evaluation of prefix form is not simple.

We can create an equivalent postorder expression from a fully parenthesized expression as follows:

- Replace each closing parenthesis by its closest operator to left,
- Remove all opening parentheses.

The procedure for creating prefix and postfix expressions from an infix expression is illustrated in the figure below.
<p align="center">
<img src="../images/infixPostfix.jpg">
</p>
Evaluation of the postfix form of expression using a stack is quite simple. The stack holds the operands until an operator is encountered. Then repeatedly
perform the following steps.

- Pop two operand from the stack
- two operand from the stack

Once an operator is found, pop the required pair of operands on the top of the stack. Compute the result and push the result back to the stack. 
Repeatedly perform computations until reaching the end of the input. So, the evaluation process is simple.
However, the important initial step is to transform the infix form of an expression to postfix form. If a tree form of the expression is available, 
then the postorder traversal list gives the desired postorder form.  

A C program for coverting the infix form of an expression to its equivalent postfix form is provided for the reader's reference.

[program](../CODES/infixToPostfixConverter/index.md)

[Back to Index](../index.md)
