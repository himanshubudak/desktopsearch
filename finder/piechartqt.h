#ifndef PIECHARTQT_H
#define PIECHARTQT_H

#include<iostream>
#include<fstream>  ///////.............
#include "tries.h"
#include<list>
#include<string>
#include<vector>


//#include <Qstring>
#include <QDialog>
#include <QWidget>
#include <QHash>
#include<QPainter>
#include<iostream>
#include<QPushButton>
#include <QLineEdit>
#include <random.h>
#include <mybutton.h>
using namespace std;
class Arena : public QWidget
{
    Q_OBJECT

public:
    explicit Arena(QWidget *parent = 0);
    string fileName;
    vector<mybutton*> buttonlist;
    vector<mybutton*> previousList;
    vector<string> vec;
    vector<fax*> fileVec;
    //vector<mybutton*> bet;

    QPushButton *trainB;
    QPushButton *testingB;
    QPushButton *startB;
    QPushButton *stopB;
    QPushButton *backB;
    QPushButton *nextB;
    QPushButton *presearchB;
    QPushButton *fullsearchB;
    QPushButton *quitB;
    QPushButton *rset;

    QLineEdit *userinput;

    tries t1;
    tries t2;
    int valueN;

    int fileCount;
    /*void mousePressEvent(QMouseEvent *er);
    void setrect();
    QPainter *paint;
    QImage *image;
    int flag;
    int flag_array[7][6];

protected:
void paintEvent(QPaintEvent *ev);
void paintEvent1();
*/

        void updatelist(int count){

        //fileCount = count;
        //buttonlist.resize(10);
        //previousList.resize(10);
        //buttonlist.resize(10);
        int j = fileVec.size();
        string s;
        s= "end of list";

        while (!buttonlist.empty()){
           buttonlist.back()->hide();
           buttonlist.pop_back();
        }


        for(int i=0;i<10;i++){

            if (count == j){
                QPushButton *trainC;
                trainC = new QPushButton (s.c_str(),this);
                trainC->setGeometry (100 , 26*(i+0) , 200 , 25);
                //buttonlist.push_back(trainC);
                connect(trainC,SIGNAL(clicked()),this,SLOT(openrecording()));
                nextB->hide();
                break;
            }
            string str1;
            str1 = " ";
            string str2;
            str1.append(fileVec[count]->nam);
            str2 = fileVec[count]->add;
            str1.append("    :  ");
            str1.append(str2);
            mybutton *mb=new mybutton(this);
            mb->setText(str1.c_str());
            mb->f=fileVec[i];
            //bet.push_back(mb)
            connect(mb,SIGNAL(clicked()),mb,SLOT(generate()));
            connect(mb,SIGNAL(valueChanged(fax*)),this,SLOT(bCall(fax*)));
            mb->setGeometry (100 , 55 + 26*(i+0) , 800 , 25);
            mb->setStyleSheet("text-align:left");
            buttonlist.push_back(mb);
            previousList.push_back(mb);
            mb->show();

            count++;
        }
    }

    void giveinput(QString line){
        char str[1000];
        strcpy(str, line.toAscii().data());
        string s;
        s = str;
        fileName = s;
    }
    void startArena(tries t1,tries t2,int n);

public slots:
void openrecording();
void backtomain();
void transferinput();
void startTree();
void startTrie();
void nextCall();
void prevCall();
void reset();
void bCall(fax*);
void quitA();
void resetIt();
void preSearch();
void completeSearch();
};

#endif // PIECHARTQT_H
