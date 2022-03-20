#include <Windows.h>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/BubbleBobble.h>

BubbleBobble MyGame;

void GameInit()
{
    // 텍스쳐를 로딩하고 준비
    MyGame.GameInit();
}

void GameLoop()
{
    //게임 실행
    Rectangle(GameEngineWindow::GETDC(), 100, 100, 200, 200);

    MyGame.GameLoop();
}

int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char*    lpCmdLine,
    _In_ int       nCmdShow)
{

    GameEngineDebug::LeakCheckOn();

    // 게임의 화면 하나 -> 윈도우 생성함수 한번 호출
    // GameEngineBase의 cpp까지 알길이 없으므로 참조 추가 해야됨
    GameEngineWindow::GetInst_().CreateGameWindow(hInstance, "GameWindow");
    GameEngineWindow::GetInst_().ShowGameWindow();
    GameEngineWindow::GetInst_().MessageLoop(GameInit, GameLoop);

    GameEngineWindow::Destroy();

    MyGame.GameEnd();
}