AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = noiserandomizer

mainincludedir = $(includedir)/noiserandomizer
maininclude_HEADERS = \
    all_header_files.h

common_sources = \
    all_source_files.cpp

noiserandomizer_SOURCES = main.cpp $(common_sources)
noiserandomizer_LDADD = libnoiserandomizer.la
noiserandomizer_CXXFLAGS = $(AM_CXXFLAGS) -lnoisekernel

lib_LTLIBRARIES = libnoiserandomizer.la
libnoiserandomizer_la_LDFLAGS = -version-info 1:0:0 -pthread
libnoiserandomizer_la_CXXFLAGS = $(AM_CXXFLAGS) -pthread -lnoisekernel
libnoiserandomizer_la_SOURCES = $(common_sources)

TESTS = noiserandomizer