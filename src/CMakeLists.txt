# Credit to Jonathan Hamberg for the FetchContent code	#
# https://jonathanhamberg.com/				#
# https://github.com/Jonathan-Hamberg/			#

# === Fetching GLFW3 ===

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
)

FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL TRUE CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()
  
# === Fetching GLAD ===

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
)

FetchContent_GetProperties(glad)
if(NOT glad_POPULATED)
    FetchContent_Populate(glad)
    set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
    set(GLAD_API "gl=" CACHE STRING "API type/version pairs, like \"gl=3.2,gles=\", no version means latest")
    set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")
    add_subdirectory(${glad_SOURCE_DIR} ${glad_BINARY_DIR})
endif()

# === Fetching GLM ===

FetchContent_Declare(glm           
  GIT_REPOSITORY https://github.com/g-truc/glm.git                  
)

FetchContent_MakeAvailable(glm)

# === === === === === ===

add_executable(
    demo 
  
    main.cc
)

target_compile_definitions(demo PUBLIC -DGLFW_INCLUDE_NONE)
target_link_options(demo PUBLIC -static)

target_include_directories(
    demo 
PRIVATE
    "src/"
PUBLIC
    ${glfw_SOURCE_DIR}/include
    ${glad_SOURCE_DIR}/include
    ${glm_SOURCE_DIR}/glm
)

target_link_libraries(
    demo 
PRIVATE
    glfw
    glad
    glm
)
