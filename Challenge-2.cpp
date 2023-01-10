//                                                       COMPANY NAME - GOODMAN SACHS
//                                                  TOTAL NO. OF  15  QUESTIONS COMPLETED .
1.
int maxPoints(vector<Point> &points) {
    int result = 0;
    for(int i = 0; i < points.size(); i++){
        int samePoint = 1;
        unordered_map<double, int> map;
        for(int j = i + 1; j < points.size(); j++){
            if(points[i].x == points[j].x && points[i].y == points[j].y){
                samePoint++;
            }
            else if(points[i].x == points[j].x){
                map[INT_MAX]++;
            }
            else{
                double slope = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
                map[slope]++;
            }
        }
        int localMax = 0;
        for(auto it = map.begin(); it != map.end(); it++){
            localMax = max(localMax, it->second);
        }
        localMax += samePoint;
        result = max(result, localMax);
    }
    return result;
}
2.
int d(vector<int>& p1, vector<int>& p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    unordered_set<int> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
    return !s.count(0) && s.size() == 2;
}
3.
int trailingZeroes(int n) {
    int sum=0;
	int tmp=0;
	while(n/5>0)
	{
		tmp=n/5;
		sum+=tmp;
		n=tmp;
    }
    return sum;
 }
 4.
 bool isPossible(vector<int>& nums) {
        unordered_map<int,int> cnt, tails;
        for(int &i : nums) cnt[i]++;
        for(int &i : nums){
            if(!cnt[i]) continue;
            cnt[i]--;
            if(tails[i-1] > 0){
                tails[i-1]--;
                tails[i]++;
            }
            else if(cnt[i+1] && cnt[i+2]){
                cnt[i+1]--;
                cnt[i+2]--;
                tails[i+2]++;
            }
            else return false;
        }
        return true;
    }
6.class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        int n = v.size();
        int ans = INT_MAX;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.find(v[i])!=m.end()){
                ans = min(ans,i-m[v[i]]+1);
            }
            m[v[i]] = i;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
7.
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n); 
        
        for(int i = 0; i < n; i++){
            pos[nums2[i]] = i;
        }
        vector<int> pref(n) , suff(n);
        ordered_set s,s2;
        for(int i = 0; i < n; i++){
            pref[i] = s.order_of_key(pos[nums1[i]]);
            s.insert(pos[nums1[i]]);
        }
       
        for(int i = n-1; i >= 0; i--){
            suff[i] = s2.order_of_key(-pos[nums1[i]]);
            s2.insert(-pos[nums1[i]]);
        }
        long long ans = 0;
        for(int i = 1; i < n-1; i++){
            ans = ans + pref[i]*1LL*suff[i];
        }
        return ans;
    }
};
8.
class Solution
{
    public:
    vector<int> ans;
    int target = 0;
    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows)
    {
        vector<int> res(12, 0);
        rec(11, numArrows, aliceArrows, 0, res);
        return ans;
    }
    void rec(int n, int numArrows, vector<int> &aliceArrow, int sum, vector<int> res)
    {
        if (n == -1 || numArrows <= 0)
        {
            if (sum > target)
            {
                target = sum;
                if (numArrows > 0)
                {
                    res[0] += numArrows;
                }
                ans = res;
            }
            return;
        }
        int req = aliceArrow[n] + 1;
        if (req <= numArrows)
        {
            res[n] = req;
            rec(n - 1, numArrows - req, aliceArrow, sum + n, res);
            res[n] = 0;
        }
        rec(n - 1, numArrows, aliceArrow, sum, res);
        return;
    }
};
9.
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n=profits.size();
    vector<pair<int,int>> projects(n);
    for(int i=0;i<n;i++) projects[i]={profits[i],capital[i]}; 
    int i=0;
    sort(projects.begin(),projects.end(),[&](pair<int,int> a,pair<int,int> b){ return a.second<b.second;});
    priority_queue<int> maxProfit;
    while(k--){
        while(i<n && w>=projects[i].second) maxProfit.push(projects[i++].first);
        
        if(!maxProfit.empty()) w+=maxProfit.top(),maxProfit.pop();
    }
    return w;
}
10.
static int MOD=1e9+7;
class Solution {
public:
    int delay,forget;
    vector<long> memo;
    // Total number of people who would have found out about the secret by the nth day.
    long dp(int n) {
        if(!n)
            return 0;
        if(memo[n]!=-1)  // Return cached result if exists.
            return memo[n];
		// Current contribution of 1 person who knows the secret
        long result=1;
        for(int i=delay;i<forget;i++)       // Number of people that the secret will be forwarded to
            if(n-i>=0)
                result=(result+dp(n-i))%MOD;
        return memo[n]=result;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        this->delay=delay;
        this->forget=forget;
        memo.resize(n+1,-1);
        return (dp(n)-dp(n-forget)+MOD)%MOD;    // Subtract the people who found out by the `n-forget` day as observed.
    }
};
11.
class transaction {
public:
    int time;
    int amount;
    string city;
    string tran;
    bool marked;
    
