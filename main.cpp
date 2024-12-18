#include <bits/stdc++.h>
#include "BookData.h"
#include "BookManageRun.h"
using namespace std;

int main() {
    readInfoFromFile("BookManage.txt");//读取数据
    flashData();//主要是为了初始化那些未储存的数据
    while (true) //无尽循环，在关闭系统时结束运行
    {
        mainmenu();//菜单栏
        mainKeyDown();//按键输入处理
        system("cls");//清空窗口
        saveInfoToFile("BookManage.txt");//每一个循环都保存一次
    }

}







