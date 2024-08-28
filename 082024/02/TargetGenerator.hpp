#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <string>
#include <vector>
#include "ATarget.hpp"
#include "BrickWall.hpp"
#include "Dummy.hpp"

class TargetGenerator {
public:
	TargetGenerator();
  ~TargetGenerator();
	void learnTargetType(ATarget* newTarget);
	void forgetTargetType(std::string const &targetType);
	ATarget *createTarget(std::string const &targetType);

private:
	std::vector<ATarget *> _learntTargetTypes;
  TargetGenerator(TargetGenerator &other);
  TargetGenerator operator=(TargetGenerator &other);
};

#endif

/*
Make a TargetGenerator class, in canonical form, and as before,
non-copyable.

It will have the following functions:

* void learnTargetType(ATarget*), teaches a target to the generator

* void forgetTargetType(string const &), that makes the generator forget a
  target type if it's known

* ATarget* createTarget(string const &), that creates a target of the
  specified type
*/
