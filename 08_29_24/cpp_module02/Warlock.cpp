#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
	return _name;
}

const std::string &Warlock::getTitle() const
{
	return _title;
}

void Warlock::setTitle(const std::string &title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}		

void Warlock::learnSpell(ASpell *spell)
{
	if(spell)
		_spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName)
{
	_spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget &target)
{
	// std::cout << "Entering launchSpell" << std::endl;
	ASpell *newSpell = _spellBook.createSpell(spellName);
	// std::cout << "newSpell: " << newSpell << std::endl;
	if (newSpell)
	{
		// std::cout << "Entering the if condition" << std::endl;
		newSpell->launch(target);
	}
}

