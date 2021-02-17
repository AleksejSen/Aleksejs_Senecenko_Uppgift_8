QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#LIBS += -L"/usr/local/bin" -lpower -lcomponent -lresistance

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    libcomponent.h \
    libpower.h \
    libresistance.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/lib/ -lcomponent

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.


unix:!macx: LIBS += -L$$PWD/lib/ -lpower

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

unix:!macx: LIBS += -L$$PWD/lib/ -lresistance

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
