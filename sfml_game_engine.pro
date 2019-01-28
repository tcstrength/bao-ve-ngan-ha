TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/main.cpp \
    src/Managers/TextureManager.cpp \
    src/Utils/Log.cpp \
    src/Context.cpp \
    src/Config.cpp \
    src/Engines/GameEngine.cpp \
    src/Utils/Indexer.cpp \
    src/Utils/Misc.cpp \
    src/Environment/Environment.cpp \
    src/Environment/EnvironmentObject.cpp \
    src/Objects/FloatingText.cpp \
    src/Objects/GameObject.cpp \
    src/Objects/ObjectType.cpp \
    src/Managers/ObjectTypeManager.cpp \
    src/Parsers/OBJTParser.cpp \
    src/Objects/Missile.cpp \
    src/Entities/Camera.cpp \
    src/Objects/Hero.cpp \
    src/Objects/BasicCraft.cpp

LIBS += -lsfml-system -lsfml-window -lsfml-graphics

HEADERS += \
    src/Managers/TextureManager.h \
    src/Utils/Log.h \
    src/Context.h \
    src/Config.h \
    src/GameEngine.h \
    src/Engines/GameEngine.h \
    src/Utils/Indexer.h \
    src/Utils/Misc.h \
    src/Environment/Environment.h \
    src/Environment/EnvironmentObject.h \
    src/Objects/Attributes.h \
    src/Objects/FloatingText.h \
    src/Objects/GameObject.h \
    src/Objects/ObjectType.h \
    src/Managers/ObjectTypeManager.h \
    src/Parsers/OBJTParser.h \
    src/Objects/Missile.h \
    src/Entities/Camera.h \
    src/Objects/Hero.h \
    src/Objects/BasicCraft.h
