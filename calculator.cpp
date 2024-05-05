#include <iostream>
#include<sstream>
#include "HiEasyX.h"            
using namespace std;

hiex::SysButton BTN[20];
hiex::SysEdit edit;

void Clear();

void ButtonSet(hiex::Window wnd);
void EditSet(hiex::Window wnd);
int ShowEditTS(int IAdd, int choose);
void NumMain(int ClickNum, int NumDecide, int choose);
void NumCompute();

void NumSet(int ClickNum, int NumDecide);
void SignSet(int ClickNum);

void SignSwap();
void NumSwap();

string ConString(double x);
double ConString(string x);

int Add = 0;
double NumEnd = 0;
int SignCompute = 0;
string DSC = "0";
string InNum01 = "0";
string InNum02 = "0";
string NumText = "0";
string SignChoose = "0";


int* PAdd = &Add;
double* PNumEnd = &NumEnd;
int* PSignCompute = &SignCompute;
string* PDSC = &DSC;
string* PNumText = &NumText;
string* PInNum01 = &InNum01;
string* PInNum02 = &InNum02;
string* PSignChoose = &SignChoose;


void NumSet(int ClickNum, int NumDecide)
{
	if (ClickNum == 1 && NumDecide == 0)
	{
		*PInNum01 = "0";
	}
	else if (ClickNum == 1 && NumDecide > 0)
	{
		*PInNum01 += "0";
	}


	else if (4 <= ClickNum && ClickNum <= 6 && NumDecide == 0)
	{
		*PInNum01 = to_string(ClickNum - 3);
	}
	else if (4 <= ClickNum && ClickNum <= 6 && NumDecide >= 0)
	{
		*PInNum01 += to_string(ClickNum - 3);
	}


	else if (8 <= ClickNum && ClickNum <= 10 && NumDecide == 0)
	{
		*PInNum01 = to_string(ClickNum - 4);
	}
	else if (8 <= ClickNum && ClickNum <= 10 && NumDecide >= 0)
	{
		*PInNum01 += to_string(ClickNum - 4);
	}


	else if (12 <= ClickNum && ClickNum <= 14 && NumDecide == 0)
	{
		*PInNum01 = to_string(ClickNum - 5);
	}
	else if (12 <= ClickNum && ClickNum <= 14 && NumDecide >= 0)
	{
		*PInNum01 += to_string(ClickNum - 5);
	}


}
void SignSet(int ClickNum)
{
	switch (ClickNum)
	{
	case 3:
		*PSignChoose = "=";
		break;
	case 7:
		*PSignChoose = "+";
		break;
	case 11:
		*PSignChoose = "-";
		break;
	case 15:
		*PSignChoose = "*";
		break;
	case 19:
		*PSignChoose = "/";
		break;
	default:
		break;
	}
}

