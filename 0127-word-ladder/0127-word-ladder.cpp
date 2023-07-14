class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //Make up a set to store the word List
        unordered_set<string>dict(wordList.begin(), wordList.end());
        //Check if the end word is in the dict or not 
        if(dict.find(endWord) == dict.end())
            return 0;
        //Make queue to perform BFS 
        queue<string>q;
        //Push the beginWord into the queue
        q.push(beginWord);
        //Create A distance Mapping between the word and their distances 
        unordered_map<string, int>dist;
        //Put the beginWord into the dist with ditance 1 
        dist[beginWord] = 1;
        
        //Perform the BFS because we have to find the shortest transformation 
        while(!q.empty()){
            string word = q.front();
            q.pop();
            
            for(int i=0;i<word.length();i++){
                string newWord = word;
                for(char c = 'a'; c<='z';c++){
                    newWord[i]=c;
                    if(newWord == endWord){
                        return dist[word] + 1;
                    }
                    if(dict.find(newWord)!=dict.end() 
                        && dist.find(newWord) == dist.end()){
                        q.push(newWord);
                        dist[newWord] = dist[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
};