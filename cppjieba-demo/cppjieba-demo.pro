TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    ../cppjieba/include/cppjieba/Jieba.hpp


win32: LIBS += $$PWD/libcppjieba.lib \
                $$PWD/libcppjieba.obj

