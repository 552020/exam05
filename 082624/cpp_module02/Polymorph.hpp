#pragma once

#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
		Polymorph();
		~Polymorph();

		ASpell *clone() const;
};

/*	
Create the following two spells, on the same model as Fwoosh:

* Polymorph (Name: "Polymorph", Effects: "turned into a critter")

*/
