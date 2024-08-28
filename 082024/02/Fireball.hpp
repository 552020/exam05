#ifndef FIREWALL_HPP
#define FIREWALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell {
public:
  Fireball();
  Fireball(const Fireball &other);
  Fireball &operator=(const Fireball &other);
  ~Fireball();

  void launch(const ATarget &target) const;
  ASpell *clone() const;
};

#endif

// * Fireball (Name: "Fireball", Effects: "burnt to a crisp")
