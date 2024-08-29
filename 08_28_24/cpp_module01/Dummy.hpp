#pragma once

#include "ATarget.hpp"
#include <iostream>

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();

		ATarget *clone() const;
};

/*

When all this is done, create an implementation of ATarget called Fwoosh. Its
default constructor will set the name to "Fwoosh" and the effects to
"fwooshed". You will, of course, implement the clone() method. In the case of
Fwoosh, it will return a pointer to a new Fwoosh object.

In the same way, create a concrete ATarget called Dummy, the type of which
is "Target Practice Dummy". You must also implement its clone() method.

*/
