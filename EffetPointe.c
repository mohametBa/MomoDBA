#include <stdio.h>
#include <stdlib.h>
#include <math.h>



#define dim 10  //On définit les dimensions de la matrice appelée ici M (voir ci-après)

typedef float mat[dim][dim]; // Définition de la matrice M qui est carrée

void entete();
void Bsup(mat M);
void GS1(mat M);
void planplan(mat M);
void GS2(mat M);
void planpointe(mat M);

void entete()
{
	int k;
	char x='#';
	
	printf("\n\n");
	
		for(k=0;k<20;k++)
		{
			printf("%c%c",x,x);
		}

	printf("\n\n");
	printf("PROJET NIVEAU B L3 EEA: EFFET DE POINTE\n");
	printf("Groupe TP 8\n");
	printf("Réalisé par les élèves suivants:\n");
	printf("Morland Marine\tBa Mohamet\tDe Mages Rachel\tFaqih Sara\n");
	printf("\n\n");

	for(k=0;k<20;k++)
	{
		printf("%c%c",x,x);
	}
		
	printf("\n\n");
}

void Bsup(mat M)   //Borne supérieur
{
  int c; //Déclaration des variables des colonnes
  float BSup;//Borne supérieure
  do
	{
	 printf("Donner la plus grande valeur du potentiel V\n");
     scanf("%f",&BSup);

	}while(BSup<=0);

    for(c=0;c<dim;c++)
    {
     M[0][c]=BSup;
    }

}

void GS1(mat M)
{
	int c,l,compteur=0;
	float x,y;
	float pre=1.e-8; //Maximum de précision pour un potentiel donné, erreur minimale

	do
	{
		y=0.;
  		for(l=1;l<dim-1;l++)
  
		{
    			for(c=0;c<dim;c++)
      			{
      				x=M[l][c];

					if(c==0)
          			{
            			M[l][c]=(M[l-1][c]+M[l+1][c]+M[l][c+1])/3;
         			}

          			if(c!=0 && c!=dim-1)
          			{
            			M[l][c]=(M[l-1][c]+M[l+1][c]+M[l][c+1]+M[l][c-1])/4;
          			}

          			if(c==dim-1)
          			{
            			M[l][c]=(M[l-1][c]+M[l+1][c]+M[l][c-1])/3;
          			}

        			y+=fabs(M[l][c]-x);
      			}

		} compteur+=1;
		
		printf("Le nombre de calculs effectués est de %d et l'erreur est de %f\n",compteur, y);

	}while(y>pre);
 
}

void Fichier(mat M)
{
	int l,c;
	
	FILE *F;
	F=fopen("Matrice.txt","w");

	for(l=0;l<dim;l++)
	{
		for(c=0;c<dim;c++)
		{
      		fprintf(F,"%f\t",M[l][c]);
      	}

		fprintf(F,"\n");
	}
}

void planplan(mat M)
{
	Bsup(M);
	GS1(M);
	Fichier(M);
}

void GS2(mat M)
{
	int c,l,ligne, compteur=0;
	float x,y, pre=1.e-8, a=(sqrt(2.5e-6)), b=5e-3;
  
	do
	{
		y=0;
  
		for(c=0;c<=dim-1;c++)
		{
			for(l=0;l<dim-1;l++)
			{
				x=M[l][c];
				ligne=sqrt(((dim-c)*a/b)*((dim-c)*a/b)-1);

          		if(c==0 && l>ligne)
          		{
           			M[l][c]=(M[l-1][c]+M[l+1][c]+M[l][c+1])/3;
        		}

        		if(c!=0 && c!=dim-1 && l>ligne)
        		{
    				M[l][c]=(M[l-1][c]+M[l+1][c]+M[l][c+1]+M[l][c-1])/4;
        		}

          		if(c==dim-1 && l>ligne)
        		{
            		M[l][c]=(M[l-1][c]+M[l+1][c]+M[l][c-1])/3;
        		}

        		y+=fabs(M[l][c]-x);
       
			}
		
  		}compteur+=1;
  		
		//printf("Le nombre de calculs effectués est de %d et l'erreur minimale est de %f\n",compteur,y);

	}while(y>pre);

}

void planpointe(mat M)
{
	float a=(sqrt(2.5e-6)), b=5e-3;
	int V, c, l, ligne;
	
	do
	{
    	printf("Saisir un potentiel V positif\n");
        scanf("%d",&V);
    
    }while(V<0);
    
// BORNE SUPERIEUR HYPERBOLE
	
	for(c=0;c<=dim-1;c++)
		{
			ligne=sqrt(((dim-c)*a/b)*((dim-c)*a/b)-1); //ligne correspondant au passage de la ligne
			
			for(l=0;l<dim;l++)
			{	
				if(l<=ligne)
				M[l][c]=V;
			}
		}
		
	GS2(M);
	Fichier(M);
}

int main (void)
{
	int Choix;
	mat M={{0}};
	entete();
	printf("Vous avez deux choix, choisissez\n");
	printf("(1) système plan-plan\n");
	printf("(2) système plan-pointe\n");
	scanf("%d",&Choix);

	switch(Choix)
	{
		case 1:
        		printf("\n");
           		printf("Choix: plan-plan\n");
				planplan(M);
		break;
		
		case 2:
        		printf("\n");
        		printf("Choix: plan-pointe\n");
				planpointe(M);
		break;
	}

return 0;
}

