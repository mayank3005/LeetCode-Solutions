class DisjointSet
{
public:
    vector<int>parent ;
    DisjointSet(int n){
        parent.resize(n+1,0) ;
        for(int i = 0 ; i<=n ; i++){
            parent[i] = i ;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node ;
        }
        return parent[node] = findUPar(parent[node]) ;
    }
    void find(int u , int v){
        int ulp_u = findUPar(u) ;
        int ulp_v = findUPar(v) ;
        if(ulp_u==ulp_v)return ;
        else if(ulp_v< ulp_u){
            parent[ulp_u] = ulp_v ;
        }
        else{
            parent[ulp_v] = ulp_u ;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26) ;
        for(int i = 0 ; i < s1.length() ;i++){
            ds.find(s1[i]-97,s2[i]-97) ;
        }
        for(int i = 0 ; i < baseStr.length();i++){
            baseStr[i] = char(ds.findUPar(baseStr[i]-97)+97) ;
        }
        return baseStr ;
    }
};