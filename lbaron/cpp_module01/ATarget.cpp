#include"ATarget.hpp"

ATarget::ATarget(std::string const & type) : type(type)
{
}

ATarget::ATarget(ATarget const & obj)
{
	*this = obj;
}

ATarget::~ATarget()
{
}

ATarget & ATarget::operator=(ATarget const & rhs)
{
	this->type = rhs.type;
	return *this;
}

std::string const & ATarget::getType() const
{
	return this->type;
}

void ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
