## Hash Functions

Hashing uses a hash function to map a key (element) to an index position in hash table. The function should have the following
characteristics:

- Low cost
- Uniformity
- Deterministic

Low cost implies the hash function should be computable in time of O(1). Uniformity means hash function should distribute the
keys equally likely in its range space or the index space of the hash table. Hash function is deterministic if gives same hash 
value for a given input. If hash function is not deterministic then it might give different index values in different operations.
So, we cannot access a key from the stored slot. 

The well known hash functions use following four methods:

- Division
- Multiplication
- Midsquare
- Folding

Division method is the simplest and most well used hashing function. It is given by:
<p style="text-align:center">
  <i>h(x)</i> = <i>x</i> mod <i>m</i>, where <i>m</i> is the hash table size.
</p>
Let us analyze the characteristics of division function and its impact on different table sizes <i>m</i>.
First consider the value of <i>m = 2<sup>p</sup></i>, then division function will map any key <i>x</i> only
to its lower order <i>p</i> bits. Therefore, a table size that is a power of 2 is a bad choice irrespective of key space. In fact, the 
division function maps all values of <i>x = am + b</i> map to same table slot <i>b</i>. Therefore, even the choice of a prime value
for <i>m</i> may not work out. 

Let us try find out the conditions for which division function may work. We assume the base of the number system to be
<i>b</i> such that <i>b</i> &#8801; 1 (mod <i>m</i>). Now consider a key value of the form
<p style="text-align:center">
  <i>x</i> mod <i>m</i> = &#40; &#8721;<sup>r</sup><sub>0</sub> <i>x<sub>i</sub> b<sup>i</sup></i> &#41; mod <i>m</i>
</p>


