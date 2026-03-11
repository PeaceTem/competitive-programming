# Python Data Structures in the Standard Library

## 1. Built-in Data Structures

These are part of the Python language itself.

- **list** – dynamic array
    
- **tuple** – immutable sequence
    
- **set** – unordered unique elements
    
- **frozenset** – immutable set
    
- **dict** – key-value mapping
    
- **str** – immutable sequence of characters
    
- **bytes / bytearray** – binary data sequences
    

---

## 2. `collections` Module

The **collections** module provides specialized container data structures.

- `deque` – double-ended queue
    
- `Counter` – frequency counting dictionary
    
- `defaultdict` – dictionary with default values
    
- `OrderedDict` – dictionary that remembers insertion order
    
- `namedtuple` – tuple with named fields
    
- `ChainMap` – links multiple dictionaries
    
- `UserDict`
    
- `UserList`
    
- `UserString`
    

---

## 3. `heapq`

The **heapq** module implements a **binary heap (priority queue)**.

- Min heap (priority queue)
    

---

## 4. `queue`

The **queue** module provides thread-safe queues.

- `Queue` – FIFO queue
    
- `LifoQueue` – stack
    
- `PriorityQueue` – priority queue
    
- `SimpleQueue`
    

---

## 5. `array`

The **array** module provides **typed arrays**.

- `array.array`
    

More memory-efficient than lists for numeric data.

---

## 6. `bisect`

The **bisect** module provides utilities for **binary search and sorted lists**.

Used for maintaining sorted arrays efficiently.

---

## 7. `graphlib`

The **graphlib** module provides graph utilities.

- `TopologicalSorter` – performs topological sorting of DAGs.

Python sorting: 
```
sorted_array = sorted(arr, key=lambda x: x[1])
sorted_array = sorted(arr, key=lambda x: (x[0], x[1]))

```

from functools import cmp_to_key
```
def compare(a, b):
    return len(a) - len(b)

words = ["apple", "kiwi", "banana"]

sorted(words, key=cmp_to_key(compare))
```

```
s = "Hello World"

s.lower()        # hello world
s.upper()        # HELLO WORLD
s.capitalize()   # Hello world
s.title()        # Hello World
s.strip()        # remove spaces
s.replace("World","Python")
```

```
s = "programming"

s.find("gram")    # index
s.startswith("pro")
s.endswith("ing")
```

```
s = "banana"

s.count("a")
```

```
name = "Alice"
age = 25

f"{name} is {age} years old"
```

```
s = "abc123"

s.isalpha()
s.isdigit()
s.isalnum()
s.isspace()
```

```
s = "apple"

s.replace("p", "x")
```

```
list("hello")
```

```
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

p1 = Person("Alice", 25)
```

Encapsulation: restrict access to an object
```
class Person:
    def __init__(self, name):
        self.__name = name  # private

    def get_name(self):
        return self.__name
```

Inheritance

```
class Employee(Person):
    def __init__(self, name, salary):
        super().__init__(name)
        self.salary = salary
```

```
class A:
    def greet(self):
        print("Hello from A")

class B(A):
    def greet(self):
        print("Hello from B")

obj = B()
obj.greet()  # Hello from B
```

```
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Circle(Shape):
    def __init__(self, r):
        self.r = r
    def area(self):
        return 3.14 * self.r**2
```

```
class Point:
    def __init__(self, x, y):
        self.x, self.y = x, y
    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

p1 = Point(1,2)
p2 = Point(3,4)
p3 = p1 + p2  # uses __add__
```

```
def decorator(func):
    def wrapper():
        print("Before function")
        func()
        print("After function")
    return wrapper

@decorator
def say_hello():
    print("Hello")

say_hello()
```

