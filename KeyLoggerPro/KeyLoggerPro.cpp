/**
 * KeyLoggerPro.cpp
 *
 * @author Raul Butuc
 * @version 1.0.0 - 23/07/2016
 */

#include "stdafx.h"
#include "KeyLoggerPro.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance, 
                      _In_ LPWSTR lpCmdLine,
                      _In_ int nCmdShow) {
  UNREFERENCED_PARAMETER(hPrevInstance);
  UNREFERENCED_PARAMETER(lpCmdLine);

  HACCEL hAccelTable =
    LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KEYLOGGERPRO));
  
  MSG msg;

  while (GetMessage(&msg, nullptr, 0, 0)) {
    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  return static_cast<int>(msg.wParam);
}
