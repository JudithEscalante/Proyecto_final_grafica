#include "mlabel.h"

MLabel::MLabel(QWidget *parent):QLabel(parent)
{

}

void MLabel::mouseMoveEvent(QMouseEvent *put)
{
    emit Mouse_Pos();
}

void MLabel::mousePressEvent(QMouseEvent *put)
{
    this->x = put->x();
    this->y = put->y();
    emit Mouse_Pressed();
}

void MLabel::leaveEvent(QEvent *)
{
    emit Mouse_Left();
}




