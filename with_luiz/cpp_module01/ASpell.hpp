#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	public:
		ASpell(const std::string &name, const std::string &effects);
		ASpell(const ASpell &rhs);
		ASpell &operator=(const ASpell &other);
		virtual ~ASpell();

		const std::string &getName() const;
		const std::string &getEffects() const;
		virtual ASpell *clone() const = 0;
		void launch(const ATarget &target);

	protected:
		std::string _name;
		std::string _effects;
	
	private:
		ASpell();

};


/*

Make a ASpell class. It has to be in Coplien's form.

It has the following private attributes :
* name (string)
* title (string)

Since they're private, you will write the following getters :
* getName, returns a reference to constant string
* getTitle, returns a reference to constant string

Both these functions will have to be callable on a constant ASpell.

Create the following setter:
* setTitle, returns void and takes a reference to constant string

Your ASpell will also have, in addition to whatever's required by Coplien's
form, a constructor that takes, in this order, its name and title. Your ASpell
will not be able to be copied, instantiated by copy, or instantiated without a
name and a title.

For example :

ASpell bob;                            //Does not compile
ASpell bob("Bob", "the magnificent");  //Compiles
ASpell jim("Jim", "the nauseating");   //Compiles
bob = jim;                              //Does not compile
ASpell jack(jim);                      //Does not compile

Upon creation, the ASpell says :

<NAME>: This looks like another boring day.

Of course, whenever we use placeholders like <NAME>, <TITLE>, etc...
in outputs, you will replace them by the appropriate value. Without the < and >.

When he dies, he says:

<NAME>: My job here is done!

Our ASpell must also be able to introduce himself, while boasting with all its
might.

So you will write the following function:
* void introduce() const;

It must display:

<NAME>: I am <NAME>, <TITLE>!

Here's an example of a test main function and its associated output:

int main()
{
  ASpell const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  ASpell* jack = new ASpell("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}
*/

