include_directories(
  ${server_common_include_dirs}
  ${PROJECT_SOURCE_DIR}/include/platform
  ${PROJECT_SOURCE_DIR}/include/client
  ../..
)

include_directories(
    ${DRM_INCLUDE_DIRS}
    ${EGL_INCLUDE_DIRS}
    ${GL_INCLUDE_DIRS}
    ${UDEV_INCLUDE_DIRS}
)

add_library(
  mirplatformgraphicsmesax11objects OBJECT

  platform.cpp
  display.cpp
  display_configuration.cpp
  display_buffer.cpp
  egl_helper.cpp
)

add_library(
  mirplatformgraphicsmesax11objects-symbols OBJECT

  graphics.cpp
)
