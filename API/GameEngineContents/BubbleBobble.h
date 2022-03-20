#pragma once
#include <GameEngine/GameEngine.h>

class BubbleBobble : public GameEngine
{
public:
	// constructer destructer
	BubbleBobble();
	~BubbleBobble();

	// delete Function
	BubbleBobble(const BubbleBobble& _Other) = delete;
	BubbleBobble(BubbleBobble&& _Other) noexcept = delete;
	BubbleBobble& operator=(const BubbleBobble& _Other) = delete;
	BubbleBobble& operator=(BubbleBobble&& _Other) noexcept = delete;

	void GameInit() override;
	void GameLoop() override;
	void GameEnd() override;

protected:

private:
	 

};

