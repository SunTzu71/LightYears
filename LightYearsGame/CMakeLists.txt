add_executable(${LIGHT_YEARS_TARGET_NAME} src/main.cpp
        src/framework/Application.cpp)

target_include_directories(${LIGHT_YEARS_TARGET_NAME} PUBLIC
       ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${LIGHT_YEARS_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${LIGHT_YEARS_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${LIGHT_YEARS_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${LIGHT_YEARS_TARGET_NAME} PUBLIC sfml-audio)

add_custom_command(
        TARGET ${LIGHT_YEARS_TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:sfml-graphics>
        $<TARGET_FILE_DIR:${LIGHT_YEARS_TARGET_NAME}>
)
add_custom_command(
        TARGET ${LIGHT_YEARS_TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:sfml-window>
        $<TARGET_FILE_DIR:${LIGHT_YEARS_TARGET_NAME}>
)
add_custom_command(
        TARGET ${LIGHT_YEARS_TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:sfml-system>
        $<TARGET_FILE_DIR:${LIGHT_YEARS_TARGET_NAME}>
)
add_custom_command(
        TARGET ${LIGHT_YEARS_TARGET_NAME}
        POST_BUILD
        COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:sfml-audio>
        $<TARGET_FILE_DIR:${LIGHT_YEARS_TARGET_NAME}>
)