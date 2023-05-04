class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>rq,dq;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                rq.push(i);
            }
            else{
                dq.push(i);
            }
        }
        
        int a,b;
        while(!rq.empty()&&!dq.empty()){
            a=rq.front();
            b=dq.front();
            rq.pop();
            dq.pop();
            if(a<b){
                rq.push(a+senate.size());
            }
            else{
                dq.push(b+senate.size());
            }
        }
        if(rq.size()>dq.size()){
            return "Radiant";
        }
        else{
            return "Dire";
        }
    }
};