#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) : _name(name), _effects(effects)
{
}

ASpell::ASpell(const ASpell &other) : _name(other._name), _effects(other._effects)
{
}

ASpell &ASpell::operator=(const ASpell &rhs)
{
	_name = rhs._name;
	_effects = rhs._effects;
	return *this;
}

ASpell::~ASpell()
{
}

const std::string &ASpell::getName() const
{
	return _name;
}

const std::string &ASpell::getEffects() const
{
	return _effects;
}


void ASpell::launch(const ATarget &target)
{
	target.getHitBySpell(*this);
}




