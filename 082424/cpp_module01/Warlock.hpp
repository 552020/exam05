#pragma once

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, const ATarget &target);

	private:
		Warlock();
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &rhs);
		std::string _name;
		std::string _title;
		std::vector<ASpell *> _spells;
};

/*

Add to the Warlock the following member functions:

* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
* forgetSpell, takes a string corresponding a to a spell's name, and makes the
  Warlock forget it. If it's not a known spell, does nothing.
* launchSpell, takes a string (a spell name) and a reference to ATarget, that
  launches the spell on the selected target. If it's not a known spell, does
  nothing.

You will need a new attribute to store the spells your Warlock knows. Several
types fit the bill, it's up to you to choose the best one.

Make a Warlock class. It has to be in Coplien's form.

It has the following private attributes :
* name (string)
* title (string)

Since they're private, you will write the following getters :
* getName, returns a reference to constant string
* getTitle, returns a reference to constant string

Both these functions will have to be callable on a constant Warlock.

Create the following setter:
* setTitle, returns void and takes a reference to constant string

Your Warlock will also have, in addition to whatever's required by Coplien's
form, a constructor that takes, in this order, its name and title. Your Warlock
will not be able to be copied, instantiated by copy, or instantiated without a
name and a title.

For example :

Warlock bob;                            //Does not compile
Warlock bob("Bob", "the magnificent");  //Compiles
Warlock jim("Jim", "the nauseating");   //Compiles
bob = jim;                              //Does not compile
Warlock jack(jim);                      //Does not compile

Upon creation, the Warlock says :

<NAME>: This looks like another boring day.

Of course, whenever we use placeholders like <NAME>, <TITLE>, etc...
in outputs, you will replace them by the appropriate value. Without the < and >.

When he dies, he says:

<NAME>: My job here is done!

Our Warlock must also be able to introduce himself, while boasting with all its
might.

So you will write the following function:
* void introduce() const;

It must display:

<NAME>: I am <NAME>, <TITLE>!

Here's an example of a test main function and its associated output:

int main()
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}

~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Mistress of Magma!$
Richard - Mistress of Magma$
Jack: This looks like another boring day.$
Jack: I am Jack, the Long!$
Jack: I am Jack, the Mighty!$
Jack: My job here is done!$
Richard: My job here is done!$

*/
