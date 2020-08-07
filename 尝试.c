/*#include<stdio.h>
int  N;
void Transpose(int (*a)[N], int n);
void  Swap(int *x, int *y);
void InputMatrix(int (*a)[N], int n);
void PrintMatrix(int (*a)[N], int n);
int main()
{
    printf("Input n:");
    scanf("%d", &N);
    int a[N][N];
    int (*p)[N] = a;
    InputMatrix(p,N);
    Transpose(p,N);
    PrintMatrix(p, N);
    return 0;
}
void InputMatrix(int (*a)[N], int n)
{
    int i, j;
    printf("Input %d*%d matrix:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", *(a + i) + j);
        }
    }
}
void Transpose(int (*a)[N], int n)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            Swap(*(a + i) + j, *(a + j) + i);
        }
    }
}
void  Swap(int *x, int *y)
{
    int t = 0;
    t = *x;
    *x = *y;
    *y = t;
}
void PrintMatrix(int (*a)[N], int n)
{
    int i, j;
    printf("The transposed matrix is:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d\t", *(*(a + i) + j));
        }
        printf("\n");
    }
}*/

/*#include<stdio.h>
int main() 
{
	int n=0,i=0;
	scanf("%d",&n);
	int u[n];
	for (i=0;i<n;i++){
		scanf("%d",&u[i]);
	}for (i=0;i<n;i++){
		printf("%d\t",u[i]);
	}
	return 0;
}*/
/*#include<stdio.h> 
int main()
{
	int n=9;
	int a[n];
	return 0;
}*/

#include<stdio.h>
int main()
{
	int n=9;
	
	printf("%d\n",&n);
	n=98;
	printf("%d",&n); 
	return 0; 
 } 
