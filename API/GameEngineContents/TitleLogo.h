#pragma once
#include <GameEngine/GameEngineActor.h>

class TitleLogo : public GameEngineActor
{
public:
	// constructer destructer
	TitleLogo();
	~TitleLogo();

	// delete Function
	TitleLogo(const TitleLogo& _Other) = delete;
	TitleLogo(TitleLogo&& _Other) noexcept = delete;
	TitleLogo& operator=(const TitleLogo& _Other) = delete;
	TitleLogo& operator=(TitleLogo&& _Other) noexcept = delete;

protected:

private:
	 

};

