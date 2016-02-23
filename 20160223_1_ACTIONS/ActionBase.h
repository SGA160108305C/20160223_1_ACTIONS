#pragma once
#include "GameObject.h"

class ActionBase
{
public:

	ActionBase(){}
	virtual ~ActionBase(){}

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Destroy() = 0;

	inline GameObject* GetTarget() { return target; }
	inline void SetTarget(GameObject* _target) { target = _target; }

protected:
	bool isStart = false;
	GameObject* target = nullptr;
};

