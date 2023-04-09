!exists($$OUT_PWD/.qmake.cache) {
    system("echo ROOT_PROJECT  = $$PWD           >> $$OUT_PWD/.qmake.cache")
    system("echo PATH_INSTALL  = $$OUT_PWD/build >> $$OUT_PWD/.qmake.cache")
    system("echo ROOT_BUILD    = $$OUT_PWD/bin   >> $$OUT_PWD/.qmake.cache")
    system("echo ROOT_APP      = $$PWD/app       >> $$OUT_PWD/.qmake.cache")
    system("echo ROOT_QMQTT    = $$PWD/src/mqtt  >> $$OUT_PWD/.qmake.cache")
}

TEMPLATE = subdirs

SUBDIRS += \
    src \
    app

app.depends = src



