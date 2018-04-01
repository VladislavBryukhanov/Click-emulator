#include <stdio.h>
#include <conio.h>
#include"stdafx.h"
#include "resource.h"
#include<ctime>


BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInst;
POINT cursorPos;
INT x[10],y[10];
TCHAR edit[1024];
int editInt,maxI,RealI;
HWND hEdit;
BOOL swt=0;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{

	hInst = hInstance;
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc); 
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	TCHAR str[50];
	switch(message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0); 
		return TRUE;

	case WM_INITDIALOG:
		RealI=0;
	hEdit=GetDlgItem(hWnd,IDC_EDIT1);
		return TRUE;


		case WM_MBUTTONDOWN:
		GetWindowText(hEdit,edit,GetWindowTextLength(hEdit)+1);
		editInt=_tstoi(edit);
		EnableWindow(hEdit,false);
		MessageBox(hWnd,L"1st", L"1st",MB_OK | MB_ICONASTERISK);
		return FALSE;

			
case WM_KEYDOWN:
		switch(wParam)
		{
		case 49:
			GetCursorPos(&cursorPos);
		x[0] = cursorPos.x; 
		y[0] = cursorPos.y;
		RealI++;
			return TRUE;
			case 50:
			GetCursorPos(&cursorPos);
		x[1] = cursorPos.x; 
		y[1] = cursorPos.y;
		RealI++;
			return TRUE;
			case 51:
			GetCursorPos(&cursorPos);
		x[2] = cursorPos.x; 
		y[2] = cursorPos.y;
		RealI++;
			return TRUE;
			case 52:
			GetCursorPos(&cursorPos);
		x[3] = cursorPos.x; 
		y[3] = cursorPos.y;
		RealI++;
			return TRUE;
			case 53:
			GetCursorPos(&cursorPos);
		x[4] = cursorPos.x; 
		y[4] = cursorPos.y;
		RealI++;
			return TRUE;
			case 54:
			GetCursorPos(&cursorPos);
		x[5] = cursorPos.x; 
		y[5] = cursorPos.y;
		RealI++;
			return TRUE;
			case 55:            //7
			GetCursorPos(&cursorPos);
		x[6] = cursorPos.x; 
		y[6] = cursorPos.y;
		RealI++;
			return TRUE;
		
		case 32:
			if(swt==0)
		{
			MessageBox(hWnd,L"STARTED", L"STARTED",MB_OK | MB_ICONASTERISK);
		SetTimer(hWnd, 1, editInt*1000, NULL);
			swt=1;
		}
		else
		{
			KillTimer(hWnd,1);
			MessageBox(hWnd,L"STOPER", L"STOPER",MB_OK | MB_ICONASTERISK);
			swt=0;
		}
			
		return FALSE;
		}
		return TRUE;


	


	case WM_TIMER:
		SetCursorPos(x[maxI],y[maxI]); 
		Sleep(500);
		if(maxI==0||maxI==2){mouse_event(MOUSEEVENTF_RIGHTDOWN,0, 0, 0, 0);mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);}
		else{mouse_event(MOUSEEVENTF_LEFTDOWN,x[maxI], y[maxI], 0, 0);//игнорирует заданные координаты(х и у) даже если вместо них поставить константные числа
		mouse_event(MOUSEEVENTF_LEFTUP, x[maxI], y[maxI], 0, 0);}
		//MessageBox(hWnd,L"di4", L"di4",MB_OK | MB_ICONASTERISK);
		
		maxI++;
		if(maxI==RealI)
			maxI=0;
		return TRUE;
	}	
	
	
	return FALSE;


}