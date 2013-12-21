#include "piechartqt.h"
#include <QtGui>
#include <QApplication>
#include <QPushButton>
#include <iostream>
#include<QHBoxLayout>

Arena::Arena(QWidget *parent) :
    QWidget(parent)
{
/*********butten******/

    fileCount = 0;
    QHBoxLayout Lay;

    userinput = new QLineEdit(this) ;
    userinput->setGeometry(100 , 20 , 100 , 27);

    Lay.addWidget(userinput);

    quitB = new QPushButton("Quit" , this);
    quitB->setGeometry(500 , 20 , 50,50);
    connect (quitB,SIGNAL(clicked()),this,SLOT(quitA())) ;
    
    rset = new QPushButton("Reset" , this);
    rset->setGeometry(200,400,50,50);
    connect (rset,SIGNAL(clicked()),this,resetIt());
    rset->show();

    trainB=new QPushButton ("Training",this);

    trainB->setGeometry(200,200,60,40);
    trainB->hide();
    testingB=new QPushButton ("Testing",this);
    testingB->setGeometry(400,200,60,40);
    testingB->hide();
    connect(trainB,SIGNAL(clicked()),this,SLOT(openrecording()));

    startB=new QPushButton("Start",this);
    startB->setGeometry(200,200,60,40);
    stopB=new QPushButton("Stop",this);
    stopB->setGeometry(400,200,60,40);
    backB=new QPushButton("Back",this);
    backB->setGeometry(150,400,50,50);
    connect(backB,SIGNAL(clicked()),this,SLOT(prevCall()));
    presearchB = new QPushButton("Prefix-Search",this);
    presearchB->setGeometry(215 , 20 , 100,27);
    connect(presearchB,SIGNAL(clicked()),this,SLOT(preSearch()));
    presearchB->hide();
    fullsearchB = new QPushButton("keyword Search",this);
    fullsearchB->setGeometry(320 , 20 , 120 , 27);
    connect(fullsearchB,SIGNAL(clicked()),this,SLOT(completeSearch()));
    fullsearchB->hide();
    nextB = new QPushButton("Next",this);
    nextB->setGeometry(100 , 400 , 50 , 50);
    connect(nextB,SIGNAL(clicked()),this,SLOT(nextCall()));
    nextB->hide();
    startB->hide();
    stopB->hide();
    backB->hide();

   // this->setLayout(&Lay);
}
void Arena::openrecording(){
    trainB->hide();
    testingB->hide();
    startB->show();
    stopB->show();
    backB->show();

}

void Arena::backtomain(){
    trainB->show();
    testingB->show();
    startB->hide();
    stopB->hide();
    backB->hide();
}



void Arena::transferinput(){
    QString line;
    line = userinput->text();
    giveinput(line);

}
void Arena::startArena(tries t11, tries t12, int n){
    t1 = t11;
    t2 = t12;
    valueN = n;
    presearchB->show();
    fullsearchB->show();

}

void Arena::preSearch(){
    presearchB->hide();
    fullsearchB->hide();
    connect(userinput, SIGNAL( textChanged(const QString & ) ),
            this, SLOT(reset()) );
}

void Arena::completeSearch(){
    QPushButton *sear = new QPushButton ("Search",this);
    sear->setGeometry(215,20,100,27);
    sear->show();
    presearchB->hide();
    fullsearchB->hide();
    connect(sear,SIGNAL(clicked()),this,SLOT(startTree()));
}

void Arena::reset(){
    cout << 123 <<endl;
    if (fileVec.empty()){
        userinput.clear();
    }
    else {
        while(!previousList.empty()){
            previousList.back()->hide();
            previousList.pop_back();
        }
        while(!fileVec.empty()){
            //vec.back()->hide();
            fileVec.pop_back();
        }
        userinput.clear();
    }
}

void Arena::startTrie(){
    //presearchB->show();
    /*QPushButton *asd;
    asd = new QPushButton("hi!!!!",this);
    asd->setGeometry(200,200,30,30);
    asd->show();*/
    QString input = userinput->text();
    char star[1000];
    strcpy(star, input.toAscii().data());
    string str = star ;

    fileVec = process(str,t2,t1,valueN);

    //cout << fileVec.size()<<endl;

    /*QPushButton *sample;
    sample = new QPushButton(str.c_str(),this);
    sample->setGeometry(300,20,200,40);
    sample->show();
*/

    cout << "hey" <<endl;
    presearchB->hide();
    fullsearchB->hide();
    updatelist(0);
    nextB->show();
    backB->show();
}
void Arena::startTree(){
    presearchB->hide();
    fullsearchB->hide();
    //updatelist(0);
    QString input = userinput->text();
    char star[1000];
    strcpy(star, input.toAscii().data());
    string str = star ;

    fileVec = full(str,t2);

    //cout << fileVec.size() <<endl;

    updatelist(0);
    nextB->show();
    backB->show();
}

void Arena::nextCall(){
    if (fileCount+10 > fileVec.size()){
        nextB->hide();
    }
    else {
    backB->show();
    fileCount+=10;
    updatelist(fileCount);
    }
}

void Arena::prevCall(){
    nextB->show();
    if (fileCount == 0){
        backB->hide();
    }
    else{
        fileCount-=10;
        updatelist(fileCount);
    }

}


void Arena::bCall(fax* x){
    //fax x;
    //x.nam="firefox";x.add="##";
    showthis(x,t2,t1);
}

void Arena::quitA(){
    onClose(t1);
    qApp->quit();
}

void Arena::resetIt(){
    reset();
    fullsearchB->show();
    presearchB->show();
}


//void Arena::evaluat_app(int x,int e->y() /*turn also */){
  //}



