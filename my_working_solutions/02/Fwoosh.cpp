#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") 
{
};

Fwoosh::Fwoosh(const Fwoosh &other) : ASpell(other) 
{
};

Fwoosh &Fwoosh::operator=(const Fwoosh &other) 
{
  if (this != &other) {
    ASpell::operator=(other);
  }
	return *this;
};

Fwoosh::~Fwoosh() 
{
};

void Fwoosh::launch(const ATarget &target) const 
{
	target.getHitBySpell(*this);
};

ASpell *Fwoosh::clone() const 
{ 
	return new Fwoosh(*this); 
};
