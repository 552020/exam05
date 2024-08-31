#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects)
    : _name(name), _effects(effects) {};

ASpell::ASpell(const ASpell &other)
    : _name(other._name), _effects(other._effects) {};

ASpell &ASpell::operator=(const ASpell &other) {
  if (this != &other) {
    _name = other._name;
    _effects = other._effects;
  }
	return *this;
};

ASpell::~ASpell() {};

const std::string &ASpell::getName() const { return _name; }

const std::string &ASpell::getEffects() const { return _effects; }

void ASpell::launch(const ATarget &target) const {
  target.getHitBySpell(*this);
}

// Finally, add to your ASpell class a launch function that takes a reference to
// constant ATarget.

// This one will simply call the getHitBySpell of the passed object, passing the
// current instance as parameter.