void NumSwap()
{
	string swap;
	swap = *PInNum01;
	*PInNum02 = swap;
	*PInNum01 = "0";
}
void SignSwap()
{
	string swap;
	swap = *PSignChoose;
	*PDSC = swap;
	*PSignChoose = "";
}

 double ConString(string x)
{
	stringstream CNum(x);
	double Num = 0;
	CNum >> Num;
	return (Num);
}
 string ConString(double x)
 {
	 ostringstream oss;
	 oss << x;
	 string Num = oss.str();
	 return (Num);
 }

 void  Clear()
 {
	 * PDSC = "0";
	 * PSignChoose = "0";
	 * PNumText = "0";
	 * PInNum01 = "";
	 * PInNum02 = "";

	 * PSignCompute = 0;
	 * PAdd = 0;
	 
	string NumShow = "0";
	wstring text(NumShow.begin(), NumShow.end());
	edit.SetText(text);
	 	 
 }
 
 int ShowEditTS(int IAdd, int choose)
 {
	 string NumShow = "";
	 if (choose == 1 && SignCompute == 0)
	 {
		 NumShow = InNum02 + DSC + "\r\n";
		 IAdd = 1;
	 }
	 else if (choose == 0 && IAdd == 0)
	 {
		 NumShow = InNum01;
	 }
	 else if (choose == 0 && IAdd == 1)
	 {
		 NumShow = InNum02 + DSC + "\r\n" +InNum01;
	 }
	 else if (choose == 1 && IAdd == 1 && SignCompute == 1)
	 {
		 NumCompute();		 
		 NumShow = InNum02 + DSC + InNum01 + SignChoose + "\r\n" + ConString(NumEnd);
		 
		 cout << "ShowEditTS(int IAdd, int choose):" << endl;
		 cout << "InNum02:" << InNum02 << "\n InNum01:" << InNum01 << " ConString(NumEnd):" << ConString(NumEnd) << endl;

		 *PSignCompute = 0;
		 *PInNum01 = ConString(NumEnd);
		 
	 }
	 
	 wstring text(NumShow.begin(), NumShow.end());
	 edit.SetText(text);
	 return (IAdd);
 }

 void NumCompute()
 {
	 double Num1 = ConString(InNum02);
	 double Num2 = ConString(InNum01);
	 
	 if (DSC == "+")
	 {
		 *PNumEnd = Num1 + Num2;
	 }
	 else if (DSC == "-")
	 {
		 *PNumEnd = Num1 - Num2;
	 }
	 else if (DSC == "*")
	 {
		 *PNumEnd = Num1 * Num2;
	 }
	 else if (DSC == "/")
	 {
		 *PNumEnd = Num1 / Num2;
	 }
 }

 void NumMain(int ClickNum, int NumDecide, int choose)
 {
	 if (choose == 0)
	 {
		 NumSet(ClickNum, NumDecide);		 
	 }
	 else if (choose == 1 && SignCompute == 0)
	 {
		 SignSet(ClickNum);
		 SignSwap();
		 NumSwap();
	 }
	 else if (choose == 1 && SignCompute == 1)
	 {
		 SignSet(ClickNum);
	 }
	*PAdd = ShowEditTS (Add, choose);

 }
 
 void ButtonSet(hiex::Window wnd)
 {
	 int y = 420;
	 int FontH = 24;
	 int FontW = 0;
	 int BtnNum = 0;

	 for (int i = 1; i <= 5; i++)
	 {
		 for (int j = 1; j <= 4; j++)
		 {
			 BTN[BtnNum].Create(wnd.GetHandle(), 4 + (j - 1) * 84, 420 - (i - 1) * 54, 80, 50, L"");
			 BTN[BtnNum].SetFont(FontH, FontW, L"Î¢ÈíÑÅºÚ");
			 BtnNum++;
		 }
	 }

	 BTN[16].SetText(L"C");	BTN[17].SetText(L"");	BTN[18].SetText(L"");	BTN[19].SetText(L"¡Â");
	 BTN[12].SetText(L"7");	BTN[13].SetText(L"8");	BTN[14].SetText(L"9");	BTN[15].SetText(L"¡Á");
	 BTN[8].SetText(L"4");	BTN[9].SetText(L"5");	BTN[10].SetText(L"6");	BTN[11].SetText(L"-");
	 BTN[4].SetText(L"1");	BTN[5].SetText(L"2");	BTN[6].SetText(L"3");	BTN[7].SetText(L"+");
	 BTN[0].SetText(L"");	BTN[1].SetText(L"0");	BTN[2].SetText(L"");	BTN[3].SetText(L"=");
	 
	 cout << "ButtonSet(hiex::Window wnd):true" << endl;
 }

 void EditSet(hiex::Window wnd)
 {
	 edit.PreSetStyle(hiex::SysEdit::PreStyle{ true, false,false, true, false, true });
	 edit.Create(wnd.GetHandle(), 10, 50, 320, 60, L"0");
	 edit.RightAlign(true);
	 edit.ReadOnly(true);
	 edit.SetFont(30, 0, L"Î¢ÈíÑÅºÚ");

	 cout << "EditSet(hiex::Window wnd):true" << endl;
 }

int main()
{
	hiex::Window wnd(340, 480, SHOWCONSOLE | NOMINIMIZE, L"¼ÆËãÆ÷");	
	ButtonSet(wnd);
	EditSet(wnd);

	system("color 2");

	int NumDecide = 0;
	while (wnd.IsAlive())
	{				
		for (int i = 0; i < 20; i++)
		{
			if (BTN[i].IsClicked())
			{
				if (i == 1|| i == 4 || i == 5 || i == 6 || i == 8 || i == 9 || i == 10 || i == 12 || i == 13 || i == 14)
				{
					NumMain(i, NumDecide , 0);
					NumDecide++;
					cout << "BTN[i].IsClicked():" << "NumDecide:" << NumDecide << "_" << i << endl;
				}
				else if (i == 3 || i == 7 || i == 11 || i == 15 || i == 19)
				{
					if (i == 3)
					{
						*PSignCompute = 1;
					}
					NumMain(i, 0, 1);
					NumDecide = 0;
					cout << "BTN[i].IsClicked():" << "NumDecide:" << NumDecide << "_" << i << endl;
				}
				else if (i == 16)
				{
					Clear();
					cout << "clear:true" << endl;
				}
			}	
		}
		Sleep(50);
	}	
	hiex::init_end();
    return 0;
}

