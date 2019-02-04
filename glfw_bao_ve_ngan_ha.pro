TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/Utils/Indexer.cpp \
    src/Utils/Log.cpp \
    src/Utils/Misc.cpp \
    src/Renderers/Window.cpp \
    src/Renderers/Drawable.cpp \
    src/Context.cpp \
    src/main.cpp \
    src/Renderers/Mesh.cpp \
    src/Utils/NonCopyable.cpp \
    src/Shaders/Shader.cpp \
    src/Renderers/Texture.cpp \
    src/Shaders/Shader2D.cpp \
    src/Renderers/Sprite.cpp \
    src/Parsers/Parser.cpp \
    src/Renderers/Animation.cpp \
    src/Utils/glfwClock.cpp \
    src/Resources/TextureManager.cpp \
    src/Resources/AnimationManager.cpp \
    src/Effects/Effect.cpp \
    src/Entities/Transformer.cpp \
    src/Entities/Camera.cpp \
    src/Events/Event.cpp \
    src/Events/EventSignal.cpp \
    src/Events/EventType.cpp \
    src/Events/EventData.cpp

HEADERS += \
    src/Utils/Indexer.h \
    src/Utils/Log.h \
    src/Utils/Misc.h \
    src/Renderers/Window.h \
    src/Renderers/Drawable.h \
    src/Config.h \
    src/Context.h \
    src/Renderers/Mesh.h \
    src/Renderers/Vertex.h \
    src/Utils/NonCopyable.h \
    src/Shaders/Shader.h \
    src/Renderers/Texture.h \
    src/Shaders/Shader2D.h \
    src/Renderers/Sprite.h \
    src/Parsers/Parser.h \
    src/Renderers/Animation.h \
    src/Utils/glfwClock.h \
    src/Resources/TextureManager.h \
    src/Resources/AnimationManager.h \
    src/Effects/Effect.h \
    src/Entities/Transformer.h \
    src/Entities/Camera.h \
    src/Events/Event.h \
    src/Events/EventSignal.h \
    src/Events/EventType.h \
    src/Events/EventData.h

LIBS += -lglfw -lGL -lGLEW -lSOIL
