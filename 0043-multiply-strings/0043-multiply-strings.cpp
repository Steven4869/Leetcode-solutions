class Solution {
public:
    string multiply(string num1, string num2) {
        //Create a vctor of size n+m with all elements 0
        vector<int>result(num1.size()+num2.size(),0);
        //Base Case
        if(num1=="0"||num2=="0")
            return "0";
        //Start with the last for both string in a nested loop 
        for(int i=num1.size()-1;i>=0;i--){
            for(int j=num2.size()-1;j>=0;j--){
                result[i+j+1]=result[i+j+1]+(num1[i]-'0')*(num2[j]-'0');
                result[i+j]=result[i+j]+result[i+j+1]/10;
                result[i+j+1]=result[i+j+1]%10;
            }
        }
        
        //Now the vector is full of the multiplied integer 
        string ans ="";
        int i=0;
        while(result[i]==0){
            i++;
        }
        while(i<result.size()){
            ans = ans + to_string(result[i]);
            i++;
        }
        return ans;
    }
};