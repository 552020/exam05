#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"ASpell.hpp"
#include"ATarget.hpp"

class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget* obj);
		void forgetTargetType(std::string const & target);
		ATarget* createTarget(std::string const & target);
		
	private:
		TargetGenerator(TargetGenerator const & obj);
		TargetGenerator & operator=(TargetGenerator const & rhs);
		std::vector<ATarget*> targetList;
};

