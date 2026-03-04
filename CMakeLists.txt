cmake_minimum_required(VERSION 3.20)
set(TARGET woof)
project(${TARGET} LANGUAGES CXX)

# =========================
# Compilateur & Standard
# =========================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # Moderne compilation -fPIE
add_definitions(-DFORCED_CXX_STANDARD=14) # Used for the attribute definition
find_package(Python3 REQUIRED) # Try to find python for the dependencies

# =========================
#<Right> Warnings
# =========================
add_compile_options(
    -W
    -Wall
    -Wextra
    -Wpedantic
    -Wunused-parameter
    -Wshadow
    -Wuninitialized
)

# =========================
# Sources
# =========================
set(SRC
    # Global
    src/woof/DynamicLibrary.cpp

    # Engine
    src/woof/Engine.cpp
    src/woof/engine/run.cpp

    # Factory
    src/woof/factory/ObjectFactory.cpp
    src/woof/factory/GraphicFactory.cpp
    src/woof/factory/RenderFactory.cpp

    # Object
    src/woof/object/ShapeDescriptor.cpp

    # Graphic
    src/woof/graphic/SDLGraphic.cpp

    # Render
    src/woof/render/SDLRender.cpp
    src/woof/render/OpenGLRender.cpp
    src/woof/render/VulkanRender.cpp
)
add_library(${TARGET} STATIC ${SRC})
#add_library(${TARGET} SHARED ${SRC})

# =========================
# Dependencies
# =========================
add_library(utils STATIC IMPORTED)
set_target_properties(utils PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/cmake/libutils.a)
target_link_libraries(${TARGET} PRIVATE utils)
add_custom_target(generated_exception_header ALL
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/cmake/script/generate_exception_header.py
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
add_dependencies(${TARGET} generated_exception_header)

# =========================
# Includes
# =========================
target_include_directories(${TARGET} PUBLIC include)
#target_link_libraries(${TARGET} PRIVATE ...)

# =========================
# Modes
# =========================
target_compile_options(${TARGET} PRIVATE
    $<$<CONFIG:Debug>:-g -ggdb3>
    $<$<CONFIG:Release>:-O1>
)

# =========================
# Utils
# =========================
add_custom_target(get_unregistered_files
    COMMAND bash ${CMAKE_SOURCE_DIR}/cmake/script/check_files.sh unregistered ${SRC}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
