
#ifndef BOOKMANAGE_BOOKMANAGERUN_H
#define BOOKMANAGE_BOOKMANAGERUN_H

#endif //BOOKMANAGE_BOOKMANAGERUN_H

void mainmenu() ;//���Ͷ���.cpp

void mainKeyDown();

void bookstore_menu();

void report_menu();

void saveInfoToFile(const char *fileName);

void readInfoFromFile(const char *fileName);

extern int BookAllNum ;//������ȫ�ֱ��������浽�˵ڼ�λ
extern BookData DataBase[100];//���������������