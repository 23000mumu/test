QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddaily.cpp \
    main.cpp \
    miniwidget.cpp \
    miniwidget1.cpp \
    miniwidget2.cpp \
    miniwidget3.cpp \
    myddl.cpp \
    mywidget.cpp \
    widget.cpp

HEADERS += \
    adddaily.h \
    miniwidget.h \
    miniwidget1.h \
    miniwidget2.h \
    miniwidget3.h \
    myddl.h \
    mywidget.h \
    widget.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
