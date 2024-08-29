#pragma once

#include <iostream>
#include <vector>
#include "ATarget.hpp"
#include "ATarget.hpp"

class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget* target);
		void forgetTargetType(const std::string &targetType);
		ATarget* createTarget(std::string const &targetType);

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

*/
