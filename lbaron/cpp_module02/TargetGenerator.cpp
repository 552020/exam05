#include"TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::TargetGenerator(TargetGenerator const & obj)
{
	*this = obj;
}

TargetGenerator::~TargetGenerator()
{
}

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & rhs)
{
	this->targetList = rhs.targetList;
	return *this;
}

void TargetGenerator::learnTargetType(ATarget* obj)
{
	for(std::vector<ATarget*>::const_iterator it = targetList.begin();it != targetList.end(); ++it)
	{
		if((*it)->getType() == obj->getType())
			return;
	}
	targetList.push_back(obj);

}

void TargetGenerator::forgetTargetType(std::string const & target)
{
		for(std::vector<ATarget*>::iterator it = targetList.begin();it != targetList.end(); ++it)
	{
		if((*it)->getType() == target)
		{
			targetList.erase(it);
			return;
		}
	}
}

ATarget* TargetGenerator::createTarget(std::string const & target)
{
	ATarget* tmp = NULL;
	for(std::vector<ATarget*>::const_iterator it = targetList.begin();it != targetList.end(); ++it)
	{
		if((*it)->getType() == target)
			tmp = (*it)->clone();
	}
	return tmp;
}
