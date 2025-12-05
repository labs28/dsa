
#include <stdio.h>

int readmatrix(int mat[3][3],int row,int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &mat[i][j]);
}
}
}
int triplet(int mat[3][3],int row,int col)
{
    int nr[3];
    int nc[3];
     int nonzeroval[3];
    int k=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(mat[i][j]!=0)
            {
               nr[k]=i;
               nc[k]=j;
               nonzeroval[k]=mat[i][j];
               k++;
            }
        }
    }
    printf("\nSparse Matrix Representation (row  col  value):\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", nr[i], nc[i], nonzeroval[i]);
    }
}
int main()
{
    int mat[3][3];
    int row;
    int col;
    printf("Enter an elements of row and column");
    scanf("%d%d",&row,&col);
    readmatrix(mat,row,col);
    triplet(mat,row,col);

    return 0;
}
