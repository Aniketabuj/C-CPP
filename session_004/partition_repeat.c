void partition(int* a, int p, int r)
{
    int i;
    int j;
    int pivot;
    int tmp;

    pivot =a[r];
    i = p - 1;

    for(j = p; j < r; j++)
    {
        if(a[j] <= pivot)
        {
            i = i + 1;
            tmp  =  a[i];
            a[i] =  a[j];
            a[j] =  tmp;
            
        }
    }

    tmp = a[r];
    a[r] = a[i+1];
    a[i+1] = tmp;

    return(i +1);
}

void partition(int* a, int p, int r)
{
    int i;
    int j;
    int pivot;
    int tmp;

    pivot =a[r];
    i = p - 1;

    for(j = p; j < r; j++)
    {
        if(a[j] <= pivot)
        {
        i = i +1;
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        }
    }
    
}
