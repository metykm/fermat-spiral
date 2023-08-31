#include "immintrin.h"
#include <stdio.h>
#include <stdint.h>
#define _GNU_SOURCE
#include <math.h>


/*Branche + / - */

__m256  _ZGVcN8v_sinf(__m256 x);
__m256  _ZGVcN8v_cosf(__m256 x);

typedef struct spiral {
  __m256 viv, vivx, vivsq, va, vax, vasq;
  __m256 x, y, r0, r1, a, b;


 } spiral;



void a(){

    spiral sx;

    sx.vivx = _mm256_set_ps(2.0f, 4.0f, 8.0f, 16.0f, 32.0f, 64.0f, 128.0f, 256.0 );
    sx.viv = _ZGVcN8v_cosf(sx.vivx);
    sx.vivsq = _mm256_sqrt_ps(sx.vivx);
    sx.x = _mm256_mul_ps(sx.viv , sx.vivsq);

   printf("%12.8f x  %12.8f x %12.8f x  %12.8f x %12.8f x %12.8f x %12.8f x %12.8f x    \n   ",  sx.x[1], sx.x[2], sx.x[3], sx.x[4], sx.x[5], sx.x[6] + 1, sx.x[7], sx.x[0]);
}

void b(){

    spiral sx;

    sx.vax = _mm256_set_ps(2.0f, 4.0f, 8.0f, 16.0f, 32.0f, 64.0f, 128.0f, 256.0f);
    sx.va = _ZGVcN8v_sinf(sx.vax);
    sx.vasq = _mm256_sqrt_ps(sx.vax);
    sx.y = _mm256_mul_ps(sx.va , sx.vasq);


    printf("%12.8f y  %12.8f y %12.8f y  %12.8f y %12.8f y %12.8f y %12.8f y %12.8f y    \n   ",  sx.y[1], sx.y[2], sx.y[3], sx.y[4], sx.y[5], sx.y[6], sx.y[7], sx.y[0]);
}

void c() {


    spiral sx;


    sx.a = _mm256_sqrt_ps(sx.y);

    sx.r0 = _mm256_mul_ps(sx.x, sx.x);
    sx.r1 = _mm256_mul_ps(sx.y, sx.y);

    sx.va = _mm256_add_ps(sx.r1, sx.r0);

    sx.b = _mm256_sqrt_ps(sx.va);


   sx.a = _mm256_mul_ps(sx.b, sx.a);

   sx.a = _mm256_div_ps(sx.a, sx.y); // r * sqrt k / k
   sx.a = _mm256_mul_ps(sx.a, sx.a);


   sx.r0 = _ZGVcN8v_cosf(sx.va);
   sx.r1 = _ZGVcN8v_sinf(sx.a);


   sx.r1 = _mm256_div_ps(sx.r0, sx.r1);


   printf("cot %12.8f slope  %12.8f  %12.8f   %12.8f  %12.8f  %12.8f  %12.8f  %12.8f slope    \n   ",  sx.r1[1], sx.r1[2], sx.r1[3], sx.r1[4], sx.r1[5] , sx.r1[6], sx.r1[7], sx.r1[0]);


}

void main(){

 spiral sx;

 a();
 b();
 c();
}
