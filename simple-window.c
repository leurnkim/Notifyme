#include <windows.h>

#define WIN32_LEAN_AND_MEAN

const char g_szClassName[] = "OurClass";

      // Шаг 4: "the Window Procedure".
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_LBUTTONDOWN:
			DestroyWindow(hwnd);
			break;

  /**
		case WM_CLOSE:
			DestroyWindow(hwnd);
	
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
  **/

		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}


  //
  // The Blast From The Past.
  //


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

        // Шаг 1: Регистрация класса окна.
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.style		 = 0;
	wc.lpfnWndProc	 = WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.hInstance	 = hInstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);			// Needs some expiriments?
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

        // Class registration seems doing by name.
	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Регистрауия окна прервана!", "Ошибка!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}


        // Шаг 2: Создание Окна.
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"Заголовок Моего Окна",
		WS_POPUP,								// Window Style (WS_*)...
												// WS_OVERLAPPEDWINDOW,
												// WS_DLGFRAME: no minimize/maximize, shut. controls,
												// WS_POPUP: just we're expected to be.
		CW_USEDEFAULT, CW_USEDEFAULT, 540, 120,		// start posotoin and geometry,
		NULL,										// HWND      hWndParent,
		NULL,										// HMENU     hMenu,
		hInstance,									// HINSTANCE hInstance,
		NULL);										// LPVOID    lpParam.

        // Errorcheck.
	if(hwnd == NULL)
	{
		MessageBox(NULL, "Создание окна прервано!", "Ошибка!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

        // Шаг 3: "The Message Loop"
	while(GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}