#include <stdio.h>
#include <conio.h>
#include"stdafx.h"
#include "resource.h"
#include<ctime>


BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
SHORT SpaceState,LBMState,RBMState;
HINSTANCE hInst;
POINT cursorPos;
INT x[10],y[10];
INT btn[20];
TCHAR edit[1024];
int maxI,RealI;
double editDoub;
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
		maxI=0;
		hEdit=GetDlgItem(hWnd,IDC_EDIT1);
		return TRUE;


	case WM_MBUTTONDOWN:
		GetWindowText(hEdit,edit,GetWindowTextLength(hEdit)+1);
		editDoub=_tstoi(edit);
		EnableWindow(hEdit,false);
		MessageBox(hWnd,L"1st", L"1st",MB_OK | MB_ICONASTERISK);
		SpaceState=0;
		LBMState==0;
		RBMState==0;
		SetTimer(hWnd, 1, 100, NULL);
		return TRUE;






	/*case WM_KEYDOWN:

		switch(wParam)
		{
		case 49:
		GetCursorPos(&cursorPos);
		x[RealI] = cursorPos.x; 
		y[RealI] = cursorPos.y;
		btn[RealI]=0;
		RealI++;
		return TRUE;
		case 50://2
		GetCursorPos(&cursorPos);
		x[RealI] = cursorPos.x; 
		y[RealI] = cursorPos.y;
		btn[RealI]=1;
		RealI++;
		return TRUE;
		case 32:
		if(swt==0)
		{
		MessageBox(hWnd,L"STARTED", L"STARTED",MB_OK | MB_ICONASTERISK);
		SetTimer(hWnd, 1, editDoub*1000, NULL);
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
*/
	case WM_TIMER:
		SpaceState= GetAsyncKeyState(107);
		LBMState= GetAsyncKeyState(35);
		RBMState= GetAsyncKeyState(40);
		if(LBMState!=0)
		{

			GetCursorPos(&cursorPos);
			x[RealI] = cursorPos.x; 
			y[RealI] = cursorPos.y;
			btn[RealI]=0;
			RealI++;
			//MessageBox(hWnd,L"1", L"1",MB_OK | MB_ICONASTERISK);
		}
		if(RBMState!=0)
		{

			GetCursorPos(&cursorPos);
			x[RealI] = cursorPos.x; 
			y[RealI] = cursorPos.y;
			btn[RealI]=1;
			RealI++;
			//MessageBox(hWnd,L"2", L"2",MB_OK | MB_ICONASTERISK);
		}
		if(SpaceState!=0)
		{

		if(swt==0)
		{
		//MessageBox(hWnd,L"STARTED", L"STARTED",MB_OK | MB_ICONASTERISK);
		SetTimer(hWnd, 1, editDoub*1000, NULL);
		swt=1;
		}
		else
		{
		KillTimer(hWnd,1);
		//MessageBox(hWnd,L"STOPER", L"STOPER",MB_OK | MB_ICONASTERISK);
		swt=0;
		}

		}
		/*KeyState= GetAsyncKeyState(32);
		if(KeyState!=0)
		MessageBox(hWnd,L"GOOD", L"GOOD",MB_OK | MB_ICONASTERISK);
		else if(KeyState==0)
		MessageBox(hWnd,L"BAD", L"BAD",MB_OK | MB_ICONASTERISK);
		*/
		if(swt==1)
		{
			SetCursorPos(x[maxI],y[maxI]);
			if(btn[maxI]==0)
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN,0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
			else if(btn[maxI]==1)
			{
				mouse_event(MOUSEEVENTF_RIGHTDOWN,0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			}

			maxI++;
			if(maxI==RealI)
				maxI=0;
			return TRUE;
		}
	}	
	return FALSE;
}