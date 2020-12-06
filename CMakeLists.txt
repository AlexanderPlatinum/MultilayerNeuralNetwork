cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

project(MultilayerNeuralNetwork)

set(SRC
    main.cpp
    Common/NeuroNetwork.cpp
    SimpleAI/EnvironmentState.cpp
    SimpleAI/Warrior.cpp)

set(HEADERS
    Common/NeuroNetwork.h
    SimpleAI/EnvironmentState.h
    SimpleAI/Result.h
    SimpleAI/TrainElement.h
    SimpleAI/Warrior.h)

add_executable(MultilayerNeuralNetwork ${SRC} ${HEADERS})
