#ifndef DUMMY_HPP
# define DUMMY_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class Dummy: public ATarget
{
	private:
		Dummy(const Dummy &obj);
		Dummy &operator=(const Dummy &obj);
	public:
		Dummy();
		virtual ~Dummy();
		ATarget *clone() const;
};

#endif
