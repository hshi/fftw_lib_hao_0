#include <iostream>
#include <iomanip>
#include "fftw_hao.h"
using namespace std;

void FFTServer_void_construction_test()
{
    int dimen=1;
    int n[1]={1};
    int L=1;
    FFTServer fft;
    size_t flag=0;
    if(fft.dimen!=dimen) flag++;
    for(int i=0; i<dimen; i++) {if(fft.n[i]!=n[i]) flag++;}
    if(fft.L!=L) flag++;
    if(flag==0) cout<<"FFTServer passed the void construction test!\n";
    else cout<<"Warning!!!! FFTServer failed the void construction test!\n";
}

void FFTServer_param_construction_test()
{
    int dimen=3;
    int n[3]={2,3,6};
    int L=36;
    FFTServer fft(dimen,n,'R');
    size_t flag=0;
    if(fft.dimen!=dimen) flag++;
    for(int i=0; i<dimen; i++) {if(fft.n[i]!=n[i]) flag++;}
    if(fft.L!=L) flag++;
    if(flag==0) cout<<"FFTServer passed the param construction test!\n";
    else cout<<"Warning!!!! FFTServer failed the param construction test!\n";
}

void FFTServer_equal_construction_test()
{
    int dimen=3;
    int n[3]={2,3,6};
    int L=36;
    FFTServer fft_tmp(dimen,n,'R');
    FFTServer fft(fft_tmp);
    size_t flag=0;
    if(fft.dimen!=dimen) flag++;
    for(int i=0; i<dimen; i++) {if(fft.n[i]!=n[i]) flag++;}
    if(fft.L!=L) flag++;
    if(flag==0) cout<<"FFTServer passed the equal construction test!\n";
    else cout<<"Warning!!!! FFTServer failed the equal construction test!\n";
}

void FFTServer_equal_test()
{
    int dimen=3;
    int n[3]={2,3,6};
    int L=36;
    FFTServer fft_tmp(dimen,n, 'R');
    FFTServer fft; fft=fft_tmp;
    size_t flag=0;
    if(fft.dimen!=dimen) flag++;
    for(int i=0; i<dimen; i++) {if(fft.n[i]!=n[i]) flag++;}
    if(fft.L!=L) flag++;
    if(flag==0) cout<<"FFTServer passed the equal test!\n";
    else cout<<"Warning!!!! FFTServer failed the equal test!\n";
}

void four_1D_test()
{
    int dimen=1;
    int n[1]={3};
    FFTServer fft(dimen,n, 'R');
    complex<double> a[3]={{1,2},{2,3},{3,4}};
    complex<double>* b;
    complex<double> bforw_exact[3]={{6.,9.},{-2.366025403784438,-0.6339745962155598},{-0.6339745962155603,-2.366025403784437}};
    complex<double> bback_exact[3]={{6.,9.},{-0.6339745962155603,-2.366025403784437},{-2.366025403784438,-0.6339745962155598}};
    size_t flag=0;
   
    b=fft.fourier_forw(a);
    for(int i=0; i<3; i++) {if(abs(b[i]-bforw_exact[i])>1e-12) flag++;}
    b=fft.fourier_back(a);
    for(int i=0; i<3; i++) {if(abs(b[i]-bback_exact[i])>1e-12) flag++;}
    if(flag==0) cout<<"FFTServer passed the 1D fourier test!\n";
    else cout<<"Warning!!!! FFTServer failed the 1D fourier test!\n";
}

void four_2D_test()
{
    int dimen=2;
    int n[2]={2,3};
    FFTServer fft(dimen,n, 'R');
    complex<double> a[6]={{1,2},{2,3},{3,4},{2,2},{1,3},{3,2}};
    complex<double>* b;
    complex<double> bforw_exact[6]={{12.,16.},{-1.4999999999999987, 0.5980762113533187},{-1.4999999999999982,-4.598076211353313}, 
                                    {0., 2. },{-3.2320508075688763,-1.8660254037844366},{0.23205080756887897,-0.1339745962155594}};
    complex<double> bback_exact[6]={{12.,16.},{-1.4999999999999982,-4.598076211353313}, {-1.4999999999999987, 0.5980762113533187},
                                    {0., 2. },{0.23205080756887897,-0.1339745962155594},{-3.2320508075688763,-1.8660254037844366}};
    size_t flag=0;
   
   
    b=fft.fourier_forw(a);
    for(int i=0; i<6; i++) {if(abs(b[i]-bforw_exact[i])>1e-12) flag++;}
    b=fft.fourier_back(a);
    for(int i=0; i<6; i++) {if(abs(b[i]-bback_exact[i])>1e-12) flag++;}
    if(flag==0) cout<<"FFTServer passed the 2D fourier test!\n";
    else cout<<"Warning!!!! FFTServer failed the 2D fourier test!\n";
    //cout<<flag<<endl;
    //for(int i=0; i<6; i++) cout<<b[i]<<"\n";
}

void fftw_hao_test()
{
    FFTServer_void_construction_test();
    FFTServer_param_construction_test();
    FFTServer_equal_construction_test();
    FFTServer_equal_test();
    four_1D_test();
    four_2D_test();
}
