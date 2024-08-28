#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell {
public:
  Polymorph();
  Polymorph(const Polymorph &other);
  Polymorph &operator=(const Polymorph &other);
  ~Polymorph();

  void launch(const ATarget &target) const;
  ASpell *clone() const;
};

#endif

// * Polymorph (Name: "Polymorph", Effects: "turned into a critter")
