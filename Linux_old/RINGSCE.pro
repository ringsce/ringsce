QT += gui widgets sql
CONFIG += c++11
requires(qtConfig(filedialog))

qtHaveModule(printsupport): QT += printsupport

TEMPLATE        = app
TARGET          = RINGSCE


HEADERS       = \
    highlighter.h \
    dialog.h \
    mainwindow.h \
    sqlcontactmodel.h \
    sqlconversationmodel.h \
    ui_main.h \
    ui_new_file.h \
    ui_new_project.h \
    main.h \
    new_file.h \
    new_project.h

SOURCES       = main.cpp \
    highlighter.cpp \
    dialog.cpp \
    mainwindow.cpp \
    sqlcontactmodel.cpp \
    sqlconversationmodel.cpp

RESOURCES     = application.qrc \
    qml.qrc \
    shared.qrc
# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/application
INSTALLS += target

DISTFILES += \
    ChatToolBar.qml \
    ContactPage.qml \
    ConversationPage.qml \
    main.qml \
    qtquickcontrols2.conf


HEADERS += sqlcontactmodel.h \
    sqlconversationmodel.h

SOURCES += main.cpp \
    sqlcontactmodel.cpp \
    sqlconversationmodel.cpp

RESOURCES += \
    qml.qrc \
    ../shared/shared.qrc

