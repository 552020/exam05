#include <string>
#include <iostream>

class Warlock
{
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		std::string getName() const;
		std::string getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;
	private:
		Warlock();
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &other);
		std::string _name;
		std::string _title;
};
