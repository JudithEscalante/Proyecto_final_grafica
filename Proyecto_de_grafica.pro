#-------------------------------------------------
#
# Project created by QtCreator 2017-01-11T10:23:30
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets




TARGET = Proyecto_de_grafica
TEMPLATE = app


SOURCES += main.cpp\
        grafica.cpp \
    mlabel.cpp \
    opengl.cpp \
    glwidget.cpp

HEADERS  += grafica.h \
    mlabel.h\
    Cimg.h \
    opengl.h \
    glwidget.h

FORMS    += grafica.ui \
    opengl.ui

#LIBS += -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core

LIBS += -lglut -lpthread -lX11

LIBS += -L/usr/local/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab -lrt -lpthread -lm -ldl

CONFIG += link_pkgconfig
PKGCONFIG += opencv

CONFIG += link_pkgconfig
PKGCONFIG += opencv

RESOURCES += \
    figure.qrc
