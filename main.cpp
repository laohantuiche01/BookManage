#include <bits/stdc++.h>
#include "BookData.h"
#include "BookManageRun.h"
using namespace std;

int main() {
    readInfoFromFile("BookManage.txt");//��ȡ����
    flashData();//��Ҫ��Ϊ�˳�ʼ����Щδ���������
    while (true) //�޾�ѭ�����ڹر�ϵͳʱ��������
    {
        mainmenu();//�˵���
        mainKeyDown();//�������봦��
        system("cls");//��մ���
        saveInfoToFile("BookManage.txt");//ÿһ��ѭ��������һ��
    }

}







