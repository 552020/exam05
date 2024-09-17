# EXAM 05

## Notes

- You can use `#pragma once` instead of `#ifndef MYCLASS_HPP`, `#define MYCLASS_HPP`, etc.
- You don't need the `<string>` header if you include `<iostream>`, as it already contains the definition for `std::string`.
- Don't get confused between a const reference to an object `const MyClass &ref` and `MyClass const &ref`. They are the same; both generate identical machine code. The first version is considered better practice, but during the exam, you may be asked to use the second version. It makes no functional difference.
- You don't need to use `this->_myVar` instead of `myVar` if there are no naming conflicts.
- The copy assignment operator must always return a reference.
- The `virtual` keyword can be used in both the declaration and implementation of a virtual function in the derived class of an abstract class, though it’s not required in both places.
- You don't need to declare or define copy constructors and copy assignment operators in the derived classes of `ASpell` and `ATarget` abstract classes.
- You don't need to wrap returned variables in parentheses.
- Remember to declare the destructor in abstract classes as `virtual` to ensure it is called only once.
- A pure virtual function is declared in an abstract class by following it with `= 0`: `virtual void myVirtualFunction() const = 0`.
- The check in the copy assignment operator (`if (this != &other)`) is good practice but not necessary. In this case, the performance gain would be negligible as the objects in the exercises contain very little information.
- Some believe that using the copy assignment operator inside the copy constructor is a bad practice due to the risk of shallow copies. However, if done correctly, it can be beneficial, especially when maintaining deep copies in both constructors and assignment operators. This practice helps avoid mistakes when adding members to your object.
- Methods declared as `private` don't need to be implemented if not used. In general, unused methods don't require implementation. For the `Warlock` class, you are required to declare the copy constructor and copy assignment operator as `private`, but there's no need to implement them.
- If you're using Vim, remember:
  - `:%s/oldword/newword/gc` for search and replace.
  - `:split` vs `:vsplit` to split windows.
  - `:term` to open a terminal.
  - `CTRL-w w` or `CTRL-w` + `h/j/k/l` to move between windows.
- Compile early and often, especially after writing a new class.
- You should use the `clone()` method instead of hard-coding the creation of spells like this:

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

  Similarly, avoid hard-coding for `createTarget` in the `TargetGenerator` method. This will pass `grademe`, but in the exam, other spell classes will be added, and the hard-coded method will fail.

- You can leak memory but not seg fault, so unless you're concerned about memory management, you don't need to delete spells and targets created on the heap.

## Notes Explained

### 1. **Why Do We Need the `virtual` Keyword Before the Destructor in an Abstract Class?**

- **Polymorphic Destruction:** When deleting a derived class object via a base class pointer, the destructor of the derived class will not be called unless the base class destructor is marked as `virtual`.

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

- **Reason:** The `virtual` keyword ensures that both the base and derived class destructors are called when an object is deleted through a base class pointer. Without `virtual`, only the base class destructor is called, leading to resource leaks if the derived class allocates resources that need to be freed in its destructor.

### 2. **Are Objects Passed to the Copy Constructor and Copy Assignment Operator Always Constant?**

Yes, objects passed to the copy constructor and copy assignment operator are always passed as constant references to prevent modifying the original object.

- **Copy Constructor:**

  ```cpp
  MyClass(const MyClass& other);  // 'other' is a constant reference
  ```

- **Copy Assignment Operator:**

  ```cpp
  MyClass& operator=(const MyClass& other);  // 'other' is a constant reference
  ```

### 3. **Do We Need to Explicitly Declare the Base Class Constructor in the Derived Class?**

Yes, when defining a constructor in a derived class, you must call the constructor of the base class to initialize the base part of the object. This is done in the initialization list.

- **Default Constructor:**
  If the base class has a default constructor, it is called automatically.

- **Parameterized Constructor:**
  If the base class has no default constructor, you **must** call it explicitly in the derived class's initialization list.

  ```cpp
  class Base {
  public:
      Base(int x) { /*...*/ }
  };

  class Derived : public Base {
  public:
      Derived(int y) : Base(y) { /*...*/ }
  };
  ```

### 4. **Finishing the Implementation of `Dummy::operator=`:**

Here’s the full implementation of the `Dummy` class:

```cpp
#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::Dummy(const Dummy &other) : ATarget(other) {}

Dummy& Dummy::operator=(const Dummy &other) {
    if (this != &other) {  // Self-assignment check
        ATarget::operator=(other);  // Assign base class part
        // Dummy has no additional members, so nothing else is required
    }
    return *this;
}

Dummy::~Dummy() {}

ATarget* Dummy::clone() const {
    return new Dummy(*this);  // Return a new copy of the Dummy object
}
```
