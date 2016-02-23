#include "stdafx.h"
#include "ActionSequence.h"


ActionSequence::ActionSequence()
{
}


ActionSequence::~ActionSequence()
{
}

void ActionSequence::Start()
{
	currentIndex = 0;
	if (actionArray.empty())
	{
		return;
	}

	actionArray[currentIndex]->Start();
}

void ActionSequence::Update()
{

}

void ActionSequence::Destroy()
{

}

void ActionSequence::OnActionFinish(ActionBase* sender)
{

}