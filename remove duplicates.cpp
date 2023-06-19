 int remove_duplicate(int a[],int n){
      int i,j;
      i=0;
      for(j=1;j<n;j++){
          if(a[i]!=a[j]){
              i++;
              a[i]=a[j];
          }
      }
      
      return i+1;
    }
