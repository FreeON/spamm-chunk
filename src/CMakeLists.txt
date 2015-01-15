add_library( chunk-C
  chunk.c
  chunk_block.c
  chunk_tiled.c
  chunk_tree.c
  chunk_mic.c
  chunk_mic.h
  lapack_interface.h
  matrix_4x4.S
  )
set_target_properties( chunk-C
  PROPERTIES
  COMPILE_FLAGS "${STDC} ${OpenMP_C_FLAGS} ${MIC_CFLAGS}"
  LINK_FLAGS "${MIC_LDFLAGS}" )

add_library( chunk-F
  chunk_config.F90
  chunk_types.F90
  spamm_chunk.F90
  )
target_compile_definitions( chunk-F
  PUBLIC
  "CONFIG_BLOCK_SIZE=${CONFIG_BLOCK_SIZE}"
  "CONFIG_CHUNK_SIZE=${CONFIG_CHUNK_SIZE}"
  "REAL_KIND_EXPRESSION=${REAL_KIND_EXPRESSION}"
  )

include_directories( ${CMAKE_BINARY_DIR} )

set( headers
  chunk.h
  chunk_block.h
  chunk_tiled.h
  chunk_tree.h
  )

install( TARGETS chunk-C
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib )
install( FILES ${headers}
  DESTINATION include )
