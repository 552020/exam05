#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") 
{
};

Polymorph::Polymorph(const Polymorph &other) : ASpell(other) 
{
};

Polymorph &Polymorph::operator=(const Polymorph &other) 
{
  if (this != &other) {
    ASpell::operator=(other);
  }
	return *this;
};

Polymorph::~Polymorph() 
{
};

void Polymorph::launch(const ATarget &target) const 
{
	target.getHitBySpell(*this);
};

ASpell *Polymorph::clone() const 
{ 
	return new Polymorph(*this); 
};
