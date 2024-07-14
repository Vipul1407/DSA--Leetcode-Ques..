class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<string, int>> st;
        int i, j, k;
        for (i = 0; i < formula.size(); i++) {
            char c = formula[i];
            if (isupper(c)) {
                string element = "";
                element += c;
                for (j = i + 1; j < formula.size(); j++) {
                    c = formula[j];
                    if (!islower(c))
                        break;
                    element += c;
                }

                string sdigit = "";
                for (k = j; k < formula.size(); k++) {
                    c = formula[k];
                    if (!isdigit(c))
                        break;
                    sdigit += c;
                }
                if (sdigit == "")
                    sdigit = "1";
                int digit = stoi(sdigit);
                st.push({element, digit});
                i = k - 1;
            } else if (c == '(') {
                st.push({"(", -1});
            } else if (c == ')') {
                string sdigit = "";
                for (j = i + 1; j < formula.size(); j++) {
                    c = formula[j];
                    if (!isdigit(c))
                        break;
                    sdigit += c;
                }
                if (sdigit == "")
                    sdigit = "1";
                int digit = stoi(sdigit);
                vector<pair<string, int>> temp;
                pair<string, int> op = {"(", -1};
                while (st.top() != op) {
                    pair<string, int> p = st.top();
                    st.pop();
                    temp.push_back({p.first, p.second * digit});
                }
                st.pop();
                while (temp.size() > 0) {
                    st.push(temp.back());
                    temp.pop_back();
                }
                i = j - 1;
            }
        }
        map<string, int> mp;
        while (!st.empty()) {
            pair<string, int> p = st.top();
            st.pop();
            mp[p.first] += p.second;
        }
        string ans = "";
        for (auto i : mp) {
            string e = i.first;
            string d = to_string(i.second);
            if (d == "1")
                d = "";
            ans += e + d;
        }
        return ans;
    }
};