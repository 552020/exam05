#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string _name;
		std::string _effects;
		ASpell();
		ASpell(const ASpell &obj);
		ASpell &operator=(const ASpell& obj);
	public:
		ASpell(const std::string &name, const std::string &effects);
		virtual ~ASpell();
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell *clone() const = 0;
		void launch(const ATarget &obj);
};

#endif
