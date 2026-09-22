#define vi vector<int>
#define vvi vector<vi>

class sgt{
    private :
        int k;
        vector<array<int,6>> arr;
        array<int,6> operation(const array<int,6>& left, const array<int,6>& right){
            array<int,6> res = left;
            for (int i=0;i<k;i++)res[(left[5]*i)%k] += right[i];
            res[5] = (left[5] * right[5]) % k;
            return res;
        }
    public:
        sgt(int n, int k){
            arr.resize(4*n);
            this->k = k;
        }
        void buildTree(int pos , int start, int end ,vi& nums){
            if (start == end){
                arr[pos][nums[start]]=1;
                arr[pos][5]=nums[start];
                return ;
            }
            int mid = start+(end-start)/2;
            buildTree(pos*2,start,mid,nums);
            buildTree(pos*2+1,mid+1,end,nums);
            arr[pos]=operation(arr[pos*2], arr[pos*2+1]);
        }
        void update(int pos, int start, int end,int update_pos,int value){
            if (start == end and start==update_pos){
                for (int i=0;i<6;i++)arr[pos][i]=0;
                arr[pos][value] = 1;
                arr[pos][5] = value;
                return ;
            }
            int mid = start+(end-start)/2;
            if (update_pos<=mid)update(pos*2,start,mid,update_pos,value);
            else update(pos*2+1,mid+1,end,update_pos,value);
            arr[pos]=operation(arr[pos*2], arr[pos*2+1]);
        }
        array<int,6> get(int pos, int start, int end,int low, int high){
            if (start>=low and end<=high)return arr[pos];
            int mid = start+(end-start)/2;
            if (high <= mid) return get(pos*2,start,mid,low,high);
            if (low > mid) return get(pos*2+1,mid+1,end,low,high);
            return operation(get(pos*2,start,mid,low,high),get(pos*2+1,mid+1,end,low,high));
        }
};

class Solution {
public:
    vi resultArray(vi& nums, int k, vvi& q) {
        int len = nums.size(), qlen = q.size();
        vi ans(qlen,0);
        for (auto& i:nums)i %= k;
        sgt root(len,k);
        root.buildTree(1,0,len-1,nums);
        for (int i=0;i<qlen;i++){
            root.update(1,0,len-1,q[i][0], q[i][1]%k);
            ans[i] = root.get(1,0,len-1,q[i][2], len-1)[q[i][3]];
        }
        return ans ;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();