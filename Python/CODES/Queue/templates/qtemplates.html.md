# Description of Template Files

<strong>NOTE:</strong> The text describes all the template files for queue operations. This file would be accessible from the dropdown menu
under link "Description" for Flask API pages when we execute the web application.  The basic structure of the template file is appears below with
description. The description acquaints the reader with the organization of the template files used in the application.

It consists of HTML-Jinja code along with description. To create actual template file:
<ul>
        <li>Copy the entire text below into a file named <samp>qtemplates.html</samp></li>
        <li>Insert "&lt;p&gt;" and "&lt;/p&gt;" tags for paragraphs of text descripttion.</li>
</ul>

```
{% extends 'base.html' %}
{% block head %}
        <title>{{t}}</title>    
{% endblock %} 

{% block body %}

<center>
<h2>Templates for Display of Webpages</h2>
</center>
<br>
<div class="container">
```
We rely heavily on &lt;a href="https://getbootstrap.com"&gt;bootstrap&lt;/a&gt; and &lt;a href="https://jinja.palletsprojects.com/en/3.1.x/"&gt;Jinja&lt;a&gt; template engine to create
the HTML files for the application. Using bootstrap front end tool allows use of powerful production ready CSS and Javascript via CDN. 
There is no need to learn much CSS or Javascripts. We just include appropriate CDN links into templates. The display of
queue operations through HTML files is controlled by <samp>render_template()</samp>.  For rendering template we need 
to pass data from the Python apps to the templates. Jinja template engine brings dynamicity by fetching and replacing dynamic 
values provided by Flask apps. Jinja coding is easy, the syntax pretty much similar to Python. 

In the application, we have used four different template files. Each file display a web navigation bar for accessing different apps. 
The files are described below.

```
<div class="card" style="max-width: 56rem; background-color:DCE6E9; border:2px solid gray;padding:3px;">
    <div class="card-block">
        <code style="background-color:DCE6E9; color:black">
            Three files are used for description links:<br>
                new_queue.html: Describes the queue operations for the class queue <br> 
                qapps.html: Describes the apps for queue operations<br>
                qtemplate.html: Describes the template for the display webpages <br>
            <br>
           One file have been used for queue operations: <br>
                enqueue.html<br>
    </code>
    </div>
</div>
```
All HTML files have certain fixed header tags. To make our layout design easier, we identified the set of common tags and put them into
a single file called <samp>base.html</samp>. This file should be included in all other HTML template files. It converts template 
files into full featured HTML files. The <samp>base.html</samp> file appear below. The file consists of <samp>title</samp>, 
<samp>head</samp> and <samp>body</samp>. The <samp>tile</samp> is provided by respective flask app and passed a parameter in 
<samp>render_template()</samp> function. In Jinja, all variables are wrapped in double curly braces "&#123;&#123; &#125;&#125;.
Every block begins with key word  &#123;&#37; block block_name &#37;&#125;, and ends with 
&#123;&#37; endblock &#37;&#125;. For example, <samp>base.html</samp> has two blocks: one for head block
and the other for body block. It is a short file, the full file appears below.</p>

```
 <div class="container">
    <pre class="language-python"><code class="language-python">
       &lt;!-- base.html file --&gt;
          &lt;html lang="en"&gt;
             &lt;title&gt;&#123;&#123; t &#125;&#125; &lt;title&gt;
             &lt;head&gt;
                &lt;link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css"&gt;
                &lt;script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js">&lt;/script&gt;
                &lt;script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js">&lt;/script&gt;
 
                    &#123;&#37; block head &#37;&#125; 
                        &lt;h1&gt;Queue Operations&lt;h1&gt; 
                    &#123;&#37; endblock &#37;&#125;&#125;
             &lt;/head&gt;
             &lt;body&gt;
                   &#123;&#37; block body &#37;&#125; 
                       &lt;!-- Code for body block --&gt;
                   &#123;&#37; endblock &#37;&#125;
            &lt;/body&gt;
&lt;/html&gt;
    </code> </pre>
       </div>
```
    
