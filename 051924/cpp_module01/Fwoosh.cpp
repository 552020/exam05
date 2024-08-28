#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::~Fwoosh()
{
}


Fwoosh::Fwoosh(const Fwoosh &obj): ASpell(obj)
{
}

Fwoosh &Fwoosh::operator=(const Fwoosh &obj)
{
	if (this != &obj)
	{
		ASpell::operator=(obj);
	}
	return (*this);
}

ASpell *Fwoosh::clone() const
{
	return (new Fwoosh(*this));
}
