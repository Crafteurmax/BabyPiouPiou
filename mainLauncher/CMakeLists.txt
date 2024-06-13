add_executable(mainLauncher mainLauncher.cpp)

target_link_libraries(mainLauncher PUBLIC src pugixml sfml-graphics ImGui-SFML::ImGui-SFML)

##COPY RESSOURCES
#CODE REUTILISE Depuis le channel #questions du discord

add_custom_target(copy-resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${CMAKE_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)
file(GLOB_RECURSE RESOURCES LIST_DIRECTORIES true CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/resources/*.*)
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/resources
    DEPENDS ${CMAKE_SOURCE_DIR}/resources
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/resources
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${RESOURCES}
            ${CMAKE_CURRENT_BINARY_DIR}/resources)


add_dependencies(mainLauncher copy-resources)
