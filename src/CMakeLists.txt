set(NAME exec)

add_executable(${NAME})

target_link_libraries(${NAME}
    PRIVATE
    gfx
)

target_sources(${NAME}
    PRIVATE
    main.cpp
    Window.cpp 
    State.cpp 

    include/State.hpp
    include/Window.hpp
)

target_include_directories(${NAME}
    PRIVATE
    include/
)

add_custom_target(${NAME}.run
    COMMAND ${CMAKE_EXECUTE_PROCESS_COMMAND_ECHO}
    ${NAME}
    DEPENDS ${NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    USES_TERMINAL
)

add_custom_command(TARGET ${NAME} PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:${NAME}>/res/)