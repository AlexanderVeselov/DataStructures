set(SOURCES dstest.cpp)

add_executable(DSTest ${SOURCES})
target_link_libraries(DSTest PRIVATE DS)
