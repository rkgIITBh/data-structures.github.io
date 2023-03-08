# The Layout Template for Display

<strong>NOTE:</strong> This code below should be saved in a file named <samp>base.html</samp>. It specifies the common features of the display layout 
we have planned for the results of operations on a queue. Apart from the requirements of styles sheets and javascript, we also need an app navigation
bar for a prodcution like presentation of the web API. The navigation bar is a reverse (dark) horizontal strip where application links are
displayed with one active <samp>Home</samp> link. The list of available application links are:
<ul>
  <li>Enqueue: Requires an input and inserts the input at the rear of the queue if capacity has not exceed. </li>
  <li>Dequeue: Removes the element at the front of the queue if the queue is nonempty.</li>
  <li>Makenull: Makes the queue empty.</li>
  <li>Descritption: It describes the application framework including queue class, templates and Flask apps</li>
  <li>Source code: It describes the source code for the queue and the Flask front end. </li>
</ul> 
The template file <samp>base.html</samp> is extended using Jinja template engine framework to specify four other templates for displying the
results and associated description. 

```
<html lang="en">
    <title>{{ t }}</title>
    <head>
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
        <link rel="stylesheet" href="{{ url_for('static', filename='main.css') }}">
 
        {% block head %} <h1>Queue Operations</h1> {% endblock %}
    </head>
    <body>
        
    <nav class="navbar navbar-inverse">
    <div class="container-fluid">
      <div class="navbar-header">
         <ul class="nav navbar-nav">
            <li class="active"><a href="/">Home</a></li>
            <li><a href="/dequeue">Dequeue</a></li>
            <li><a href="/printq">Print Queue</a></li>
            <li><a href="/makeempty">Makenull</a></li>
            <li class="nav-item dropdown">
                <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Description</a>
                <ul class="dropdown-menu" aria-labelledby="dropdownMenuLink">
                   <li><a class="dropdown-item" href="about">Circular queue</a></li>
                   <li><a class="dropdown-item" href="qapps">Flask apps</a></li>
                   <li><a class="dropdown-item" href="qstyles">Templates</a></li>
               </ul></li>
            <li class="nav-item dropdown">
                 <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">Source code</a>
                <ul class="dropdown-menu" aria-labelledby="dropdownMenuLink">
                    <li><a class="dropdown-item" href="appcode">App code</a></li>
                    <li><a class="dropdown-item" href="clcode">Queue class</a></li>
                </ul></li>
         </ul>
      </div>
    </div>
    </nav>
    {% block body %} {% endblock %}

  </body>
  <script src="static/newScript.js" charset="utf-8"></script>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.3/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script> 
</html>
```
