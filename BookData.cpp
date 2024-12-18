
#include <bits/stdc++.h>
#include <string>
#include "BookData.h"
#include "BookManageRun.h"

void BookData::setISBN() //定义的时候设置ISBN号
{
    cout << "请输入书的ISBN号：\n";
    long long int tempNum;
    cin >> tempNum;
    long long int num=tempNum;
    int count = 0;
    while (num!= 0) {
        num /= 10;
        count++;
    }
    if(count>13)
    {
        cout<<"输入位数超出限制！\n";
        BookData::setISBN();
        return;
    }
    else
    {
        BookISBN=tempNum;
    }
}

void BookData::setTitle() //设置书名
{
    cout << "请输入书名：\n";
    cin >> BookTitle;
}

void BookData::setQty() //设置剩余数量（这个当时理解错了，后面QTY是单价）
{
    cout << "请输入书的剩余数量：\n";
    cin >> BookNum;
}

void BookData::setretail() //设置单价
{
    cout << "请输入书的单价：\n";
    cin >> qtyOnHand;
}

void BookData::setAuthor() //作者
{
    cout << "请输入书的作者：\n";
    cin >> BookAuther;
}

void BookData::setPub() //出版社
{
    cout << "请输入书的出版社：\n";
    cin >> BookPub;
}

void BookData::setAddData() //添加日期
{
    cout << "请输入书的进货日期：\n年：";
    cin >> BookAddData[0];
    cout << "月：";
    cin >> BookAddData[1];
    cout << "日：";
    cin >> BookAddData[2];

}

void BookData::setWholesale() //设置进价
{
    cout << "请输入批发价：\n";
    cin >> BookWholesale;
}

void BookData::input() //输入的整合
{
    setTitle();
    setQty();
    setretail();
    setWholesale();
    setAuthor();
    setPub();
    setAddData();
}

bool BookData::isEmpty(int memberNum) //0.o这个直接用第一行元素是否是0代替了
{
    if (DataBase[memberNum].BookISBN == '\0') {
        return false;
    } else return true;
}

int lookUpBook() //输入名字找书
{
    char memberTitle[20];//定义一个容器
    cin >> memberTitle;
    for (int i = 0; i < BookAllNum; i++) {
        if (!strcmp(DataBase[i].BookTitle, memberTitle)) //俩相同返回值为0，加了个！
        {
            return i;//返回出
        }
    }
    return -1;
}

int lookUpBookByISBN(int BookISBN) //通过ISBN找书
{
    for (int i = 0; i < BookAllNum; i++) {
        if (BookISBN == DataBase[i].BookISBN) {
            return i;
        }
    }
    return -1;
}

void printData() //打印出全部信息
{
    cout << "\t图书管理系统\n";
    cout << "ISBN号\t\t书名\t\t作者\t出版社\t\t剩余数量\t单价\t进价\t日期\n";
    for (int i = 0; i < 100; i++) {
        if (DataBase[i].BookISBN != '\0') {
            cout << DataBase[i].BookISBN << "\t" << DataBase[i].BookTitle << "\t\t" << DataBase[i].BookAuther << "\t"
                 << DataBase[i].BookPub << "\t\t" << DataBase[i].BookNum << "\t\t" << DataBase[i].qtyOnHand << "\t"
                 << DataBase[i].BookWholesale << "\t" << DataBase[i].BookAddData[0] << "年"
                 << DataBase[i].BookAddData[1] << "月"
                 << DataBase[i].BookAddData[2] << "日\n";
        }
    }
}

void flashData() //更新类成员的数据
{
    for (int i = 0; i < BookAllNum; i++) {
        DataBase[i].BookAddPrice = DataBase[i].BookWholesale * (double) DataBase[i].BookNum;
        DataBase[i].BookAddDataNum =
                10000 * DataBase[i].BookAddData[0] + 100 * DataBase[i].BookAddData[1] + DataBase[i].BookAddData[2];
        DataBase[i].BookBuyNum=0;
    }

}
