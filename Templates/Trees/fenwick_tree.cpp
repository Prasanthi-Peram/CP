//Reversible implementations such as addition, multiplication and XOR
template <typename T>
class ReversableOperator{
    public:
    virtual T apply (const T&a, const T& b)=0;
    virtual T undo (const T& c, const T& b)=0;
};

template <typename T>
class FenwickTree{
    private:
    vector<T> tree;
    ReversableOperator<T>* f;//Objects of Abstarct base class cannot be created directly, we make functions in the derived class and use a base class pointer to initialize them

    public:
    FenwickTree(const vector<T>& ar, ReversableOperator<T>* f){
        this->f=f;
        tree=ar;
        int size= tree.size();

        for(int i=1;i<size;i++){
            int p=i+(i&-i);//Index to parent
            if(p<size){
                tree[p]=f->apply(tree[p],tree[i]);
            }
        }
    }

    // Returns the f(tree[i]) from index 1 to i, inclusive
    T query(T i){
        T q=T();
        while(i>0){
            if(q==T()){
                q=tree[i];
            }else{
                q=f->apply(q,tree[i]);
            }
            i-=i&-i;
        }
        return q;
    }

    T query(T i, T j){
        if(i>1){
            return f->undo(query(j),query(i-1));
        }else{
            return query(j);
        }
    }

    T valueAt(T i){
        return f->undo(query(i),query(i-1));
    }

    // Apply k to element at index i, propagating the change to the right end of the tree so that range operations still work

    void apply(T i, const T& k){
        int size= tree.size();
        while(i<size){
            tree[i]=f->apply(tree[i],k);
            i+=i&-i;
        }
    }

    //Updates the value at index i
    void update(T i, const T& value){
        T orig= valueAt(i);
        apply(i, f->undo(value,orig));
    }
};
