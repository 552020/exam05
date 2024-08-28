#include"Warlock.hpp"

Warlock::Warlock(std::string const & name, std::string const & title) : name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(Warlock const & obj)
{
	*this = obj;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

Warlock & Warlock::operator=(Warlock const & rhs)
{
	this->name = rhs.name;
	this->title = rhs.title;
	return *this;
}

std::string const & Warlock::getName() const
{
	return this->name;
}

std::string const & Warlock::getTitle() const
{
	return this->title;
}

void Warlock::setTitle(std::string const & str)
{
	this->title = str;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* obj)
{
	for(std::vector<ASpell*>::const_iterator it = book.begin();it != book.end(); ++it)
	{
		if((*it)->getName() == obj->getName())
			return;
	}
	book.push_back(obj);
}

void Warlock::forgetSpell(std::string spell)
{
	for(std::vector<ASpell*>::iterator it = book.begin();it != book.end(); ++it)
	{
		if((*it)->getName() == spell)
		{
			book.erase(it);
			return;
		}
	}
}

void Warlock::launchSpell(std::string spell, ATarget const & target)
{
	for(std::vector<ASpell*>::const_iterator it = book.begin();it != book.end(); ++it)
	{
		if((*it)->getName() == spell)
		{
			(*it)->launch(target);
			return;
		}
	}
}
