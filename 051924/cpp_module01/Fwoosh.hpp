#ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class Fwoosh: public ASpell
{
	private:
		Fwoosh(const Fwoosh &obj);
		Fwoosh &operator=(const Fwoosh& obj);
	public:
		Fwoosh();
		virtual ~Fwoosh();
		ASpell *clone() const;
};

#endif
