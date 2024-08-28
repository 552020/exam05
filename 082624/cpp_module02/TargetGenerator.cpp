#include "TargetGenerator.hpp"




TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
}

std::vector<ATarget *> &TargetGenerator::getTargets()
{
	return _targets;
}
	
void TargetGenerator::learnTargetType(ATarget *target)
{
	std::vector<ATarget *>::const_iterator it;
	for(it = _targets.begin(); it != _targets.end(); ++it)
	{
		if((*it)->getType() == target->getType())
			return;
	}
	_targets.push_back(target);
}

void TargetGenerator::forgetTargetType(std::string const &targetType)
{
	std::vector<ATarget *>::iterator it;
	for(it = _targets.begin(); it != _targets.end(); ++it)
	{
		if((*it)->getType() == targetType)
		{
			_targets.erase(it);
			return;
		}
	}
}

ATarget *TargetGenerator::createTarget(std::string const &targetType)
{
	if (targetType == "Target Practice Dummy")
		return new Dummy();
	else if (targetType == "Inconspicuous Red-brick Wall")
		return new BrickWall();
	else
		return NULL;
}


	

