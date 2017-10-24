#include <Windows.h>
#include <string>

#include "Graphics.h"

#include "Level1.h"
#include "GameController.h"

Graphics* graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, int nCmdShow)
{
	WNDCLASSEX windowclass;

	LPCSTR m_AppTitle = "Direct2D";

	ZeroMemory(&windowclass, sizeof(WNDCLASSEX));

	windowclass.cbSize = sizeof(WNDCLASSEX);
	windowclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowclass.hInstance = hInstance;
	windowclass.lpfnWndProc = WindowProc;
	windowclass.lpszClassName = m_AppTitle;
	windowclass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&windowclass);

	UINT m_ClientWidth = 1600;
	UINT m_ClientHeight = 900;

	RECT r = { 0, 0, m_ClientWidth, m_ClientHeight };
	AdjustWindowRect(&r, WS_OVERLAPPEDWINDOW, FALSE);
	UINT width = r.right - r.left;
	UINT height = r.bottom - r.top;
	UINT x = GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2;
	UINT y = GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2;

	HWND wndHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, m_AppTitle, m_AppTitle, WS_OVERLAPPEDWINDOW, x, y, m_ClientWidth, m_ClientHeight, NULL, NULL, hInstance, 0);

	if (!wndHandle)
	{
		OutputDebugString("\nFAILED TO CREATE WINDOW\n");
		return false;
	}

	graphics = new Graphics;

	if (!graphics->Init(wndHandle))
	{
		delete graphics;
		return false;
	}

	ShowWindow(wndHandle, SW_SHOW);

	GameLevel::Init(graphics);
	GameController::LoadInitialLevel(new Level1());

	MSG message;
	message.message = WM_NULL;

	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, wndHandle, 0, 0, PM_REMOVE))
			DispatchMessage(&message);
		else
		{
			//UPDATE
			GameController::Update();

			//RENDER
			graphics->BeginDraw();
			GameController::Render();
			graphics->EndDraw();
		}
	}

	delete graphics;

	return true;
}