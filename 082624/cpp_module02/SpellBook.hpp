#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include <vector>

class SpellBook
{
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &spellName);
		ASpell *createSpell(std::string const &spellName);
		std::vector<ASpell *> &getSpells();


	private:
		SpellBook(const SpellBook &other);
		SpellBook &operator=(const SpellBook &rhs);
		std::vector<ASpell *> _spells;

};

/*

Now, make a SpellBook class, in canonical form, that can't be copied or instantiated
by copy. It will have the following functions:

* void learnSpell(ASpell*), that COPIES a spell in the book
* void forgetSpell(string const &), that deletes a spell from the book, except
  if it isn't there
* ASpell* createSpell(string const &), that receives a string corresponding to
  the name of a spell, creates it, and returns it.

*/
