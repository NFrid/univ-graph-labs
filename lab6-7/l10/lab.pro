CONFIG += c++11

QT += widgets
SOURCES += main.cpp statusbar.cpp
HEADERS += statusbar.h

RESOURCES += qml.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
