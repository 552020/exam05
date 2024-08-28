#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall();
		BrickWall(const BrickWall &other);
		BrickWall &operator=(const BrickWall &other);
		virtual ~BrickWall();

		virtual ATarget *clone() const;
};

#endif

// In addition to this, just so he won't have only dummy to attack, let's make a new target for him, which will be the BrickWall (Type: "Inconspicuous Red-brick Wall").

