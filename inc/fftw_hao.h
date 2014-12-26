#ifndef FFTW_HAO
#define FFTW_HAO

#include "fftw_define.h"

class FFTServer
{
 int  dimen;
 int* n;
 int  L;
 std::complex<double>* inforw;
 std::complex<double>* outforw;
 std::complex<double>* inback;
 std::complex<double>* outback;
 fftw_plan planforw;
 fftw_plan planback;
 public:
 FFTServer();
 FFTServer(int Dc, const int* Nc);
 FFTServer(const FFTServer& x);
 ~FFTServer();

 FFTServer& operator  = (const FFTServer& x);

 std::complex<double>* fourier_forw(const std::complex<double>* inarray);
 std::complex<double>* fourier_back(const std::complex<double>* inarray);

 friend void FFTServer_void_construction_test();
 friend void FFTServer_param_construction_test();
 friend void FFTServer_equal_construction_test();
 friend void FFTServer_equal_test();
};

#endif
