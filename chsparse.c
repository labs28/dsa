#include <stdio.h>
int readmatrix(int mat[3][3],int row,int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &mat[i][j]);
}
}
}
int displaymatrix(int mat[3][3],int row,int col)
{
    printf("Matrix is:-\n");
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++) {
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}
	
}
int sparsematrix(int mat[3][3],int row,int col)
{
    int zerocount=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
          if (mat[i][j] == 0)
				zerocount++;  
        }
    }
    	if (zerocount > (row * col) / 2)
		printf("The matrix is sparse.\n");
	else
		printf("The matrix is not sparse.\n");
    
}
int main() {
    
    int mat[3][3];
    int row;
    int col;
    printf("Enter number of rows and columns: ");
	scanf("%d %d", &row, &col);

	printf("Enter elements of the matrix:\n");
    readmatrix(mat,row,col);
    displaymatrix(mat,row,col);
    sparsematrix(mat,row,col);
}
	
