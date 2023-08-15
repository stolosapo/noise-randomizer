AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = noiserandomizer

mainincludedir = $(includedir)/noiserandomizer
maininclude_HEADERS = \
    NoiseRandomizer.h \
    State.h \
    Pattern.h \
    Simple555Pattern.h \
    RandomPattern.h \
    StateApplier.h \
    GPIOObject.h \
    GPIOApplier.h

common_sources = \
    NoiseRandomizer.cpp \
    Pattern.cpp \
    Simple555Pattern.cpp \
    RandomPattern.cpp \
    StateApplier.cpp \
    GPIOObject.cpp \
    GPIOApplier.cpp \
    Arguments.h Arguments.cpp \
    Logger.h Logger.cpp \
    StringHelper.h StringHelper.cpp \
    FileHelper.h FileHelper.cpp \
    random.h random.cpp

noiserandomizer_SOURCES = main.cpp $(common_sources)
noiserandomizer_LDADD = libnoiserandomizer.la
noiserandomizer_CXXFLAGS = $(AM_CXXFLAGS) -lnoisekernel

lib_LTLIBRARIES = libnoiserandomizer.la
libnoiserandomizer_la_LDFLAGS = -version-info 1:0:0 -pthread
libnoiserandomizer_la_CXXFLAGS = $(AM_CXXFLAGS) -pthread -lnoisekernel
libnoiserandomizer_la_SOURCES = $(common_sources)
