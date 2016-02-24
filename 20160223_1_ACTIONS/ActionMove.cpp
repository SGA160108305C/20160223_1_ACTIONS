#include "stdafx.h"
#include "ActionMove.h"


ActionMove::ActionMove()
{
}


ActionMove::~ActionMove()
{
}

void ActionMove::Start()
{
	if (!target)
	{
		return;
	}

	isStart = true;
	passedTime = 0.0f;
	target->SetPosition(start);
}

void ActionMove::Update()
{
	if (!target || isStart == false)
	{
		return;
	}

	passedTime += (float)GameManager::GetTick();
	if (passedTime > durationTime)
	{
		target->SetPosition(goal);
		isStart = false;
		if (actionDelegate)
		{
			actionDelegate->OnActionFinish(this);
		}
		return;
	}

	D3DXVECTOR3 pos;
	D3DXVec3Lerp(&pos, &start, &goal, passedTime / durationTime);
	//printf_s("pos: %.2f\n", passedTime / durationTime);
	target->SetPosition(pos);
}

void ActionMove::Destroy()
{

}