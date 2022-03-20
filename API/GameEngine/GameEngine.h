#pragma once
#include <map>
#include <string>

//게임 엔진이란 게임 그자체의 시작과 끝 실행중을 담당한다.
class GameEngineLevel;
class GameEngine
{
public:
	// constructer destructer
	GameEngine();
	~GameEngine();

	// delete Function
	GameEngine(const GameEngine& _Other) = delete;
	GameEngine(GameEngine&& _Other) noexcept = delete;
	GameEngine& operator=(const GameEngine& _Other) = delete;
	GameEngine& operator=(GameEngine&& _Other) noexcept = delete;

	// GameEngine 이 세가지를 내용이 없더라도 구현해야함
	virtual void GameInit() = 0;
	virtual void GameLoop() = 0;
	virtual void GameEnd() = 0; 
	
	

protected:
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		NewLevel->SetName(_Name);
		NewLevel->Loading();
		AllLevel.insert(std::make_pair(_Name, NewLevel));
	}

private:
	std::map<std::string, GameEngineLevel*> AllLevel;
	 

};

