#pragma once

#include "stdafx.h"
#include <Windows.h>

/**
 * Displays the pid of the current process.
 * Mainly included for debugging purposes.
 */
void DisplayPid();

/**
 * Dll entry point.
 */
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     );
