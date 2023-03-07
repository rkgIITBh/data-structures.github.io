# Displaying queue after insertion

We require a template file for displaying queue after adding a new element to the rear. It increases the number of elements if there is an available
slot for new insertion. However, if the queue is full it returns saying that no insertion is possible as the queue is full.

```
{% extends 'base.html' %}
{% block head %}
        <title>{{ t }}</title>    
{% endblock %} 

{% block body %}

<nav class="navbar navbar-inverse">
  <div class="container-fluid">
    <div class="navbar-header">
      <ul class="nav navbar-nav">
        <li class="active"><a href="/">Home</a></li>
        <li><a href="/dequeue">Dequeue</a></li>
        <li><a href="/printq">Print Queue</a></li>
        <li><a href="/makeempty">Makenull</a></li>
        <li class="nav-item dropdown">
          <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
          Description
          </a>

          <ul class="dropdown-menu" aria-labelledby="dropdownMenuLink">
            <li><a class="dropdown-item" href="about">Circular queue</a></li>
            <li><a class="dropdown-item" href="qapps">Flask apps</a></li>
            <li><a class="dropdown-item" href="qstyles">Templates</a></li>
          </ul><li>
                        <li class="nav-item dropdown">
          <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
              Source code
          </a>

          <ul class="dropdown-menu" aria-labelledby="dropdownMenuLink">
            <li><a class="dropdown-item" href="appcode">App code</a></li>
            <li><a class="dropdown-item" href="clcode">Queue class</a></li>
          </ul></li>
      </ul>
    </div>
  </div>
</nav>

<br>

<div class="method" style="text-align:center">
      <h2>{{ h }}</h2>
      <h3>Queue capacity: {{ cap }}</h3>
      <br>
      {{ ele_s }}&nbsp;
</div>
<br>
<hr>
<br>
<div span="right" style="text-align:center">
    <form action="/enqueue" method="POST">
            <input type="text" name="element" placeholder="enter value">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <button class="btn btn-success"
                    type="submit">Enqueue</button>&nbsp;&nbsp;&nbsp;&nbsp;
<div span="right" style="text-align:center">
    </form>
</div>

<br>
<hr>
{% endblock %}

```
