#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"
#include <iostream>

class ASpell; // Forwared declaration

class ATarget {
public:
  ATarget(const std::string &type);
  ATarget(const ATarget &other);
  ATarget &operator=(const ATarget &other);
  virtual ~ATarget();

  const std::string &getType() const;
  void getHitBySpell(const ASpell &spell) const;

protected:
  std::string _type;

  virtual ATarget *clone() const = 0;

private:
  ATarget();
};

#endif
