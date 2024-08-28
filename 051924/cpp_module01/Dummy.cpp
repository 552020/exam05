#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Practice Dummy")
{
}

Dummy::~Dummy()
{
}


Dummy::Dummy(const Dummy &obj): ATarget(obj)
{
}

Dummy &Dummy::operator=(const Dummy &obj)
{
	if (this != &obj)
	{
		ATarget::operator=(obj);
	}
	return (*this);
}

ATarget *Dummy::clone() const
{
	return (new Dummy(*this));
}
