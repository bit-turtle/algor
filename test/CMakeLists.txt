project(AlgorTests)

file(GLOB_RECURSE ALGOR_TEST_SOURCES
    CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c" 
)

add_executable(algortest ${ALGOR_TEST_SOURCES})

target_link_libraries(algortest algor)

add_custom_target(testalgor ALL
	COMMAND ${CMAKE_CURRENT_BINARY_DIR}/algortest
	DEPENDS algortest
)
