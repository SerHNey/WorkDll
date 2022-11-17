#include <Windows.h>
#define PATH L"Dllfile.dll"
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	HINSTANCE hMyDll;
	if ((hMyDll = LoadLibrary(PATH))==NULL) return 1;


	FreeLibrary(hMyDll);

	return 0;
}
