QT += widgets
requires(qtConfig(filedialog))

qtHaveModule(printsupport): QT += printsupport

TEMPLATE        = app
TARGET          = OpenKrownIDE

HEADERS       = mainwindow.h \
    highlighter.h \
    textedit.h \
    classwizard.h

SOURCES       = main.cpp \
    highlighter.cpp \
    classwizard.cpp \
    mainwindow.cpp \
    textedit.cpp

RESOURCES     = application.qrc
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/application
INSTALLS += target
