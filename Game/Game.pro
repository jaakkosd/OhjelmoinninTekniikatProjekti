TEMPLATE = app
TARGET = NYSSE

QT += core gui widgets network multimedia

CONFIG += c++14

SOURCES += \
    actoritem.cpp \
    busuiitem.cpp \
    city.cc \
    courseconverter.cpp \
    creategame.cc \
    engine.cpp \
    imgactoritem.cpp \
    main.cc \
    mainwindow.cpp \
    movement.cpp \
    ratikkaitem.cpp \
    passangeruiitem.cpp \
    rulesdialog.cpp \
    setupdialog.cpp \
    stopuiitem.cpp


win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

HEADERS += \
    actoritem.h \
    busuiitem.h \
    city.hh \
    courseconverter.h \
    engine.h \
    imgactoritem.h \
    mainwindow.h \
    movement.h \
    passangeruiitem.h \
    rulesdialog.h \
    setupdialog.h \
    stopuiitem.h \
    ratikkaitem.h

FORMS += \
    mainwindow.ui \
    rulesdialog.ui \
    setupdialog.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
