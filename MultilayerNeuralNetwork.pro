TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    SimpleAI/Warrior.cpp \
    main.cpp \
    Common/NeuroNetwork.cpp \
    SimpleAI/EnvironmentState.cpp

HEADERS += \
    Common/NeuroNetwork.h \
    SimpleAI/Result.h \
    SimpleAI/TrainElement.h \
    SimpleAI/Warrior.h \
    SimpleAI/EnvironmentState.h
