cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Qml
)
find_package(Qt6Core REQUIRED COMPONENTS Private)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON) # This is to find generated *.moc and *.h files in build dir

option(BUILD_STATIC "Compile static libraries" ${EMSCRIPTEN})

if (BUILD_STATIC)
    add_library(SortFilterProxyModel STATIC "")
else()
    add_library(SortFilterProxyModel SHARED "")
endif()

target_sources(SortFilterProxyModel PRIVATE
    qqmlsortfilterproxymodel.cpp
    qvariantlessthan.cpp
    filters/filter.cpp
    filters/filtercontainer.cpp
    filters/rolefilter.cpp
    filters/valuefilter.cpp
    filters/indexfilter.cpp
    filters/regexpfilter.cpp
    filters/rangefilter.cpp
    filters/expressionfilter.cpp
    filters/filtercontainerfilter.cpp
    filters/anyoffilter.cpp
    filters/alloffilter.cpp
    filters/filtersqmltypes.cpp
    sorters/sorter.cpp
    sorters/sortercontainer.cpp
    sorters/rolesorter.cpp
    sorters/stringsorter.cpp
    sorters/expressionsorter.cpp
    sorters/sortersqmltypes.cpp
    proxyroles/proxyrole.cpp
    proxyroles/proxyrolecontainer.cpp
    proxyroles/joinrole.cpp
    proxyroles/switchrole.cpp
    proxyroles/expressionrole.cpp
    proxyroles/proxyrolesqmltypes.cpp   
    proxyroles/singlerole.cpp   
    proxyroles/regexprole.cpp
    sorters/filtersorter.cpp
    proxyroles/filterrole.cpp
    upstream/qsortfilterproxymodel.cpp
    qqsfpm_global.h
)

target_link_libraries(SortFilterProxyModel
    PRIVATE
        Qt::CorePrivate
    PUBLIC
        Qt::Core
        Qt::Qml
)

target_compile_definitions(SortFilterProxyModel
    PRIVATE
        QQSFPM_LIBRARY
)

if ((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))
    target_compile_options(SortFilterProxyModel PUBLIC "/Zc:__cplusplus")
endif()
