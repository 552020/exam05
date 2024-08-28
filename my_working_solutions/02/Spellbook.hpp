#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include <string>
#include <vector>

class Spellbook {
public:
	Spellbook();
  ~Spellbook();
	void learnSpell(ASpell* newSpell);
	void forgetSpell(std::string spellName);
	ASpell *createSpell(std::string const &spellName);
	const std::vector<ASpell *> &getSpells() const;

private:
  Spellbook(Spellbook &other);
  Spellbook operator=(Spellbook &other);
	std::vector<ASpell *> _spells;
};

#endif

/*
Now, make a SpellBook class, in canonical form, that can't be copied or instantiated
by copy. It will have the following functions:

* void learnSpell(ASpell*), that COPIES a spell in the book
* void forgetSpell(string const &), that deletes a spell from the book, except
  if it isn't there
* ASpell* createSpell(string const &), that receives a string corresponding to
  the name of a spell, creates it, and returns it.
*/
