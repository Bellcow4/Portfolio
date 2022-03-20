#include <Windows.h>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/BubbleBobble.h>

BubbleBobble MyGame;

void GameInit()
{
    // �ؽ��ĸ� �ε��ϰ� �غ�
    MyGame.GameInit();
}

void GameLoop()
{
    //���� ����
    Rectangle(GameEngineWindow::GETDC(), 100, 100, 200, 200);

    MyGame.GameLoop();
}

int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char*    lpCmdLine,
    _In_ int       nCmdShow)
{

    GameEngineDebug::LeakCheckOn();

    // ������ ȭ�� �ϳ� -> ������ �����Լ� �ѹ� ȣ��
    // GameEngineBase�� cpp���� �˱��� �����Ƿ� ���� �߰� �ؾߵ�
    GameEngineWindow::GetInst_().CreateGameWindow(hInstance, "GameWindow");
    GameEngineWindow::GetInst_().ShowGameWindow();
    GameEngineWindow::GetInst_().MessageLoop(GameInit, GameLoop);

    GameEngineWindow::Destroy();

    MyGame.GameEnd();
}