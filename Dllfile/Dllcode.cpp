#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <cstdio>
#include "Header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
extern "C" __declspec(dllimport) void MyFunc();



void MyFunc() {


	FILE* pFile = fopen("Users.csv", "r");
	long size;
	if (!pFile) perror("Error opening file");
	else
	{
		fseek(pFile, 0, SEEK_END);
		size = ftell(pFile);
		fclose(pFile);
		printf("Size of myfile.txt: %ld bytes.\n", size);
		fclose(pFile);
	}
	HANDLE file = CreateFile(L"Users.csv", GENERIC_READ, NULL,0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	void* storoka = calloc(size+1, 1);
	DWORD bytes;
	ReadFile(file, storoka,size , &bytes, NULL);
	CloseHandle(file);
	//char* person;
	//person = strtok(storoka, " ");
	file = CreateFile(L"resylt.csv", GENERIC_WRITE, NULL, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(file, storoka, size, &bytes, NULL);


}