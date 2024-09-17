#pragma once

#include <iostream>
#include "ATarget.hpp"

class Flower : public ATarget
{
	public:
		Flower();
		~Flower();

		ATarget *clone() const;
};

/*

In the same way, create a concrete ATarget called Dummy, the type of which
is "Target Practice Dummy". You must also implement its clone() method.
*/