</div>
<h2 id="equations">Equations</h2>
<p><span class="math display">\[\mathbb{N} = \{ a \in \mathbb{Z} : a &gt; 0 \}\]</span></p>
<div class="sourceCode" id="cb25"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb25-1"><a href="#cb25-1"></a>$$\mathbb{N} = <span class="sc">\{</span> a \in \mathbb{Z} : a &gt; 0 <span class="sc">\}</span>$$</span></code></pre></div>
<p><span class="math display">\[\forall \; x \in X \quad \exists \; y \leq \epsilon\]</span></p>
<div class="sourceCode" id="cb26"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb26-1"><a href="#cb26-1"></a>$$\forall \; x \in X \quad \exists \; y \leq \epsilon$$</span></code></pre></div>
<p><span class="math display">\[\color{blue}{X \sim Normal \; (\mu,\sigma^2)}\]</span></p>
<div class="sourceCode" id="cb27"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb27-1"><a href="#cb27-1"></a>$$\color{blue}{X \sim Normal \; (\mu,\sigma^2)}$$</span></code></pre></div>
<p><span class="math display">\[P \left( A=2 \, \middle| \, \dfrac{A^2}{B}&gt;4 \right)\]</span></p>
<div class="sourceCode" id="cb28"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb28-1"><a href="#cb28-1"></a>$$P \left( A=2 \, \middle| \, \dfrac{A^2}{B}&gt;4 \right)$$</span></code></pre></div>
<p><span class="math display">\[f(x) = x^2 - x^\frac{1}{\pi}\]</span></p>
<div class="sourceCode" id="cb29"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb29-1"><a href="#cb29-1"></a>$$f(x) = x^2 - x^\frac{1}{\pi}$$</span></code></pre></div>
<p><span class="math display">\[f(X,n) = X_n + X_{n-1}\]</span></p>
<div class="sourceCode" id="cb30"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb30-1"><a href="#cb30-1"></a>$$f(X,n) = X_n + X_{n-1}$$</span></code></pre></div>
<p><span class="math display">\[f(x) = \sqrt[3]{2x} + \sqrt{x-2}\]</span></p>
<div class="sourceCode" id="cb31"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb31-1"><a href="#cb31-1"></a>$$f(x) = \sqrt<span class="co">[</span><span class="ot">3</span><span class="co">]</span>{2x} + \sqrt{x-2}$$</span></code></pre></div>
<p><span class="math display">\[\mathrm{e} = \sum_{n=0}^{\infty} \dfrac{1}{n!}\]</span></p>
<div class="sourceCode" id="cb32"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb32-1"><a href="#cb32-1"></a>$$\mathrm{e} = \sum_{n=0}^{\infty} \dfrac{1}{n!}$$</span></code></pre></div>
<p><span class="math display">\[\prod_{i=1}^{n} x_i - 1\]</span></p>
<div class="sourceCode" id="cb33"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb33-1"><a href="#cb33-1"></a>$$\prod_{i=1}^{n} x_i - 1$$</span></code></pre></div>
<p><span class="math display">\[\lim_{x \to 0^+} \dfrac{1}{x} = \infty\]</span></p>
<div class="sourceCode" id="cb34"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb34-1"><a href="#cb34-1"></a>$$\lim_{x \to 0^+} \dfrac{1}{x} = \infty$$</span></code></pre></div>
<p><span class="math display">\[\int_a^b y \: \mathrm{d}x\]</span></p>
<div class="sourceCode" id="cb35"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb35-1"><a href="#cb35-1"></a>$$\int_a^b y \: \mathrm{d}x$$</span></code></pre></div>
<p><span class="math display">\[\log_a b = 1\]</span></p>
<div class="sourceCode" id="cb36"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb36-1"><a href="#cb36-1"></a>$$\log_a b = 1$$</span></code></pre></div>
<p><span class="math display">\[\min(P) = \max_{i:S_i \in S} S_i\]</span></p>
<div class="sourceCode" id="cb37"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb37-1"><a href="#cb37-1"></a>$$\max(S) = \max_{i:S_i \in S} S_i$$</span></code></pre></div>
<p><span class="math display">\[\dfrac{n!}{k!(n-k)!} = \binom{n}{k}\]</span></p>
<div class="sourceCode" id="cb38"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb38-1"><a href="#cb38-1"></a>$$\dfrac{n!}{k!(n-k)!} = \binom{n}{k}$$</span></code></pre></div>
<p><span class="math display">\[\small \text{$\dfrac{b}{a+b}=3, \:$ therefore we can set $\: a=6$}\]</span></p>
<div class="sourceCode" id="cb39"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb39-1"><a href="#cb39-1"></a>$$\text{$\dfrac{b}{a+b}=3, \:$ therefore we can set $\: a=6$}$$</span></code></pre></div>
<h2 id="functions">Functions</h2>
<p><span class="math display">\[
f(x)=
\begin{cases}
1/d_{ij} &amp; \quad \text{when $d_{ij} \leq 160$}\\ 
0 &amp; \quad \text{otherwise}
\end{cases}
\]</span></p>
<div class="sourceCode" id="cb40"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb40-1"><a href="#cb40-1"></a>$$</span>
<span id="cb40-2"><a href="#cb40-2"></a>f(x)=</span>
<span id="cb40-3"><a href="#cb40-3"></a>\begin{cases}</span>
<span id="cb40-4"><a href="#cb40-4"></a>1/d_{ij} &amp; \quad \text{when $d_{ij} \leq 160$}<span class="sc">\\</span> </span>
<span id="cb40-5"><a href="#cb40-5"></a>0 &amp; \quad \text{otherwise}</span>
<span id="cb40-6"><a href="#cb40-6"></a>\end{cases}</span>
<span id="cb40-7"><a href="#cb40-7"></a>$$</span></code></pre></div>
<h2 id="matrices">Matrices</h2>
<p><span class="math display">\[
\begin{matrix}
1 &amp; 2 &amp; 3 \\
4 &amp; 5 &amp; 6 \\
7 &amp; 8 &amp; 9
\end{matrix}
\]</span></p>
<div class="sourceCode" id="cb41"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb41-1"><a href="#cb41-1"></a>$$</span>
<span id="cb41-2"><a href="#cb41-2"></a>\begin{matrix}</span>
<span id="cb41-3"><a href="#cb41-3"></a>1 &amp; 2 &amp; 3 <span class="sc">\\</span></span>
<span id="cb41-4"><a href="#cb41-4"></a>4 &amp; 5 &amp; 6 <span class="sc">\\</span></span>
<span id="cb41-5"><a href="#cb41-5"></a>7 &amp; 8 &amp; 9</span>
<span id="cb41-6"><a href="#cb41-6"></a>\end{matrix}</span>
<span id="cb41-7"><a href="#cb41-7"></a>$$</span></code></pre></div>
<p><span class="math display">\[
M = 
\begin{bmatrix}
\frac{5}{6} &amp; \frac{1}{6} &amp; 0 \\[0.3em]
\frac{5}{6} &amp; 0 &amp; \frac{1}{6} \\[0.3em]
0 &amp; \frac{5}{6} &amp; \frac{1}{6}
\end{bmatrix}
\]</span></p>
<div class="sourceCode" id="cb42"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb42-1"><a href="#cb42-1"></a>$$</span>
<span id="cb42-2"><a href="#cb42-2"></a>M = </span>
<span id="cb42-3"><a href="#cb42-3"></a>\begin{bmatrix}</span>
<span id="cb42-4"><a href="#cb42-4"></a>\frac{5}{6} &amp; \frac{1}{6} &amp; 0 <span class="sc">\\</span><span class="co">[</span><span class="ot">0.3em</span><span class="co">]</span></span>
<span id="cb42-5"><a href="#cb42-5"></a>\frac{5}{6} &amp; 0 &amp; \frac{1}{6} <span class="sc">\\</span><span class="co">[</span><span class="ot">0.3em</span><span class="co">]</span></span>
<span id="cb42-6"><a href="#cb42-6"></a>0 &amp; \frac{5}{6} &amp; \frac{1}{6}</span>
<span id="cb42-7"><a href="#cb42-7"></a>\end{bmatrix}</span>
<span id="cb42-8"><a href="#cb42-8"></a>$$</span></code></pre></div>
<p><span class="math display">\[
M =
\begin{bmatrix}
1 &amp; 0 \\
0 &amp; 1
\end{bmatrix}
\begin{bmatrix}
1 &amp; 0 \\
0 &amp; 1
\end{bmatrix}
\]</span></p>
<div class="sourceCode" id="cb43"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb43-1"><a href="#cb43-1"></a>$$ </span>
<span id="cb43-2"><a href="#cb43-2"></a>M =</span>
<span id="cb43-3"><a href="#cb43-3"></a>\begin{bmatrix}</span>
<span id="cb43-4"><a href="#cb43-4"></a>1 &amp; 0 <span class="sc">\\</span></span>
<span id="cb43-5"><a href="#cb43-5"></a>0 &amp; 1</span>
<span id="cb43-6"><a href="#cb43-6"></a>\end{bmatrix}</span>
<span id="cb43-7"><a href="#cb43-7"></a>\begin{bmatrix}</span>
<span id="cb43-8"><a href="#cb43-8"></a>1 &amp; 0 <span class="sc">\\</span></span>
<span id="cb43-9"><a href="#cb43-9"></a>0 &amp; 1</span>
<span id="cb43-10"><a href="#cb43-10"></a>\end{bmatrix}</span>
<span id="cb43-11"><a href="#cb43-11"></a>$$</span></code></pre></div>
<p><span class="math display">\[ 
M =
\begin{pmatrix}
1 &amp; 0 \\
0 &amp; 1
\end{pmatrix}
\begin{pmatrix}
1 &amp; 0 \\
0 &amp; 1
\end{pmatrix}
\]</span></p>
<div class="sourceCode" id="cb44"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb44-1"><a href="#cb44-1"></a>$$ </span>
<span id="cb44-2"><a href="#cb44-2"></a>M =</span>
<span id="cb44-3"><a href="#cb44-3"></a>\begin{pmatrix}</span>
<span id="cb44-4"><a href="#cb44-4"></a>1 &amp; 0 <span class="sc">\\</span></span>
<span id="cb44-5"><a href="#cb44-5"></a>0 &amp; 1</span>
<span id="cb44-6"><a href="#cb44-6"></a>\end{pmatrix}</span>
<span id="cb44-7"><a href="#cb44-7"></a>\begin{pmatrix}</span>
<span id="cb44-8"><a href="#cb44-8"></a>1 &amp; 0 <span class="sc">\\</span></span>
<span id="cb44-9"><a href="#cb44-9"></a>0 &amp; 1</span>
<span id="cb44-10"><a href="#cb44-10"></a>\end{pmatrix}</span>
<span id="cb44-11"><a href="#cb44-11"></a>$$</span></code></pre></div>
<p><span class="math display">\[
A_{m,n} =
\begin{pmatrix}
a_{1,1} &amp; a_{1,2} &amp; \cdots &amp; a_{1,n} \\
a_{2,1} &amp; a_{2,2} &amp; \cdots &amp; a_{2,n} \\
\vdots &amp; \vdots &amp; \ddots &amp; \vdots \\
a_{m,1} &amp; a_{m,2} &amp; \cdots &amp; a_{m,n} 
\end{pmatrix}
\]</span></p>
<div class="sourceCode" id="cb45"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb45-1"><a href="#cb45-1"></a>$$</span>
<span id="cb45-2"><a href="#cb45-2"></a>A_{m,n} = </span>
<span id="cb45-3"><a href="#cb45-3"></a>\begin{pmatrix}</span>
<span id="cb45-4"><a href="#cb45-4"></a>a_{1,1} &amp; a_{1,2} &amp; \cdots &amp; a_{1,n} <span class="sc">\\</span></span>
<span id="cb45-5"><a href="#cb45-5"></a>a_{2,1} &amp; a_{2,2} &amp; \cdots &amp; a_{2,n} <span class="sc">\\</span></span>
<span id="cb45-6"><a href="#cb45-6"></a>\vdots &amp; \vdots &amp; \ddots &amp; \vdots <span class="sc">\\</span></span>
<span id="cb45-7"><a href="#cb45-7"></a>a_{m,1} &amp; a_{m,2} &amp; \cdots &amp; a_{m,n} </span>
<span id="cb45-8"><a href="#cb45-8"></a>\end{pmatrix}</span>
<span id="cb45-9"><a href="#cb45-9"></a>$$</span></code></pre></div>
<h2 id="font-sizes">Font sizes</h2>
<p><span class="math inline">\(\Huge Hello!\)</span> <br> <span class="math inline">\(\huge Hello!\)</span> <br> <span class="math inline">\(\LARGE Hello!\)</span> <br> <span class="math inline">\(\Large Hello!\)</span> <br> <span class="math inline">\(\large Hello!\)</span> <br> <span class="math inline">\(\normalsize Hello!\)</span> <br> <span class="math inline">\(\small Hello!\)</span> <br> <span class="math inline">\(\scriptsize Hello!\)</span> <br> <span class="math inline">\(\tiny Hello!\)</span> <br></p>
<div class="sourceCode" id="cb46"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb46-1"><a href="#cb46-1"></a>$\Huge Hello!$</span>
<span id="cb46-2"><a href="#cb46-2"></a>$\huge Hello!$</span>
<span id="cb46-3"><a href="#cb46-3"></a>$\LARGE Hello!$</span>
<span id="cb46-4"><a href="#cb46-4"></a>$\Large Hello!$</span>
<span id="cb46-5"><a href="#cb46-5"></a>$\large Hello!$</span>
<span id="cb46-6"><a href="#cb46-6"></a>$\normalsize Hello!$</span>
<span id="cb46-7"><a href="#cb46-7"></a>$\small Hello!$</span>
<span id="cb46-8"><a href="#cb46-8"></a>$\scriptsize Hello!$</span>
<span id="cb46-9"><a href="#cb46-9"></a>$\tiny Hello!$</span></code></pre></div>
<p>Example: <span class="math display">\[\small \text{Font size is small, eg. $\sum{x_i = 10}$}\]</span></p>
<div class="sourceCode" id="cb47"><pre class="sourceCode markdown"><code class="sourceCode markdown"><span id="cb47-1"><a href="#cb47-1"></a>$$\small \text{Font size is small, eg. $\sum{x_i = 10}$}$$</span></code></pre></div></div>


The next function is known as multiplication function. It relies on finding product of <i>x</i> by a randomly chosen fraction
between 0 and 1 and extracting the middle bits of 
