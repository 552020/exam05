#include "ASpell.hpp"

ASpell::ASpell()
{
}

ASpell::~ASpell()
{
}

ASpell::ASpell(const std::string &name, const std::string &effects): _name(name), _effects(effects)
{
}


ASpell::ASpell(const ASpell &obj)
{
	_name = obj._name;
	_effects = obj._effects;
}

ASpell &ASpell::operator=(const ASpell &obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		_effects = obj._effects;
	}
	return (*this);
}

 std::string ASpell::getName() const
{
	return (_name);
}

 std::string ASpell::getEffects() const
{
	return _effects;
}


void ASpell::launch(const ATarget &obj)
{
	obj.getHitBySpell(*this);
}
