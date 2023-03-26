/*
In this q we have to find max and min ele from the unsorted array by the minimum comparison





int* findmaxmin(int ar[],int l,int r){
        int min,max;
        max=INT_MIN;
        min=INT_MAX;
        if(l==r){
            min=ar[l];
            max=ar[r];
        }
        else if(l+1==r){
            if(ar[l]>ar[r]){
                min=ar[r];
                max=ar[l];
            }
            else{
                min=ar[l];
                max=ar[r];
            }
        }
        else{
            int m=l+(r-l)/2;
            int *leftmaxmin;
            leftmaxmin=findmaxmin(ar,l,m);
            int *rightmaxmin;
            rightmaxmin=findmaxmin(ar,m+1,r);
            if(leftmaxmin[0]>rightmaxmin[0]){
                min=rightmaxmin[0];
            }
            else{
                min=leftmaxmin[0];
            }
            
            if(leftmaxmin[1]>rightmaxmin[1]){
                max=leftmaxmin[1];
            }
            else{
                max=rightmaxmin[1];
            }
        }
        
        int *maxmin=new int[2];
        maxmin[0]=min;
        maxmin[1]=max;
        return maxmin;
    }
    int findSum(int A[], int N)
    {
    	int *result=findmaxmin(A,0,N-1);
    
    	return result[0]+result[1];
    }
