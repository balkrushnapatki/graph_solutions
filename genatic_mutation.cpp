
// basically what we think that how can  graph is present in it .honestely i  am 
//confused that how graph is related but what is concept that consider a string or start string 
//as a first node and replace character and on reach replacement we assume that a node is created so 
// this is the thing which can be  learnt from this question 




class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        set<string> s;
        vector<char> replace{'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push(startGene);
        int ans = 0;
        s.insert(startGene);

        while (!q.empty()) {
            int k = q.size();
            ans++;
            while (k--) {

                string temp;

                for (int i = 0; i < 4; i++) {

                    for (int j = 0; j < 8; j++) {
                        temp = q.front();
                        temp[j] = replace[i];

                       
                        auto it = find(bank.begin(), bank.end(), temp);
                        
                        if (it != bank.end()) {
                             if (temp == endGene)
                            return ans;
                            
                            if (s.find(temp) == s.end()) {
                                q.push(temp);
                                s.insert(temp);
                            }
                        }
                    }
                }
                q.pop();
                
            }
        }

        return -1;
    }
};