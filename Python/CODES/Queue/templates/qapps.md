# Displaying operations in Queue

```
{% extends 'base.html' %}
{% block head %}
        <title>{{t}}</title>    
        <link rel="stylesheet" href="{{ url_for('static', filename='main.css') }}">

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
<center>
<h2>Flask Webapps for Queue Visualizing Operations</h2>
</center>
<br>
<div class="container">

<p>Python Flask is a flexible microframework for building webapplications.
The framework is called microframework because it does not have database
abstraction layer or components where pre-existing third party libraries
can be used for common functions. It does not require any particular 
tool or library. Flask API is executed by invoking the Flask microserver.
The framework comes with a default server. It allows developer to build
lightweight RESTful Python-based apps.

<p>A Python Flask app begins with a decorator <var>@app.route</var> and
followed by specifying the route for executing the desired function.
The function name should be same as that in the route. The route or the
path is a mnemonic  which separates one from another. For example, 
a root function begins with route string "/", whereas a print queue
function may be defined relative to the root as "/printq". However,
both functions appear in the same file. Referring each according to
the corresponding route string is a way to tell which Python script
should be executed.
</p>


    <div class="card" style="max-width: 56rem; background-color:DCE6E9; border:2px solid gray;padding:3px;">
    <div class="card-block">
<code style="background-color:DCE6E9; color:black">

python3 app_file_name.py</code>
    </div>
    </div>


<p>We need to import modules from flask API which are made available for
writing applications much like Java imports. It is a critical abstraction
used for structuring the code and helps in fast application building. 
In C-language we have #include which provides similar functionalities. 
Lots of material available in the Internet on Flask and Python imports.
We will discuss these at a different point of time. However,
local imports are important from the point of view of application 
development. We use local import to include local files in our 
application. For example, in our circular queue RESTful application, we 
use <var>queueOps.py</var> file. It allows the application to access
queue operations defined in the class.
</p>

<p>
Now let us discuss a bit on structuring of the application. The 
application is planned as a tutorial for exploring various operations on
queue data structure. The ides is to display the state of queue after 
executing each operation. The important operations which change a 
queue's state are:
    <div class="card" style="max-width: 56rem; background-color:DCE6E9; border:2px solid gray;padding:3px;">
    <div class="card-block">
<code style="background-color:DCE6E9; color:black">

    Enqueue()  # Inserts new elements at the rear.<br>
    Dequeue()  # Deletes elements from the front<br>
    Makenull() # Makes the queue empty<br>
</code>
</div>
</div>

Three other non-mutating operations, namely, 
    <div class="card" style="max-width: 56rem; background-color:DCE6E9; border:2px solid gray;padding:3px;">
    <div class="card-block">
<code style="background-color:DCE6E9; color:black">

    getFront() # Get the element at the front<br>
    getRear()  # Get the element at the rear<br>
printQ()   # Print existing elements in the queue
</code>
</div>
</div>

are also used to query state of a queue. However, we leave the first two
nonmutating operations to the reader. Therefore, our Flask application  
deals with four operations.
</p>

<p>The actual operation is executed from our previously defined class 
<var>queueOps</var> available in file <var>queueOps.py</var>. Printing
contents of queue is simple. However, the requires the queue elements
to be placed in a string and displayed on the browser. We take the help
of <var>queue.to_list()</var> to convert the queue elements to a string
and identify the two ends by prepending the string "front->" and 
appending "%lt;-rear".</p> 

<p>First, we discuss the @app.route("printq"). It allows us to know 
the state of queue by printing the content and identifying its front
and rear ends. Extracting queue's content and displying it
in the above format lets the user know if the operations are working
according to the specification. The code snippet for the app.route
is given below.
</p>

<div class="container">
<pre class="language-python" ><code class="language-python">
@app.route("&#47;printq", methods=['GET'])
def printq():
    t1 = "Print queue" # Title of webpage
    if q.isEmpty(): 
        h1 = "Queue is empty" # Header for empty queue
        return render_template('enqueue.html', ele_s="front-&gt; &lt;-rear", l=len(q), t=t1, h=h1,cap=q._size)

    # If queue is not empty 
    h1 = "Queue has " +str(len(q))+ " elements" # Header 
    return render_template('enqueue.html', ele_s=q.to_list(), l=len(q), t=t1, h=h1, cap=q._size)
</code></pre>
</div>

<p><var>Render_template()</var> picks the appropriate HTML template for
displaying the queue. We use Jinja to provide dynamicity to HTML file.
The webpage header and other variable data are provided through app
variables: 
</p>
    <div class="card" style="max-width: 56rem; background-color:DCE6E9; border:2px solid gray;padding:3px;">
    <div class="card-block">
<code style="background-color:DCE6E9; color:black">

    t     # Provides the title of the webpage<br>
    h     # Describes the header<br>
    l     # Size of the queue<br>
    cap   # Capacity or limit of the queue<br>
    ele_s # String for displaying the queue<br>
</code>
</div>
</div>
<p>The dequeue is simple, it only deletes an element if the queue
is nonempty, otherwise reports that the queue is empty. The
state of the queue is extracted and rendered through template as in
"/printq". However, the header and title should be modified to
let user know that the state of the queue is reported after
performing the dequeue operation. The code snippets
dequeue app is provided below:
</p>

<div class="container">
<pre class="language-python" ><code class="language-python">
@app.route("/dequeue", methods=['GET','POST'])
def dequeue():
    t1 = "Dequeue"
    if q.isEmpty():
        h1 = "Queue is empty: deletion not possible"
        return render_template('enqueue.html', ele_s=q.to_list(), l=len(q),t=t1, h=h1, cap=q._size)

    h1 = "Dequeued: " + str(q.dequeue()) # Header for successful dequeue 
    return render_template('enqueue.html', ele_s=q.to_list(), l=len(q),t=t1, h=h1, cap=q._size)
</code></pre>
</div>
<p>Enqueue operation is dependent on the user's input. So the only 
difference from dequeue operation is to accept input from through
a web form. If the input is a numeric value then the value is appended
at the rear end of the queue, otherwise is discarded. A value can
be inserted provided the queue is not full. So, we first check for
queue full condition, then check for validity of the input. If the
test passes two checks then the value is enqueued. The code snippet
for the enqueue operation is given below.
</p>

<div class="container">
<pre class="language-python"><code class="language-python">
@app.route("/enqueue", methods=['POST', 'GET'])
def enqueue():
    t1 = "Enqueue" # Title of the webpage for enqueue
    if q.isFull(): # if true then no insertion 
        h1 = "Queue is Full: enqueue not possible" # Header for no enqueue
        return render_template('enqueue.html', ele_s=q.to_list(), l=len(q), t=t1, h=h1, cap=q._size)

    val = request.values.get("element") # Fetch value from the webform
    if val.isnumeric():  # Check for numeric value
        q.enqueue(val)   # Enqueu if value is numeric
        h1 = "Enqueued: " + str(val) # Header for value enqueued
        return render_template('enqueue.html', ele_s=q.to_list(), l=len(q), t=t1, h=h1, cap=q._size)

    h1 = "Input undefined or nonnumeric" # Header for invalid input 
    return render_template('enqueue.html', ele_s=q.to_list(), l=len(q), t=t1, h=h1, cap=q._size)
</code></pre>
</div>


<br>
<br>
<br>
 <script src="static/newScript.js" charset="utf-8"></script>


<a href= "https://rkgiitbh.github.io/data-structures.github.io/CODES/circularQueue/">Click here for the complete source code in C.</a>


</div>
{% endblock %}

```
