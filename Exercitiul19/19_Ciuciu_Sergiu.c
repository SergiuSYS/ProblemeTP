#include <stdio.h>
#include <stdlib.h>

void umplere_matrice(int **matrice, int k, int n);

int main()
{
    FILE *InputFile;
    FILE *OutputFile;
    InputFile = fopen("mat.in", "r");
    OutputFile = fopen("mat.out", "w");
    int N, K;

    if (InputFile == NULL || OutputFile == NULL)
    {
        printf("Fișierul nu s-a putut deschide!\n");
        return 0;
    }
    fscanf(InputFile, "%d %d", &N, &K);
    
    int **mat = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; ++i)
    {
        mat[i] = (int *)malloc(N * sizeof(int));
    }
     umplere_matrice(mat, K, N);
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            fprintf(OutputFile, "%d ", mat[i][j]);
        }
        fprintf(OutputFile, "\n");
    }

    fclose(OutputFile);
    fclose(InputFile);

    for (int i = 0; i < N; ++i)
    {
        free(mat[i]);
    }
    free(mat);

    return 0;
}

void umplere_matrice(int **matrice, int K, int N){
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            matrice[i][j] = 0;
        }
    }

    int nr = 1;
    matrice[K - 1][0] = nr++;

    for (int i = K - 2; i >= 0; --i)
    {
        matrice[i][0] = nr++;
    }

    int direction = 1;
    for (int i = K - 1; i <= N; i++)
    {
        if (direction == 1)
        {
            for (int j = 1; j < N; j++)
            {
                matrice[i-1][j] = nr++;
            }
        }
        else
        {
            for (int j = N - 1; j > 0; j--)
            {
                matrice[i-1][j] = nr++;
            }
        }
        direction *= -1;
    }
    for (int i = N - 1; i > K - 1; i--)
    {
        matrice[i][0] = nr++;
    }

}
