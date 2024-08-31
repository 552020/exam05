# EXAM 05

# Notes

- You can use `#pragma once` instead of `#ifndef MYCLASS_HPP`, `#define MYCLASS_HPP`, `#ifndef`.
- You don't need the `<string>` header if you use `<iostream>` for the definition of `std::string`, cause `<iostream>` already contains it.
- Don't get confused about a const reference to an object `const MyClass &ref` and `MyClass const &ref`. That's exactly the same: it generates the same machine code. The first version is considered better practice, during the exam you are asked to write the second version, but as I said, it makes no difference.
- You don't need to use `this->_myVar` instead of `myVar` if there is not naming conflicts.
- The copy assignemnt operator is supposed to always return a reference.
- The `virtaul` keyword can also be declared in the declaration and implementation of the virtual function in the derived class of an abstract class. But it has not to be.
- You don't need to declare and define copy constructor and copy assignment operators in the definition of the derived classes of the ASpell and ATarget abstract classes.
- You don't need to wrap the returned variables in parenthesis.
- Remember the `virtual` keyword in the destructor in abstract classes, so that the destructor is called just one time.
- A pure virtual function is followed in the declaration in the abstract class by a `= 0`: `virtual void myVirtualFunction() const = 0`.
- The check in the copy assignment operator if you are copying the same object (comparing the adresses of the objects on the right and left side of the equal) `if (this != &other)` is a good practice but not necessary. And since the objects in the exercises contains very few information we are not getting that much performance optimization.
- The model said that the use of the copy assignment operator in the copy constructor is a bad practice for the risk of 'shallow' copies. But actually if you do it properly I think it's a good practice, since you need to make a deep copy also when you use the copy assignment operator. If you keep adding stuff to your object, it lowers the risk of forgetting to make a deep copy of objects holding adresses of other objects as values.
- When you declare a method as `private` you don't need do implement it (if you are not using it). In general unused method, don't need to be implemented. You'll need to declare the copy constructor and copy assignment operator of Warlock as private, as requested by the subject. You don't need to implement the methods.
- If you use Vim you'll need:

  - `:%s/oldword/newword/gc`
  - `:split` vs `:vsplit`
  - `:term`
  - `CTRL w w` to move between windows or `CTRL w` + `h/j/k/l`.

- Compile early & often: everytime you write a new class.
-
- You need to use the clone() method instead of doing this

```cpp

ASpell *Spellbook::createSpell(std::string const &spellName)
{
	if (spellName == "Fwoosh")
		return new Fwoosh();
	else if (spellName == "Fireball")
		return new Fireball();
	else if (spellName == "Polymorph")
		return new Polymorph();
	else
		return NULL;
}

```

And the same for the createTarget in the TargetGenerator method. You'll pass grademe but not the exam, cause in the exam other spell classes are added, which will not work with this 'hard-coded' createSpell method.

- You can't seg fault but you can leak. So if it doesn't bother you. You don't need to delete the memory in the heap created for spells and targets.

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
