class KthLargest {
public:
    int n;
    vector<int> vec;
    priority_queue <int, vector<int>, greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        int i=0;
        while(i<nums.size()){
            pq.push(nums[i]);
            i++;
        }
        while(pq.size()>k){
            pq.pop();
        }        
    }
    int add(int val) {
        pq.push(val);
        cout<<pq.top()<<endl;
        if(pq.size()>n){
            pq.pop();
        }
        cout<<pq.top()<<endl;
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */