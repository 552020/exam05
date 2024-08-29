#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
}

void SpellBook::learnSpell(ASpell *spell)
{
	if(!spell)
		return;
	std::vector<ASpell *>::const_iterator it;
	for(it = _spells.begin(); it != _spells.end(); ++it)
	{
		if((*it)->getName() == spell->getName())
			return;
	}
	_spells.push_back(spell);
}

void SpellBook::forgetSpell(const std::string &spellName)
{
	std::vector<ASpell *>::iterator it;
	for(it = _spells.begin(); it != _spells.end(); ++it)
	{
		if((*it)->getName() == spellName)
		{
			_spells.erase(it);
			return;
		}
	}
}

ASpell* SpellBook::createSpell(std::string const &spellName)
{
	ASpell *newSpell = NULL;
	std::vector<ASpell *>::const_iterator it;
	for(it = _spells.begin(); it != _spells.end(); ++it)
	{
		if((*it)->getName() == spellName)
		{
			newSpell = (*it)->clone();
			return newSpell;
		}
	}
	return newSpell;
}

