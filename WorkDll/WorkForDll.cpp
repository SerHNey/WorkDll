#include <Windows.h>

#define PATH L"Dllfile.dll"
typedef void(_cdecl* MyFunc)();


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{

	HINSTANCE hMyDll;
	if ((hMyDll = LoadLibrary(PATH))==NULL) return 1;
	MyFunc myf = GetProcAddress(hMyDll, "MyFunc");
	myf("бсющ");


	FreeLibrary(hMyDll);

	return 0;
}
