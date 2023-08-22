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
  __m256 x, y, r0, r1, b, a;


 } spiral;


/*  
residue_narrow_t x = {
    .branch = {
      0x14e8b6e, 0x3553e74, 0x0464e4c, 0x61de408,
      0x006a30e, 0x6e9b25b, 0x3e6f39e, 0x19ec754,
      0x5c71cc3, 0x2bc1c0e, 0x554338e, 0x14e8b6e,
    },
  };
Add the limbs sx.vivx*/

void a(){

    spiral sx;

    sx.vivx = _mm256_set_ps(2.0f, 4.0f, 8.0f, 16.0f, 32.0f, 64.0f, 128.0f, 256.0 );
    sx.viv = _ZGVcN8v_cosf(sx.vivx);
    sx.vivsq = _mm256_sqrt_ps(sx.vivx);
    sx.x = _mm256_mul_ps(sx.viv , sx.vivsq);


    printf("%12.8f x %12.8f x \n", sx.x[2], sx.x[3]);
}

void b(){

    spiral sx;

    sx.vax = _mm256_set_ps(2.0f, 4.0f, 8.0f, 16.0f, 32.0f, 64.0f, 128.0f, 256.0f);
    sx.va = _ZGVcN8v_sinf(sx.vax);
    sx.vasq = _mm256_sqrt_ps(sx.vax);
    sx.y = _mm256_mul_ps(sx.va , sx.vasq);

    printf("%12.8f y %12.8f y \n", sx.y[2], sx.y[3]);
}

void c() {


    spiral sx;

 

    sx.r0 = _mm256_mul_ps(sx.x, sx.x);
    sx.r1 = _mm256_mul_ps(sx.y, sx.y);

    sx.a = _mm256_mul_ps(sx.a, sx.a);
    sx.b = _mm256_add_ps(sx.r0, sx.r1);

   printf("%12.8f c, %12.8f c \n", sx.b[2], sx.b[3]);

   sx.r0 = _mm256_div_ps(sx.b, sx.a);

   sx.r0 = _ZGVcN8v_cosf(sx.r0);
   sx.r1 = _ZGVcN8v_sinf(sx.r0);

   sx.a = _mm256_div_ps(sx.r0, sx.r1);

   printf("slope: %12.8f \n", sx.a[0]);
}

void main(){

 spiral sx;

 a();
 b();
 c();
}
