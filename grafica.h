#ifndef GRAFICA_H
#define GRAFICA_H

#include <QMainWindow>
#include <QMessageBox>
#include <fstream>
#include <QThread>
#include <vector>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "opengl.h"
#include "glwidget.h"
#include "formopengl.h"
using namespace cv;
using namespace std;
typedef int i;
namespace Ui {
class grafica;
}

class grafica : public QMainWindow
{
    Q_OBJECT

public:
    explicit grafica(QWidget *parent = 0);
    ~grafica();

private:
    Ui::grafica *ui;
    void framework_draw(Mat &figure,i Rows, i Columns);
    vector<Mat> frames;
    vector<Mat> binary;
    void video();
    void save_frames();
    void Binary2();
    i framework[4];//almacena los limites respectivos
    i count;//Ubica que limite hay que definir
    i width;//Ancho del label que muestra las imagenes  de la camara
    i high; //Alto del label que muestra las imagenes obtenidas de la camara
    void Binary_image ();
    void Mesh();
    void look_show();



private slots:


    void Mouse_Current_Pressed();//Captura las posiciones de mouse en el labelCamara
    void on_segundo_clicked();
    void on_primero_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // GRAFICA_H
