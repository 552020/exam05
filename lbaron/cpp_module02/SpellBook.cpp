#include"SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::SpellBook(SpellBook const & obj)
{
	*this = obj;
}

SpellBook::~SpellBook()
{
}

SpellBook & SpellBook::operator=(SpellBook const & rhs)
{
	this->book = rhs.book;
	return *this;
}

void SpellBook::learnSpell(ASpell* obj)
{
	for(std::vector<ASpell*>::const_iterator it = book.begin();it != book.end(); ++it)
	{
		if((*it)->getName() == obj->getName())
			return;
	}
	book.push_back(obj);
}

void SpellBook::forgetSpell(std::string const & spell)
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

ASpell* SpellBook::createSpell(std::string const & spell)
{
	ASpell* tmp = NULL;
	for(std::vector<ASpell*>::const_iterator it = book.begin();it != book.end(); ++it)
	{
		if((*it)->getName() == spell)
			tmp = (*it)->clone();
	}
	return tmp;
}
