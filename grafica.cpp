#include "grafica.h"
#include "ui_grafica.h"
#include <math.h>
grafica::grafica(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grafica)
{ 
    ui->setupUi(this);

    connect(ui->Video, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Current_Pressed()));

    count = 0;
    framework[0]=0;
    framework[1]=0;
    framework[2]=0;
    framework[3]=0;

    width = ui->Video->geometry().width();
    high = ui->Video->geometry().height();


}

grafica::~grafica()
{
    delete ui;
}

void grafica::video()
{

    VideoCapture laser;
    laser.open("laser1.mp4");

    double count1= laser.get(CV_CAP_PROP_FRAME_COUNT),f=0;
    laser.set(CV_CAP_PROP_POS_FRAMES,0);
    while(f<count1)
            {

                Mat frame;
                bool p=laser.read(frame);
                if(p) frames.push_back(frame);//Comienza a capturar frames de la camara
                else return;
                Mat result;
                cvtColor(frame, result,CV_BGR2RGB);
                QImage frame_2= QImage((uchar*) result.data, result.cols, result.rows, result.step, QImage::Format_RGB888);
                ui->Video->setPixmap(QPixmap::fromImage(frame_2));

                f++;
                laser.set(CV_CAP_PROP_POS_FRAMES,f-1);
            }
}
void grafica::look_show()
{
    for(int i=0; i<frames.size();i++)
    {
        Mat new1;
        cvtColor(frames[i], new1,CV_BGR2RGB);
        QImage frame_2= QImage((uchar*) new1.data, new1.cols, new1.rows, new1.step, QImage::Format_RGB888);
        ui->Video->setPixmap(QPixmap::fromImage(frame_2));

    }
}
void grafica::on_primero_clicked()
 {
     ui->primero->setEnabled(false);
     look_show();
     ui->segundo->setEnabled(true);
 }
void grafica::on_segundo_clicked()
{
    ui->segundo->setEnabled(false);

    //save_frames();
    QMessageBox m;
    m.setText("All frames have been saved");
    m.exec();
    ui->primero->setEnabled(true);
}
void grafica::save_frames()
{
    cout<<frames.size();
    for(size_t i = 0;i < frames.size(); ++i)
    {
       Mat picture;
       cvtColor(frames[i], picture,CV_BGR2RGB);
       QImage picture1= QImage((uchar*) picture.data, picture.cols, picture.rows, picture.step, QImage::Format_RGB888);
       QString str = "normal_set/picture"+QString::number(i)+".jpg";
       picture1.save(str,"JPEG");
    }
    QMessageBox m;
    m.setText("All frames have been saved");
    m.exec();


}

void grafica::Mouse_Current_Pressed()
{
    cout<<"error";
}

void grafica::on_pushButton_clicked()
{

   Binary2();
   Mesh();
   QMessageBox n;
   n.setText("Listo points.txt");
   n.exec();

}
void grafica::Binary_image()
{
    QString nombre;
    for(int i = 0; i < 432; ++i )
    {
        nombre = "normal_set/picture" + QString::number(i)+ ".jpg";
        cout<<"entro";
        string nu= nombre.toStdString();
        Mat img ;
        img = imread(nu);
        Mat binario;
        for(int k=0;k<img.rows;k++)
        {
            for(int j=0;j<img.cols;j++)
            {
               int value = (img.at<Vec3b>(k,j)[0]+ img.at<Vec3b>(k,j)[1]+img.at<Vec3b>(k,j)[2])/3;
              if(value > 230)
                binario.at<uchar>(k,j)=0;
              else
                binario.at<uchar>(k,j)=255;
            }
        }

        binary.push_back(binario);
        QString str = "binary_set/picture"+QString::number(i)+".jpg";
        Mat es;
        cvtColor(binario, es,CV_BGR2RGB);
        QImage picture1= QImage((uchar*) es.data, es.cols, es.rows, es.step, QImage::Format_RGB888);
        picture1.save(str,"JPEG");
    }
}

void grafica::Binary2()
{
    QString nombre;
    for(int i = 0; i < 432; ++i )
    {
        nombre = "normal_set/picture" + QString::number(i)+ ".jpg";
        string nu= nombre.toStdString();
        Mat im_gray=imread(nu,CV_LOAD_IMAGE_GRAYSCALE);
        Mat img_bw= im_gray > 240;
        binary.push_back(img_bw);
        QString nombre2;
        nombre2 = "binary_set/picture" + QString::number(i)+ ".jpg";
        string nu2= nombre2.toStdString();
        imwrite(nu2,img_bw);

    }
}
void grafica:: Mesh()
{

    ofstream mesh_text("binary_set/points.txt");
    for(int angle = 0; angle < 360;  angle ++)
    {
       i position = angle * binary.size()/ 360;
       i label = 0;
       i average = 0;
       for(int y = 0; y < binary[0].rows;  ++y)
        {
           label = 0;
           average = 0;
           for(int x = 540; x < binary[0].cols;  ++x)
            {
                if(binary[position].at<uchar>(x,y) == 255)
                {
                    label ++;
                    average += x;

                }

            }

            if(label > 0){
                average = average/label;
                float ratio= average / sin(22.5 * 2 * asin(1)/ 180);
                mesh_text << angle << " ";
                mesh_text << (int)(ratio * cos(angle * 2 * asin(1)/ 180)) << " ";
                mesh_text << y << " ";
                mesh_text << (int)(ratio * sin(angle * 2 * asin(1) / 180)) << "\n";
            }
        }

    }

    mesh_text.close();

}

void grafica::on_pushButton_2_clicked()
{
    Opengl *view = new Opengl;
    view->show();
}
