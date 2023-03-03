void computeLPSarray(string &pat, int n, vector<int> &lps) {

	int len = 0, i = 1;
	lps[0] = 0;

	while (i < n) {
		if (pat[i] == pat[len]) {
			lps[i] = ++len;
			i++;
		} else {
			if (len)
				len = lps[len - 1];
			else
				lps[i] = 0,i++;
		}
	}

}

int KMPSearch(string &txt, string &pat) {

	int n = txt.length(), m = pat.length();

	vector<int> lps(m);

	computeLPSarray(pat, m, lps);

	int i = 0, j = 0;

	while (i < n) {
		if (txt[i] == pat[j]) i++, j++;
		else {
			if (j)
				j = lps[j - 1];
			else
				i++;
		}
		if (j == m) {
			return i-m;
			j = lps[j - 1];
		}
	}
    return -1;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        return KMPSearch(haystack,needle);
    }
};