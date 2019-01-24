TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/main.cpp \
    src/Managers/TextureManager.cpp \
    src/Utils/Log.cpp \
    src/Objects/Object.cpp \
    src/Objects/ObjectType.cpp \
    src/Managers/ObjectTypeManager.cpp \
    src/Context.cpp \
    src/Config.cpp \
    src/Engines/GameEngine.cpp \
    src/Objects/Group.cpp \
    src/Utils/Indexer.cpp \
    src/Objects/Missile.cpp \
    src/Objects/FloatingText.cpp \
    src/Utils/Misc.cpp \
    src/Objects/GameObject.cpp

LIBS += -lsfml-system -lsfml-window -lsfml-graphics

HEADERS += \
    src/Managers/TextureManager.h \
    src/Utils/Log.h \
    src/Objects/Object.h \
    src/Objects/ObjectType.h \
    src/Managers/ObjectTypeManager.h \
    src/Context.h \
    src/Config.h \
    src/Objects/Attributes.h \
    src/GameEngine.h \
    src/Engines/GameEngine.h \
    src/Objects/Group.h \
    src/Utils/Indexer.h \
    src/Objects/Missile.h \
    src/Objects/FloatingText.h \
    src/Utils/Misc.h \
    src/Objects/GameObject.h
