cmake_minimum_required(VERSION 3.12)
project(memstore)

set(CMAKE_C_STANDARD 11)

# Add your source files here
set(SOURCES
    src/main.c
    src/utils.c
    src/store.c
    src/persist.c
    src/test.c
)

# Add your header files here
set(HEADERS
)

# Add any additional libraries here
set(LIBRARIES
    # Example: pthread
)

# Add any additional include directories here
set(INCLUDE_DIRS
    include
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link any additional libraries
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

# Add any additional include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})