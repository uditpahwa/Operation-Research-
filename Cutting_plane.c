#include <stdio.h>
#include "DualSimplex.h"
int main()
{
//------ALL VARAIBLES DEFINED HERE----------------------------///
    float tableau[100][100],objective[100],sum[100],big_m;
    int num_eq,num_var,i,j,eq_kind[100],re_assign,flag=0,optimise_type,iter,j_1,temp=0,adjust=0;

//------------------------------------------------------------///
//--------------INPUT------------------------------------///
    printf("Enter the number of equations ::  ");
    scanf("%d", &num_eq);
    printf("Enter the number of variables ::  ");
    scanf("%d", &num_var);
                        //   printf("%f %f", num_eq,num_var);
    printf("Enter the coefficients of variables and the RHS ");
    for(i=0;i<num_eq;i++)
    {
        for(j=0;j<num_var+1;j++)
        {
            scanf("%f", &tableau[i][j]);
        }
    }
    printf("Enter the kind of equation \n1 - <=\n2 - >= \n3 - =\n");
    for(i=0;i<num_eq;i++)
    {
        scanf("%d", &eq_kind[i]);
    }
    printf("Enter the objective function's coefficients and constant term(enter 0 if no constant)");
    for(i=0;i<num_var+1;i++)
    {
        scanf("%f", &objective[i]);
    }
    printf("For maximization enter 1 \nFor minimization enter 2 ");
    scanf("%d", &optimise_type);
    printf("Enter the iteration number to be printed ::");
    scanf("%d", &iter);
    printf("Enter the non-basic variable to be printed:: ");
    scanf("%d", &j_1);
    for(i=0;i<num_eq;i++)
    {


        if(eq_kind[i] == 2)
        {
            for(j=0;j<num_var+1;j++)
            {
                tableau[i][j] = -1*tableau[i][j];
            }
        }

    }
     if(optimise_type == 1)
        {
            for(j=0;j<=num_var;j++)
            {
                tableau[num_eq][j] = -1*(objective[j]);
            }
        }
        else if(optimise_type == 2)
        {
            for(j=0;j<=num_var;j++)
            {
                tableau[num_eq][j] = objective[j];
            }
        }
    //Tableau Has Been Made-----------------------------------------------------------------------------
    printf("The Initial Table is::: \n");
     for (i=0; i<num_eq+1;i=i+1)
     {
          for(j=0;j<num_var+1;j=j+1)
          {
               printf("%.2f  ", tableau[i][j]);

          }
          printf("\n");
     }
     for(i=0;i<num_eq;i++)
     {
          tableau[i][num_var+1] = i+1;
     }
     for(j=0;j<num_var;j++)
     {
          tableau[num_eq+1][j] = (j+1)*10;
     }

    Dual_Simplex(num_eq,num_var,tableau,iter,1,j_1);
}
