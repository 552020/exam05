#pragma once

#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall();
		~BrickWall();

		ATarget *clone() const;
};

/*	
In addition to this, just so he won't have only dummy to attack, let's make a
new target for him, which will be the BrickWall (Type: "Inconspicuous Red-brick Wall").

*/
