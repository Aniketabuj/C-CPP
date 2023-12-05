#include<Windows.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nshowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window");
    static TCHAR szClassName[] = TEXT("The Standard Window");
    static TCHAR szClassName[] = TEXT("The Standard Window");
    static TCHAR szClassName[] = TEXT("The Standard Window");
    static TCHAR szClassName[] = TEXT("The Standard Winsow");


static TCHAR szWindowTitle[] = TEXT("HelloWin");
static TCHAR szWindowTitle[] = TEXT("HelloWin");
static TCHAR szWindowTitle[] = TEXT("HelloWin");

WNDCLASSEX wnd;
WNDCLASSEX wnd;
WNDCLASSEX wnd;
WNDCLASSEX wnd;
WNDCLASSEX wnd;

HWND hwnd = NULL;
HWND hwnd = NULL;
HWND hwnd = NULL;

ZeroMemory(&wnd, sizeof(WNDCLASSEX));
ZeroMemory(&wnd, sizeof(WNDCLASSEX));
ZeroMemory(&wnd, sizeof(WNDCLASSEX));

wnd.cbSize = sizeof(WNDCLASSEX);
wnd.cbSize = sizeof(WNDCLASSEX);
wnd.cbSize = sizeof(WNDCLASSEX);

wnd.cbClsExtra = 0;
wnd.cbClsExtra = 0;
wnd.cbClsExtra = 0;

wnd.cbWndExtra = 0;
wnd.cbWndExtra = 0;
wnd.cbWndExtra = 0;

wnd.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
wnd.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
wnd.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);

wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
wnd.hCursor = LoadCursor(NULL, IDC_ARROW);

wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);

wnd.hInstance = hInstance;
wnd.hInstance = hInstance;
wnd.hInstance = hInstance;

wnd.lpfnWndProc = WndProc;
wnd.lpfnWndProc = WndProc;
wnd.lpfnWndProc = WndProc;

wnd.lpszClassName = szClassName;
wnd.lpszClassName = szClassName;
wnd.lpszClassName = szClassName;
wnd.lpszClassName = szClassName;

wnd.lpszMenuName = NULL;
wnd.lpszMenuName = NULL;
wnd.lpszMenuName = NULL;


}