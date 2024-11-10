#define ll long long
struct item {
	ll val;
};

struct segTree {

	int size;
	vector<item> values;

	item NEUTRAL_VALUE = {0};

	item merge(item a, item b) {
		item c; c.val = (a.val | b.val); return c;
	}

	item single(ll x) {
		return {x};
	}

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		values.resize(2 * size);
	}

	void build(vector<int> &a, ll x, int lx, int rx) {
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
			values[x] = single(v);
			return;
		}
		int mid = (lx + rx) >> 1;
		if (i <= mid) update(i, v, 2 * x + 1, lx, mid);
		else update(i, v, 2 * x + 2, mid + 1, rx);
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
	}

	void update(int i, ll v) {
		update(i, v, 0, 0, size - 1);
	}

	item query(int x, int lx, int rx, int l, int r) {
		if (lx > r or rx < l) return NEUTRAL_VALUE;
		if (lx >= l and rx <= r) return values[x];
		int mid = (lx + rx) >> 1;
		item s1 = query(2 * x + 1, lx, mid, l, r);
		item s2 = query(2 * x + 2, mid + 1, rx, l, r);
		return merge(s1, s2);
	}

	item query(int l, int r) {
		return query(0, 0, size - 1, l, r);
	}

};

class Solution {
public:
    int minimumSubarrayLength(vector<int>& v, int k) {
        int n=v.size();
        segTree tree; tree.init(n); tree.build(v);
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(tree.query(i,n-1).val<k) continue;
            if(v[i]>=k) return 1;
            int l=i,r=n-1;
            while(l+1<r){
                int mid=(l+r)>>1;
                int val=tree.query(i,mid).val;
                if(val>=k) r=mid;
                else l=mid;
            }
            ans=min(ans,r-i+1);
        }
        return (ans==1e9?-1:ans);
    }
};