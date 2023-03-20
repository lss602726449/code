#include <iostream>
#include <xmmintrin.h>
#include <time.h>
#include <windows.h>
#include <mutex>
#include <condition_variable>
using namespace std;

__attribute__((aligned(16))) float A[] = {1.0f, 2.0f, 3.0f, 4.0f};
__attribute__((aligned(16))) float B[] = {3.0f, 4.0f, -1.0f, 2.0f};
__attribute__((aligned(16))) float C[] = {0.0f, 0.0f, 0.0f, 0.0f};

int main()
{   
    int n = 1000000;
    std::mutex mtx1;
    std::condition_variable cv;
    float a1[] = {1.0f, 2.0f, 3.0f, 4.0f};
    float b1[] = {3.0f, 4.0f, -1.0f, 2.0f};
    float c1[] = {0.0f, 0.0f, 0.0f, 0.0f};
    LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime, nEndTime;
	double time = 0;
	QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);
    for(int i=0; i<n; i++){
        //load to reg
        __m128 a = _mm_load_ps(&A[0]);
        __m128 b = _mm_load_ps(&B[0]);
        //calculate
        __m128 c = _mm_mul_ps(a, b);
        //store result to C array
        _mm_store_ps(&C[0], c);
    }
    QueryPerformanceCounter(&nEndTime);
    cout<<"time = "<<(double)(nEndTime.QuadPart - nBeginTime.QuadPart) * 1000 / (double)nFreq.QuadPart<<"ms"<<endl;  //输出时间（单位：ｓ）
    QueryPerformanceCounter(&nBeginTime);
    for(int i=0; i<n; i++){
        for(int i=0; i<4; i++){
            c1[i] = a1[i] + b1[i];
        }
    }
    QueryPerformanceCounter(&nEndTime);
    cout<<"time = "<<(double)(nEndTime.QuadPart - nBeginTime.QuadPart) * 1000 / (double)nFreq.QuadPart<<"ms"<<endl;  //输出时间（单位：ｓ）
    // std::cout << "result:" << C[0] << " " << C[1] << " " << C[2] << " " << C[3] << std::endl;
    return 0;
}
