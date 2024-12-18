#include <bits/stdc++.h>
#include "BookData.h"
#include "BookManageRun.h"

using namespace std;

void bookstore_menu();

void report_menu();

void bookstoreFixData();

void cashier_menu();

void Sortmenu();

int BookAllNum = 0;
BookData DataBase[100];

void mainmenu()                           //���˵��������
{
    cout << "----------------------------\n";
    cout << "\tͼ�����ϵͳ\n";
    cout << "\t  ���˵�\n";
    cout << "   1.����ģ��\n";
    cout << "   2.������ģ��\n";
    cout << "   3.����ģ��\n";
    cout << "   4.�˳�ϵͳ\n\n";
    cout << "   ����ѡ��:\n";
    cout << "   ������1~4֮�������\n";
    cout << "----------------------------\n";
}


void mainKeyDown() {
    int userKey = 0;
    cin >> userKey;                       //�û�������Ϣ
    switch (userKey)                      //�������֣��жϲ���
    {
        case 1://����ģ��
            system("cls");//��ս���
            cashier_menu();//���뵽����ģ��
            return;
        case 2://ͼ�����ģ��
            system("cls");
            bookstore_menu();//���뵽ͼ�����ģ��
            return;
        case 3://����ģ��
            system("cls");
            report_menu();//���뵽����ģ��
            return;
        case 4:
            cout << "�˳�ϵͳ\n";
            cout << "�˳�ϵͳ�ɹ���\n";
            system("pause");     //��ʾ��Ϣ
            exit(0);                 //�˳�ϵͳ������ֵΪ0
        default://�����û�Ϲ��������
            cout << "����������Ч,����������!\n";
            mainKeyDown();              //�ٴ�����
    }
}

void bookstoreSeachBook() //ͼ�����ģ�����Ѱͼ��
{
    cout << "������Ҫ���ҵ�������\n";
    int tempIndex = lookUpBook();
    if (tempIndex == -1) //����û�ҵ������
    {
        cout << "ERROR!δ�ҵ������ҵ��鼮��\n����Ҫ����������[y/n]\n";
        char tempJudge;
        cin >> tempJudge;
        if (tempJudge == 'y') {
            bookstoreSeachBook();
        } else {
            return;
        }
    } else //����鼮���ݣ�-------�����ǵüӶ���������鼮�����--��
    {
        system("cls");
        cout << "\tͼ�����ϵͳ\n";
        cout << "ISBN�ţ�" << DataBase[tempIndex].BookISBN << endl;
        cout << "������" << DataBase[tempIndex].BookTitle << endl;
        cout << "���ߣ�" << DataBase[tempIndex].BookAuther << endl;
        cout << "�����磺" << DataBase[tempIndex].BookPub << endl;
        cout << "ʣ��������" << DataBase[tempIndex].BookNum << endl;
        cout << "���ۣ�" << DataBase[tempIndex].qtyOnHand << endl;
        cout << "�����ۣ�" << DataBase[tempIndex].BookWholesale << endl;
    }
}

int cashierPrint(int tempNum) //���ڶ�����ݴ����ڴ�ӡ
{
    system("cls");
    cout << "������ѡ���鼮��ISBN�ţ�\n";
    int tempBookISBN;//����
    int tempnum = 0;//��¼�ҵ���ķ���λ�ã�-1Ϊû�ҵ���
    cin >> tempBookISBN;
    tempnum = lookUpBookByISBN(tempBookISBN);
    if (tempnum == -1) //û�ҵ�
    {
        cout << "����������ЧISBN�룡���ٴ����룡\n";
        system("pause");
        return cashierPrint(tempNum);//�ٴν�������
    } else //�ҵ���
    {
        cout << "������Ҫ�����������";
        int BookBuyNum = 0;
        cin >> BookBuyNum;
        cout << "\n";
        if (BookBuyNum > DataBase[tempnum].BookNum) //������������
        {
            cout << "û����ô���飡\n";
            system("pause");
            return cashierPrint(tempNum);//�ٵ���
        } else {
            DataBase[tempnum].BookBuyNum = BookBuyNum;//��������
            return tempnum;
        }
    }
}

