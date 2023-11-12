#include <iostream>
#include <easyx.h>
#include "HiEasyX.h"
#include <math.h>
using namespace std;

void ShowLine()
{
	BEGIN_TASK();			//启动任务，标识开始绘制

	setlinestyle(PS_SOLID, 1);
	line(0, 225, 800, 225);
	line(400, 0, 400, 450);

	END_TASK();				// 完成绘制，结束任务
	REDRAW_WINDOW();		// 刷新屏幕，使刚才绘制的内容显示出来
}

void FuncShow(int a , int b , int c)
{
	
	setorigin(400, 225);// 设置坐标原点到屏幕中央点
	for (double i = -10; i <= 10; i+=0.001)
	{
		

		double x = i;
		double y = a*x*x+b*x+c;

		double X = x*20;
		double Y = -y*20;
	
		BEGIN_TASK();
		putpixel(X, Y, BLUE);
		END_TASK();
		REDRAW_WINDOW();

		cout <<"正在绘制：" << "(" << x << "," << y << ")" << endl;
			
	}
	
}

int main()
{
	
	HWND hwnd = hiex::initgraph_win32(800, 450, EW_SHOWCONSOLE| EW_NOMINIMIZE);// 初始化窗口	
	SetWindowTextA(hwnd, "一元二次函数绘制（在控制台窗口输入函数）");
	system("title 函数数入");

	ShowLine();
	
	cout << "分别输入a,b,c的值（输入后按回车键）" << endl;;
	int a, b, c;

	cin >> a;
	cin >> b;
	cin >> c;	

	cout << "请等待图像绘制。。。" << endl;
	system("color 4");
	FuncShow(a,b,c);
	system("color 2");
	cout << "绘制完成！" << endl;

	system("pause");	
	closegraph();			// 关闭窗口
	return 0;
}

