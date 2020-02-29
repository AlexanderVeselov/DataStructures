set(SOURCES
    ds.cpp
    vector.hpp
    list.hpp)

add_library(DS ${SOURCES})
target_include_directories(DS PUBLIC .)