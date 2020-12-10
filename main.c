#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void quicksort(int n, int k, int *sum, int **mas);

int main()
{
    setlocale(LC_ALL,"Rus");
    int m, n,i,j;

    printf("Введите размерность маcсива m*n:\n");
    scanf("%d %d", &m, &n);

    int **mas = (int**) malloc(sizeof(int*)* m);
    int *stolb_sum = (int*) malloc(sizeof(int*)* m);

    printf("Введите элементы массива:\n");

    for(int i = 0; i < m; ++i)
    {
        mas[i] = (int*) malloc(sizeof(int)*n);
        stolb_sum[i] = 0;
        for(int j = 0; j < n; ++j)
        {
            scanf("%d", &mas[i][j]);
            stolb_sum[i] += mas[i][j];
        }
    }

    printf("Исходная массив:\n");

    for (i=0; i<m; i++, printf("\n"))
        for (j=0; j<n; j++)
            printf("%d ", mas[i][j]);

    quicksort(m, n, stolb_sum, mas);

    printf("Отсортированный массив\n");

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
return 0;
}

void quicksort(int a, int k, int *sum, int **mas)
{

    int i = 0, j = a - 1;

    int temp, mid = sum[(i + j) / 2];

    do
    {

        while(sum[i] < mid)
            i++;

        while(sum[j] > mid)
            j--;

        if(i <= j)
        {
            int *t = (int *) malloc(sizeof(int) * k);
            t = mas[i];
            mas[i] = mas[j];
            mas[j] = t;

            temp = sum[i];
            sum[i] = sum[j];
            sum[j] = temp;
            i++;
            j--;
        }

    }
    while(i <= j);

    if(j > 0)
        quicksort(j, k, sum, mas);

    if(a > i)
        quicksort(a - i, k, sum + i, mas + i);

}
