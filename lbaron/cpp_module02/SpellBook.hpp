#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"ASpell.hpp"
#include"ATarget.hpp"

class SpellBook
{
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell* obj);
		void forgetSpell(std::string const & spell);
		ASpell* createSpell(std::string const & spell);
		
	private:
		SpellBook(SpellBook const & obj);
		SpellBook & operator=(SpellBook const & rhs);
		std::vector<ASpell*> book;
};

