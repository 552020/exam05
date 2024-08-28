#ifndef WARLOCK_HPP
# define WARLOCK_HPP
#include <iostream>

class Warlock {
	private: 
		Warlock &operator=(Warlock const &rhs);
		Warlock(Warlock const &obj);
		Warlock();
		std::string _name;
		std::string _title;

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &str);
		void setName(std::string const &str);
		void introduce() const;
};

#endif
