#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Warlock.hpp"
#include <iostream>

int main() {
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh *fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
