 Data Types and ADTs

Where to begin learning about data structure? Though the meaning of a structure is known to us, it is not clear what data means except being a collection of bit strings. Bit strings 
are uninteresting unless these are related to the values. The values give some measurements or assessments of the physical characteristics of our interests. For example, values may 
be related to temperature, humidity, wind speed that indicate whether the weather is comfortable or unbearable. However, the weather example hides the raw data under several layers 
of abstractions. The first layer of abstraction is native data types of the programming language. The native data types of C, for example, includes:

 
```
     int, signed int, unsigned int, long int, 
     float, double, long double, 
     char, signed char, unsigned char. 
```
 

Sometimes we refer to these native types as simple types. Each type consists of (i) a universe and (ii) allowable operations, and (iii) exceptions. The universe of the short int type 
of C is defined by the range [-32768, 32767]. Normal integer arithmetic operations are defined over the data type. Exceptions are raised by operation like division by zero or an 
overflow due to multiplication or addition. The overflow is caused due to machine precision. Floats defines real numbers system with some gaps. The gaps are also due to finite 
machine precision. C also allows declaration of arrays. However, arrays do not belong to native types as an array consists of a collection of some simple type. For example, we can 
define an array of int or float or char. Arrays are also referred to as compound types. Another example of other compound types is struct or record of mixed types that may also 
include compound type. For example, we can define a record type as follows:

 
```
 #define MAX 100
struct student {  
    char name[MAX];
    int rollNo;
};
```
 

The use of a compound type is much like a simple type. 

An abstract data type is an encapsulation of data structure that is independent of implementation. Essentially ADT defines two things, namely, (i) representation of data and (ii) 
specification of operations on it. There is no information on data storage in the memory or on the permissible operations on these data. In simple terms, it gives the representation 
of data with interfaces to operating on the data. It is much like an algebraic structure in mathematics. 

Abstractions are always very useful. Since the implementation is separate from the interface, a client can operate on a data structure using the interface. The client need not bother 
about the operation or data modification if a mutating operation is applied to data. It simplifies the coding. We can view the ADT as providing a small window or counter through 
which the client gets services (applying operations) but does not have to bother about the kind of activities behind the walls and beyond the window. 

![Wall of abstraction](https://github.com/rkgIITBh/Data-Structures.io/blob/gh-pages/images/wallOfAbstraction.jpg?raw=true "Wall of abstraction)

The wall of abstraction between client and implementation lets the client use data structure only through the interface. Implementation protects internal details from accidental or 
deliberate modification by the client programs. 

For illustration, consider how an array is specified as an ADT. The universe consists of a set of all arrays of type T. T can be any simple type provided by the native data types. 
So, we are not concerned with T as we specify the interface. An array will provide three operations, namely,

- ###  new(index1, index2): It returns a new array of type T with bounds as specified by index1 and index2, where index1 and index2 are unsigned integers.
- ###  get(A, index): takes an array and an index (unsigned integer) and returns a value of type T.
- ### put(A, index, T): takes an array, an index, and a value of type T and returns the same array with value of array element at index modified to the new value.
 
We may use C pre-processor to hide the implementation from client programs. The implementation part is usually separate and stored in a header file or a ".h" extension file. 

Let me end this short note illustrating how a linked can be defined in C.

 
```
#ifndef LIST_H
#define LIST_H
typedef struct node {
   int info;
   struct node *next; 
} NODE;
 
// List Operations
#endif 
```
Once we have defined the structure and tag, the list operations programs are placed in the [list.h](https://www.dropbox.com/s/s9urv9pctmiqpfe/list.h?dl=0) file. 

The next blog will deal with List operation in detail.
