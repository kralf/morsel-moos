remake_file_configure(Doxygen.h.remake)
remake_add_documentation(
  DOXYGEN Doxyfile.remake
  INPUT ${REMAKE_PROJECT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
)
