#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title)
    : _name(name), _title(title) {
  std::cout << _name << ": This looks like another boring day." << std::endl;
};

Warlock::~Warlock() {
  std::cout << _name << ": My job here is done!" << std::endl;
};

const std::string &Warlock::getName() const { return _name; };

const std::string &Warlock::getTitle() const { return _title; };

void Warlock::setTitle(const std::string &title) { _title = title; };

void Warlock::introduce() const {
  std::cout << _name << ": I am " << _name << ", " << _title << "!"
            << std::endl;
}

void Warlock::learnSpell(ASpell *newSpell) {
	_spells.learnSpell(newSpell);
}

void Warlock::forgetSpell(std::string spellName) {
	_spells.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget &target) {
  std::vector<ASpell *>::const_iterator it;
  for (it = _spells.getSpells().begin(); it != _spells.getSpells().end(); ++it) {
    if ((*it)->getName() == spellName) {
			ASpell *spellToLaunch = _spells.createSpell(spellName);
      // (*it)->launch(target);
			spellToLaunch->launch(target);
    }
  }
}
