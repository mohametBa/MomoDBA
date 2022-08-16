#include <stdio.h>
#include <math.h>

typedef int vect[10];
double varred(double x0, double h, double x);
double newton_poly(double *Delta, int n, double u); 
void lecture (vect x, vect y, int *i);
void Leverrier(double *X, int n, double *a);
double dichotomie( double *px, double *py, int n, double alpha, double x );
float lag(vect Px,vect Py,int pn,float palfa);

void lecture (vect x, vect y, int *i)
{	
double **Y;
int k;
double n=10;
double N=2;
FILE *F;
int *p;
Y=(double**)malloc(n*sizeof(double*));
for(k=0;k<n;k++)
{
Y[k]=(double*)malloc(N*sizeof(double));
}



	F = fopen("projet_L2.txt","r");
	*i=0;
	while (!feof(F))
		{
			fscanf(F,"%f \t %f",&x[*i],&y[*i]);
			(*i)++;
		}
		*p=i;
		for(i=0;i<= *p; i++)
		{
			printf("%d %d \n", &x[*i],&y[*i]);
		}
		
	fclose(F);
for(k=0;k<n;k++)
{
free(Y[k]);
}
free(Y); 
}

double newton_poly(double *Delta, int n, double u)
{	
	double k;
 	double p;
 	int j;
 	p=Delta[0];
 	k=1;
 	for(j=1;j<n;j++)
  	{ 
    	k=k*(u-(j-1))/j;
    	p=p+k*Delta[j];
   	}
 return p;

}

double varred(double x0, double h, double x)
{	
	double u;
	printf("entrer les parametres :\n"); //Parametre du polynome
	scanf("%f","%f",&x0,&h);
	u = (x - x0)/h;
	return u;

}
void Leverrier(double *X, int n, double *a)
{
int i,j;
double *S,p; 
S = (double*)malloc((n+1)*sizeof(double));
for (i=0 ; i<n ; i++)	
{ 
 	p = X[i];
for (j=1 ; j<=n ; j++) 
{ 
	S[j] = S[j]+p;
	p = p*X[i];	
}
}
a[0]= 1;
for (i=1 ; i<=n ; i++)	
{ a[i] = 0;
for ( j=0 ; j<=i-1 ; j++ ) 
{ 
a[i] = a[i] - a[j]*S[i-j]; } a[i] = a[i]/i;
} 
free(S);
}

float lag(vect Px,vect Py,int pn,float palfa)
{

	int k,j;
	vect L;
	float P;
	for(k=0;k<=pn;k++)
	{
	L[k] =1;
		for(j=0;j<=pn;j++)
		{
			L[k] =1;
			if(j==k)
			{
				L[k] *= 1;
			}
			else
			{
				L[k]*=(palfa-Px[j])/(Px[k]-Px[k]);
			}
		}
		P += L[k]*Py[k];
	return P;
	}
}


double dichotomie( double *px, double *py, int n, double alpha, double x )
{	
double x0=(x0-alpha);
double x1=(x0+alpha);
double x2;
x2=(x0+x1)/2;
while ((x2-x1) < (2*0,00001))
{
	if (lag(Px,Py,pn,x0)*lag(Px,Py,pn,x2)<0)
	{
		x1=x1;
	}
	else 
	{
		x0=x2;
	}
}

  	return x2;
  	
}
int main (void)
{
	vect x0,y0;
 	int i,n,py0;
 	lecture(x0,y0,&n);
 	for(i=0;i<n;i++)
  	{ 
    	printf("%d %d \n",x0[i],y0[i]);
   	}
 	int Delta;

 	double y[10]={1,4,21,88,256};
 	double D[10];
 	double u;
 	printf("Point de calcul de u:");
 	scanf("%lf",&u);
 
 	double *px,*py;
 	py=(double*)malloc(10*sizeof(double));
 	px=(double*)malloc(10*sizeof(double));
 
 	double x1,h,x;
 	printf("saisir  x0   \n"); 
 	scanf("%lf",&x1);
 	printf("saisir   x  \n"); 
 	scanf("%lf",&x);
 	printf("saisir le pas\n"); 
 	scanf("%lf",&h);
 
 	diffinies(y,5,D);
 	printf("P=%lf \n",newton_poly(D,4,u));
 
 	free(py);
 	free(px);

return 0;
}





