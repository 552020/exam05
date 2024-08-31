#include "ATarget.hpp"

ATarget::ATarget(const std::string &type): _type(type)
{
};

ATarget::ATarget(const ATarget &other): _type(other._type)
{
};

ATarget &ATarget::operator=(const ATarget &other) {
	if(this != &other)
	{
		_type = other._type;
	}
	return *this;
}

ATarget::~ATarget()
{
};

const std::string &ATarget::getType() const
{
	return _type;
};

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}

// <TYPE> has been <EFFECTS>!

// <TYPE> is the ATarget's type, and <EFFECTS> is the return of the ASpell's getEffects function.
