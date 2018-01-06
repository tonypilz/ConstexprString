TEMPLATE = app
CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++1y

SOURCES += main.cpp \
    main_example.cpp

HEADERS += \
    tmp.h \
    c_string_concatenate_via_template_char_list_not_practical.h \
    cstring_concatenation.h \
    tests.h




