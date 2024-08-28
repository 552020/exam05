#include "SpellBook.hpp"




SpellBook:: SpellBook()
{
}

SpellBook::~SpellBook()
{
}
std::vector<ASpell *> &SpellBook::getSpells()
{
	return _spells;
}
	
void SpellBook::learnSpell(ASpell *spell)
{
	std::vector<ASpell *>::const_iterator it;
	for(it = _spells.begin(); it != _spells.end(); ++it)
	{
		if((*it)->getName() == spell->getName())
			return;
	}
	_spells.push_back(spell);
}


void SpellBook::forgetSpell(std::string const &spellName)
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

ASpell *SpellBook::createSpell(std::string const &spellName)
{
	if (spellName == "Fwoosh")
		return new Fwoosh();
	else if (spellName == "Fireball")
		return new Fireball();
	else if (spellName == "Polymorph")
		return new Polymorph();
	else
		return NULL;
}


	

