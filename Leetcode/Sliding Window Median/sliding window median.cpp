class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int a=0;
        int j=0;
        vector <double> res; // Declare result vector
        multiset <long long int, greater <int>> temp; //Multisets are a type of associative containers similar to set, with an exception that multiple elements can have same values.
        multiset <long long int, greater <int> > :: iterator itr; // declare iterator for the declared multiset to iterate through the data structure.
        for (int i=0;i<nums.size();i++){//iterate through provided vector.
            temp.insert(nums[i]);
            j++;
            if (j==k){ // when j reaches the window size.
                itr=temp.begin();
                advance(itr, temp.size() / 2);

                if(k%2 == 0) {
                    res.push_back((*itr + *(--itr))/2.0);
                }else {
                    res.push_back(*itr);
                }
                temp.erase(temp.find(nums[a]));
                a++;
                j=k-1;
            }
        }
        return res;
    }
};