bool cashierdecide() //��ģ�������ظ�ѯ���Ƿ�����
{
    cout << "\n����Ҫ�����ɹ���[y/n] ";
    char temp_decide;//�ַ������������Y��N
    cin >> temp_decide;
    if (temp_decide == 'y') //������
    {
        return false;
    } else if (temp_decide == 'n') //������
    {
        return true;
    } else //����Ϲ������
    {
        cout << "������y��yes������n��no��\n";
        return cashierdecide();//�ٸ�����
    }
}

void cashier_menu() //����˵�
{
    double priceSumPrice = 0;//�ܼƵ���ļ۸�
    int tempIndex[100];//�������˶�����
    int tempNum = 0;
    while (true) //������������Ϣ
    {
        tempIndex[tempNum] = cashierPrint(tempNum);
        tempNum++;
        if (cashierdecide()) //�������ˣ�������Break����������true��false�෴��
        {
            break;
        } else
            continue;
    }

    system("cls");//�������
    cout << "\tͼ�����ϵͳ\n";
    cout << "ISBN��\t����\t����\t������\tʣ������\t����\t����\t����\n";
    for (int i = 0; i < tempNum; i++) //����Լ���������鼮��Ϣ�ĸ���
    {
        priceSumPrice = priceSumPrice + DataBase[tempIndex[i]].qtyOnHand * DataBase[tempIndex[i]].BookBuyNum;//�����ܼ�
        DataBase[tempIndex[i]].BookNum = DataBase[tempIndex[i]].BookNum - DataBase[tempIndex[i]].BookBuyNum;//�������ʣ�������Ŀ
        cout << DataBase[tempIndex[i]].BookISBN << "\t" << DataBase[tempIndex[i]].BookTitle << "\t"
             << DataBase[tempIndex[i]].BookAuther << "\t"
             << DataBase[tempIndex[i]].BookPub << "\t" << DataBase[tempIndex[i]].BookNum << "\t"
             << DataBase[tempIndex[i]].qtyOnHand << "\t"
             << DataBase[tempIndex[i]].BookWholesale << "\t" << DataBase[tempIndex[i]].BookAddData[0] << "��"
             << DataBase[tempIndex[i]].BookAddData[1] << "��"
             << DataBase[tempIndex[i]].BookAddData[2] << "��\n";
    }
    cout << "-------------------------------------\n";
    printf("���ۺϼƣ�RMB %.2lf\n", priceSumPrice);//��������Ϣ
    printf("����˰��RMB %.2lf\n", priceSumPrice * 0.06);
    printf("Ӧ����RMB %.2lf\n\n", priceSumPrice * 1.06);
    system("pause");

}

void bookstoreFixOne(int i)//�޸�λ��Ϊi���鼮��Ϣ
{
    system("cls");
    cout << "1.����\n2.����\n3.������\n4.ʣ������\n5.����\n6.����\n7.����\n";
    cout << "������Ҫ�޸ĵ����ݣ�\n";
    int tempNum = 0;//��������
    cin >> tempNum;
    switch (tempNum) {
        case 1:
            DataBase[i].setTitle();//����������Ŀ
            return;
        case 2:
            DataBase[i].setAuthor();//����
            return;
        case 3:
            DataBase[i].setPub();//������
            return;
        case 4:
            DataBase[i].setQty();//����
            flashData();
            return;
        case 5:
            DataBase[i].setretail();//����
            flashData();
            return;
        case 6:
            DataBase[i].setWholesale();//����
            flashData();
            return;
        case 7:
            DataBase[i].setAddData();//������������
            flashData();//���������������
            return;
        default://Ϲ������
            cout << "����������Ч������������!\n";
            system("pause");
            bookstoreFixOne(i);//�ٸ�����
    }
}

void bookstoreFixContinue(int i)//�޸Ķ�������
{
    char tempChar;
    cin >> tempChar;
    if (tempChar == 'y') {
        bookstoreFixOne(i);//���ص����溯���޸�
        cout << "����Ҫ�޸�����������[y/n]\n";
        bookstoreFixContinue(i);//���޸�
        return;
    } else if (tempChar == 'n') {
        return;
    } else {
        cout << "�������˴�����ַ���\n����������y(yes)����n(no):\n";
        bookstoreFixContinue(i);//Ϲ������
        return;
    }
}

