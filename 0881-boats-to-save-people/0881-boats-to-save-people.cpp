class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        sort(people.begin(), people.end());
        int start = 0;
        int end = people.size()-1;
        while(start<=end){
            if(people[start]+people[end]<=limit){
                count++;
                start++;
                end--;
            }
            else{
                count++;
                end--;
            }
        }
        return count;
    }
};