class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char,int > umap;
          
          for(int i=0;i<n;i++){
              umap[x[i]]=b[i];
          }
          int sum=0;
          string temp="";
          string ans="";
          int max=INT_MIN;
          for(int i=0;i<w.size();i++){
              if(umap.find(w[i])!=umap.end()){
                  sum=sum+umap[w[i]];
              }
              else{
                  sum=sum+w[i];
              }
              temp=temp+w[i];
              if(sum>max){
                  max=sum;
                  ans=temp;
              }
              if(sum<0){
                  sum=0;
                  temp="";
              }
          }
          
          return ans;
      }
};
