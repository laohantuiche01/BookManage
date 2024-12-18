
#ifndef BOOKMANAGE_BOOKMANAGERUN_H
#define BOOKMANAGE_BOOKMANAGERUN_H

#endif //BOOKMANAGE_BOOKMANAGERUN_H

void mainmenu() ;//解释都在.cpp

void mainKeyDown();

void bookstore_menu();

void report_menu();

void saveInfoToFile(const char *fileName);

void readInfoFromFile(const char *fileName);

extern int BookAllNum ;//声名的全局变量，最大存到了第几位
extern BookData DataBase[100];//用来储存具体内容