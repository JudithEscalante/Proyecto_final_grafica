#include "opengl.h"
#include "ui_opengl.h"

Opengl::Opengl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Opengl)
{
    ui->setupUi(this);
}

Opengl::~Opengl()
{
    delete ui;
}
