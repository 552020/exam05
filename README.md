# Notes

- The copy assignemnt operator is supposed to always return a reference.
- the `virtaul` keyword can also be declared in tht declaration and implementatio of the virtual function in the derived class of an abstract class. But it has not to be.
- Remember the `virtual` keywordk before destructor in abstract classes, so that the destructor is called just one time.
- A pure virtual function is followed in the declaration in the abstract class by a `= 0`: `virtual void myVirtualFunction() const = 0`.

# Notes Explained

## 1. **Why Do We Need the `virtual` Keyword Before the Destructor in an Abstract Class?**

- **Polymorphic Destruction:** When you have a pointer or reference to a base class pointing to a derived class object, and you delete the base class pointer, the destructor of the derived class will not be called unless the base class's destructor is marked as `virtual`.

  ```cpp
  class Base {
  public:
      virtual ~Base() { std::cout << "Base destructor" << std::endl; }
  };

  class Derived : public Base {
  public:
      ~Derived() { std::cout << "Derived destructor" << std::endl; }
  };

  Base* obj = new Derived();
  delete obj;  // Calls both Derived and Base destructors if Base's destructor is virtual
  ```

- **Reason:** The `virtual` keyword ensures that the correct destructor (both base and derived) is called when an object is deleted through a base class pointer. Without `virtual`, only the base class destructor would be called, leading to potential resource leaks if the derived class allocates resources that need to be freed in its destructor.

## 2. **Are the Objects Passed in the Copy Constructor and the Copy Assignment Operator Always Constant Objects?**

Yes, the objects passed to the copy constructor and copy assignment operator are always passed as constant references. This is because you don't want to modify the object being copied from; you only need to read its data to initialize or assign to the new object.

- **Copy Constructor:**

  ```cpp
  MyClass(const MyClass& other);  // 'other' is a constant reference
  ```

- **Copy Assignment Operator:**
  ```cpp
  MyClass& operator=(const MyClass& other);  // 'other' is a constant reference
  ```

### 3. **When Declaring the Constructor of a Derived Class, Do We Always Need to Declare the Constructor of the Base Class?**

Yes, when you define a constructor in a derived class, you typically need to call the constructor of the base class to properly initialize the base part of the object. This is done in the initialization list.

- **Default Constructor:**
  If the base class has a default constructor (i.e., a constructor that takes no arguments), it is called automatically if you do not explicitly call another constructor in the initialization list.

- **Parameterized Constructor:**
  If the base class does not have a default constructor (but has a parameterized constructor), you **must** explicitly call that constructor in the initialization list of the derived class.

  ```cpp
  class Base {
  public:
      Base(int x) { /*...*/ }
  };

  class Derived : public Base {
  public:
      Derived(int y) : Base(y) { /*...*/ }  // Must call Base's constructor
  };
  ```

### 4. **Finishing the Implementation of `Dummy::operator=`:**

Here’s the complete implementation of the `Dummy` class:

```cpp
#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {
}

Dummy::Dummy(const Dummy &other) : ATarget(other) {
}

Dummy& Dummy::operator=(const Dummy &other) {
    if (this != &other) {  // Self-assignment check
        ATarget::operator=(other);  // Assign base class part
        // Since Dummy has no additional members, nothing else needs to be done here
    }
    return *this;
}

Dummy::~Dummy() {
}

ATarget* Dummy::clone() const {
    return new Dummy(*this);  // Return a new copy of the Dummy object
}
```

### Explanation of the `Dummy` Class Implementation:

- **Constructor:** Initializes the `Dummy` with the type `"Target Practice Dummy"` by calling the `ATarget` constructor.
- **Copy Constructor:** Calls the base class copy constructor to copy the base part of the `Dummy` object.
- **Copy Assignment Operator:**
  - Performs a self-assignment check (`if (this != &other)`).
  - Calls the base class's copy assignment operator to handle copying the base part.
- **Destructor:** Since there's no specific resource management needed in `Dummy`, the destructor is straightforward.
- **`clone` Method:** Implements the clone functionality by returning a new `Dummy` object that is a copy of the current one, ensuring that polymorphic copying works correctly.

### Summary:

- **Virtual Destructors:** Ensure proper cleanup in polymorphic base classes.
- **Const References:** Are used in copy constructors and assignment operators to prevent modification of the source object.
- **Constructor Calls in Derived Classes:** Must call base class constructors, especially if the base class has parameterized constructors.
- **Dummy Class:** Now fully implements the `clone` method, along with the necessary constructors and assignment operator.
# exam05
