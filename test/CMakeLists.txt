set(test_exe fftwtest)

set(test_srcs
        ../inc/fftw_define.h
        ../inc/fftw_hao.h
        fftw_hao_test.cpp
        test_all.cpp
   )

add_executable(${test_exe} ${test_srcs})

target_link_libraries(${test_exe} fftwhao ${lib_all})

install(TARGETS ${test_exe}  DESTINATION test)