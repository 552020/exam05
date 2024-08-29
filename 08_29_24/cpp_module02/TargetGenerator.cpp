#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if(!target)
		return;
	std::vector<ATarget *>::const_iterator it;
	for(it = _targets.begin(); it != _targets.end(); ++it)
	{
		if((*it)->getType() == target->getType())
			return;
	}
	_targets.push_back(target);
}

void TargetGenerator::forgetTargetType(const std::string &targetType)
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

ATarget* TargetGenerator::createTarget(std::string const &targetType)
{
	ATarget *newTarget = NULL;
	std::vector<ATarget *>::const_iterator it;
	for(it = _targets.begin(); it != _targets.end(); ++it)
	{
		if((*it)->getType() == targetType)
		{
			newTarget = (*it)->clone();
		}
	}
	return newTarget;
}

