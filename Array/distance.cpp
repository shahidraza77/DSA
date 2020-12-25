long long minDist(long long arr[], long long n, long long x, long long y)
{  
    long long i,index1,index2;
    for(i=0;i<n;i++)
    {
        if(x==arr[i])
        {
            index1=i;
            break;
        }
    }
    if(i==n)
      return -1;
      else
      {
        for(i=0;i<n;i++)
        {
        if(y==arr[i])
         {
            index2=i;
            break;
        }
          }
      }
      if(i==n)
      return -1;
      else if(index1>index2)
             return index1-index2;
             else
             return index2-index1;
    //add code here.
}