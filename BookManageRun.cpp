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

void mainmenu()                           //主菜单界面设计
{
    cout << "----------------------------\n";
    cout << "\t图书管理系统\n";
    cout << "\t  主菜单\n";
    cout << "   1.收银模块\n";
    cout << "   2.书库管理模块\n";
    cout << "   3.报表模块\n";
    cout << "   4.退出系统\n\n";
    cout << "   输入选择:\n";
    cout << "   请输入1~4之间的数。\n";
    cout << "----------------------------\n";
}


void mainKeyDown() {
    int userKey = 0;
    cin >> userKey;                       //用户输入信息
    switch (userKey)                      //输入数字，判断操作
    {
        case 1://收银模块
            system("cls");//清空界面
            cashier_menu();//进入到收银模块
            return;
        case 2://图书操作模块
            system("cls");
            bookstore_menu();//进入到图书操作模块
            return;
        case 3://报表模块
            system("cls");
            report_menu();//进入到报表模块
            return;
        case 4:
            cout << "退出系统\n";
            cout << "退出系统成功！\n";
            system("pause");     //显示信息
            exit(0);                 //退出系统，返回值为0
        default://处理用户瞎输入的情况
            cout << "输入数字无效,请重新输入!\n";
            mainKeyDown();              //再次输入
    }
}

void bookstoreSeachBook() //图书管理模块的找寻图书
{
    cout << "请输入要查找的书名：\n";
    int tempIndex = lookUpBook();
    if (tempIndex == -1) //处理没找到的情况
    {
        cout << "ERROR!未找到您查找的书籍！\n您还要继续查找吗？[y/n]\n";
        char tempJudge;
        cin >> tempJudge;
        if (tempJudge == 'y') {
            bookstoreSeachBook();
        } else {
            return;
        }
    } else //输出书籍内容（-------后续记得加多个重名的书籍的情况--）
    {
        system("cls");
        cout << "\t图书管理系统\n";
        cout << "ISBN号：" << DataBase[tempIndex].BookISBN << endl;
        cout << "书名：" << DataBase[tempIndex].BookTitle << endl;
        cout << "作者：" << DataBase[tempIndex].BookAuther << endl;
        cout << "出版社：" << DataBase[tempIndex].BookPub << endl;
        cout << "剩余数量：" << DataBase[tempIndex].BookNum << endl;
        cout << "单价：" << DataBase[tempIndex].qtyOnHand << endl;
        cout << "批发价：" << DataBase[tempIndex].BookWholesale << endl;
    }
}

int cashierPrint(int tempNum) //对于多个数据储存于打印
{
    system("cls");
    cout << "请输入选购书籍的ISBN号：\n";
    int tempBookISBN;//找书
    int tempnum = 0;//记录找到书的返回位置（-1为没找到）
    cin >> tempBookISBN;
    tempnum = lookUpBookByISBN(tempBookISBN);
    if (tempnum == -1) //没找到
    {
        cout << "您输入了无效ISBN码！请再次输入！\n";
        system("pause");
        return cashierPrint(tempNum);//再次进行输入
    } else //找到了
    {
        cout << "请输入要购买的数量：";
        int BookBuyNum = 0;
        cin >> BookBuyNum;
        cout << "\n";
        if (BookBuyNum > DataBase[tempnum].BookNum) //超出了最多的书
        {
            cout << "没有这么多书！\n";
            system("pause");
            return cashierPrint(tempNum);//再迭代
        } else {
            DataBase[tempnum].BookBuyNum = BookBuyNum;//更新数据
            return tempnum;
        }
    }
}

bool cashierdecide() //此模块由于重复询问是否还买书
{
    cout << "\n您还要继续采购吗？[y/n] ";
    char temp_decide;//字符串储存输入的Y与N
    cin >> temp_decide;
    if (temp_decide == 'y') //还买书
    {
        return false;
    } else if (temp_decide == 'n') //不买了
    {
        return true;
    } else //处理瞎输的情况
    {
        cout << "请输入y（yes）或者n（no）\n";
        return cashierdecide();//再给我输
    }
}

