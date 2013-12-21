#ifndef MYBUTTON_H
#define MYBUTTON_H
#include <QDialog>
#include <QWidget>
#include <QHash>
#include<QPainter>
#include<iostream>
#include<QPushButton>
#include <QLineEdit>
#include <random.h>
using namespace std;


class mybutton:public QPushButton
{
    Q_OBJECT
public:
    fax * f;
    explicit mybutton(QWidget *parent = 0);
signals:
    void valueChanged(fax*);

public slots:
    void generate();
};

#endif // MYBUTTON_H
