#pragma once
#include <iostream>
#include <string>

class Warlock {
public:
  Warlock(std::string const &name, std::string const &title);
  ~Warlock();
  std::string const &getName() const;
  std::string const &getTitle() const;
  void setTitle(std::string const &str);
  void introduce() const;

private:
  std::string name;
  std::string title;
  Warlock(Warlock const &obj);
  Warlock &operator=(Warlock const &rhs);
};
