//This is the template for idempotent range queries, eg: Range min queries
void buildSparseTable(const vector<long long int>& arr,vector<vector<long long int>>& st,int K,int N){
    //copy(arr.begin(), arr.end(), st[0]);
    rep(i,0,N) st[0][i]=arr[i];
    for(int i=1;i<=K;i++){
        for(int j=0;j+(1<<i)<=N;j++){
            st[i][j]= min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
    }
}

void storelg (vector<int>& lg,int MAXN){
    //O(1)
    lg[1]=0;
    rep(i,2,MAXN+1) lg[i]=lg[i/2]+1;
}

long long int solve(int a, int b, vector<vector<long long int>>& st,const vector<int>& lg){
    //Query
    int i=lg[b-a+1];
    long long int minimum =min(st[i][a],st[i][b-(1<<i)+1]);

    return minimum;
}