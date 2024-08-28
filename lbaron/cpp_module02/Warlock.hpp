#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"ASpell.hpp"
#include"ATarget.hpp"
#include"Fwoosh.hpp"
#include"Dummy.hpp"
#include"Fireball.hpp"
#include"Polymorph.hpp"
#include"BrickWall.hpp"
#include"SpellBook.hpp"
#include"TargetGenerator.hpp"

class Warlock
{
	public:
		Warlock(std::string const & name, std::string const & title);
		~Warlock();
		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle(std::string const & str);
		void introduce() const;
		void learnSpell(ASpell* obj);
		void forgetSpell(std::string spell);
		void launchSpell(std::string spell, ATarget const & target);
		
	private:
		std::string name;
		std::string title;
		Warlock(Warlock const & obj);
		Warlock & operator=(Warlock const & rhs);
		SpellBook book;	
};

