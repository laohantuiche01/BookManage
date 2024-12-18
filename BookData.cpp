
#include <bits/stdc++.h>
#include <string>
#include "BookData.h"
#include "BookManageRun.h"

void BookData::setISBN() //�����ʱ������ISBN��
{
    cout << "���������ISBN�ţ�\n";
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
        cout<<"����λ���������ƣ�\n";
        BookData::setISBN();
        return;
    }
    else
    {
        BookISBN=tempNum;
    }
}

void BookData::setTitle() //��������
{
    cout << "������������\n";
    cin >> BookTitle;
}

void BookData::setQty() //����ʣ�������������ʱ�����ˣ�����QTY�ǵ��ۣ�
{
    cout << "���������ʣ��������\n";
    cin >> BookNum;
}

void BookData::setretail() //���õ���
{
    cout << "��������ĵ��ۣ�\n";
    cin >> qtyOnHand;
}

void BookData::setAuthor() //����
{
    cout << "������������ߣ�\n";
    cin >> BookAuther;
}

void BookData::setPub() //������
{
    cout << "��������ĳ����磺\n";
    cin >> BookPub;
}

void BookData::setAddData() //�������
{
    cout << "��������Ľ������ڣ�\n�꣺";
    cin >> BookAddData[0];
    cout << "�£�";
    cin >> BookAddData[1];
    cout << "�գ�";
    cin >> BookAddData[2];

}

void BookData::setWholesale() //���ý���
{
    cout << "�����������ۣ�\n";
    cin >> BookWholesale;
}

void BookData::input() //���������
{
    setTitle();
    setQty();
    setretail();
    setWholesale();
    setAuthor();
    setPub();
    setAddData();
}

bool BookData::isEmpty(int memberNum) //0.o���ֱ���õ�һ��Ԫ���Ƿ���0������
{
    if (DataBase[memberNum].BookISBN == '\0') {
        return false;
    } else return true;
}

int lookUpBook() //������������
{
    char memberTitle[20];//����һ������
    cin >> memberTitle;
    for (int i = 0; i < BookAllNum; i++) {
        if (!strcmp(DataBase[i].BookTitle, memberTitle)) //����ͬ����ֵΪ0�����˸���
        {
            return i;//���س�
        }
    }
    return -1;
}

int lookUpBookByISBN(int BookISBN) //ͨ��ISBN����
{
    for (int i = 0; i < BookAllNum; i++) {
        if (BookISBN == DataBase[i].BookISBN) {
            return i;
        }
    }
    return -1;
}

void printData() //��ӡ��ȫ����Ϣ
{
    cout << "\tͼ�����ϵͳ\n";
    cout << "ISBN��\t����\t����\t������\tʣ������\t����\t����\t����\n";
    for (int i = 0; i < 100; i++) {
        if (DataBase[i].BookISBN != '\0') {
            cout << DataBase[i].BookISBN << "\t" << DataBase[i].BookTitle << "\t" << DataBase[i].BookAuther << "\t"
                 << DataBase[i].BookPub << "\t" << DataBase[i].BookNum << "\t" << DataBase[i].qtyOnHand << "\t"
                 << DataBase[i].BookWholesale << "\t" << DataBase[i].BookAddData[0] << "��"
                 << DataBase[i].BookAddData[1] << "��"
                 << DataBase[i].BookAddData[2] << "��\n";
        }
    }
}

void flashData() //�������Ա������
{
    for (int i = 0; i < BookAllNum; i++) {
        DataBase[i].BookAddPrice = DataBase[i].BookWholesale * (double) DataBase[i].BookNum;
        DataBase[i].BookAddDataNum =
                10000 * DataBase[i].BookAddData[0] + 100 * DataBase[i].BookAddData[1] + DataBase[i].BookAddData[2];
        DataBase[i].BookBuyNum=0;
    }

}
