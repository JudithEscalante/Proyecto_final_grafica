#ifndef OPENGL_H
#define OPENGL_H

#include <QWidget>

namespace Ui {
class Opengl;
}

class Opengl : public QWidget
{
    Q_OBJECT

public:
    explicit Opengl(QWidget *parent = 0);
    ~Opengl();

private:
    Ui::Opengl *ui;
};

#endif // OPENGL_H
