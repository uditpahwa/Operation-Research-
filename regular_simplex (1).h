void Reg_Simplex(int num_eq,int num_var,float tableau[100][100],float adjust)
{
    //VARIABLES INITIATION______________________________________________//
    int i,j,pivot_column=0,pivot_row=0,unbound_test=0,flag_1=0,lol_3=0,lol_4=0;
    float minima,min_ratio[100],p,q,r,s,new_tableau[100][100],temp_,value,prob[100],prob_1[100];

    //FIND THE PIVOT COLUMN_____________________________________________//

    i=num_eq;
    minima = tableau[i][0];
    for(j=0;j<num_var;j++)
    {
        if(tableau[i][j]<minima)
        {
            minima = tableau[i][j];
            pivot_column = j;
        }
        else
        {
            minima = minima;
        }
    }
    //END FINDING PIVOT COLUMN____________________________________//

    //FINDING MINIMUM RATIOS______________________________________//

    for(i=0;i<num_eq;i++)
    {
        j = num_var;
        min_ratio[i] = tableau[i][j]/tableau[i][pivot_column];
    }
     

    //FINDING PIVOT ROW______________________________________________//
    for(i=0;i<num_eq;i++)
    {
        if(min_ratio[i]<0)
        {
            min_ratio[i]=1000;
            unbound_test++;
        }
        else
        {
            continue;
        }
    }
    
    
    
    if(unbound_test == num_eq)
    {
        printf("Problem is unbounded");
    }


    else if (unbound_test != num_eq)
    {

        minima = min_ratio[0];
        for(i=0;i<num_eq;i++)
        {
            if(min_ratio[i]<minima)
                {
                    minima = min_ratio[i];
                    pivot_row = i;
                }
                else
                {
                    minima = minima;
                }
        }
        // EXCHANIGNG THE VAR
        j= num_var+1;
        i = pivot_row;
        temp_ = tableau[i][j];
        tableau[i][j] = tableau[num_eq+1][pivot_column];
        tableau[num_eq+1][pivot_column] = temp_;
    //END EXCHANGE

            //BOUNDEDNESS______________________________________________//

            //SIMPLEX BEGINS___________________________________________//
            p = tableau[pivot_row][pivot_column];
            //PIVOT ROW OPERATION______________________________________//
            for(j=0;j<num_var+1;j++)
            {
                i = pivot_row;
                if(j == pivot_column)
                {
                    new_tableau[i][j] = 1/p;
                }
                else
                {
                    new_tableau[i][j] = (1/p)*tableau[i][j];
                }
            }
            //PIVOT ROW OPERATIONS_____________________________________//
            for(i=0;i<num_eq+1;i++)
            {
                j = pivot_column;
                if(i == pivot_row)
                {
                    new_tableau[i][j]= 1/p;
                }
                else
                {
                    new_tableau[i][j] = -1*(1/p)*tableau[i][j];
                }
            }
            for(i=0;i<num_eq+1;i++)
            {
                for(j=0;j<num_var+1;j++)
                {
                    if(i == pivot_row)
                    {
                        break;
                    }
                    if(j==pivot_column)
                    {
                        new_tableau[i][j] = new_tableau[i][j];
                    }
                    else
                    {
                        s = tableau[i][j];
                        q = tableau[pivot_row][j];
                        r = tableau[i][pivot_column];
                        new_tableau[i][j] = (float)(p*s-q*r)/p;
                    }

                }
            }
            //ARRANGING THE ENTERING/LEAVING VARIABLE
                j=num_var+1;

                for(i=0;i<num_eq;i++)
                {
                    new_tableau[i][j] = tableau[i][j];
                }

               i=num_eq+1;

                for(j=0;j<num_var;j++)
                {
                    new_tableau[i][j] = tableau[i][j];
                }
            for(j=0;j<num_var;j++)
            {
                if(new_tableau[num_eq][j]<0)
                {
                    flag_1=1;
                    break;

                }
                else
                {
                    flag_1 = 0;
                }
            }
           

            if(flag_1 == 1)
            {
               
                Reg_Simplex(num_eq,num_var,new_tableau,adjust);

            }
            else if(flag_1 == 0)
            {
                    value = (1/new_tableau[num_eq][num_var]);
                printf("The Value of the game is :: %.2f \n",value-adjust);
                printf("Press 4 for the final tableau\n");
                scanf("%d", &lol_3);
                for (i=0; i<num_eq+1+1;i=i+1)
                    {
                        for(j=0;j<num_var+1+1;j=j+1)
                            {
                                printf("%.2f \t", new_tableau[i][j]);

                            }
                                printf("\n");
                    }
                    printf("1,2,3 are variables 10,20,30 are slacks");
                  printf("Press 5 for the Optimal Stratergies\n");
                  scanf("%d", &lol_4);
                  for(j=0;j<num_var;j++)
                  {
                         for(i=0;i<num_eq;i++)
                         {
                              if(new_tableau[i][num_var+1] == j+1)
                              {
                                   prob[i] = value*new_tableau[i][num_var] ;
                                   //printf("y %d :: %.2f\n",j+1,value*new_tableau[i][num_var]);
                              }
                              
                              
                         }
                  }
                  for(i=0;i<num_eq;i++)
                  {
                         for(j=0;j<num_var;j++)
                         {
                              if( new_tableau[num_eq+1][j] == (i+1)*10 )
                              {
                                   prob_1[j] = value*new_tableau[num_eq][j] ;
                                   //printf("y %d :: %.2f\n",j+1,value*new_tableau[i][num_var]);
                              }
                              
                              
                         }
                  }
                  for(j=0;j<num_var;j++)
                  {
                    printf("y %d :: %.2f\n",j+1, prob[j]);
                  }
                  for(j=0;j<num_eq;j++)
                  {
                    printf("x %d :: %.2f\n",j+1, prob_1[j]);
                  }
                
                
            }

    }
}
