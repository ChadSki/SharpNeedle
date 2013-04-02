#include "stdafx.h"
#include <Windows.h>

#include "dllmain.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        //DisplayPid();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

void DisplayPid()
{
    DWORD pid = GetCurrentProcessId();
    wchar_t buf[64];
    wsprintf(buf, L"Hey, it worked! Pid is %d", pid);

    MessageBox(NULL, buf, L"Injected MessageBox", NULL);
}
