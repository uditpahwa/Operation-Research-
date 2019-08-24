#include <stdio.h>
#include "regular_simplex.h"
//#include "bigm_simplex.h"

//void Reg_Simplex(int num_eq,int num_var,float tableau[100][100],int num_iter,int a);
int main()
{
//------ALL VARAIBLES DEFINED HERE----------------------------///
    float tableau[100][100],objective[100],sum[100],big_m,min_max[100],max_min[100],minima,maxima,adjust =0;
    int num_eq,num_var,i,j,re_assign,flag=0,temp=0,k=0,lol_1,lol_2,lol_3,flag_2=0,lambda_1=0,lambda_2=0;

//------------------------------------------------------------///
//--------------INPUT------------------------------------///
    printf("Enter the number of stratergies for player  1::  ");
    scanf("%d", &num_eq);
    printf("Enter the number of stratergies for player 2 ::  ");
    scanf("%d", &num_var);
                        //   printf("%f %f", num_eq,num_var);
    printf("Enter the payoffs for the players ");
    for(i=0;i<num_eq;i++)
    {
        for(j=0;j<num_var;j++)
        {
            scanf("%f", &tableau[i][j]);
        }
    }
    printf("Press 1 for Initial table\n");
    scanf("%d", &lol_1);

    for(i=0;i<num_eq;i++)
    {
          for(j=0;j<num_var;j++)
          {
               printf("%.2f \t", tableau[i][j]);
          }
          printf("\n");
    }
   //---------------------END OF INPUT-------------------------------------------
    //------------------- CHECK TO SEE IF GAME IS STABLE--------------------///

    for(i=0;i<num_eq;i++)
    {
      minima = tableau[i][0];
          for(j=0;j<num_var;j++)
          {
               if(tableau[i][j]<minima)
               {
                minima = tableau[i][j];
               }
               else
               {
                    continue;
               }
         }
          max_min[k] = minima;
          k++;
    }
    k=0;
    for(j=0;j<num_var;j++)
    {
      maxima = tableau[0][j];
          for(i=0;i<num_eq;i++)
          {
               if(tableau[i][j]>maxima)
               {
                maxima = tableau[i][j];
               }
               else
               {
                    continue;
               }
         }
          min_max[k] = maxima;
          k++;
    }
    maxima = max_min[0];
    for(i=0;i<num_eq;i++)
          {
               if(max_min[i]>maxima)
               {
                maxima = max_min[i];
                lambda_1 = i;
               }
               else
               {
                    continue;
               }
         }
      minima = min_max[0];
      for(j=0;j<num_var;j++)
          {
               if(min_max[j]<minima)
               {
                minima = min_max[j];
                lambda_2 = j;
               }
               else
               {
                    continue;
               }
         }
    printf("Press 2 to know if the game is stable or not\n");
    scanf("%d", &lol_2);
    if(minima == maxima)
    {
          printf("The Game is Stable\n");
          printf("The Value of the game is %.2f \n", minima);
          printf("The optimal Stratergy is (%d , %d)", lambda_1+1,lambda_2+1);
    }
    else if (maxima != minima)
    {
          printf("The game is unstable\n");
          flag_2 =1;
    }

    for(i=0;i<num_eq;i++)
    {
          if(max_min[i]<0)
          {
               flag = 1;
               break;
          }
          else
          {
               continue;
          }
    }
    // IF NEGATIVE VALUES PRESENT IN GAME
    if(flag == 1)
    {
          minima = max_min[0];
          for(i=0;i<num_eq;i++)
          {
               if(max_min[i]<minima)
               {
                minima = max_min[i];
               }
               else
               {
                    continue;
               }
         }
       minima = -1*minima;
       adjust = minima;
       for(i=0;i<num_eq;i++)
          {
               for(j=0;j<num_var;j++)
               {
                  tableau[i][j] = tableau[i][j] + minima;
               }

          }





    }
    /*for(i=0;i<num_eq;i++)
          {
               for(j=0;j<num_var;j++)
               {
                    printf("%.2f \t", tableau[i][j]);
               }
               printf("\n");
          }*/
    if(flag_2 == 1)
    {

          for(i=0;i<num_eq;i++)
          {
               tableau[i][num_var] = 1;
          }

          for(j=0;j<num_var;j++)
          {
               tableau[num_eq][j] = -1;
          }
          //SLACK IS 10,20,30
          //VAR IS 1,2,3
          for(i=0;i<num_eq;i++)
          {
               tableau[i][num_var+1] = (i+1)*10;
          }

          for(j=0;j<num_var;j++)
          {
               tableau[num_eq+1][j] = j+1;
          }

          printf("Press 3 for the Value of the Game\n");
          scanf("%d", &lol_3);
          Reg_Simplex(num_eq,num_var,tableau,adjust);
    }








}
