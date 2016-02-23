#pragma once
#include "ActionBase.h"

class ActionSequence :
	public ActionBase, public ActionDeligate
{
public:
	ActionSequence();
	virtual ~ActionSequence();

	virtual void Start() override;
	virtual void Update() override;
	virtual void Destroy() override;

	virtual void OnActionFinish(ActionBase* sender) override;

private:
	std::vector<ActionBase*> actionArray;
	UINT32 currentIndex = 0;
};

