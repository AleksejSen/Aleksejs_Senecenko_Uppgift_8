/* Window Wiht the closeing button:*/
//#include <QApplication>
//#include "window.h"

//int main(int argc, char **argv)
//{
//    QApplication app (argc, argv);

//    Window window;
//    window.show();

//    return app.exec();
//}

//#include <QApplication>
//#include <QProgressBar>
//#include <QSlider>

//int main(int argc, char **argv)
//{
//    QApplication app (argc, argv);
//    // Create a container window
//    QWidget window;
//    window.setFixedSize(600, 400);
//    //Create progress bar
//    QProgressBar *progressBar = new QProgressBar(&window);
//    progressBar->setRange(0, 100);
//    progressBar->setValue(0);
//    progressBar->setGeometry(10,10,180,30);
//    //Create slider
//    QSlider *slider = new QSlider(&window);
//    slider->setOrientation(Qt::Horizontal);
//    slider->setRange(0,100);
//    slider->setValue(0);
//    slider->setGeometry(10, 40, 180, 30);
//    window.show();
//    //Connecting
//    QObject::connect(slider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));

//    return app.exec();
//}


#include <QApplication>
#include <QPushButton>
#include <QWidget>

#define WIDE 200
#define HIGHT 200

#define BUTTON_WIDE  100
#define BUTTON_HIGHT 50

int main(int argc, char **argv)
{

    QApplication app (argc, argv);


    QWidget window;

    window.setFixedSize(WIDE, HIGHT);

    QPushButton *buttonInfo = new QPushButton("Info", &window);

    buttonInfo->setGeometry(WIDE/2 - BUTTON_WIDE/2, HIGHT/2 - BUTTON_HIGHT/2,  BUTTON_WIDE, BUTTON_HIGHT);

    QPushButton *buttonQuit = new QPushButton("Quit", &window);

    buttonQuit->setGeometry(WIDE/2 - BUTTON_WIDE/2, (HIGHT/2 - BUTTON_HIGHT/2)+BUTTON_HIGHT,  BUTTON_WIDE, BUTTON_HIGHT);

    window.show();

   QObject::connect( buttonQuit, SIGNAL (clicked(bool)), QApplication::instance(), SLOT (quit()));

   QObject::connect( buttonInfo, SIGNAL (clicked(bool)), QApplication::instance(), SLOT (aboutQt()));

    return app.exec();
}