    transaction (int t, int a, string c, string tr) {
        tran = tr;
        time = t;
        amount = a;
        city = c;
        marked = false;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        if(transactions.empty())
            return {};
        
        unordered_map<string, vector<transaction*>> trans;
        
        for(string &st : transactions) {
            istringstream ss(st);
            string token = "";
           
            getline(ss, token, ',');
            string name = token;
            getline(ss, token, ',');
            int time = stoi(token);
            getline(ss, token, ',');
            int amount = stoi(token);
            getline(ss, token, ',');
            string city = token;
            
            transaction *t = new transaction(time, amount, city, st);
            trans[name].push_back(t);
        }
        vector<string> result;
        
        for(auto &p : trans) {
           
            sort(p.second.begin(), p.second.end(), [](const transaction* a, const transaction* b) {
                return a->time < b->time;
            });
            for(int i=0; i<p.second.size(); i++) {
                
                if(p.second[i]->amount > 1000) {
                    result.push_back(p.second[i]->tran);
                    p.second[i]->marked = true;
                }
               
                if(i > 0 && p.second[i]->time <= p.second[i-1]->time + 60) {
                    int r = i-1;
                    while(r >= 0 && p.second[r]->time >= p.second[i]->time - 60) {
                        if(p.second[i]->city != p.second[r]->city) {
                            if(!p.second[r]->marked) {
                                result.push_back(p.second[r]->tran);
                                p.second[r]->marked = true;
                            }
                            if(!p.second[i]->marked) {
                                p.second[i]->marked = true;
                                result.push_back(p.second[i]->tran);
                            }
                        }
                        r--;
                    }
                }
            }
        }
        return result;
    }
};
12.
void pushLeft(stack<TreeNode*> &s, TreeNode* n) {
    while (n != nullptr) 
        s.push(exchange(n, n->left));
}
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> res;
    stack<TreeNode*> s1, s2;
    pushLeft(s1, root1);
    pushLeft(s2, root2);
    while (!s1.empty() || !s2.empty()) {
        stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : 
            s1.top()->val < s2.top()->val ? s1 : s2;
        auto n = s.top(); s.pop();
        res.push_back(n->val);
        pushLeft(s, n->right);
    }
    return res;
}
13.
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<vector<int> > ld = grid, rd = grid;//ld = left diagonal, rd = right diagonal
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int pi = i - 1;
                int prevj = j - 1;
                if(pi >= 0 && prevj >= 0) ld[i][j] += ld[pi][prevj];
                prevj = j + 1;
                if(pi >= 0 && prevj < n) rd[i][j] += rd[pi][prevj];
            }
        }
        map<int, int> cnt;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ++cnt[grid[i][j]];
                for(int k = 1; k <=max(m, n); ++k) {
                    int left = j - k;
                    int right = j + k;
                    int bot = i + 2 * k;
                    if(left < 0 || right >= n || bot >= m) continue;
                    int sum = rd[i + k][left] - rd[i][j] 
                                         + ld[i + k][right] - ld[i][j] 
                                         + ld[bot][j] - ld[i + k][left]
                                         + rd[bot][j] - rd[i + k][right]
                                         + grid[i][j] - grid[bot][j];
                    ++cnt[sum];
                }
                while(cnt.size() > 3) {
                    auto it = cnt.begin();
                    cnt.erase(it);
                }
            }
        }
        vector<int> ans;
        for(auto it = cnt.rbegin(); it != cnt.rend(); it++) {
            ans.push_back(it->first);
            if(ans.size() >= 3) return ans;
        }
        return ans;
    }
};
14.
int rev(int n) {
    int res = 0;
    for (; n > 0; n /= 10)
        res = res * 10 + n % 10;
    return res;
}
int countNicePairs(vector<int>& nums) {
    unordered_map<int, int> m;
    int res = 0;
    for (auto n : nums)
        res = (res + m[n - rev(n)]++) % 1000000007;
    return res;
}
15
class Solution {
public:
    int result = 0;
    int n = 0;
    int maximumGood(vector<vector<int>>& statements) {
        n = statements.size();
        string cur = "";
        dfs(statements, cur, 0, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& statements, string& cur, int index, int goodPersonCount){
        if(index == n){
            //Check if cur is valid
            if(isValid(cur, statements)) result = max(goodPersonCount, result);
            return;
        }
        
        //Make current person a good person and call DFS
        cur.push_back('1');
        dfs(statements, cur, index+1, goodPersonCount+1);
        
        //Backtrack: Make current person a bad person and call DFS
        cur.back() = '0';
        dfs(statements, cur, index+1, goodPersonCount);
        
        cur.pop_back();
    }
    
    bool isValid(string& cur, vector<vector<int>>& statements){
        //isValid() will check if the statement of goodPerson (i) about person (j) i.e. statement[i][j], is contradictory to what we have in cur[j]
        
        //If it is contradictory, then in terms of question i is lying, and is not a goodPerson, so this is not a valid count.
        
        //If s[i][j] == 2, i.e. person i said nothing about j, then we can skip it.
        for(int i=0; i<n; i++){
            if(cur[i] == '1'){ //We only care about what good people say
                //Now we check what they said is in accordance with what we have in cur
                for(int j=0; j<n; j++){
                    if(statements[i][j] != 2 && statements[i][j] != cur[j] - '0') return false;
                }
            }
        }
        
        //All statements made by good person is in accordance with cur, so we have a valid count of good people
        return true;
    }};
