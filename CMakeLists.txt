cmake_minimum_required(VERSION 3.15)
cmake_policy(VERSION 3.15)

include(FetchContent)
project(BabyPiouPiou VERSION 1.0.0 LANGUAGES CXX)

if(WIN32)
  # SonarLint support for CMake requires the following flag to be set on.
  #(see https://community.sonarsource.com/t/sonarlint-for-visual-studio-v4-38-support-cmake-projects/50127)
  set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

set (BUILD_SHARED_LIBS FALSE)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW) # This cmake_policy avoids warning by cmake when we use pugixml

cmake_policy(SET CMP0135 NEW) # This cmake_policy avoids warning by cmake when we fetch contents based on URL


# SFML
set(SFML_VERSION 2.6.1)
FetchContent_Declare(
  SFML
  URL "https://github.com/SFML/SFML/archive/${SFML_VERSION}.zip"
)
FetchContent_MakeAvailable(sfml)

# ImGui
set(IMGUI_VERSION 1.89)
FetchContent_Declare(
  imgui
  URL "https://github.com/ocornut/imgui/archive/v${IMGUI_VERSION}.zip"
)
FetchContent_MakeAvailable(imgui)

# ImGui-SFML
set(IMGUI_SFML_VERSION 2.3)
FetchContent_Declare(
  imgui-sfml
  GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
  GIT_TAG 2.6.x
)
set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" ON)

FetchContent_MakeAvailable(imgui-sfml)


FetchContent_Declare(
    pugixml
    URL https://github.com/zeux/pugixml/releases/download/v1.14/pugixml-1.14.tar.gz
)

FetchContent_MakeAvailable(pugixml)

add_subdirectory(src)
add_subdirectory(mainLauncher)

#
# Include GoogleTest
#
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# enable_testing() must be in the source directory root (see cmake documentation at https://cmake.org/cmake/help/latest/command/enable_testing.html)
# Otherwise, Visual Studio test explorer does not see unit tests (See ticket https://developercommunity.visualstudio.com/t/No-tests-discovered-for-googletest-and-C/1148799#T-ND1150621)
include(GoogleTest)
enable_testing()
add_subdirectory(unitTests)