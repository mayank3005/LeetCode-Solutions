class Solution {
struct item {
	int val;
};

struct segTree {

	int size;
	vector<item> values;

	item NEUTRAL_VALUE = {0};

	item merge(item a, item b) {
        item c; c.val=a.val+b.val;return c;
	}

	item single(int x) {
		return {x};
	}

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		values.resize(2 * size);
        fill(values.begin(),values.end(),NEUTRAL_VALUE);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (lx == rx) {
			if (lx < (int)a.size()) values[x] = single(a[lx]);
			return;
		}
		int mid = (lx + rx) >> 1;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid + 1, rx);
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
	}

	void build(vector<int> &a) {
		build(a, 0, 0, size - 1);
	}

	void update(int i, int v, int x, int lx, int rx) {
		if (lx == rx) {
			values[x].val+=v;
			return;
		}
		int mid = (lx + rx) >> 1;
		if (i <= mid) update(i, v, 2 * x + 1, lx, mid);
		else update(i, v, 2 * x + 2, mid + 1, rx);
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
	}

	void update(int i, int v) {
		update(i, v, 0, 0, size - 1);
	}

	int query(int x, int lx, int rx, int sum) {
        if(lx==rx){
            if(values[x].val>=sum) return lx;
            else return -1;
        }
            
		int mid = (lx + rx) >> 1;
        if(values[2*x+1].val>=sum) return query(2 * x + 1, lx, mid,sum);
		else return query(2 * x + 2, mid + 1, rx, sum-values[2*x+1].val);
	}

	int query(int sum) {
		return query(0, 0, size - 1, sum);
	}

};
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        segTree tree; tree.init(110); vector<int> ans;
        for(int i=0;i<k-1;i++) tree.update(nums[i]+50,1);
        for(int i=k-1;i<n;i++){
            tree.update(nums[i]+50,1);
            int val=tree.query(x)-50;
            val=min(val,0); ans.push_back(val);
            tree.update(nums[i-k+1]+50,-1);
        }
        return ans;
    }
};