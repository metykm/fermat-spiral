#include "immintrin.h"
#include <stdio.h>
#include <stdint.h>
#define _GNU_SOURCE
#include <math.h>


/* NIST B-409 Base x values, Base y values*/
/*add r = sqrt y + x */
__m256  _ZGVcN8v_sinf(__m256 x);
__m256  _ZGVcN8v_cosf(__m256 x);

typedef struct spiral {
  __m256 viv, vivsq, va, vasq;
  __m256 x, y;


 } spiral;


void a(){

    spiral sx;
    float f[8];

    sx.viv = _mm256_set_ps(0x0273c706, 0x81c364ba, 0xd2181b36, 0xdf4b4f40, 0x38514f1f, 0x5488d08f, 0x0158aa4f, 0xa7bd198d);
    sx.viv = _ZGVcN8v_cosf(sx.viv);
    sx.vivsq = _mm256_sqrt_ps(sx.viv);
    sx.x = _mm256_mul_ps(sx.viv , sx.vivsq);
    _mm256_storeu_ps(f, sx.x);

    printf("%12.8f %12.8f %12.8f %12.8f %12.8f %12.8f %12.8f %12.8f\n", f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
}

void b(){

    spiral sx;
    float f[8];

    sx.va = _mm256_set_ps(0xbb7996a7, 0x60794e54, 0x5603aeab, 0x8a118051, 0xdc255a86, 0x34e59703, 0xb01ffe5b, 0xf1771d4d);
    sx.va = _ZGVcN8v_sinf(sx.va);
    sx.vasq = _mm256_sqrt_ps(sx.va);
    sx.y = _mm256_mul_ps(sx.va , sx.vasq);
   _mm256_storeu_ps(f, sx.y);

    printf("%12.8f %12.8f %12.8f %12.8f %12.8f %12.8f %12.8f %12.8f\n", f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
}



int main(){

 spiral sx;

 a();
 b();
 return 0;
}
