#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	public:
		ATarget(const std::string &type);
		ATarget(const ATarget &other);
		ATarget &operator=(const ATarget &rhs);
		virtual ~ATarget();

		const std::string &getType() const;
		virtual ATarget *clone() const = 0;
		void getHitBySpell(const ASpell &spell) const;

	protected:
		std::string _type;

	private:
		ATarget();
};

/*

Now, add to your ATarget a getHitBySpell function that takes a reference to
constant ASpell.

It will display :

<TYPE> has been <EFFECTS>!

<TYPE> is the ATarget's type, and <EFFECTS> is the return of the ASpell's
getEffects function.
Now you will create an ATarget abstract class, in Coplien's form. It has a type
attribute, which is a string, and its associated getter, getType, that return a
reference to constant string.

In much the same way as ASpell, it has a clone() pure method.

All these functions can be called on a constant object.

It has a constructor that takes its type.

Now, add to your ATarget a getHitBySpell function that takes a reference to
constant ASpell.

It will display :

<TYPE> has been <EFFECTS>!

<TYPE> is the ATarget's type, and <EFFECTS> is the return of the ASpell's
getEffects function.
*/
