#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T14:26:48
#
#-------------------------------------------------

QT       -= gui

TARGET = gol_business_sequential
TEMPLATE = lib

DEFINES += GOL_BUSINESS_SEQUENTIAL_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    InitializeUniverse.cpp \
    InitializeGalaxies.cpp \
    InitializeCells.cpp \
    EvolveGalaxy.cpp \
    RandomizeCells.cpp \
    EvolveUniverse.cpp

HEADERS += \
        Preprocessor.h \
    InitializeUniverse.h \
    InitializeGalaxies.h \
    InitializeCells.h \
    EvolveGalaxy.h \
    RandomizeCells.h \
    EvolveUniverse.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += $$PWD/../gol_business_models
INCLUDEPATH += $$PWD/../gol_business_repositories

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gol_business_commands_core/release/ -lgol_business_commands_core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gol_business_commands_core/debug/ -lgol_business_commands_core
else:unix: LIBS += -L$$OUT_PWD/../gol_business_commands_core/ -lgol_business_commands_core

INCLUDEPATH += $$PWD/../gol_business_commands_core
DEPENDPATH += $$PWD/../gol_business_commands_core

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gol_business_commands/release/ -lgol_business_commands
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gol_business_commands/debug/ -lgol_business_commands
else:unix: LIBS += -L$$OUT_PWD/../gol_business_commands/ -lgol_business_commands

INCLUDEPATH += $$PWD/../gol_business_commands
DEPENDPATH += $$PWD/../gol_business_commands

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gol_data_repositories/release/ -lgol_data_repositories
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gol_data_repositories/debug/ -lgol_data_repositories
else:unix: LIBS += -L$$OUT_PWD/../gol_data_repositories/ -lgol_data_repositories

INCLUDEPATH += $$PWD/../gol_data_repositories
DEPENDPATH += $$PWD/../gol_data_repositories
