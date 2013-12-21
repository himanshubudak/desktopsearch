#include "mybutton.h"


mybutton::mybutton(QWidget *parent) :
    QPushButton(parent)
{

}


void mybutton::generate()
{
        emit valueChanged(f);
}