void cashier_menu() //输出菜单
{
    double priceSumPrice = 0;//总计的书的价格
    int tempIndex[100];//储存买了多少书
    int tempNum = 0;
    while (true) //输如多个购书信息
    {
        tempIndex[tempNum] = cashierPrint(tempNum);
        tempNum++;
        if (cashierdecide()) //不够买了（由于是Break，所以上面true与false相反）
        {
            break;
        } else
            continue;
    }

    system("cls");//清空内容
    cout << "\t图书管理系统\n";
    cout << "ISBN号\t书名\t作者\t出版社\t剩余数量\t单价\t进价\t日期\n";
    for (int i = 0; i < tempNum; i++) //输出以及出售完后书籍信息的更改
    {
        priceSumPrice = priceSumPrice + DataBase[tempIndex[i]].qtyOnHand * DataBase[tempIndex[i]].BookBuyNum;//计算总价
        DataBase[tempIndex[i]].BookNum = DataBase[tempIndex[i]].BookNum - DataBase[tempIndex[i]].BookBuyNum;//计算买后剩余书的数目
        cout << DataBase[tempIndex[i]].BookISBN << "\t" << DataBase[tempIndex[i]].BookTitle << "\t"
             << DataBase[tempIndex[i]].BookAuther << "\t"
             << DataBase[tempIndex[i]].BookPub << "\t" << DataBase[tempIndex[i]].BookNum << "\t"
             << DataBase[tempIndex[i]].qtyOnHand << "\t"
             << DataBase[tempIndex[i]].BookWholesale << "\t" << DataBase[tempIndex[i]].BookAddData[0] << "年"
             << DataBase[tempIndex[i]].BookAddData[1] << "月"
             << DataBase[tempIndex[i]].BookAddData[2] << "日\n";
    }
    cout << "-------------------------------------\n";
    printf("销售合计：RMB %.2lf\n", priceSumPrice);//输出相关信息
    printf("零售税：RMB %.2lf\n", priceSumPrice * 0.06);
    printf("应付金额：RMB %.2lf\n\n", priceSumPrice * 1.06);
    system("pause");

}

void bookstoreFixOne(int i)//修改位置为i的书籍信息
{
    system("cls");
    cout << "1.书名\n2.作者\n3.出版社\n4.剩余数量\n5.单价\n6.进价\n7.日期\n";
    cout << "请输入要修改的内容：\n";
    int tempNum = 0;//输入命令
    cin >> tempNum;
    switch (tempNum) {
        case 1:
            DataBase[i].setTitle();//重新设置题目
            return;
        case 2:
            DataBase[i].setAuthor();//作者
            return;
        case 3:
            DataBase[i].setPub();//出版社
            return;
        case 4:
            DataBase[i].setQty();//数量
            flashData();
            return;
        case 5:
            DataBase[i].setretail();//单价
            flashData();
            return;
        case 6:
            DataBase[i].setWholesale();//进价
            flashData();
            return;
        case 7:
            DataBase[i].setAddData();//重新输入数据
            flashData();//更新相关联的数据
            return;
        default://瞎够吧输
            cout << "输入数字无效！请重新输入!\n";
            system("pause");
            bookstoreFixOne(i);//再给我输
    }
}

void bookstoreFixContinue(int i)//修改多项数据
{
    char tempChar;
    cin >> tempChar;
    if (tempChar == 'y') {
        bookstoreFixOne(i);//返回到上面函数修改
        cout << "您还要修改其他数据吗？[y/n]\n";
        bookstoreFixContinue(i);//再修改
        return;
    } else if (tempChar == 'n') {
        return;
    } else {
        cout << "您输入了错误的字符！\n请重新输入y(yes)或者n(no):\n";
        bookstoreFixContinue(i);//瞎够吧输
        return;
    }
}

