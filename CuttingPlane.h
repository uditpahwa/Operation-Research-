void Cutting_plane(int num_eq,int num_var,float tableau[100][100],int iter,int a,int j_1)
{
    //VARIABLES INITIATION______________________________________________//
    int i,j,pivot_column=0,pivot_row=0,unbound_test=0,flag_1=0,flag_2 =0,flag_3=0,DualSimp =0,infeasible_test=0,G_pivot;
    float minima,min_ratio[100],p,q,r,s,new_tableau[100][100],temp_,fract,fract_[100],maxima;
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

            //BOUNDEDNESS______________________________________________//
            //EXCHANGE OF BASIC/NON-BASIC VARIABLE
        j= num_var+1;
        i = pivot_row;
        temp_ = tableau[i][j];
        tableau[i][j] = tableau[num_eq+1][pivot_column];
        tableau[num_eq+1][pivot_column] = temp_;

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
           /* if(a == iter)
            {
                printf("The iteration number %d\n",a);
                for (i=0; i<num_eq+1;i=i+1)
                {
                    for(j=0;j<num_var+1;j=j+1)
                        {
                            printf("%f ", new_tableau[i][j]);

                        }
                    printf("\n");
                }
                printf("The %d th non-basic variable column::\n",j_1);
                for(i=0;i<num_eq+1;i++)
                {

                    printf("%f\n", new_tableau[i][j_1-1]);
                }

            }*/

            if(flag_1 == 1)
            {
                a++;
                Cutting_plane(num_eq,num_var,new_tableau,iter,a,j_1);

            }
            else if(flag_1 == 0)
            {
                /*printf("The optimal has been reached in iteration number :: %d \n", a-1);
                for (i=0; i<num_eq+1;i=i+1)
                    {
                        for(j=0;j<num_var+1;j=j+1)
                            {
                                printf("%.2f ", new_tableau[i][j]);

                            }
                                printf("\n");
                    }
                    printf("Optimal :: %.2f",new_tableau[num_eq][num_var]);*/
                    for(i=0;i<num_eq;i++)
                    {
                        if(new_tableau[i][num_var+1] == i+1)
                        {
                            fract = new_tableau[i][num_var] - (int)new_tableau[i][num_var] ;

                            if(fract != 0)
                            {
                                printf("Using cutting plane Method\n");
                                flag_3 = 1;
                                break;
                            }
                        }

                    }
                    for(i=0;i<num_eq;i++)
                    {
                        if(new_tableau[i][num_var+1] == i+1)
                        {
                            fract = new_tableau[i][num_var] - (int)new_tableau[i][num_var] ;
                            fract_[i] = fract;

                        }

                    }
                    if(flag_3 == 1)
                    {
                        maxima = fract_[0]
                        for(i=0;i<num_var;i++)
                        {
                            if(fract_[i]>maxima)
                            {
                                maxima = fract[i]
                                G_pivot = i;
                            }
                            else
                            {
                                maxima = maxima;
                            }
                        }



                    }
            }

    }
}
