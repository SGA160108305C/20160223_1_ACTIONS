#include "stdafx.h"
#include "GameState_Actions.h"


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

		ActionMove* move = new ActionMove;
		move->SetStart(D3DXVECTOR3(0, 0, 0));
		move->SetGoal(D3DXVECTOR3(0, 0, 15));
		move->SetDurationTime(2.0f);
		move->SetTarget(girl);

		girl->SetAction(move);
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
	GameManager::GetCamera()->SetDistance(30.0f);
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
