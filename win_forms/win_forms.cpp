



#include "win_forms.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string>
#include <math.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <shellapi.h>
#include <clocale>
#include <cwchar>

#include <iostream>


static LRESULT CALLBACK
WindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg) {
        case WM_CREATE:
        {
            //DragAcceptFiles(wnd, TRUE);
            break;
        }

        case WM_DESTROY:
        {
            //DragAcceptFiles(wnd, FALSE);
            PostQuitMessage(0);
            return 0;
        }
        case WM_USER:
        {
            return 0;
        }
        case WM_DROPFILES:
        {
            //HandleFiles(wparam);
            //DragFunc(wnd, wparam);
            return 0;
        }
    }
    //if (nk_gdip_handle_event(wnd, msg, wparam, lparam))
    //    return 0;
    return DefWindowProcW(wnd, msg, wparam, lparam);
}

HWND wnd = 0;

void EF_forceRequestRedraw()
{
    PostMessage(wnd, WM_USER, 0, 0);
}


#include <strstream>
#include <vector>
#include <unordered_map>



extern "C" __declspec(dllexport) int32_t EEmbCreateWindow(const char* title, uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
	 WNDCLASSW wc;
    //WNDCLASSEXW wc;
    RECT rect = { 
        (LONG)x, 
        (LONG)y, 
        (LONG)width, (LONG)height 
    };
    DWORD style = WS_OVERLAPPEDWINDOW;
    DWORD exstyle = WS_EX_APPWINDOW | WS_EX_ACCEPTFILES;
    int running = 1;
    int needs_refresh = 1;

    /* Win32 */
    memset(&wc, 0, sizeof(wc));
    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandleW(0);
    wc.hIcon = LoadIcon(wc.hInstance, "IDI_APPLICATION"); //LoadIcon(nullptr, IDI_APPLICATION);
    //wc.lpszMenuName = L"Ex4_Menu";//LoadMenu(wc.hInstance, "Ex4_Menu");
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = L"NuklearWindowClass";
    //wc.hIconSm = LoadIcon(wc.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    RegisterClassW(&wc);
    //RegisterClassExW(&wc);

    std::string s = title;

    std::unordered_map<std::string, uint32_t> mm;
    std::vector<std::string> vm;

    for (auto c : s)
    {
        mm[""+c] = c-'0';
        if (c > 'A' && c < 'Z')
        {
            vm.push_back(""+c);
        }
    }

    s = "";
    for (auto c : vm)
    {
        auto f = mm.find(c);
        if (f != mm.end())
        {
            std::cerr << "ok: " << f->first << " = " << f->second << "\n";
        }
        s += c;
    }



    

    // std::wstringstream cls("");
    // cls << " [" << title << "\n";
    std::wstring total(s.c_str(), s.c_str()+s.size());

    AdjustWindowRectEx(&rect, style, FALSE, exstyle);

    // std::string s = title;
    // std::string ws(s.size()); 
    // ws.resize(mbstowcs(&ws[0], s.c_str(), s.size());

    wnd = CreateWindowExW(exstyle, wc.lpszClassName, (const wchar_t*)total.c_str(),
        style | WS_VISIBLE, 
        GetSystemMetrics(SM_CXSCREEN)/2 - width/2, 
        GetSystemMetrics(SM_CYSCREEN)/2 - height,
        rect.right-rect.left, 
        rect.bottom-rect.top,
        // WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL, NULL, wc.hInstance, NULL);

    /* GUI */

    // HICON hIcon = LoadIcon(wc.hInstance, "IDI_ICON1");
    // HICON hIcon2 = LoadIcon(nullptr, "IDI_ICON1");
    // HICON hIcon3 = LoadIcon(wc.hInstance, IDI_APPLICATION);
    // HICON hIcon4 = LoadIcon(nullptr, IDI_APPLICATION);

    // if (hIcon || hIcon2 || hIcon3 || hIcon4)
    // {
    //     std::cerr << (uint64_t)hIcon << "; " << (uint64_t)hIcon2 << "; " << (uint64_t)hIcon3 << "; " << (uint64_t)hIcon4 << ";\n";
    // }


    // auto hResource = FindResource(nullptr, "IDI_TEXT", RT_RCDATA);
	// size_t _size = SizeofResource(nullptr, hResource);
	// auto hMemory = LoadResource(nullptr, hResource);
	// LPVOID ptr = LockResource(hMemory);

    // auto hResource = FindResource(nullptr, L"IDI_ICON1", RT_RCDATA);
    // std::cerr << "Err code: " << GetLastError() << "\n";
	// size_t _size = SizeofResource(nullptr, hResource);
    // std::cerr << "Err code: " << GetLastError() << "\n";
	// auto hMemory = LoadResource(nullptr, hResource);
    // std::cerr << "Err code: " << GetLastError() << "\n";
	// auto ptr = LockResource(hMemory);
    // std::cerr << "Err code: " << GetLastError() << "\n";

    // int offset = LookupIconIdFromDirectoryEx((uint8_t*)ptr, true, 192, 192, LR_DEFAULTCOLOR);
    // HICON hIcon0 = CreateIconFromResourceEx((uint8_t*)ptr+offset, _size, true, 0x00030000, 0, 0, LR_DEFAULTCOLOR | LR_SHARED);//, LR_DEFAULTCOLOR | LR_SHARED);
    // std::cerr << "Err code: " << GetLastError() << "\n";


    // HDC hDcDlg = GetDC(wnd);
    // DrawIcon(hDcDlg, 10, 20, hIcon0); 
    // std::cerr << "Err code: " << GetLastError() << "\n";

    // auto txt = (const char*) ptr;

    // std::cerr << txt << "\n";

    // SendMessage(wnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon0);
    // SendMessage(wnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon0);

    

    while (running)
    {

        //std::cout << "draw\n";

        /* Input */
        MSG msg;
        //nk_input_begin(ctx);
        if (needs_refresh == 0) {
            if (GetMessageW(&msg, NULL, 0, 0) <= 0)
                running = 0;
            else {
                TranslateMessage(&msg);
                DispatchMessageW(&msg);
            }
            needs_refresh = 1;
        }
        else needs_refresh = 0;
        while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                running = 0;
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
            needs_refresh = 1;
        }
    }
    UnregisterClassW(wc.lpszClassName, wc.hInstance);

	return 0;
}