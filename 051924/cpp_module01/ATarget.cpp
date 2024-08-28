#include "ATarget.hpp"

class ASpell;

ATarget::ATarget()
{
}

ATarget::ATarget(const std::string &type)
{
	_type = type; 
}

ATarget::~ATarget()
{
}


ATarget::ATarget(const ATarget &obj)
{
	_type = obj._type;
}

ATarget &ATarget::operator=(const ATarget &obj)
{
	if (this != &obj)
	{
		_type = obj._type;
	}
	return (*this);
}

const std::string &ATarget::getType() const
{
	return (_type);
}


void ATarget::getHitBySpell(ASpell &obj) const
{
	std::cout << _type << " has been " << obj.getEffects() << "!" << std::endl;
}
