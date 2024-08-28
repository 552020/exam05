#pragma once

#include <iostream>
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include <vector>

class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &targetType);
		ATarget *createTarget(std::string const &targetType);
		std::vector<ATarget *> &getTargets();


	private:
		TargetGenerator(const TargetGenerator &other);
		TargetGenerator &operator=(const TargetGenerator &rhs);
		std::vector<ATarget *> _targets;

};

/*

Make a TargetGenerator class, in canonical form, and as before,
non-copyable.

It will have the following functions:

* void learnTargetType(ATarget*), teaches a target to the generator

* void forgetTargetType(string const &), that makes the generator forget a
  target type if it's known

* ATarget* createTarget(string const &), that creates a target of the
  specified type

Now, make a SpellBook class, in canonical form, that can't be copied or instantiated
by copy. It will have the following functions:
*/
