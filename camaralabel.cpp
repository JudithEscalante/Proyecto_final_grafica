#include "camaralabel.h"
#include "ui_camaralabel.h"

Camaralabel::Camaralabel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Camaralabel)
{
    ui->setupUi(this);
}

Camaralabel::~Camaralabel()
{
    delete ui;
}
