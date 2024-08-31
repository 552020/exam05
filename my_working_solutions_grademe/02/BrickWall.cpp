#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {};

BrickWall::BrickWall(const BrickWall &other) : ATarget(other) {};

BrickWall &BrickWall::operator=(const BrickWall &other) {
  if (this != &other)
    ATarget::operator=(other);
	return *this;
  // Since BrickWall has no additional members, nothing else needs to be implemented
  // here
};

BrickWall::~BrickWall() {};

ATarget *BrickWall::clone() const { return new BrickWall(*this); };
