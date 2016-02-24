#include "stdafx.h"
#include "GameState_Actions.h"
#include "ActionMove.h"


GameState_Actions::GameState_Actions()
{
}


GameState_Actions::~GameState_Actions()
{
}

void GameState_Actions::Initialize()
{
	if (grid == nullptr)
	{
		grid = new Grid;
		grid->Initialize();
	}
	if (girl == nullptr)
	{
		girl = new Character;
		girl->Initialize();

		ActionSequence* sequence = new ActionSequence;

		ActionMove* move1 = new ActionMove;
		move1->SetStart(D3DXVECTOR3(0, 0, 0));
		move1->SetGoal(D3DXVECTOR3(0, 0, -15));
		move1->SetDurationTime(1.0f);
		move1->SetTarget(girl);
		move1->SetDelegate(sequence);
		sequence->AddAction(move1);

		ActionMove* move2 = new ActionMove;
		move2->SetStart(D3DXVECTOR3(0, 0, -15));
		move2->SetGoal(D3DXVECTOR3(10, 0, -15));
		move2->SetDurationTime(1.0f);
		move2->SetTarget(girl);
		move2->SetDelegate(sequence);
		sequence->AddAction(move2);

		ActionMove* move3 = new ActionMove;
		move3->SetStart(D3DXVECTOR3(10, 0, -15));
		move3->SetGoal(D3DXVECTOR3(10, 0, 0));
		move3->SetDurationTime(1.0f);
		move3->SetTarget(girl);
		move3->SetDelegate(sequence);
		sequence->AddAction(move3);

		girl->SetAction(sequence);
	}
	Reset();
}

void GameState_Actions::Destroy()
{
	SAFE_DELETE(girl);
	SAFE_DELETE(grid);
}

void GameState_Actions::Reset()
{
}

void GameState_Actions::Update()
{
	if (girl)
	{
		girl->Update();
	}
}

void GameState_Actions::Render()
{
	if (grid)
	{
		grid->Render();
	}
	if (girl)
	{
		girl->Render();
	}
}

void GameState_Actions::OnEnterState()
{
	GameManager::GetCamera()->SetDistance(20.0f);
	Initialize();
}

void GameState_Actions::OnLeaveState()
{
	Destroy();
}

LRESULT GameState_Actions::InputProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	return result;
}
