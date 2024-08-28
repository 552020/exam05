#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	public:
		ASpell(const std::string &name, const std::string &effects);
		ASpell(const ASpell &other);
		ASpell &operator=(const ASpell &rhs);
		virtual ~ASpell();

		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell *clone() const = 0;
		void launch(const ATarget &target);

	private:
		ASpell();
		std::string _name;
		std::string _effects;
};

/*	

Finally, add to your ASpell class a launch function that takes a reference to
constant ATarget.

This one will simply call the getHitBySpell of the passed object, passing the
current instance as parameter.
	


Create an abstract class called ASpell, in Coplien's form, that has the
following protected attributes:

* name (string)
* effects (string)

Both will have getters (getName and getEffects) that return strings.

Also add a clone pure method that returns a pointer to ASpell.

All these functions can be called on a constant object.

ASpell has a constructor that takes its name and its effects, in that order.

*/
