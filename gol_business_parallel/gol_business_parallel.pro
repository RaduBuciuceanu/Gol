QT       -= gui

TARGET = gol_business_parallel
TEMPLATE = lib

DEFINES += GOL_BUSINESS_PARALLEL_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    ParallelEvolveUniverse.cpp \
    EvolveGalaxyThread.cpp

HEADERS += \
    Preprocessor.h \
    ParallelEvolveUniverse.h \
    EvolveGalaxyThread.h

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gol_data_repositories/release/ -lgol_data_repositories
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gol_data_repositories/debug/ -lgol_data_repositories
else:unix: LIBS += -L$$OUT_PWD/../gol_data_repositories/ -lgol_data_repositories

INCLUDEPATH += $$PWD/../gol_data_repositories
DEPENDPATH += $$PWD/../gol_data_repositories

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gol_business_commands/release/ -lgol_business_commands
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gol_business_commands/debug/ -lgol_business_commands
else:unix: LIBS += -L$$OUT_PWD/../gol_business_commands/ -lgol_business_commands

INCLUDEPATH += $$PWD/../gol_business_commands
DEPENDPATH += $$PWD/../gol_business_commands

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gol_business_sequential/release/ -lgol_business_sequential
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gol_business_sequential/debug/ -lgol_business_sequential
else:unix: LIBS += -L$$OUT_PWD/../gol_business_sequential/ -lgol_business_sequential

INCLUDEPATH += $$PWD/../gol_business_sequential
DEPENDPATH += $$PWD/../gol_business_sequential
