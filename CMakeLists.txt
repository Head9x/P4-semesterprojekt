cmake_minimum_required(VERSION 3.15)
project(UITest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories("${CMAKE_SOURCE_DIR}/wxWidgets/include" "%(AdditionalIncludeDirectories)")

# Library directories
link_directories("${CMAKE_SOURCE_DIR}/wxWidgets/lib/vc_x64_dll/$(Configuration)" "%(AdditionalLibraryDirectories)" "${CMAKE_SOURCE_DIR}/wxWidgets/lib/vc_x64_dll")

# Preprocessor definitions
# add_definitions(-DCMAKE_INTDIR="Release" -DCMAKE_INTDIR="Debug" -DNDEBUG -DCMAKE_INTDIR="MinSizeRel" -D%(PreprocessorDefinitions) -D_WINDOWS -DWXUSINGDLL -DCMAKE_INTDIR="RelWithDebInfo" -DWIN32)
add_definitions(
    -DWIN32
    -D_WINDOWS
    -DCMAKE_INTDIR=\"Debug\"
    -DWXUSINGDLL
)
if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /SUBSYSTEM:WINDOWS")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /SUBSYSTEM:WINDOWS")
endif()


# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

# Source files
set(SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp" "${CMAKE_SOURCE_DIR}/src/P4Projekt.cpp")
set(HEADER_FILES )

# Add executable
add_executable(UITest ${SOURCE_FILES} ${HEADER_FILES})

# Link libraries
target_link_libraries(UITest "gdi32.lib" "ole32.lib" "comdlg32.lib" "${CMAKE_SOURCE_DIR}/wxWidgets/lib/vc_x64_dll/wxmsw32u_core.lib" "winspool.lib" "shell32.lib" "uuid.lib" "advapi32.lib" "user32.lib" "${CMAKE_SOURCE_DIR}/wxWidgets/lib/vc_x64_dll/wxbase32u.lib" "oleaut32.lib" "kernel32.lib")
