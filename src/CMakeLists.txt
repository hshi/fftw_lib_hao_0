set(fftw_srcs fftw_hao.cpp)

add_library(fftwhao STATIC ${fftw_srcs})

install(TARGETS fftwhao  DESTINATION lib)
