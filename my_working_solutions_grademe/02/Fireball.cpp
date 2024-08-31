#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") 
{
};

Fireball::Fireball(const Fireball &other) : ASpell(other) 
{
};

Fireball &Fireball::operator=(const Fireball &other) 
{
  if (this != &other) {
    ASpell::operator=(other);
  }
	return *this;
};

Fireball::~Fireball() 
{
};

void Fireball::launch(const ATarget &target) const 
{
	target.getHitBySpell(*this);
};

ASpell *Fireball::clone() const 
{ 
	return new Fireball(*this); 
};
