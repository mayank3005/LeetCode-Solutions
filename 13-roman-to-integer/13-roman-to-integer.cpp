class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> one;map<string,int> two;
        one.insert({'I',1});
        one.insert({'V',5});
        one.insert({'X',10});
        one.insert({'L',50});
        one.insert({'C',100});
        one.insert({'D',500});
        one.insert({'M',1000});

        two.insert({"IV",4});
        two.insert({"IX",9});
        two.insert({"XL",40});
        two.insert({"XC",90});
        two.insert({"CD",400});
        two.insert({"CM",900});

        int n=s.length();
        int ans=0;
        for(int i=0;i<n;){
            if(i!=n-1 and two.count(s.substr(i,2))){
                ans+=two[s.substr(i,2)];
                i+=2;
            }else{
                ans+=one[s[i]];
                i++;
            }
        }
        return ans;
    }
};