

// 		             k;double sin()
// 		         ,cos();main(){float A=
// 		       0,B=0,i,j,z[1760];char b[
// 		     1760];printf("\x1b[2J");for(;;
// 		  ){memset(b,32,1760);memset(z,0,7040)
// 		  ;for(j=0;6.28>j;j+=0.07)for(i=0;6.28
// 		 >i;i+=0.02){float c=sin(i),d=cos(j),e=
// 		 sin(A),f=sin(j),g=cos(A),h=d+2,D=1/(c*
// 		 h*e+f*g+5),l=cos      (i),m=cos(B),n=s\
// 		in(B),t=c*h*g-f*        e;int x=40+30*D*
// 		(l*h*m-t*n),y=            12+15*D*(l*h*n
// 		+t*m),o=x+80*y,          N=8*((f*e-c*d*g
// 		 )*m-c*d*e-f*g-l        *d*n);if(22>y&&
// 		 y>0&&x>0&&80>x&&D>z[o]){z[o]=D;;;b[o]=
// 		 ".,-~:;=!*#$@"[N>0?N:0];}}/*#****!!-*/
// 		  printf("\x1b[H");for(k=0;1761>k;k++)
// 		   putchar(k%80?b[k]:10);A+=0.04;B+=
// 		     0.02;}}/*****####*******!!=;:~
// 		       ~::==!!!**********!!!==::-
// 		         .,~~;;;========;;;:~-.
// 		             ..,--------,*/



#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define R(mul,shift,x,y) \
  _=x; \
  x -= mul*y>>shift; \
  y += mul*_>>shift; \
  _ = 3145728-x*x-y*y>>11; \
  x = x*_>>10; \
  y = y*_>>10;

int8_t b[1760], z[1760];

void main() {
  int sA=1024,cA=0,sB=1024,cB=0,_;
  for (;;) {
    memset(b, 32, 1760);  // text buffer
    memset(z, 127, 1760);   // z buffer
    int sj=0, cj=1024;
    for (int j = 0; j < 90; j++) {
      int si = 0, ci = 1024;  // sine and cosine of angle i
      for (int i = 0; i < 324; i++) {
        int R1 = 1, R2 = 2048, K2 = 5120*1024;

        int x0 = R1*cj + R2,
            x1 = ci*x0 >> 10,
            x2 = cA*sj >> 10,
            x3 = si*x0 >> 10,
            x4 = R1*x2 - (sA*x3 >> 10),
            x5 = sA*sj >> 10,
            x6 = K2 + R1*1024*x5 + cA*x3,
            x7 = cj*si >> 10,
            x = 40 + 30*(cB*x1 - sB*x4)/x6,
            y = 12 + 15*(cB*x4 + sB*x1)/x6,
            N = (-cA*x7 - cB*((-sA*x7>>10) + x2) - ci*(cj*sB >> 10) >> 10) - x5 >> 7;

        int o = x + 80 * y;
        int8_t zz = (x6-K2)>>15;
        if (22 > y && y > 0 && x > 0 && 80 > x && zz < z[o]) {
          z[o] = zz;
          b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
        }
        R(5, 8, ci, si)  // rotate i
      }
      R(9, 7, cj, sj)  // rotate j
    }
    for (int k = 0; 1761 > k; k++)
      putchar(k % 80 ? b[k] : 10);
    R(5, 7, cA, sA);
    R(5, 8, cB, sB);
    usleep(15000);
    printf("\x1b[23A");
  }
}



// 		             k;double sin()
// 		         ,cos();main(){float A=
// 		       0,B=0,i,j,z[1760];char b[
// 		     1760];printf("\x1b[2J");for(;;
// 		  ){memset(b,32,1760);memset(z,0,7040)
// 		  ;for(j=0;6.28>j;j+=0.07)for(i=0;6.28
// 		 >i;i+=0.02){float c=sin(i),d=cos(j),e=
// 		 sin(A),f=sin(j),g=cos(A),h=d+2,D=1/(c*
// 		 h*e+f*g+5),l=cos      (i),m=cos(B),n=s\
// 		in(B),t=c*h*g-f*        e;int x=40+30*D*
// 		(l*h*m-t*n),y=            12+15*D*(l*h*n
// 		+t*m),o=x+80*y,          N=8*((f*e-c*d*g
// 		 )*m-c*d*e-f*g-l        *d*n);if(22>y&&
// 		 y>0&&x>0&&80>x&&D>z[o]){z[o]=D;;;b[o]=
// 		 ".,-~:;=!*#$@"[N>0?N:0];}}/*#****!!-*/
// 		  printf("\x1b[H");for(k=0;1761>k;k++)
// 		   putchar(k%80?b[k]:10);A+=0.04;B+=
// 		     0.02;}}/*****####*******!!=;:~
// 		       ~::==!!!**********!!!==::-
// 		         .,~~;;;========;;;:~-.
// 		             ..,--------,*/
