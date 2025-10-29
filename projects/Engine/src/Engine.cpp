#include <Engine/Engine.hh>

#if defined(_MSC_VER)
// Windows
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN		1
#endif//WIN32_LEAN_AND_MEAN
#include <Windows.h>

BOOL APIENTRY DllMain(
	HMODULE		hModule,
	DWORD		ulReasonForCall,
	LPVOID		lpReserved
) {
	switch (ulReasonForCall) {
	case DLL_PROCESS_ATTACH: {
		//TODO: Initialization Here..
		DisableThreadLibraryCalls(hModule);
	} break;
	case DLL_PROCESS_DETACH: {
		//TODO: Cleanup Here..
	} break;
	}
	//case DLL_THREAD_ATTACH: {} break;
	//case DLL_THREAD_DETACH: {} break;
	return TRUE;
}

#else
//TODO: Dreamcast, macOS, FreeBSD, Linux

#endif