All other template files are created as extensions of <samp>base.html</samp> using <samp>extend</samp> keyword. The head and body blocks for a HTML 
file is specified as needed. Important part of a template file is the navigation bar. It consists of one active link and the other links become active
as and when one is clicked. We have a dropdown link in the navigation bar for accessing the descirption part.  Each dropdown menu provides a 
description as stated earlier. The code snippet for navigation bar appears below.

```
   <div class="container">
    <pre class="language-python"><code class="language-python">

&lt;nav class="navbar navbar-inverse"&gt;
  &lt;div class="container-fluid"&gt;
    &lt;div class="navbar-header"&gt;
      &lt;ul class="nav navbar-nav"&gt;
        &lt;li class="active"&gt;&lt;a href="&#47;">Home&lt;a>&lt;/li&gt;
        &lt;li>&lt;a href="/dequeue">Dequeue&lt;a>&lt;/li&gt;
        &lt;li>&lt;a href="/printq">Print Queue&lt;a>&lt;/li&gt;
        &lt;li>&lt;a href="/makeempty">Makenull&lt;a>&lt;/li&gt;
        &lt;li&gt;&lt;a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" 
                data-toggle="dropdown" aria-haspopup="true" aria-expanded="false"&gt; 
             Description links&lt;/a&gt;
            &lt;ul class="dropdown-menu" aria-labelledby="dropdownMenuLink"&gt;
                 &lt;li>&lt;a class="dropdown-item" href="about">Circular queue&lt;a&gt;&lt;/li&gt;
                 &lt;li>&lt;a class="dropdown-item" href="qapps">Queue apps&lt;a&gt;&lt;/li&gt;
                 &lt;li&gt;a class="dropdown-item" href="qstyles">Templates&lt;a&gt;&lt;/li&gt;
             &lt;/ul&gt;&lt;/li&gt;
          &lt;li class="nav-item dropdown"&gt;
          &lt;a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" 
               data-toggle="dropdown" aria-haspopup="true" aria-expanded="false"&gt;
            Source code&lt;a&gt;
            &lt;ul class="dropdown-menu" aria-labelledby="dropdownMenuLink"&gt;
                   &lt;li>&lt;a class="dropdown-item" href="appcode"&gt;App code&lt;a&gt;&lt;/li&gt;
                 &lt;li>&lt;a class="dropdown-item" href="clcode"&gt;Queue class&lt;a&gt;&lt;/li&gt;
            &lt;ul&gt;
          &lt;/li&gt;
     &lt;/ul&gt;
   &lt;/div&gt;
 &lt;/div&gt;
&lt;/nav&gt;

</code></pre>
</div>
```
Navigation bar belongs to class <samp>nav-bar</samp> and keyword <samp>navbar-inverse</samp>. It displays the menu items in black 
background with white foreground. We designed layout with five <samp>nav-items</samp> one of which is a dropdown link. The dropdown link has 
three dropdown items. A user can navigate to description for circular queue, flask apps for queue operations and template description using the 
dropdown links. 

The remaining part of the template file is easy to understand. The body block for description templates only provides text of
descirption along with images if needed. We have used only one image to describe circular queue. The other two description files
only contains text. Code block are included with HTML tags <samp>&lt;pre&gt;</samp> and <samp>&lt;/pre&gt;</samp>.
 
However, <samp>enqueue.html</samp> is different from description templates. It contains the template needed for displaying results
of operations on queue. It takes header variables and prints the corresponding strings. The result of each queue operation is 
passed on to Jinja Template Engine as parameters that may consists of one or more strings. For example, when printing the
queue Flask passes header as "Queue is Empty" or "Queue has <sampl>n</smap> elements". The value of <sampl>n</samp> is also passed as string. 
The other paraments are queue size and the current elements in the queue. 

More precisely, <samp>printq()</samp> function has two exit points with different return statements:
    <ol>
        <li>One for empty queue</li>
        <li>The other for nonempty queue</li>
    </ol>
The corresponding <samp>rendrender_template</samp> statements have different headings and strings for queue elements. The reader can
examine these and find that the two cases are correctly handled.

```
<br>
</div>
{% endblock %}
```

