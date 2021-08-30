cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(graphicseditordemo VERSION ${PROJECT_VESRION})

add_executable(graphicseditordemo
    common/point.cpp
    common/rect.cpp
    common/utils.cpp
    editor/editor.cpp
    editor/ellipse.cpp
    editor/graphicsitem.cpp
    editor/line.cpp
    editor/selectablegraphicsitem.cpp
    editor/serializablegraphicsitem.cpp
    gui/gui.cpp
    gui/textmodeui/textmodecanvas.cpp
    gui/textmodeui/textmodeui.cpp
    main.cpp
    serialize/documentreader.cpp
    serialize/documentwriter.cpp
    serialize/serializerfactory.cpp
    serialize/simpleserializer/simpledocumentreader.cpp
    serialize/simpleserializer/simpledocumentwriter.cpp
    serialize/simpleserializer/simpleserializerfactory.cpp
)

set_target_properties(graphicseditordemo PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

if (MSVC)
    target_compile_options(graphicseditordemo PRIVATE
        /W4
    )
else ()
    target_compile_options(graphicseditordemo PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


install(TARGETS graphicseditordemo RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)