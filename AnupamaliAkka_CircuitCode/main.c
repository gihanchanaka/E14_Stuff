#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float inverse[25][25];
int main()
{
    int NL;
    int NE;
    int loop[NL];
    char branch[NE];
    char type[NE];
    float value[NE];
    char answer;
    int i;
    int presance[NE][NL];
    float voltagedrops[NL];
    float resistor[NL][NL];
     float I[NL];

    printf("Do you want to continue:   ");
    scanf("%s",&answer);
    printf("Enter the number of loop:    ");
    scanf("%d",&NL);
     printf("enter the number of elements:  ");
    scanf("%d",&NE);
i=0;
while (answer=='y')
{
    for (i=0 ; i<NL ; i++ ){
      int loopnumber;
      char branch[1];
      char type[1];
      float valueread;


      printf("enter the loop number: ");
      scanf("%d",&loopnumber);
      printf("enter the  branch: ");
      scanf("%s",&branch);
      printf("resistor or voltage: ");
      scanf("%s",&type);
      printf("enter value: ");
      scanf("%lf",&valueread);


      loopnumber--;
      int branchnumber=branch-'A';
      value[branchnumber]=valueread;
      type[branchnumber]=type;
      presance[branchnumber][loopnumber]=1;
      i++;
      printf("Do you want to continue");
      scanf("%s",&answer);
    }
}
     int x,y,z;
         for ( x=0;x<NE ;x++){
                if (type[x]=='v'){
                        for( y=0 ; y<NL ;y++){
                                if(presance[x][y]==1){
                                        voltagedrops[y]+=value[x];
                                }
                        }
                }
         }
         for(x=0;x<NL;x++){
            if(type[x]=='R'){
                for(y=0;y<NL;y++){
                    if (presance[x][y]==1){
                        resistor[y][y]+=value[x];
                        for( z=0;z<NL;z++){
                            if(y!=z){
                                if (presance[x][z]==1){
                                    resistor[y][z]+=value[x];
                                    resistor[z][y]+=value[x];
                                }
                            }
                        }
                    }
                }
            }
         }



for (x=0;x<NL;x++){
     float sum=0;
    for(y=;y<NL;y++){
        sum+=inverse[x][y]*voltagedrops[y];
    }
    I[x]=sum;
    printf("the current is %lf  ",I[x]);
}
int m(G,NL){



	G=resistor[NL][NL];
	VolatgeDrops[NL];


}



float determinant(float [][25], float);
void cofactor(float [][25], float);
void transpose(float [][25], float [][25], float);

int m(float resistor[NL][NL],int NL)
{
  d = determinant(G, NL);
  if (d == 0)
   printf("\nInverse of Entered Matrix is not possible\n");
  else
   cofactor(G, NL);

  return 0;

}

/*For calculating Determinant of the Matrix */
float determinant(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }

    return (det);
}

void cofactor(float num[25][25], float f)
{
 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f);
}
/*Finding transpose of matrix*/
void transpose(float num[25][25], float fac[25][25], float r)
{
  int i, j;
  float b[25][25],  d;

  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }

}
    return 0;
}
