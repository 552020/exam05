#include"ASpell.hpp"

ASpell::ASpell(std::string const & name, std::string const & effects) : name(name), effects(effects)
{
}

ASpell::ASpell(ASpell const & obj)
{
	*this = obj;
}

ASpell::~ASpell()
{
}

ASpell & ASpell::operator=(ASpell const & rhs)
{
	this->name = rhs.name;
	this->effects = rhs.effects;
	return *this;
}

std::string const & ASpell::getName() const
{
	return this->name;
}

std::string const & ASpell::getEffects() const
{
	return this->effects;
}

void ASpell::launch(ATarget const & target)
{
	target.getHitBySpell(*this);
}
