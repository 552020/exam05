#include "Warlock.hpp"

Warlock::Warlock()
{
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const std::string &name, const std::string &title): _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;

}


Warlock::Warlock(const Warlock &obj)
{
	_name = obj._name;
	_title = obj._title;
}

Warlock &Warlock::operator=(const Warlock &obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		_title = obj._title;
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
