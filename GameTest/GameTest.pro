QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testcase1.cpp \
    ../Game/core/statistics.cpp

INCLUDEPATH += \
    ../Course/CourseLib \
    ../

DEPENDPATH += \
    ../Course/CourseLib \
    ../

HEADERS += \
    ../Game/core/statistics.h
