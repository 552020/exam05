#include "Warlock.hpp"

Warlock::Warlock()
{
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	
	for (std::vector<ASpell*>::iterator it = _spellBook.begin(); it != _spellBook.end(); ++it)
	{
		if (*it)
			delete *it;
	}
	_spellBook.clear();
}

Warlock::Warlock(const std::string &name, const std::string &title): _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;

}


Warlock::Warlock(const Warlock &obj)
{
	_name = obj._name;
	_title = obj._title;
	for (std::vector<ASpell*>::const_iterator it = obj._spellBook.begin(); it != obj._spellBook.end(); ++it)
	{
		_spellBook.push_back((*it)->clone());
	}

}

Warlock &Warlock::operator=(const Warlock &obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		_title = obj._title;
		for (std::vector<ASpell*>::const_iterator it = obj._spellBook.begin(); it != obj._spellBook.end(); ++it)
	{
		_spellBook.push_back((*it)->clone());
	}
	}
	return (*this);
}

const std::string &Warlock::getName() const
{
	return (_name);
}

const std::string &Warlock::getTitle() const
{
	return _title;
}

void Warlock::setTitle(const std::string& str)
{
	_title = str;
}

void Warlock::setName(const std::string &str)
{
	_name = str;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *obj)
{
	_spellBook.push_back(obj->clone());
}

// it is a pointer and ASpell is a pointer, I mean vector of pointers so 2x derefence

void Warlock::forgetSpell(std::string name)
{
	for (std::vector<ASpell*>::iterator it = _spellBook.begin(); it != _spellBook.end(); ++it)
		if ((*it)->getName() == name)
		{
			delete *it;
			_spellBook.erase(it);
			break;
		}

}

void Warlock::launchSpell(std::string name, ATarget const& obj)
{
	for (std::vector<ASpell*>::iterator it = _spellBook.begin(); it != _spellBook.end(); ++it)
		if ((*it)->getName() == name)
		{
			obj.getHitBySpell(**it);
			break;
		}
}
