                                               |-----ADOBE----|
                                   
------>Question 1
class Solution {


public:
    string tostring(long long n){
        if (n==0)return "0";
        string ans;
        while (n>0){
            string dem;
            dem+= ((n%10)+'0');
            ans= dem+ans;
            n/=10;
        }
        return ans;
    }
    string fractionToDecimal(int num, int denom) {
        if (num==0)return "0";
        string ans;
        if ((num<0 && denom>0) || (num>0 && denom<0))ans.push_back('-');
        num= abs(num); denom= abs(denom);
        long long quotient= num/denom;
        long long remainder= num%denom;
        ans= ans+tostring(quotient);
        if (remainder==0)return ans;
        ans+='.';
        map<long long, int> mp;
        while (remainder != 0){
            if (mp.find(remainder)!= mp.end()){
                int pos= mp[remainder];
                ans.insert(pos,"(");
                ans+=')';
                break;
            }
            else {
                mp[remainder]= ans.length();
                remainder*= 10;
                quotient= remainder/denom;
                remainder= remainder%denom;
                ans+= tostring(quotient);
            }
        }
        return ans;
    }
};


----->Question 2
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long a = 1e10, b = 1e10;
        for (int i : nums) {
            if (i > b) return true;
            if (i > a) b = min((long long) i, b);
            a = min((long long) i, a);
        }
        return false;
    }
};


----->Question 3
class Solution {
public:
    int findKthNumber(int n, int k) {
       int result = 1;
        for(--k; k > 0; )
        {            int count = 0;
            for (long long first = static_cast<long long>(result), last = first + 1;
                first <= n; 
                first *= 10, last *= 10) 
            {
                count += static_cast<int>((min(n + 1LL, last) - first)); 
            }
            
            if (k >= count)
            {   
                ++result;
                k -= count;
            }
            else
            {   
                result *= 10;
                --k;
            }
        }
        return result; 
    }
};



----->Question 4
class Solution {
public:
    int magicalString(int n) {
        queue<int>q;
        q.push(2);
        int cnt=1;
        for(int i=2; i<n; ++i){
            int num=q.front();
            q.pop();
            if(num==1){
                cnt++;
            }
            int l;
            if(q.back()==2){
                l=1;
            }
            else{
                l=2;
            }
            for(int j=0; j<num; ++j){
                q.push(l);
            }
        }
        if(n==0){return 0;}
        return cnt;
    }
};


----->Question 5

class Solution {
public:
    int findIntegers(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i-1]+f[i-2];
        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0) {
            if (num&(1<<k)) {
                ans += f[k];
                if (pre_bit) return ans;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            --k;
        }
        return ans+1;
    }
};


---->Question 6


class Solution {
public:
    
    double knightProbability(int N, int K, int r, int c){
        
        
        if(K==0) return 1.0;
        
       
        vector<vector<double>> parentBoard(N,vector<double>(N,0.0));
        
      
        vector<vector<double>> childBoard(N,vector<double>(N,0.0));
        
      
        int rowoffset[] = {-2,-2,-1,-1,2,2,1,1};
        int coloffset[] = {1,-1,2,-2,1,-1,2,-2};
        
        int cx,cy;
        
  
        parentBoard[r][c] = 1.0;
        
     
        for(int i=0;i<K;i++)
        {
            for(int p=0;p<N;p++)
            {
                for(int q=0;q<N;q++)
                { 
                  
                    double moveProb = parentBoard[p][q]/8.0;
                    
                    // generate valid child positions
                    for(int w=0;w<8;w++)
                    {
                        cx = p + rowoffset[w];
                        cy = q + coloffset[w];

                        // update child position probability
                        if(cx>=0 && cx<N && cy>=0 && cy<N)
                            childBoard[cx][cy] += moveProb;
                    }                    
                }
            }
            
            parentBoard = childBoard;
            fill(childBoard.begin(),childBoard.end(),vector<double>(N,0.0));
        }
        

        
        double knightProb = 0.0;
      
        for(int p=0;p<N;p++)
            for(int q=0;q<N;q++)
                   knightProb+=parentBoard[p][q];

        return knightProb;
    }
};

----->Question 7
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charMap(26);
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            charMap[s[i] - 'a'].push_back(i);
        }
        
        int ans = words.size();
        
        for(auto& word : words) {
            int last = -1;
            
            for(char c : word) {
                auto& cIndexes = charMap[c - 'a'];
                auto it = upper_bound(cIndexes.begin(), cIndexes.end(), last);
                if(it == cIndexes.end()) {
                    ans--;
                    break;
                } else {
                    last = *it;
                }
            }
        }
        
        return ans;
    }
};


----->Question 8
class Solution {
public:

	int ans=INT_MAX;

	// function to check no. of different characters of two strings
	int changes(string s, string ss){
		int change=0;
		for(int i=0;i<s.length();i++){
			if(s[i]!=ss[i]) change++;
		}
		return change;
	}

