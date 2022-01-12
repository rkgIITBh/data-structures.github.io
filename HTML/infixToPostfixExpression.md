## Converting an Infix Expression to a Equivalent Postfix form

Evaluation of arithmetic expressions was introduced in an earlier blog on 
the stack. The operators we are familiar with are binary, i.e., each requires two operands. It is, therefore, natural to represent arithmetic expressions 
using binary trees. The leaf nodes store operands in a binary expression tree, and internal nodes store operators. A binary expression tree appears in the figure below. 
<p align="center">
<img src="../images/expressionTree.jpg">
</p>
Traversals of the tree may give different forms of the expression:
<ol>
<li>Preorder traversal list gives the prefix form of the expression,</li>
<li>Postorder traversal list gives the postfix form of the expression,</li>
<li>Inorder traversal list gives the infix form of the expression,</li>
</ol>
We are familiar with the infix form of an arithmetic expression. Evaluation infix expression is complicated. 
It requires managing precedence of operators and evaluating parenthetic expressions inside out.  
If we need to evaluate a few arithmetic expressions in a program repeatedly. It will be better to use an expression form that is 
simpler to evaluate. We consider an evaluation simpler provided:
<ul>
<li>If the expression requires one single scan which preserves the
rules of evaluation.</li> 
<li>If it does not require any complicated data structure</li> 
<li>If it does not require memory space over the order of
expression length</li> 
<li>If it does not require time over the order of expression length</li>
</ul>
The postfix form of an arithmetic expression satisfies the properties stated above. Before discussing postfix expression, let us briefly examine if
the prefix form of an arithmetic expression can meet the state properties. In prefix form, an operator appears before its operands. 
Consider the following expression given in conventional infix form. 
<p align="center">
  <img src="https://latex.codecogs.com/svg.image?(a&plus;b)*c-d/b&plus;(a&plus;b)^{b}" title="(a+b)*c-d/b+(a+b)^{b}" />
</p>
We can get the prefix form from the preorder list of the corresponding expression tree. However, we can also transform the infix form of an 
expression into its prefix form in the following way.
<ul>
<li>Fully parenthesize the expression according to desired evaluation order</li>
<li>Replace each opening parenthesis by its closest operator to right</li>
<li>Remove all closing parentheses.</li>
</ul>
For example, the fully parenthesized form of  expression 
(a+b)*c - d/b + (a+b)^b
is given by
((((a+b)*c) - (d/b)) + (a+b)^b).
After replacing each opening parenthesis by its closest operator to right, we get
+-*+abc/de^+abb
A prefix expression can be evaluated starting from right end. In the following evaluation procedure, we denote the intermediate values by the temporaries t<sub>i</sub>, <i>i=1,2, ...</i>. 
<ul>
<li>Set t<sub>1</sub>=a+b, the modified expression becomes: +-*+abc/d^t<sub>1b</sub>b</li>
<li>Set t<sub>2</sub>= t<sub>1</sub>(a+d)<sup>b</sup>, modified expression become: +-*+abc/dt<sub>2</sub></li>
<li>Set t<sub>3</sub>=d/e, modified expression is: +-*+abct<sub>3</sub>t<sub>2</sub></li>
<li>Set t<sub>4</sub>=a+b, modified expression is: +-*t<sub>4</sub>ct<sub>3</sub>Set t<sub>2</sub></li>
<li>Set t<sub>5</sub>=(a+b)*c, modified expression is: +-t<sub>5</sub>t<sub>3</sub>t<sub>2</sub></li>
<li>Set t<sub>6</sub>=(a+b)-(d/e), modified expression is +t<sub>6t<sub>2</li>
<li>The final result is: t</sub>7</sub> = t</sub>6</sub>+t</sub>2</sub> =(a+b) - (d/e) + (a+b)^b</li>
</ul>
The process requires backward and forward scanning of the expression. Therefore, the evaluation of prefix form is not simple.

We can create an equivalent postorder expression from a fully parenthesized expression as follows:
<ul>
<li>Replace each closing parenthesis by its closest operator to left</li>
<li>Remove all opening parentheses.</li>
</ul>
The procedure for creating prefix and postfix expressions from an infix expression is illustrated in the figure below.
<p align="center">
<img src="../images/infixPostfix.jpg">
</p>
Evaluation of the postfix form of expression using a stack is quite simple. The stack holds the operands until an operator is encountered. Then repeatedly
perform the following steps.
<ol>
<li>Pop two operand from the stack</li>
<li>two operand from the stack</li>
</ol>
Once an operator is found, pop the required pair of operands on the top of the stack. Compute the result and push the result back to the stack. 
Repeatedly perform computations until reaching the end of the input. So, the evaluation process is simple.
However, the important initial step is to transform the infix form of an expression to postfix form. If a tree form of the expression is available, 
then the postorder traversal list gives the desired postorder form.  

A C program for coverting the infix form of an expression to its equivalent postfix form is provied 
[here](../CODES/infixToPostfixConverter/index.md)


[Back to Index](../index.md)
