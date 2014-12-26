set(fftw_test_srcs fftw_hao_test.cpp test_all.cpp)

add_executable(fftwtest ${fftw_test_srcs})

target_link_libraries(fftwtest fftwhao)

target_link_libraries(fftwtest ${fftw_lib})

install(TARGETS fftwtest  DESTINATION test)
