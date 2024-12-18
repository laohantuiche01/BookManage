
#ifndef BOOKMANAGE_BOOKDATA_H
#define BOOKMANAGE_BOOKDATA_H

#include <bits/stdc++.h>

using namespace std;

class BookData {
public:
    long long int BookISBN;//ISBN号
    char BookTitle[51];//书名
    int BookNum;//书的剩余数量
    double qtyOnHand;//书的单价

    int BookBuyNum=0;//书的购买数量
    char BookAuther[51];//作者
    char BookPub[51];//出版社
    double BookWholesale;//批发价
    int BookAddData[3];//进书的日期（0为年，1为月，2为日）
    double BookAddPrice= BookWholesale*(double )BookNum;//书的总价
    int BookAddDataNum=10000*BookAddData[0]+100*BookAddData[1]+BookAddData[2];//日期，为了比较日期的大小的参数

    BookData() = default;

    ~BookData() = default;

    void setISBN();

    void setTitle();

    void setretail();

    void setQty();

    void setAuthor();

    void setPub();

    void setAddData();

    void setWholesale();
    void input();//输入的整合
    bool isEmpty(int memberNum);//感觉可以替换掉 o.O

};
int lookUpBook();//根据名字查找，返回出储存的位置
void printData();//输出全部书的内容
void flashData();//为了解决重新输入内容后非储存内容（总价，比日期的数）改变的问题
int lookUpBookByISBN(int BookISBN);//根据ISBN号找书，返回储存位置
#endif //BOOKMANAGE_BOOKDATA_H