	// function to traverse through the graph
	void dfs(int i, string &start, string &end, vector<vector<int>> &g, vector<bool> &visited, int count, vector<string> &bank){
		visited[i]=true;
		count++;
		// traversing through the strings which have a difference of one character for the current string
		for(int j=0;j<g[i].size();j++){
			if(bank[g[i][j]] == end) {
				// if we have found the end mutation then check the current count and assign it to ans
				ans = min(ans, count);
				return;
			}
			// if the mutation is not visited call the recursive function
			if(visited[g[i][j]] == false){
				dfs(g[i][j], start, end, g, visited, count, bank);
				// once we visit the mutation we need to assign it as not visited so that we can traverse through it once again for desired parent mutation
				visited[g[i][j]]=false;
			} 
		}

	}

	int minMutation(string start, string end, vector<string>& bank) {
		if(count(bank.begin(), bank.end(), end)<1) return -1;
		int c=0;
		vector<vector<int>> g;
		set<string> st(bank.begin(), bank.end());
		bank = vector<string>(st.begin(), st.end());
		vector<bool> visited(bank.size(), false);

		// creating a graph where the child nodes of an element consist of strings which differ with parent by one character
		for(int i=0;i<bank.size();i++){
			g.push_back({});
			for(int j=0;j<bank.size();j++){
				if(changes(bank[i], bank[j]) == 1){
					g[i].push_back(j);
				}
			}
		}

		// checking for the mutations in bank whose difference of charcters is one, to call recursive function on it
		for(int i=0;i<bank.size();i++){
			if(changes(start, bank[i]) == 1){
				if(end == bank[i]) return 1;
				else {
					dfs(i, start, end, g, visited, 1, bank);
					visited = vector<bool> (bank.size());
				}
			}
		}
		return ans==INT_MAX ? -1:ans;
	}
};
9. class Solution
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
    10. class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();

        //we need to find the min number in the matrix and also count of negative numbers in the matrix
        int small=INT_MAX,count=0;
        long long int sum=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int val=matrix[i][j];
				//finding the smallest absolute value in the matrix
                small=min(small,abs(val));
				//counting the negative numbers
                if(val<0)
                    count++;
				//finding the sum of all the values
                sum+=abs(val);
            }
        }
		//if even number of negatives, then just return sum
        if(count%2==0)
            return sum;
        else
		//subtract the value of the min absolute element
            return sum-2*small;
    }
};
11. map<int, int> rec;
    multiset<int> count;

    void update(int t, int p) {
        if (rec.find(t) != rec.end())
            count.erase(count.find(rec[t]));
        rec[t] = p;
        count.insert(p);
    }

    int current() {
        return rec.rbegin()->second;
    }

    int maximum() {
        return *count.rbegin();
    }

    int minimum() {
        return *count.begin();
    }
    12. # define MAX_VAL 100001
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=-1,end=n;        
        // Since, the array needs to be in ascending order.
        
        // PASS 1
        // Iterate from the end, and check weather the element at index "i" is the current minimum element or not. If not then "i" is the starting index.
        int curr_min=MAX_VAL;
        for(int i = n - 1; i>=0; i--) {
            if(curr_min > nums[i]) curr_min = nums[i];
            
            if(nums[i] > curr_min) start = i;
        }
        
        // PASS 2
        // Iterate from the start, and check weather the element at index "i" is the current maximum element or not. If not then "i" is the ending index.
        int cur_max = -MAX_VAL;
        for(int i=0; i<n; i++) {
            if(cur_max < nums[i]) cur_max = nums[i];
            
            if(nums[i] < cur_max) end = i;
        }
        
        // if no starting index found, that means the array is already sorted in ascending order
        if(start==-1){ 
            return 0;
        }
        return end-start+1; // number of elements between start and end index
    }
};
13.
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        // hp[i][j] represents the min hp needed at position (i, j)
        // Add dummy row and column at bottom and right side
        vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
        hp[M][N - 1] = 1;
        hp[M - 1][N] = 1;
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
};
14.
static int MOD=1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> memo(n+1,1),prefixSum(n+1,0); // New array to store prefix sum.
        memo[0]=0; // Base case
        for(int i=1;i<=n;i++) {
            // The optimization, we avoid going to negative index by max(0,i-x).
            // We are using prefix sum to get the sum of all dps from i-forget+1 to i-delay.
            memo[i]=(memo[i]+prefixSum[max(0,i-delay)]-prefixSum[max(0,i-forget)]+MOD)%MOD;
            prefixSum[i]=(prefixSum[i-1]+memo[i])%MOD; // Store the prefixSum for ith state of dp.
        }
        return (memo[n]-memo[n-forget]+MOD)%MOD; // Subtract the people who found out by the `n-forget` day as observed.
    }
};
15.
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto x:queries)
        {
            priority_queue<pair<string,int>> v;
            for(int i=0;i<nums.size();i++)
            {
                int t=nums[i].length()-x[1];
                string p=nums[i].substr(t,x[1]);
                if(v.size()<x[0])
                    v.push({p,i});
                else
                {
                    if(v.top().first > p)
                    {
                        v.pop();
                        v.push({p,i});
                    }
                }
            }
            int val=v.top().second;
            res.push_back(val);
        }
        return res;
    }
 };
