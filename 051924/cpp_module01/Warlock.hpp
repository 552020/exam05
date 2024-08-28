#ifndef WARLOCK_HPP
# define WARLOCK_HPP
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
	private: 
		Warlock &operator=(Warlock const &rhs);
		Warlock(Warlock const &obj);
		Warlock();
		std::string _name;
		std::string _title;
		std::vector<ASpell*> _spellBook;

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &str);
		void setName(std::string const &str);
		void introduce() const;
		void learnSpell(ASpell *obj);
		void forgetSpell(std::string name);
		void launchSpell(std::string name, ATarget const &obj);
};

#endif