void bookstoreFixData() //���˵���ת�޸����ݵĺ���
{
    cout << "������Ҫ����Ŀ��ISBN�ţ�\n";
    int tempNumber;
    cin >> tempNumber;//��ȷ�����ĸ�

    for (int i = 0; i < BookAllNum; i++) //����
    {
        if (DataBase[i].BookISBN == tempNumber) {
            bookstoreFixOne(i);
            cout << "����Ҫ�޸�����������[y/n]\n";
            bookstoreFixContinue(i);
            return;
        }
    }

    cout << "δ�ҵ�Ŀ���鼮��\n���Ƿ�Ҫ�������ң�[y/n]";
    char tempcontinue;
    cin >> tempcontinue;
    if (tempcontinue == 'y') {
        bookstoreFixData();
        return;
    }

}

void bookstoreDelete() //ɾ��ͼ��
{
    int BookIndex = -1;
    cout << "������ɾ���鼮���ƣ�\n";
    BookIndex = lookUpBook();//������������
    if (BookIndex == -1) //û�ҵ�
    {
        cout << "δ�ҵ�����鼮������Ҫ����ɾ����[y/n]\n";
        char tempcontinue;
        cin >> tempcontinue;
        if (tempcontinue == 'y') //�ټ���ɾ
        {
            bookstoreDelete();
            return;
        } else return;
    } else //�ҵ���
    {
        if (BookIndex == BookAllNum - 1) //��Ĵ����������һ
        {
            BookAllNum--;
        }
        DataBase[BookIndex].BookISBN = '\0';//��ISBN��Ϊ0
        cout << "ɾ���ɹ�������\n";
        system("pause");
    }
}

void bookInputISBN(int i) //����ISBN��
{
    BookData temp;
    temp.setISBN();//��ʱ���棬����û���ظ�
    int tempNum = lookUpBookByISBN(temp.BookISBN);
    if (tempNum == -1) //û���ظ�
    {
        DataBase[i].BookISBN = temp.BookISBN;
        return;
    } else {
        cout << "��ISBN�ѱ�ʹ�ã�\n";
        cout << "���������룺\n";
        bookInputISBN(i);//�ٴ�����
    }


}

void bookstore_menu() //ͼ�����ģ�麯��
{
    cout << "\t������ģ��\n\n";
    cout << "1.����ĳ�������Ϣ\n";
    cout << "2.������\n";
    cout << "3.�޸������Ϣ\n";
    cout << "4.ɾ����\n";
    cout << "5.���ص����˵�\n\n";
    cout << "����ѡ��\n";
    int key_num = 0;//�������ִ���
    cin >> key_num;
    //switch�����BUG
    if (key_num == 1) //����ͼ����Ϣ
    {
        bookstoreSeachBook();//��ת����
        system("pause");
        return;
    } else if (key_num == 2) //������
    {
        int i = 0;
        for (; DataBase[i].BookISBN != '\0'; i++) {

        }//�ҵ����һ��\0�Ĵ��浥λ
        bookInputISBN(i);
        DataBase[i].input();
        if (i == BookAllNum) {
            BookAllNum++;
        }
        cout << "����ɹ���\n";
        system("pause");

    } else if (key_num == 3) //�޸�������Ϣ
    {
        bookstoreFixData();
    } else if (key_num == 4) //ɾ����
    {
        bookstoreDelete();
    } else if (key_num == 5) //���ص����˵�
    {
        return;
    } else //�����쳣���
    {
        cout << "ERROR!!!\n���������룡";
        system("pause");
        system("cls");
        bookstore_menu();//Ϲ������
    }

}

void bubbleSortListByQtyOnHandUp() //���۸����ð����������
{
    for (int i = 0; i < BookAllNum; i++) //�ͼ򵥵�ð������
    {
        for (int j = 0; j < BookAllNum - i - 1; j++) {
            if (DataBase[j].qtyOnHand > DataBase[j + 1].qtyOnHand) {
                BookData tempdata = DataBase[j];
                DataBase[j] = DataBase[j + 1];
                DataBase[j + 1] = tempdata;
            }
        }
    }
}

