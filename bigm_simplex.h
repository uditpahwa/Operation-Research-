void Bigm_Simplex(int num_eq,int num_var,float tableau[100][100],int iter,int a,int j_1,int temp)
{
    //VARIABLES INITIATION______________________________________________//
    int i,j,pivot_column=0,pivot_row=0,unbound_test=0,flag_1=0;
    float minima,min_ratio[100],p,q,r,s,new_tableau[100][100];

    //FIND THE PIVOT COLUMN_____________________________________________//

    i=num_eq;
    minima = tableau[i][0];
    for(j=0;j<num_var+temp;j++)
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
        j = num_var+temp;
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

            //SIMPLEX BEGINS___________________________________________//
            p = tableau[pivot_row][pivot_column];
            //PIVOT ROW OPERATION______________________________________//
            for(j=0;j<num_var+1+temp;j++)
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
            //PIVOT COLUMN OPERATIONS_____________________________________//
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
                for(j=0;j<num_var+1+temp;j++)
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
                        new_tableau[i][j] = (p*s-q*r)/p;
                    }

                }
            }
            for(j=0;j<num_var+temp;j++)
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
            if(a == iter)
            {
                printf("The iteration number %d\n",a);
                for (i=0; i<num_eq+1;i=i+1)
                {
                    for(j=0;j<num_var+1+temp;j=j+1)
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

            }

            if(flag_1 == 1)
            {
                a++;
                Bigm_Simplex(num_eq,num_var,new_tableau,iter,a,j_1,temp);

            }
            else if(flag_1 == 0)
            {
                printf("The optimal has been reached in iteration number :: %d \n", a);
                for (i=0; i<num_eq+1;i=i+1)
                    {
                        for(j=0;j<num_var+1+temp;j=j+1)
                            {
                                printf("%f ", new_tableau[i][j]);

                            }
                                printf("\n");
                    }
            }

    }
}

