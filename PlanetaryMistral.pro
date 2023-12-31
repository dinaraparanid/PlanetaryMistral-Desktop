TEMPLATE = app

QT += qml quick
CONFIG += c++1z

SOURCES += main.cpp \
    data/system_status.cpp \
    domain/client.cpp \
    data/system_location.cpp \
    data/system_time.cpp \
    data/system_view.cpp \
    presentation/models/system_status_model.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    data/system_status.h \
    domain/client.h \
    domain/json.hpp \
    data/system_location.h \
    data/system_time.h \
    data/system_view.h \
    presentation/models/system_status_model.h

LIBS += \
    -lboost_system\

DISTFILES += \
    LICENSE \
    README.md