void bubbleSortListByQtyOnHandDown() //���۸����ð�����򣨽���
{
    for (int i = 0; i < BookAllNum; i++) {
        for (int j = 0; j < BookAllNum - i - 1; j++) {
            if (DataBase[j].qtyOnHand < DataBase[j + 1].qtyOnHand) {
                BookData tempdata = DataBase[j];
                DataBase[j] = DataBase[j + 1];
                DataBase[j + 1] = tempdata;
            }
        }
    }
}

void bubbleSortListByWholesaleUp() //�����۽���ð����������
{
    for (int i = 0; i < BookAllNum; i++) {
        for (int j = 0; j < BookAllNum - i - 1; j++) {
            if (DataBase[j].BookWholesale > DataBase[j + 1].BookWholesale) {
                BookData tempdata = DataBase[j];
                DataBase[j] = DataBase[j + 1];
                DataBase[j + 1] = tempdata;
            }
        }
    }
}

void bubbleSortListByWholesaleDown() //�����۽���ð�����򣨽���
{
    for (int i = 0; i < BookAllNum; i++) {
        for (int j = 0; j < BookAllNum - i - 1; j++) {
            if (DataBase[j].BookWholesale < DataBase[j + 1].BookWholesale) {
                BookData tempdata = DataBase[j];
                DataBase[j] = DataBase[j + 1];
                DataBase[j + 1] = tempdata;
            }
        }
    }
}

void bubbleSortListByAddPriceUp() //���ܼ�ֵ����ð����������
{
    for (int i = 0; i < BookAllNum; i++) {
        for (int j = 0; j < BookAllNum - i - 1; j++) {
            if (DataBase[j].BookAddPrice > DataBase[j + 1].BookAddPrice) {
                BookData tempdata = DataBase[j];
                DataBase[j] = DataBase[j + 1];
                DataBase[j + 1] = tempdata;
            }
        }
    }
}

void bubbleSortListByAddPriceDown() //���ܼ�ֵ����ð�����򣨽���
{
    for (int i = 0; i < BookAllNum; i++) {
        for (int j = 0; j < BookAllNum - i - 1; j++) {
            if (DataBase[j].BookAddPrice < DataBase[j + 1].BookAddPrice) {
                BookData tempdata = DataBase[j];
                DataBase[j] = DataBase[j + 1];
                DataBase[j + 1] = tempdata;
            }
        }
    }
}

void bubbleSortListByAddDataNumUp() //�����ڽ���ð����������
{
    for (int i = 0; i < BookAllNum; i++) {
        for (int j = 0; j < BookAllNum - i - 1; j++) {
            if (DataBase[j].BookAddDataNum > DataBase[j + 1].BookAddDataNum) {
                BookData tempdata = DataBase[j];
                DataBase[j] = DataBase[j + 1];
                DataBase[j + 1] = tempdata;
            }
        }
    }
}

void bubbleSortListByAddDataNumDown() //�����ڽ���ð�����򣨽���
{
    for (int i = 0; i < BookAllNum; i++) {
        for (int j = 0; j < BookAllNum - i - 1; j++) {
            if (DataBase[j].BookAddDataNum < DataBase[j + 1].BookAddDataNum) {
                BookData tempdata = DataBase[j];
                DataBase[j] = DataBase[j + 1];
                DataBase[j + 1] = tempdata;
            }
        }
    }
}


bool UpOrDownMenu() //ѯ���������ǽ���
{
    cout << "�������л��ǽ������У�[u/d]\n";
    char tempdatachar;
    cin >> tempdatachar;
    if (tempdatachar == 'u')
        return true;
    else if (tempdatachar == 'd')
        return false;
    else {
        cout << "ֻ������U�����򣩻���D������\n";
        return UpOrDownMenu();//����Ϲ������
    }
}

