LIBS += -L"$$ROOT_BUILD/libs/"

message($$LIBS)

dll:            DESTDIR = $$ROOT_BUILD/libs/
else:plugin:    DESTDIR = $$ROOT_BUILD/plugins/
else:driver:    DESTDIR = $$ROOT_BUILD/drivers/
else:           DESTDIR = $$ROOT_BUILD

# Ниже только то, что относится к install

dll:            target.path = $$PATH_INSTALL
else:plugin:    target.path = $$PATH_INSTALL/plugins/
else:driver:    target.path = $$PATH_INSTALL/drivers/
else:           target.path = $$PATH_INSTALL

INSTALLS += target

# Это позволяет не порождать lib*.a файлы
contains(TEMPLATE, lib):CONFIG += plugin
