#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Spellbook.hpp"

class Warlock {
public:
  Warlock(std::string const &name, std::string const &title);
  ~Warlock();
  const std::string &getName() const;
  const std::string &getTitle() const;

  void setTitle(const std::string &title);
  void introduce() const;

	void learnSpell(ASpell* newSpell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, const ATarget &target);

private:
  Warlock();
  Warlock(Warlock &other);
  Warlock operator=(Warlock &other);

  std::string _name;
  std::string _title;
	Spellbook _spells;
	
};

#endif

/*
Add to the Warlock the following member functions:

* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
* forgetSpell, takes a string corresponding a to a spell's name, and makes the
  Warlock forget it. If it's not a known spell, does nothing.
* launchSpell, takes a string (a spell name) and a reference to ATarget, that
  launches the spell on the selected target. If it's not a known spell, does
  nothing.
	You will need a new attribute to store the spells your Warlock knows. Several types fit the bill, it's up to you to choose the best one.

Modify the Warlock, now, make it have a spell book that will be created with
him and destroyed with him. Also make his learnSpell and forgetSpell functions
call those of the spell book.

The launchSpell function will have to use the SpellBook to create the spell
it's attempting to launch.

*/

