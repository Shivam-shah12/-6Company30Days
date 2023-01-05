
//                                Microsoft Question ---> #6company30daysChallenge
// --------->>                        Total Question I Solved ::  12

// ----> (1).  Evaluate Reverse Polish Notation

      class Solution {
      public:
      bool isOperand(string x)
      {
        if(x=="+"||x=="-"|| x=="/"||x=="*")
        return 0;
         else
        return 1;
      }
      int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(isOperand(tokens[i]))
            {
               s.push(stoi(tokens[i]));
            }
            else
            { 
                
                if(!tokens[i].compare("+"))
                {
                    int one=s.top();s.pop();
                    int two=s.top();s.pop();
                    s.push(two+one);
                }
                else if(!tokens[i].compare("-"))
                {
                    int one=s.top();s.pop();
                    int two=s.top();s.pop();
                    s.push(two-one);
                }
                else if(!tokens[i].compare("/"))
                {
                   int one=s.top();s.pop();
                    int two=s.top();s.pop();
                    s.push(two/one);
                }
                else if(!tokens[i].compare("*"))
                {
                    int one=s.top();s.pop();
                    int two=s.top();s.pop();
                    s.push(two*one); 
                }
            }
        }
       return s.top();
      }
   };
   
   
// ------> (3). Bulls and Cow Question


class Solution {
public:
    string getHint(string secret, string guess) {
        
       int n=secret.size();
        int cntb=0,cntc=0;
        map<int,int> mp1;
        map<int,int> mp2;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                cntb++;
            else
            {
                mp1[secret[i]-'0']++;
                mp2[guess[i]-'0']++;
            }
            
        }
        for(auto it:mp1)
        {
            if(mp2.find(it.first)!=mp2.end())
            cntc+=min(mp2[it.first],it.second);
        }
        string s="";
        s=to_string(cntb)+"A"+to_string(cntc)+"B";
        return s;
        }
};


// ------->(4). Rotated Function 

class Solution {
public:
    int maxRotateFunction(vector<int> nums)
    {
        int sum=0, sum1=0,ans=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            sum1+=(i*nums[i]);
        }
     
        ans=sum1;
        for(int i=nums.size()-1; i>=0; i--){
            sum1+=sum-(nums[i]*nums.size());
            ans=max(ans, sum1);
        }
       
        return ans;
    }
};


// ------>(2). Combination Sum with a Twist


class Solution {
public:
vector<vector<int>> ans;
void f(int i,vector<int> &nums,vector<int> &ds,int tar,int k)
    {

        if(i>=nums.size())
        {
            if(ds.size()==k and tar==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(nums[i]<=tar)
        {
            ds.push_back(nums[i]);
            f(i+1,nums,ds,tar-nums[i],k);
            ds.pop_back();
        }
        f(i+1,nums,ds,tar,k);
    }
   
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        vector<int> ds;
       for(int i=1;i<=9;i++)
       {
           nums.push_back(i);
       }
        f(0,nums,ds,n,k);
        return ans;
    }
}; 

// ----->(5).Largest Divisible Subset


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n=nums.size(), maxi=1, num=-1;
        vector<int>v;
        sort(nums.begin(), nums.end());
        vector<int>arr(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(!(nums[i]%nums[j]) && arr[i]<arr[j]+1){
                    arr[i]=arr[j]+1;
                    if(maxi<arr[i]){
                        maxi=arr[i];
                    }
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            if(maxi==arr[i] && (num==-1 || !(num%nums[i]))){
                v.push_back(nums[i]);
                maxi--;
                num=nums[i];
            }
        }
        return v;
    }
};


// ------>(6).  Perfect Rectangles

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
         int n = rectangles.size();

    if (n == 1) return true;

    map<pair<int, int>, int> pointCounts;

    for (auto& rect : rectangles) {
      pointCounts[{rect[0], rect[1]}]++;
      pointCounts[{rect[2], rect[3]}]++;
      pointCounts[{rect[0], rect[3]}]--;
      pointCounts[{rect[2], rect[1]}]--;
    }

    int numMarks = 0;

    for (auto it = pointCounts.begin(); it != pointCounts.end(); it++) {
      if (it->second != 0) {
        if (abs(it->second) != 1) return false;

        numMarks++;
      }
    }

    return numMarks == 4;
    }
}; 
   
   
// ------>(9).Number of Pairs Satisfying Inequality


class Solution {
public:
      long long int count=0;

   void checkCount(vector<int>& nums, int start, int mid, int end,int d)
    {
        int l = start, r = mid + 1;
        while(l <= mid && r <= end)
        {
            if(nums[l]<=(nums[r]+d)) 
            {
                count += (end - r+1);
                l++;
            }
            else     
            {
                r++;
            }
        }
        sort(nums.begin() + start, nums.begin() + end + 1);  
        return;     
    }
    void mergeSort(vector<int>& nums, int start, int end,int d)
    {
        if(start == end) 
            return;
        
        int mid = (start + end)/2;
        mergeSort(nums,start, mid,d);
        mergeSort(nums,mid+1,end,d);
        
        checkCount(nums,start,mid,end,d);
        return;
        
    }

    long long numberOfPairs(vector<int>& a, vector<int>& b, int d) 
    {
        count = 0;
        int n = a.size();
        vector<int>c(n);  
        
        for(int i=0;i<n;i++)
        c[i]=a[i]-b[i];               
			
        mergeSort(c,0,n-1,d);
		
        return count;
    }
};


// ----->(10).  Shortest Unsorted Continuous Subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        vector<int> new_arr=nums;
        sort(new_arr.begin(),new_arr.end());
    
        while(i<j)
        {
           if(nums[i]==new_arr[i] && nums[j]==new_arr[j])
           {i++;j--;}
           else if(nums[i]==new_arr[i])
           i++;
           else if(nums[j]==new_arr[j])
           j--;
           else 
           return abs(i-j)+1;
        }
        
        
       return 0; 
    }
};

// ------>(12).  Happy Prefix

class Solution {
public:
     string longestPrefix(string s) {
        string ans="";
        vector<int>pos(s.size(), 0);
        int i=0, j=1;
        while(j<s.size()){
            if(s[i]==s[j]){
                pos[j]=i+1;
                i++;
                j++;
            }
            else if(i){
                i=pos[i-1];
            }
            else{
                j++;
            }
        }
        ans=s.substr(0, i);
        return ans;
    }
};
   
//  ----->(13).  Airplane Seat Assignment Probability
 
 class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1)
        return 1.00;
        else 
        return 0.5;
        
    }
};
   
// ------>(14). Minimum Deletions to Make Array Divisible

class Solution {
public:
    int LCM(vector<int>numsDivide)
    {
        int gcd=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++)
        {
            int num=numsDivide[i];
            while(num>0)
            {
                int tmp=gcd%num;
                gcd=num;
                num=tmp;
            }
        }
        return gcd;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int lcm=LCM(numsDivide);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(lcm%nums[i]==0)
            return i;
        }
        return -1;
    }
};

// ------>(15).  Number of Substrings Containing All Three Characters

class Solution {
public:
    
    int numberOfSubstrings(string s) {

       int count=0;
       int num_a=-1;int num_b=-1;int num_c=-1;
       for(int i=0;i<s.length();i++)
       {
           if(s[i]=='a')
           num_a=i;
           else if(s[i]=='b')
           num_b=i;
           else
           num_c=i;
           if(i>1)
           {
               int min_a_b=min(num_a,num_b);
               count+=min(min_a_b,num_c)+1;
           }
       }
       return count;

    }
};
   
   
   
   
   
