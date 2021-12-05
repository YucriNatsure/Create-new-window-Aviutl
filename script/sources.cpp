#include <Windows.h>
#include <filter.h>
#include<stdio.h>
#include<stdlib.h>
#include	<vfw.h>



static const LPSTR FILTER_NAME = "Hogehoge";			//Title
static const LPSTR FILTER_INFORMATION = "Hogehoghe 1.0";			//�v���O�C���t�B���^���ŕ\�������title


bool  Example(void* editp, FILTER* fp)		//���s���������֐�1��
{
}

bool Hogehoge(void* editp, FILTER* fp)		//���s���������֐�2��
{
}

BOOL func_init(FILTER* fp)
{
	fp->exfunc->add_menu_item(fp, "____", fp->hwnd, 1, 0, 0);		/*�{�^����label*/
	fp->exfunc->add_menu_item(fp, "____", fp->hwnd, 2, 0, 0);		/*�{�^����label2*/
	return TRUE;
}

BOOL func_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp, void* editp, FILTER* fp)
{
	if (msg == WM_FILTER_COMMAND) {
		if (LOWORD(wp) == 1) Example(editp, fp);		//���s���������֐����`
		else if (LOWORD(wp) == 2) Hogehoge(editp, fp);
	}
	else if (msg == WM_COMMAND) {
		if (LOWORD(wp) == MID_FILTER_BUTTON + 0) Example(editp, fp);
		else if (LOWORD(wp) == MID_FILTER_BUTTON + 1) Hogehoge(editp, fp);
		return FALSE;
	}
}

static LPSTR check_name[] = { "__", "__"};			//�{�^����Label
static int   check_def[] = { -1 , -1 };

FILTER_DLL filter = {
	FILTER_FLAG_ALWAYS_ACTIVE | FILTER_FLAG_EX_INFORMATION,
	0, 0,
	FILTER_NAME,
	0, NULL, NULL, NULL, NULL,
	2, check_name, check_def,
	NULL,
	func_init,
	NULL,
	NULL,
	func_WndProc,
	NULL,
	NULL,
	NULL,
	NULL,
	FILTER_INFORMATION,
};

extern "C" __declspec(dllexport) FILTER_DLL * GetFilterTable(void)
{
	return &filter;
}
