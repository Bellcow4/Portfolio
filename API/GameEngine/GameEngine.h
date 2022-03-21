#pragma once
#include <map>
#include <string>
#include <GameEngineBase/GameEngineDebug.h>

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

	template<typename GameType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();

		GameType UserGame;
		UserContents_ = &UserGame;

		WindowCreate();
		EngineEnd();		
	}
	
	static GameEngine& GlobalEngine()
	{
		if (nullptr == UserContents_)
		{
			MsgBoxAssert("GEngine Error");
		}
		return *UserContents_;
	}

	void ChangeLevel(const std::string& _Name);

protected:
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		NewLevel->SetName(_Name);
		GameEngineLevel* Level = NewLevel;
		Level->Loading();
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}

private:
	static std::map<std::string, GameEngineLevel*> AllLevel_;
	static GameEngineLevel* CurrentLevel_;
	static GameEngineLevel* NextLevel_;

	static GameEngine* UserContents_;

	static void WindowCreate();

	static void EngineInit();
	static void EngineLoop();
	static void EngineEnd();
};

