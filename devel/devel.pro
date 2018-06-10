TEMPLATE = app
CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -pedantic -Weffc++ -Wold-style-cast
QMAKE_CXXFLAGS += -Wconversion -Winit-self

QMAKE_CXXFLAGS += -std=c++1y


SOURCES += main.cpp \
    main_example.cpp

HEADERS += \
    c_string_concatenate_via_template_char_list_not_practical.h \
    tests.h \
    ConstexprString.h




