#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
};

TargetGenerator::~TargetGenerator() 
{
};

// teacher a target to the generator 
void TargetGenerator::learnTargetType(ATarget *newTarget) 
{
  std::vector<ATarget *>::const_iterator it;
  for (it = _learntTargetTypes.begin(); it != _learntTargetTypes.end(); ++it) {
    if ((*it)->getType() == newTarget->getType())
      return; // do nothing
  }
  _learntTargetTypes.push_back(newTarget);
}

// Deletes a spell from the book
void TargetGenerator::forgetTargetType(std::string const &targetType) 
{
  std::vector<ATarget *>::const_iterator it;
  for (it = _learntTargetTypes.begin(); it != _learntTargetTypes.end(); ++it) {
    if ((*it)->getType() == targetType) {
      _learntTargetTypes.erase(it);
      return;
    }
  }
}
// receives a string corresponding to the name of a spell creates it and returns it.
ATarget *TargetGenerator::createTarget(std::string const &targetType) 
{
	if (targetType == "Target Practice Dummy")
		return new Dummy();
	else if (targetType == "Inconspicuous Red-brick Wall")
		return new BrickWall();
	else
		return NULL;
}
