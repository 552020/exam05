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
	std::cout << _name << ": I am " << _name << ", " << _title <<  "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	std::vector<ASpell *>::const_iterator it;
	for(it = _spells.begin(); it != _spells.end(); ++it)
	{
		if((*it)->getName() == spell->getName())
			return;
	}
	_spells.push_back(spell);
}

void Warlock::forgetSpell(std::string spellName)
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

void Warlock::launchSpell(std::string spellName, const ATarget &target)
{
	//std::cout << "Entering launchSpell" << std::endl;
	std::vector<ASpell *>::const_iterator it;
	for(it = _spells.begin(); it != _spells.end(); ++it)
	{
		//std::cout << "(*it)->getName(): " << (*it)->getName() << std::endl;
		//std::cout << "spellName: " << spellName << std::endl;
		if((*it)->getName() == spellName)
		{
			//std::cout << "Entering if condition" << std::endl;
			// target.getHitBySpell(**it);
			(*it)->launch(target);
			return;
		}
	}
}

