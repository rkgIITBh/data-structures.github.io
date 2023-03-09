# Displaying a Queue After and Insertion

<strong>NOTE:</strong> We require a template file for displaying queue after each operations on a queue. After adding a new element to the rear, 
the number of elements in a queue increases. An insertion succeeds if a vacant slot available in the queue. However, if the queue is full it 
returns saying that no insertion is possible as the queue is full. The display is handled by a template file <samp>qapp.html</samp>. This file
should be created in the template folder of the queue application. The major part of this code deals with navigation which is common to all
template files for the application. The file inherits navigation interface from <samp>base.html</samp> file. We just extend <samp>base.html</samp>
and include only the part that deals with enqueue. It requires an input from the user then call insertion function <samp>"/enqueue"</samp>.
The file also serves to display queue when either <samp>"/printq"</samp> or <samp>"/dequeue"</samp> API is called. Calling the latter result 
in deletion of the element at the front of queue. 

```
{% extends 'base.html' %}
{% block head %}
        <title>{{ t }}</title>    
{% endblock %} 

{% block body %}
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
            <button class="btn btn-success" type="submit">Enqueue</button>&nbsp;&nbsp;&nbsp;&nbsp;
    </form>
</div>

<br>
<hr>
{% endblock %}

```
