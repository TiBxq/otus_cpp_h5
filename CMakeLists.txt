cmake_minimum_required(VERSION 3.2)

project(editor VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
#project(editor VERSION 0.0.1)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(editor editor.cpp EditorManager.h EditorManager.cpp Document.h Document.cpp Shape.h Logger.h)
add_executable(editor_test editor_test.cpp)

set_target_properties(editor_test PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON 
)

set_target_properties(editor PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON 
)

target_include_directories(editor_test
    PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(editor_test
    ${GTEST_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

if (MSVC)
    target_compile_options(editor PRIVATE
        /W4
    )
    target_compile_options(editor_test PRIVATE
        /W4
    )
else ()
    target_compile_options(editor PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(editor_test PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example.example@gmail.com)

include(CPack)

enable_testing()

add_test(editor_test editor_test)