void bookstoreFixData() //主菜单跳转修改数据的函数
{
    cout << "请输入要改书目的ISBN号：\n";
    int tempNumber;
    cin >> tempNumber;//先确定是哪个

    for (int i = 0; i < BookAllNum; i++) //找书
    {
        if (DataBase[i].BookISBN == tempNumber) {
            bookstoreFixOne(i);
            cout << "您还要修改其他数据吗？[y/n]\n";
            bookstoreFixContinue(i);
            return;
        }
    }

    cout << "未找到目标书籍！\n您是否还要继续查找？[y/n]";
    char tempcontinue;
    cin >> tempcontinue;
    if (tempcontinue == 'y') {
        bookstoreFixData();
        return;
    }

}

void bookstoreDelete() //删除图书
{
    int BookIndex = -1;
    cout << "请输入删除书籍名称：\n";
    BookIndex = lookUpBook();//根据名字找书
    if (BookIndex == -1) //没找到
    {
        cout << "未找到相关书籍，您还要继续删除吗？[y/n]\n";
        char tempcontinue;
        cin >> tempcontinue;
        if (tempcontinue == 'y') //再继续删
        {
            bookstoreDelete();
            return;
        } else return;
    } else //找到了
    {
        if (BookIndex == BookAllNum - 1) //书的储存最大数减一
        {
            BookAllNum--;
        }
        DataBase[BookIndex].BookISBN = '\0';//吧ISBN设为0
        cout << "删除成功！！！\n";
        system("pause");
    }
}

void bookInputISBN(int i) //输入ISBN号
{
    BookData temp;
    temp.setISBN();//临时储存，看有没有重复
    int tempNum = lookUpBookByISBN(temp.BookISBN);
    if (tempNum == -1) //没有重复
    {
        DataBase[i].BookISBN = temp.BookISBN;
        return;
    } else {
        cout << "该ISBN已被使用！\n";
        cout << "请重新输入：\n";
        bookInputISBN(i);//再次输入
    }


}

void bookstore_menu() //图书管理模块函数
{
    cout << "\t书库管理模块\n\n";
    cout << "1.查找某本书的信息\n";
    cout << "2.增加书\n";
    cout << "3.修改书的信息\n";
    cout << "4.删除书\n";
    cout << "5.返回到主菜单\n\n";
    cout << "输入选择\n";
    int key_num = 0;//输入数字储存
    cin >> key_num;
    //switch语句会出BUG
    if (key_num == 1) //查找图书信息
    {
        bookstoreSeachBook();//跳转函数
        system("pause");
        return;
    } else if (key_num == 2) //增加书
    {
        int i = 0;
        for (; DataBase[i].BookISBN != '\0'; i++) {

        }//找到最近一个\0的储存单位
        bookInputISBN(i);
        DataBase[i].input();
        if (i == BookAllNum) {
            BookAllNum++;
        }
        cout << "输入成功！\n";
        system("pause");

    } else if (key_num == 3) //修改属的信息
    {
        bookstoreFixData();
    } else if (key_num == 4) //删除书
    {
        bookstoreDelete();
    } else if (key_num == 5) //返回到主菜单
    {
        return;
    } else //处理异常情况
    {
        cout << "ERROR!!!\n请重新输入！";
        system("pause");
        system("cls");
        bookstore_menu();//瞎够吧输
    }

}

