#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy();
		Dummy(const Dummy &other);
		Dummy &operator=(const Dummy &other);
		virtual ~Dummy();

		virtual ATarget *clone() const;
};

#endif

//In the same way, create a concrete ATarget called Dummy, the type of which is "Target Practice Dummy". You must also implement its clone() method.
