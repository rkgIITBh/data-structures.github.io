<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.0/MathJax.js?config=TeX-AMS_CHTML"> </script> <script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: { inlineMath: [['$','$'], ['\\(','\\)']], processEscapes: true}, jax: ["input/TeX","input/MathML","input/AsciiMath","output/CommonHTML"], extensions: ["tex2jax.js","mml2jax.js","asciimath2jax.js","MathMenu.js","MathZoom.js","AssistiveMML.js", "[Contrib]/a11y/accessibility-menu.js"], TeX: { extensions: ["AMSmath.js","AMSsymbols.js","noErrors.js","noUndefined.js"], equationNumbers: { autoNumber: "AMS" } } }); </script> 

## Analysis of Open Address Hashing

We analyze the complexity of both successful and unsuccessful search in open address hashing ignoring clustering. All probe sequences are equally likely.
In the case of unsuccessful search, every probe except the last one hit an occupied slot and the last probe accesses an empty slot.
We define a random variable $$X$$ which denotes the number of probes made for the unsuccessful search. If $$E_i$$ to be event for $$i = 1, 2, \ldots$$ 
probes and this probe gives an occupied slot. Then the probability of the event $$\{X \ge i\}$$ is the probability of 
intersection of all events $$E_1, E_2, \ldots E_i$$, i.e., 
<p style="text-align:center">
  $$Pr\{X\ge i\} = Pr(E_1\cap E_2\cap\ldots\cap E_i)$$
</p>   
The RHS of above expression is the same as:
<p style="text-align:center">
  $$Pr(E_1\cap E_2\cap\ldots\cap E_i) = Pr(E_1).Pr(E_2|E_1).Pr(E_3|E_1\cap E_2)\ldots Pr(E_i|E_1\cap E_2\ldots E_{i-1})$$ 
</p>   
Our next task is to find the value of the RHS expression in above equation. For this we observer

- The probability of hitting an occupied slot in $$i$$th probe is $$p_i$$
- The probability of hitting an occupied slot in at least $$i$$ probes is $$q_i = \(\frac{m}{n}\)^i = \alpha^i$$

Now let us determine the expected number of probes for an unsuccessful search. We compute it by calculating 

- Probabilty of hitting at least one occupied slot which is $$q_1 = \sum_{i=1}^\infty p_i$$
- Probabilty of hitting at least two occupied slot which is $$q_2 =\sum_{i=2}^\infty p_i$$
- Probabilty of hitting at least three occupied slot which is $$q_3 =\sum_{i=3}^\infty p_i$$
- And so on ...

Adding all the expressions together, we get the value of the expression mentioned above as:
<p style="text-align:center">
$$\sum_{1}^{\infty} ip_i = \sum_{1}^{\infty} q_i$$
</p> 
For unsuccessful search we also have to add the cost of hashing to above expression. Therefore, the upper bound for the cost of unsuccessful search is: 
<p style="text-align:center">
\begin{split}
  1 + \sum_{1}^\infty q_i & = 1 + \sum_{1}^\infty \left(\frac{m}{n}\right)^i\\
  & = \frac{1}{1-\alpha}
  \end{split}
</p>