void Sortmenu() //����ķ�ҳ��
{
    cout << "��ʲô��������\n";
    cout << "1.ͼ�鵥��\n";
    cout << "2.ͼ�����\n";
    cout << "3.ͼ���ܼ�\n";
    cout << "4.ͼ���������\n";
    cout << "5.�����ϼ�ҳ��\n";
    int key_num = 0;
    cin >> key_num;//������ʲô����

    switch (key_num) {
        case 1:
            if (UpOrDownMenu())
                bubbleSortListByQtyOnHandUp();
            else
                bubbleSortListByQtyOnHandDown();
            system("cls");
            printData();
            return;
        case 2:
            if (UpOrDownMenu())
                bubbleSortListByWholesaleUp();
            else
                bubbleSortListByWholesaleDown();
            system("cls");
            printData();
            return;
        case 3:
            if (UpOrDownMenu())
                bubbleSortListByAddPriceUp();
            else
                bubbleSortListByAddPriceDown();
            system("cls");
            printData();
            return;
        case 4:
            if (UpOrDownMenu())
                bubbleSortListByAddDataNumUp();
            else
                bubbleSortListByAddDataNumDown();
            system("cls");
            printData();
            return;
        case 5:
            system("cls");
            report_menu();
            return;
        default:
            cout << "����������1~5!\n";
            system("pause");
            system("cls");
            Sortmenu();
            return;
    }

}

void report_menu() //����ģ�麯��
{
    cout << "\tͼ�����ϵͳ\n";
    cout << "\t  ����ģ��\n";
    cout << "1.����б�\n";
    cout << "2.���ۼ��б�\n";
    cout << "3.�����б�\n";
    cout << "4.���ص����˵�\n\n";
    int key_num = 0;//�������ִ���
    cin >> key_num;
    //switchò���ŵ�BUG
    if (key_num == 1) {
        system("cls");
        printData();
        system("pause");
        return;
    } else if (key_num == 2) {
        system("cls");
        cout << "\tͼ�����ϵͳ\n";
        cout << "ISBN��\t����\tʣ������\t����\t����\n";
        for (int i = 0; i < 100; i++) {
            if (DataBase[i].BookISBN != '\0') //�����Ϣ
            {
                cout << DataBase[i].BookISBN << "\t" << DataBase[i].BookTitle << "\t" << DataBase[i].BookNum << "\t"
                     << DataBase[i].qtyOnHand << "\t"
                     << DataBase[i].BookWholesale << "\n";
            }
        }
        system("pause");
        return;
    } else if (key_num == 3) {
        system("cls");
        Sortmenu();
        system("pause");
        return;
    } else if (key_num == 4) {
        return;
    } else {
        cout << "ERROR!!!\n���������룡";
        system("pause");
        system("cls");
        report_menu();//��������
    }
}


void saveInfoToFile(const char *fileName)//д��
{
    FILE *fp = fopen(fileName, "w");
    int tempNumber = 0;
    while (tempNumber < BookAllNum) //��������
    {
        fprintf(fp, "%d\t%s\t%s\t%s\t%d\t%.2lf\t%.2lf\t%d\t%d\t%d\n", DataBase[tempNumber].BookISBN,
                DataBase[tempNumber].BookTitle,
                DataBase[tempNumber].BookAuther, DataBase[tempNumber].BookPub, DataBase[tempNumber].BookNum,
                DataBase[tempNumber].qtyOnHand,
                DataBase[tempNumber].BookWholesale, DataBase[tempNumber].BookAddData[0],
                DataBase[tempNumber].BookAddData[1], DataBase[tempNumber].BookAddData[2]);
        tempNumber++;
    }
    fclose(fp);//�ر��ļ�
}

void readInfoFromFile(const char *fileName)//�ļ�������
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) //���û�еĻ������ļ�
    {
        fp = fopen(fileName, "w+");
    }
    int tempNumber = 0;//¼�뵽��ͬ�Ĵ���λ��
    while (fscanf(fp, "%d\t%s\t%s\t%s\t%d\t%lf\t%lf\t%d\t%d\t%d\n", &DataBase[tempNumber].BookISBN,
                  DataBase[tempNumber].BookTitle,
                  DataBase[tempNumber].BookAuther, DataBase[tempNumber].BookPub, &DataBase[tempNumber].BookNum,
                  &DataBase[tempNumber].qtyOnHand,
                  &DataBase[tempNumber].BookWholesale, &DataBase[tempNumber].BookAddData[0],
                  &DataBase[tempNumber].BookAddData[1], &DataBase[tempNumber].BookAddData[2]) !=
           EOF) //���ļ�����������ָ��
    {
        tempNumber++;
    }
    BookAllNum = tempNumber;//¼������
    fclose(fp);
}