#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <stdlib.h>
#include <string>

#include "Injection.h"

using namespace std;

/* There are two defined entry points here, one for a  Windows
 * application, and another for a console application.
 *
 * To switch between the two versions, we need to change our
 * subsystem dependency and then rebuild.
 *
 * To enable Windows (hidden) mode, go to project properties, find the
 * 'linker' section and change the SubSystem option to Windows. To
 * enable console (debugging) mode, change SubSystem to Console. The
 * compiler will automatically choose the appropriate entry point.
 */

/* Since there are two entry points for this program, we really
 * ought to get to a common point as soon as possible.  This is that
 * common point.
 */
void true_main() {
    char DllName[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, DllName);
    strcat_s(DllName, "\\Bootstrapper.dll");
    DWORD Pid = GetProcessIdByName("firefox.exe");
    InjectAndRunThenUnload(Pid, DllName, "LoadQuickbeam");
}

/* By starting as a Windows application but not displaying any
 * windows, we can become effectively invisible.
 */
int WinMain (HINSTANCE hInstance,
             HINSTANCE hPrevInstance,
             LPSTR lpCmdLine,
             int cmdShow)
{
    true_main();
    return 0;
}

string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileNameA( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

/* In any case, it's useful to have a console window visible
 * for debugging purposes.  Use cout to your heart's content!
 */
int main()
{
    true_main();
    return 0;
}
