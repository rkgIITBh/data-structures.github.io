# Flask Application for Exploring Queue Operations

<strong>NOTE:</strong> REST web APIs for operations on queue using Python Flask framework is intended to achieve twin objectives:
<ol>
    <li>Understanding queue data structures and operations on queues.</li>
    <li>Writing production like APIs for web interfaces with backend programs.</li>
</ol>
Each operation is handled by a decorator <samp> @app.route(<function name>)</samp>. The decorator is applied on a string that symbolically represents a distinct
path or a route. Apart from standard operations such as enqueue, dequeue, makenull, we need a couple of helper functions to create complete
set of web API for the reader to get a satisfaction and understanding of the framework of webprogramming along with data structures. For further
details [check this link](./templates/qapps.md).
    

```
# Flask APIs for web rendering of the queue operations
from flask import Flask, render_template, request, redirect, url_for,request, jsonify

from werkzeug.utils import secure_filename

ALLOWED_EXTENSIONS = set(['png', 'jpg', 'jpeg', 'gif'])

import queueOps 

# Global variable for main Flask app
app = Flask(__name__)

# Global variable for queue operations
q = queueOps.QueueArray()
l = 0

# The decorator @app.route defines a new app route that starts with "/"
# Contain methods GET or PUT. GET for fetching and PUT for publishing.
@app.route("/", methods=['GET'])
def root():
    heading = "Created a New Queue"
    title = "New Queue"
    return redirect(url_for("printq"))

@app.route("/about")
def about():
    # Describes circular queue operations
    return render_template('new_queue.html') # Available in templates directory

# This app route describes the queue operations through Flask API
@app.route("/qapps")
def qapps():
    t1 = "Flask apps"
    return render_template('qapps.html', t=t1)


# This route describes the Jinja template files for web rendering 
@app.route("/qstyles")
def qstyles():
    t1 = "Templates" 
    return render_template('qtemplates.html',t=t1)

# It redefines queue as an empty queue
@app.route("/makeempty", methods=['POST','GET'])
def makeempty():
    q.makenull()
    h1 = "Makenull queue"
    t1 = "Empty queue"
    return render_template('enqueue.html', ele_s = "front-> <-rear", t=t1, h=h1, cap=q._size)

# It modifies queue by adding new element to the rear
@app.route("/enqueue", methods=['POST', 'GET'])
def enqueue():
    t1 = "Enqueue"
    if q.isFull():
        h1 = "Queue is Full: enqueue not possible"
        return render_template('enqueue.html', ele_s=q.to_list(), l=len(q), t=t1, h=h1, cap=q._size)

    val = request.values.get("element")
    if val.isnumeric(): 
        q.enqueue(val)
        h1 = "Enqueued: " + str(val)
        return render_template('enqueue.html', ele_s=q.to_list(), l=len(q), t=t1, h=h1, cap=q._size)

    h1 = "Input undefined or nonnumeric"  
    return render_template('enqueue.html', ele_s=q.to_list(), l=len(q), t=t1, h=h1, cap=q._size)
    #return redirect(url_for("printq"))

# It modifies queue by deleting the element at the front
@app.route("/dequeue", methods=['GET','POST'])
def dequeue():
    t1 = "Dequeue"
    if q.isEmpty():
        h1 = "Queue is empty: deletion not possible"
        return render_template('enqueue.html', ele_s=q.to_list(), l=len(q),t=t1, h=h1, cap=q._size)

    h1 = "Dequeued: " + str(q.dequeue())
    #return redirect(url_for("enqueue")) 
    return render_template('enqueue.html', ele_s=q.to_list(), l=len(q),t=t1, h=h1, cap=q._size)

# It prints the queue.
@app.route("/printq", methods=['GET'])
def printq():
    t1 = "Print queue"
    c = len(q) 
    if q.isEmpty():
        h1 = "Queue is empty"
        return render_template('enqueue.html', ele_s="front-> <-rear", l=len(q), t=t1, h=h1,cap=q._size)

    h1 = "Queue has " +str(len(q))+ " elements"
    return render_template('enqueue.html', ele_s=q.to_list(), l=len(q), t=t1, h=h1, cap=q._size)
    
# It displays the source code for the queue class  
@app.route("/clcode") #, methods=['GET'])
def clcode():
    t1 = "Source code"
    h1 = "App source code"
    return render_template('class_src.html', t=t1, h=h1)

# It displays the source code for queue Flask app
@app.route("/appcode") #, methods=['GET'])
def appcode():
    t1 = "Source code" 
    h1 = "Python application source code"
    return render_template('app_src.html', t=t1, h=h1)

# Defines the name of the app as main and runs in debug mode
if __name__ == "__main__":
    app.run(debug=True)
```
