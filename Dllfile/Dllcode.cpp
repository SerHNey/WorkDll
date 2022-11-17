#include <Windows.h>

BOOL WINAPI DllMain(HINSTANCE hlnstDll, DWORD dwReason, LPVOID IpReserved) {
	BOOL bAllWentWell = TRUE;
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	if (bAllWentWell)
		return TRUE;
	else
		return FALSE;
}
extern "C" __declspec(dllimport) int MyFunc(LPWSTR str);
int MyFunc(LPWSTR str) {
	MessageBox(NULL, str, L"Я сделал", MB_OK);
	return 0;
}