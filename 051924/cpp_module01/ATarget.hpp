#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string _type;
		ATarget();
		ATarget(const ATarget &obj);
		ATarget &operator=(const ATarget& obj);
	public:
		ATarget(const std::string &type);
		virtual ~ATarget();
		const std::string &getType() const;
		virtual ATarget *clone() const = 0;
		void getHitBySpell(ASpell &obj) const;
};

#endif
