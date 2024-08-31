#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {};

Dummy::Dummy(const Dummy &other) : ATarget(other) {};

Dummy &Dummy::operator=(const Dummy &other) {
  if (this != &other)
    ATarget::operator=(other);
	return *this;
  // Since Dummy has no additional members, nothing else needs to be implemented
  // here
};

Dummy::~Dummy() {};

ATarget *Dummy::clone() const { return new Dummy(*this); };
