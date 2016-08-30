set(src_lib fftwhao)

set(srcs
        ../inc/fftw_define.h
        ../inc/fftw_hao.h
        fftw_hao.cpp
   )

add_library(${src_lib} STATIC ${srcs})

install(TARGETS ${src_lib}  DESTINATION lib)
