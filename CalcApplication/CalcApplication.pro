QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BerechnungRC.cpp \
    BerechnungRL.cpp \
    BerechnungRLC.cpp \
    Error.cpp \
    TestBerechnungRC.cpp \
    TestBerechnungRL.cpp \
    TestBerechnungRLC.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    BerechnungRC.h \
    BerechnungRL.h \
    BerechnungRLC.h \
    Error.h \
    MainWindow.h

FORMS += \
    BerechnungRC.ui \
    BerechnungRL.ui \
    BerechnungRLC.ui \
    Error.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
  Res.qrc

GOOGLETEST_DIR = $$_PRO_FILE_PWD_/../googletest

!isEmpty(GOOGLETEST_DIR): {
    GTEST_SRCDIR = $$GOOGLETEST_DIR/googletest
    GMOCK_SRCDIR = $$GOOGLETEST_DIR/googlemock
} else: unix {
    exists(/usr/src/gtest):GTEST_SRCDIR=/usr/src/gtest
    exists(/usr/src/gmock):GMOCK_SRCDIR=/usr/src/gmock
    !isEmpty(GTEST_SRCDIR): message("Using gtest from system")
}

requires(exists($$GTEST_SRCDIR):exists($$GMOCK_SRCDIR))


!isEmpty(GTEST_SRCDIR) {
    INCLUDEPATH *= \
        $$GTEST_SRCDIR \
        $$GTEST_SRCDIR/include

    SOURCES += \
        $$GTEST_SRCDIR/src/gtest-all.cc
}

!isEmpty(GMOCK_SRCDIR) {
    INCLUDEPATH *= \
        $$GMOCK_SRCDIR \
        $$GMOCK_SRCDIR/include

    SOURCES += \
        $$GMOCK_SRCDIR/src/gmock-all.cc
}
