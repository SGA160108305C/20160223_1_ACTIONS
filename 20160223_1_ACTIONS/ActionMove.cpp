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

	D3DXVECTOR3 a(0,0,1);
	D3DXVECTOR3 b = goal - start;
	D3DXVECTOR3 normalB;
	D3DXVec3Normalize(&normalB, &b);

	float aLength = D3DXVec3Length(&a);
	float bLength = D3DXVec3Length(&normalB);
	float dot = D3DXVec3Dot(&a, &normalB);//-1 ~ 1
	//printf_s("dot: %.2f\n", dot);
	// 시계방향인지 반시계방향인지 판별
	D3DXVECTOR3 cross;
	D3DXVec3Cross(&cross, &a, &normalB);
	//if (cross.y < 0)	
	//{
	//	dot *= -1;		// 반시계 방향이다. 그러면 각도가 반대로
	//}

	float angle = acos(dot / (aLength * bLength));	//acos는 0~180도 사이의 값만 나온다.
	printf_s("test: %.2f\n", dot);

	if (dot < 0 && cross.y < 0)
	{
		angle *= -1;
	}

	if (dot > 0 && cross.y < 0)
	{
		angle *= -1;
	}

	//angle = -3.14f;

	//따라서 180도 이상인지 판별
	//D3DXVECTOR3 c(1, 0, 0);	//a를 90도 만큼 돌린 백터
	//bool over180 = false;
	//if (D3DXVec3Dot(&normalB, &c) < 0.0f)	// c,b가 90도 이상이면 a,b가 180도 이상이라는 소리
	//{
	//	over180 = true;
	//}

	//180도 이상이면 180도를 더해줌
	/*if (over180)
	{
		angle += D3DX_PI;
	}*/

	target->SetAngle(angle);
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