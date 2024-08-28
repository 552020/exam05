#pragma once
#include<iostream>
#include<string>
#include"ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		ASpell* clone() const;
};


