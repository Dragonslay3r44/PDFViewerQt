# poppler.pri

INCLUDEPATH += $$PWD/3rdparty/poppler/include

LIBS += -L$$PWD/3rdparty/poppler/lib -lpoppler-qt6

# DEFINES += USE_POPPLER

win32 {
    DLL_SOURCE_DIR = $$PWD/3rdparty/poppler/bin
    DLL_TARGET_DIR = $$OUT_PWD

    POPPLER_DLL = libpoppler-qt6-3.dll

    QMAKE_POST_LINK += $$quote(copy /Y \"$$DLL_SOURCE_DIR\\$$POPPLER_DLL\" \"$$DLL_TARGET_DIR\\\") $$escape_expand(\\n\\t)
}