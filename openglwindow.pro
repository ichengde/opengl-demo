
HEADERS += openglwindow.h \
    display.h

SOURCES += \
    main.cpp \
    openglwindow.cpp \
    display.cpp
QT           += widgets

target.path = $$[QT_INSTALL_EXAMPLES]/gui/openglwindow
INSTALLS += target
