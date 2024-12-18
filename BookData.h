
#ifndef BOOKMANAGE_BOOKDATA_H
#define BOOKMANAGE_BOOKDATA_H

#include <bits/stdc++.h>

using namespace std;

class BookData {
public:
    long long int BookISBN;//ISBN��
    char BookTitle[51];//����
    int BookNum;//���ʣ������
    double qtyOnHand;//��ĵ���

    int BookBuyNum=0;//��Ĺ�������
    char BookAuther[51];//����
    char BookPub[51];//������
    double BookWholesale;//������
    int BookAddData[3];//��������ڣ�0Ϊ�꣬1Ϊ�£�2Ϊ�գ�
    double BookAddPrice= BookWholesale*(double )BookNum;//����ܼ�
    int BookAddDataNum=10000*BookAddData[0]+100*BookAddData[1]+BookAddData[2];//���ڣ�Ϊ�˱Ƚ����ڵĴ�С�Ĳ���

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
    void input();//���������
    bool isEmpty(int memberNum);//�о������滻�� o.O

};
int lookUpBook();//�������ֲ��ң����س������λ��
void printData();//���ȫ���������
void flashData();//Ϊ�˽�������������ݺ�Ǵ������ݣ��ܼۣ������ڵ������ı������
int lookUpBookByISBN(int BookISBN);//����ISBN�����飬���ش���λ��
#endif //BOOKMANAGE_BOOKDATA_H
