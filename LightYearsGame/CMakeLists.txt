add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}

    src/main.cpp

)

target_link_libraries(
	${LIGHT_YEARS_GAME_TARGET_NAME}
	PUBLIC
	${LIGHT_YEARS_ENGINE_TARGET_NAME}
)