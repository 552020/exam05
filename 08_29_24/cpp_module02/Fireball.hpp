#pragma once

#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball();
		~Fireball();

		ASpell *clone() const;
};

/*

Create the following two spells, on the same model as Fwoosh:

* Fireball (Name: "Fireball", Effects: "burnt to a crisp")
* Polymorph (Name: "Polymorph", Effects: "turned into a critter")

*/
