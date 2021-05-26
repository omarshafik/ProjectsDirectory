QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./Repository/ProjectsRepository.cpp \
    ./Model/project.cpp \
    main.cpp \
    ./View/directory.cpp \

HEADERS += \
    /Repository/ProjectsRepository.h \
    ./Repository/ProjectsRepository.h \
    ./Repository/db_constants.h \
    ./Model/project.h \
    /Repository/db_constants.h \
    ./View/directory.h \

FORMS += \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
