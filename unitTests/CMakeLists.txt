#
# Lines inspired by https://google.github.io/googletest/quickstart-cmake.html
#

# Note: include(GoogleTest)and enable_testing() already done in top CMakeLists.txt

add_executable(unitTests unitTests.cpp)
target_link_libraries(unitTests PUBLIC GTest::gtest_main src pugixml sfml-graphics ImGui-SFML::ImGui-SFML)

# The next line enables CMake’s test runner to discover the tests included in the binary,
# using the GoogleTest CMake module (which was included in root CMakeLists.txt).
gtest_discover_tests(unitTests)



##COPY RESSOURCES
#CODE REUTILISE Depuis le channel #questions du discord

add_custom_target(copy-resources_test ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)
file(GLOB_RECURSE RESOURCES LIST_DIRECTORIES true CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/resources/*.*)
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/resources
    DEPENDS ${CMAKE_SOURCE_DIR}/resources
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/resources
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${RESOURCES}
            ${CMAKE_CURRENT_BINARY_DIR}/resources)


add_dependencies(unitTests copy-resources_test)