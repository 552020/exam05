#include "Spellbook.hpp"

Spellbook::Spellbook()
{
};

Spellbook::~Spellbook() 
{
 // We suppose that all the spell created are created with createSpell, 
 // If it's not the case we will have a problem, cause we will try to delete something on the heap
 std::vector<ASpell *>::const_iterator it;
 	for(it = _spells.begin(); it != _spells.end(); ++it)
		delete *it;
};

// Copies a spell into the book
void Spellbook::learnSpell(ASpell *newSpell) 
{
  std::vector<ASpell *>::const_iterator it;
  for (it = _spells.begin(); it != _spells.end(); ++it) {
    if ((*it)->getName() == newSpell->getName())
      return; // do nothing
  }
  _spells.push_back(newSpell);
}

// Deletes a spell from the book
void Spellbook::forgetSpell(std::string spellName) 
{
  std::vector<ASpell *>::const_iterator it;
  for (it = _spells.begin(); it != _spells.end(); ++it) {
    if ((*it)->getName() == spellName) {
      _spells.erase(it);
      return;
    }
  }
}
// receives a string corresponding to the name of a spell creates it and returns it.
ASpell *Spellbook::createSpell(std::string const &spellName) 
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

const std::vector<ASpell *> &Spellbook::getSpells() const
{
	return _spells;
};
