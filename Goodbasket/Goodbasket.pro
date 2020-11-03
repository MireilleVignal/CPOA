TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        pc.cpp \
        producteur.cpp \
        responspc.cpp

HEADERS += \
    coordonnees.h \
    pc.h \
    producteur.h \
    responspc.h
