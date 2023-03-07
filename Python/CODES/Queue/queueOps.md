# Source Code for Python Queue Class

This code can be used either for plain Python script or linked to a web interface code through Python Flask app.

```
from flask import Flask, render_template, request, redirect, url_for,request, jsonify

from werkzeug.utils import secure_filename

ALLOWED_EXTENSIONS = set(['png', 'jpg', 'jpeg', 'gif'])

import queueOps 

####### Global variables #######
app = Flask(__name__)

q = queueOps.QueueArray()
l = 0

####### Flask apps for queue operation #######

# Displays current status of queue 

@app.route("/", methods=['GET'])
def root():
    heading = "Created a New Queue"
    title = "New Queue"
    return redirect(url_for("printq"))


# Defines a new empty queue. It modifies the existing queue
@app.route("/makeempty", methods=['POST','GET'])
def makeempty():
    q.makenull()
    h1 = "Makenull queue"
    t1 = "Empty queue"
    return render_template('enqueue.html', ele_s = "front-> <-rear",t=t1, h=h1, cap=q._size)


# Takes user's input and enqueues it on the queue. It modifies the queue
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

# It deletes the element at the front of the queue. It modifies the queue
@app.route("/dequeue", methods=['GET','POST'])
def dequeue():
    t1 = "Dequeue"
    if q.isEmpty():
        h1 = "Queue is empty: deletion not possible"
        return render_template('enqueue.html', ele_s=q.to_list(), l=len(q),t=t1, h=h1, cap=q._size)

    h1 = "Dequeued: " + str(q.dequeue())
    #return redirect(url_for("enqueue")) 
    return render_template('enqueue.html', ele_s=q.to_list(), l=len(q),t=t1, h=h1, cap=q._size)

# Display current state of the queue 

@app.route("/printq", methods=['GET'])
def printq():
    t1 = "Print queue"
    c = len(q) 
    if q.isEmpty():
        h1 = "Queue is empty"
        return render_template('enqueue.html', ele_s="front-> <-rear", l=len(q), t=t1, h=h1,cap=q._size)

    h1 = "Queue has " +str(len(q))+ " elements"
    return render_template('enqueue.html', ele_s=q.to_list(), l=len(q), t=t1, h=h1, cap=q._size)

###### Queue operations, apps, templates and the source code ######

# Describes circular queue logic and operations on it 
@app.route("/about")
def about():
    return render_template('new_queue.html')

# Describes the details of Flask application for 
# understanding of queue operations
@app.route("/qapps")
def qapps():
    t1 = "Flask apps"
    return render_template('qapps.html', t=t1)

# Shows the templates used for the display of webpages 
@app.route("/qstyles")
def qstyles():
    t1 = "Templates"
    return render_template('qtemplates.html',t=t1)
  
# Display Flask application source code 
@app.route("/clcode", methods['GET'])
def clcode():
    t1 = "Source code"
    h1 = "App source code"
    return render_template('class_src.html', t=t1, h=h1)

# Display Python queue class source code 
@app.route("/appcode", methods['GET'])
def appcode():
    t1 = "Source code" 
    h1 = "Python application ource code"
    return render_template('app_src.html', t=t1, h=h1)

if __name__ == "__main__":
    app.run(debug=True)

```
