#include "GameEngineWindow.h"
#include "GameEngineDebug.h"







int XMove = 0;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        //윈도우를 종료하고 루프 탈출
        GameEngineWindow::GetInst_().Off();
        return DefWindowProc(hWnd, message, wParam, lParam);
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

        EndPaint(hWnd, &ps);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }       
    default:
        break;
    }


    return DefWindowProc(hWnd, message, wParam, lParam);
}

GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow();

GameEngineWindow::GameEngineWindow()
    : hInst_(nullptr)
    , hWnd_(nullptr)
    , WindowOn_(true)
    , HDC_(nullptr)
{
}

GameEngineWindow::~GameEngineWindow()
{
    if (nullptr != HDC_)
    {
        ReleaseDC(hWnd_, HDC_);
        HDC_ = nullptr;
    }

    if (nullptr != hWnd_)
    {
        DestroyWindow(hWnd_);
        hWnd_ = nullptr;
    }
}

void GameEngineWindow::Off()
{
    WindowOn_ = false;
}

void GameEngineWindow::RegClass(HINSTANCE _hInst)
{
    //윈도우 클래스 등록
    WNDCLASSEXA wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInst;
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "GameEngineWindowClass";
    wcex.hIconSm = nullptr;
    RegisterClassExA(&wcex);
}

void GameEngineWindow::CreateGameWindow(HINSTANCE _hInst, const std::string& _Title)
{
    if (nullptr != hInst_)
    {
        MsgBoxAssert("윈도우를 2번 호출했습니다.");
        return;
    }

    Title_ = _Title;

    // 클래스 등록은 1번만
    hInst_ = _hInst;
    RegClass(_hInst);
    

    hWnd_ = CreateWindowExA(0L, "GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);

    // 화면에 무언가를 그리기 위한 핸들
    HDC_ = GetDC(hWnd_);

    if (!hWnd_)
    {
        return;
    }
}

void GameEngineWindow::ShowGameWindow()
{
    if (nullptr == hWnd_)
    {
        MsgBoxAssert("메인 윈도우가 존재하지 않습니다.");
        return;
    }

    // 호출되기전에는 그릴수 없음
    ShowWindow(hWnd_, SW_SHOW);
    UpdateWindow(hWnd_);


    
}

void GameEngineWindow::MessageLoop(void(*_InitFunction)(), void(*_LoopFunction)())
{
    //루프 돌기전 준비함수 실행
    if (nullptr != _InitFunction)
    {
        _InitFunction();
    }

    MSG msg;

    while (WindowOn_)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            DispatchMessage(&msg);
        }

        //게임 처리구간
        

        if (nullptr == _LoopFunction)
        {
            continue;
        }

        _LoopFunction();

    }


    
}
