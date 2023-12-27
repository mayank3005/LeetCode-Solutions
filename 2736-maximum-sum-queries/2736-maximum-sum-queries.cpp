bool comp(vector<int> &a,vector<int> &b){
    return a[1]>b[1];
}

class Solution {
struct item {
	int val;
};

struct segTree {

	int size;
	vector<item> values;

	item NEUTRAL_VALUE = {0};

	item merge(item a, item b) {
		item c; c.val = max(a.val,b.val); return c;
	}

	item single(int x) {
		return {x};
	}

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		values.resize(2 * size);
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
			values[x] = single(v);
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
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums1.size(); vector<int> ans(queries.size());
        vector<vector<int>> query;
        for(int i=0;i<queries.size();i++){
            query.push_back({queries[i][0],queries[i][1],i});
        }
        sort(query.begin(),query.end(),comp);
        vector<pair<int,int>> v; for(int i=0;i<nums1.size();i++) v.push_back({nums1[i],nums2[i]});
        sort(v.begin(),v.end());
        vector<int> suff(n); suff[n-1]=v[n-1].first+v[n-1].second;
        for(int i=n-2;i>=0;i--) suff[i]=v[i].first+v[i].second;
        vector<pair<int,int>> sec; 
        for(int i=0;i<n;i++) sec.push_back({v[i].second,i});
        sort(sec.begin(),sec.end()); reverse(sec.begin(),sec.end());
        
        segTree tree; tree.init(n); 
        
        int i=0;
        
        for(auto &q:query){
            int ind = lower_bound(v.begin(),v.end(),make_pair(q[0],0))-v.begin();
            while(i<n and sec[i].first>=q[1]){
                tree.update(sec[i].second,suff[sec[i].second]);
                i++;
            }
            int res = tree.query(ind,n-1).val;
            ans[q[2]]=(res>0?res:-1);
        }
        return ans;
    }
};