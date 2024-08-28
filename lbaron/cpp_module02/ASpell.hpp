#pragma once
#include<iostream>
#include<string>
#include"ATarget.hpp"

class ATarget;

class ASpell
{
	public:
		ASpell(std::string const & name, std::string const & effects);
		virtual ~ASpell();
		ASpell(ASpell const & obj);
		ASpell & operator=(ASpell const & rhs);
		std::string const & getName() const;
		std::string const & getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(ATarget const & target);

		
	private:
		std::string name;
		std::string effects;
};