void bubbleSortListByQtyOnHandUp() //按价格进行冒泡排序（升序）
{
    for (int i = 0; i < BookAllNum; i++) //就简单的冒泡排序
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

void bubbleSortListByQtyOnHandDown() //按价格进行冒泡排序（降序）
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

void bubbleSortListByWholesaleUp() //按进价进行冒泡排序（升序）
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

void bubbleSortListByWholesaleDown() //按进价进行冒泡排序（降序）
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

void bubbleSortListByAddPriceUp() //按总价值进行冒泡排序（升序）
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

void bubbleSortListByAddPriceDown() //按总价值进行冒泡排序（降序）
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

void bubbleSortListByAddDataNumUp() //按日期进行冒泡排序（升序）
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

void bubbleSortListByAddDataNumDown() //按日期进行冒泡排序（降序）
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


bool UpOrDownMenu() //询问是升序还是降序
{
    cout << "升序排列还是降序排列？[u/d]\n";
    char tempdatachar;
    cin >> tempdatachar;
    if (tempdatachar == 'u')
        return true;
    else if (tempdatachar == 'd')
        return false;
    else {
        cout << "只能输入U（升序）或者D（降序）\n";
        return UpOrDownMenu();//处理瞎输的情况
    }
}

void Sortmenu() //排序的分页面
{
    cout << "按什么进行排序？\n";
    cout << "1.图书单价\n";
    cout << "2.图书进价\n";
    cout << "3.图书总价\n";
    cout << "4.图书进货日期\n";
    cout << "5.返回上级页面\n";
    int key_num = 0;
    cin >> key_num;//操作是什么排序

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
            cout << "请输入数字1~5!\n";
            system("pause");
            system("cls");
            Sortmenu();
            return;
    }

}

void report_menu() //报表模块函数
{
    cout << "\t图书管理系统\n";
    cout << "\t  报表模块\n";
    cout << "1.书库列表\n";
    cout << "2.零售价列表\n";
    cout << "3.排序列表\n";
    cout << "4.返回到主菜单\n\n";
    int key_num = 0;//输入数字储存
    cin >> key_num;
    //switch貌似优点BUG
    if (key_num == 1) {
        system("cls");
        printData();
        system("pause");
        return;
    } else if (key_num == 2) {
        system("cls");
        cout << "\t图书管理系统\n";
        cout << "ISBN号\t\t书名\t\t剩余数量\t单价\t进价\n";
        for (int i = 0; i < 100; i++) {
            if (DataBase[i].BookISBN != '\0') //输出信息
            {
                cout << DataBase[i].BookISBN << "\t" << DataBase[i].BookTitle << "\t\t" << DataBase[i].BookNum << "\t\t"
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
        cout << "ERROR!!!\n请重新输入！";
        system("pause");
        system("cls");
        report_menu();//重新输入
    }
}


void saveInfoToFile(const char *fileName)//写入
{
    FILE *fp = fopen(fileName, "w");
    int tempNumber = 0;
    while (tempNumber < BookAllNum) //储存内容
    {
        fprintf(fp, "%d\t%s\t%s\t%s\t%d\t%.2lf\t%.2lf\t%d\t%d\t%d\n", DataBase[tempNumber].BookISBN,
                DataBase[tempNumber].BookTitle,
                DataBase[tempNumber].BookAuther, DataBase[tempNumber].BookPub, DataBase[tempNumber].BookNum,
                DataBase[tempNumber].qtyOnHand,
                DataBase[tempNumber].BookWholesale, DataBase[tempNumber].BookAddData[0],
                DataBase[tempNumber].BookAddData[1], DataBase[tempNumber].BookAddData[2]);
        tempNumber++;
    }
    fclose(fp);//关闭文件
}

void readInfoFromFile(const char *fileName)//文件读操作
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) //如果没有的话创建文件
    {
        fp = fopen(fileName, "w+");
    }
    int tempNumber = 0;//录入到不同的储存位置
    while (fscanf(fp, "%d\t%s\t%s\t%s\t%d\t%lf\t%lf\t%d\t%d\t%d\n", &DataBase[tempNumber].BookISBN,
                  DataBase[tempNumber].BookTitle,
                  DataBase[tempNumber].BookAuther, DataBase[tempNumber].BookPub, &DataBase[tempNumber].BookNum,
                  &DataBase[tempNumber].qtyOnHand,
                  &DataBase[tempNumber].BookWholesale, &DataBase[tempNumber].BookAddData[0],
                  &DataBase[tempNumber].BookAddData[1], &DataBase[tempNumber].BookAddData[2]) !=
           EOF) //读文件操作，读入指针
    {
        tempNumber++;
    }
    BookAllNum = tempNumber;//录入总数
    fclose(fp);
}
