#pragma once

#include "stdafx.h"
#include <Windows.h>

// For debugging
void DisplayPid();

// Entry point
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     );
