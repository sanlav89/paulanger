QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        advancedcompatibletable.cpp \
        fullcompatibletable.cpp \
        jumptable.cpp \
        main.cpp \
        multiset.cpp \
        outputtable.cpp \
        paulangerminimizer.cpp \
        set.cpp \
        statetable.cpp \
        statetableitem.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    advancedcompatibletable.h \
    fullcompatibletable.h \
    jumptable.h \
    multiset.h \
    outputtable.h \
    paulangerminimizer.h \
    set.h \
    statetable.h \
    statetableitem.h
