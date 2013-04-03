#include "stdafx.h"
#include <metahost.h>
#pragma comment(lib, "mscoree.lib")

#include "Bootstrapper.h"

DllExport void LoadManagedProject(const wchar_t * managedDllLocation)
{
    HRESULT hr;

    // Secure a handle to the CLR v4.0
    ICLRRuntimeHost* pClr = StartCLR(L"v4.0.30319");
    if (pClr == NULL)
    {
        MessageBox(NULL, L"", L"CLR Loading Failed", NULL);
    }
    else
    {
        MessageBox(NULL, L"", L"CLR Loading Succeeded", NULL);
        DWORD result;
        hr = pClr->ExecuteInDefaultAppDomain(
            managedDllLocation,
            L"ExampleProject.Example",
            L"EntryPoint",
            L"Argument",
            &result);
        if (hr == NULL)
        {
            MessageBox(NULL, L"", L"App Loading Failed", NULL);
        }
        else
        {
            MessageBox(NULL, L"", L"App Loading Succeeded", NULL);
        }
    }
}

ICLRRuntimeHost* StartCLR(LPCWSTR dotNetVersion)
{
    HRESULT hr;

    ICLRMetaHost* pClrMetaHost = NULL;
    ICLRRuntimeInfo* pClrRuntimeInfo = NULL;
    ICLRRuntimeHost* pClrRuntimeHost = NULL;

    // Get the CLRMetaHost that tells us about .NET on this machine
    hr = CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&pClrMetaHost);
    if (hr == S_OK)
    {
        // Get the runtime information for the particular version of .NET
        hr = pClrMetaHost->GetRuntime(dotNetVersion, IID_PPV_ARGS(&pClrRuntimeInfo));
        if (hr == S_OK)
        {
            // Check if the specified runtime can be loaded into the process. This
            // method will take into account other runtimes that may already be
            // loaded into the process and set pbLoadable to TRUE if this runtime can
            // be loaded in an in-process side-by-side fashion.
            BOOL fLoadable;
            hr = pClrRuntimeInfo->IsLoadable(&fLoadable);
            if ((hr == S_OK) && fLoadable)
            {
                // Load the CLR into the current process and return a runtime interface
                // pointer.
                hr = pClrRuntimeInfo->GetInterface(CLSID_CLRRuntimeHost,
                    IID_PPV_ARGS(&pClrRuntimeHost));
                if (hr == S_OK)
                {
                    // Start it. This is okay to call even if the CLR is already running
                    hr = pClrRuntimeHost->Start();
                    if (hr == S_OK)
                    {
                        // Success!
                        return pClrRuntimeHost;
                    }
                }
            }
        }
    }

    // Cleanup if failed
    if (pClrRuntimeHost)
    {
        pClrRuntimeHost->Release();
        pClrRuntimeHost = NULL;
    }
    if (pClrRuntimeInfo)
    {
        pClrRuntimeInfo->Release();
        pClrRuntimeInfo = NULL;
    }
    if (pClrMetaHost)
    {
        pClrMetaHost->Release();
        pClrMetaHost = NULL;
    }

    return NULL;
}
