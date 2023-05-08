//ANDZAMA AMOUGOU CEDDRIC CHATEAUBRIAND 22W2177

#include <stdio.h>
#include <stdlib.h>
#define MAX 20000
     
void fusion (int *a, int n, int m) 
{
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) 
    {
        x[k] = j == n      ? a[i++]
         : i == m      ? a[j++]
         : a[j] < a[i] ? a[j++]
         :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
        free(x);
    }
     
void tri_fusion (int *liste, int taille)
{
    if (taille < 2) return;
    int milieu = taille / 2;
    tri_fusion(liste, milieu);
    tri_fusion(liste + milieu, taille - milieu);
    fusion(liste, taille, milieu);
}
int main()
{
    FILE *file = fopen("non_trier.txt", "r");
    if(file == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(1);
    }

    int tab[MAX];
    for(int i = 0 ; i < MAX ; i++)
        fscanf(file, "%d\n" , &tab[i]);
    fclose(file);
    tri_fusion(tab , MAX);
    file = fopen("trier.txt" , "w");
    if(file == NULL)
    {
       printf("Erreur d'ouverture du fichier\n");
        exit(1); 
    }
    for(int i = 0 ; i < MAX ; i++)
        fprintf(file, "%d\n" , tab[i]);
    fclose(file);
    return 0;
}

