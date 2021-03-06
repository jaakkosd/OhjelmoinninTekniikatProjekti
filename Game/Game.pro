TEMPLATE = app
TARGET = NYSSE

QT += core gui widgets network multimedia

CONFIG += c++14

SOURCES += \
    core/city.cc \
    core/courseconverter.cpp \
    core/creategame.cc \
    core/engine.cpp \
    core/movement.cpp \
    core/statistics.cpp \
    graphicitems/flyingsquirrel.cpp \
    ui/mainwindow.cpp \
    ui/rulesdialog.cpp \
    ui/setupdialog.cpp \
    graphicitems/busuiitem.cpp \
    graphicitems/imgactoritem.cpp \
    graphicitems/passangeruiitem.cpp \
    graphicitems/ratikkaitem.cpp \
    graphicitems/stopuiitem.cpp \
    main.cc


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
    core/city.hh \
    core/courseconverter.h \
    core/engine.h \
    core/movement.h \
    graphicitems/flyingsquirrel.h \
    core/statistics.h \
    ui/mainwindow.h \
    ui/rulesdialog.h \
    ui/setupdialog.h \
    graphicitems/busuiitem.h \
    graphicitems/imgactoritem.h \
    graphicitems/passangeruiitem.h \
    graphicitems/ratikkaitem.h \
    graphicitems/stopuiitem.h

FORMS += \
    ui/mainwindow.ui \
    ui/rulesdialog.ui \
    ui/setupdialog.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
