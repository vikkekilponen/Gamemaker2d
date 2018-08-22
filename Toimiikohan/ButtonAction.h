#pragma once
#include <vector>
#include "ControllablePoint.h"
class ButtonAction
{
public:
	ButtonAction();
	~ButtonAction();
	virtual void action();
	virtual std::vector<ControllablePoint>* getObjects();

};

