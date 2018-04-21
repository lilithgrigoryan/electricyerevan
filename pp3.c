#include <stdio.h>
#include <math.h>
#define N 6

int a[N][N],m;
int temp[N][N];
float reverse[N][N];

int determinant(int f[N][N], int x)
{
  int pr,c[N],d=0,b[N][N],j,p,q,t;
	if(x==1) return f[1][1];
  if(x==2)
  {
    d=0;
    d=(f[1][1]*f[2][2])-(f[1][2]*f[2][1]);
    return(d);
   }
  else
  {
    for(j=1;j<=x;j++)
    {        
      int r=1,s=1;
      for(p=1;p<=x;p++)
        {
          for(q=1;q<=x;q++)
            {
              if(p!=1&&q!=j)
              {
                b[r][s]=f[p][q];
                s++;
                if(s>x-1)
                 {
                   r++;
                   s=1;
                  }
               }
             }
         }
     for(t=1,pr=1;t<=(1+j);t++)
     pr=(-1)*pr;
     c[j]=pr*determinant(b,x-1);
     }
     for(j=1,d=0;j<=x;j++)
     {
       d=d+(f[1][j]*c[j]);
      }
     return(d);
   }
}

int algebrDop(int temp[N][N], int a[N][N], int x, int i, int j){
	int p=1, q=1;
	int mk=0;
	if(((i+j)%2) != 0) mk=-1;
	else mk =1; 
	for(int k=1; k<=x; k++){
		if(k!=i){
			for(int l=1; l<=x; l++){
				if(l!=j){
				temp[p][q]= a[k][l];
				//printf("\n%d   ", temp[p][q]);
				q++;
				}
			}
			q=1;
			p++;
		}
	}
	int det = determinant(temp,x-1);
	//printf("\nalgdop=%d \n", determinant(temp,x-1));
	return mk*det;
}

int main()
{
	int i,j;
	printf("Enter order of matrix : ");
	scanf("%d",&m);
	printf("\nEnter the elements of matrix\n");
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			printf("a[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n\n---------- Matrix A is --------------\n");    
	for(i=1;i<=m;i++){
		printf("\n");
		for(j=1;j<=m;j++){     
			printf("%5d",a[i][j]);
		}
	}

	int d=determinant(a,m);
	printf("\n\n");
	printf("\n Determinant of Matrix A is %d .",d);
	printf("\n\n");

	int det=0;
	if(d!=0){
		for(i=1; i<=m; i++){
			for(j=1; j<=m; j++){
				det = algebrDop(temp, a, m, i, j);
				reverse[i][j]=det/d;
			}
		}
		printf("The inverse for matrix A is. ");
		for(i=1;i<=m;i++){
			printf("\n");
			for(j=1;j<=m;j++){     
				printf("%.1f  ",reverse[j][i]);
			}
		}
	}
}
