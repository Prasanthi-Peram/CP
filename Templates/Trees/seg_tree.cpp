//Number of Nodes in a binary tree is 2n-1
template <typename T>
class SegmentTree{
private:
    vector<T> tree;
    int n;
    function<T(const T&, const T&)> func;
public:
   //Constructor
   SegmentTree(const vector<T>& arr,function<T(const T&, const T&)> f): n(arr.size()), func(f){
     tree.resize(2*n);

     for(int i=0;i<n;i++) tree[n+i]=arr[i];
     for(int i=n-1;i>0;i--){
        tree[i]=func(tree[2*i],tree[2*i+1]);
     }
   }

   void update(int i, T value){
    i+=n;//Move to the leaf nodes
    tree[i]=value;

    //Propagate the changes up the tree
    while(i>1){
        i/=2;
        tree[i]=func(tree[2*i],tree[2*i+1]);
    }
   }

   //Query the range [from,to)
   T query(int from,int to){
    from+=n;
    to+=n;
    T result=T();//Default initialization
    bool initialized = false;
    while (from < to) {
            if (from % 2 == 1) { // If "from" is a right child
                result = initialized ? func(result, tree[from]) : tree[from];
                initialized = true;
                ++from;
            }
            if (to % 2 == 1) { // If "to" is a right child
                --to;
                result = initialized ? func(result, tree[to]) : tree[to];
                initialized = true;
            }
            from /= 2;
            to /= 2;
        }

        return result;
    }
   };