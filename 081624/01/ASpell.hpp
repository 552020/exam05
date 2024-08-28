#ifndef ASPELL_HPP
#define ASPELL_HPP

#include "ATarget.hpp"
#include <string>

class ATarget;

class ASpell {
public:
  ASpell(const std::string &name, const std::string &effects);
  ASpell(const ASpell &other);
  ASpell &operator=(const ASpell &other);

  virtual ~ASpell();

  const std::string &getName() const;
  const std::string &getEffects() const;
  virtual void launch(const ATarget &target) const;

protected:
  std::string _name;
  std::string _effects;

  virtual ASpell *clone() const = 0;

private:
  ASpell();
};

#endif
