#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock {
public:
  // Constructor (parameterized)
  Warlock(std::string const &name, std::string const &title);
  // Destructor
  ~Warlock();
  // Getters & Setters
  const std::string &getName() const;
  const std::string &getTitle() const;

  void setTitle(const std::string &title);
  void introduce() const;

private:
  // Construtctor (default)
  Warlock();
  // Copy Constructor
  Warlock(Warlock &other);
  // Copy Assignment operator
  Warlock operator=(Warlock &other);

  std::string _name;
  std::string _title;
};

#endif
