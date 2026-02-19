
// here simple thinking is that component creation and the points are treated like nodes and condition s teat like path is present or not so question is solved here simple dfs tells us that how many groups are present 
//from each group all can be removed except one so ans will be stopns .size()-components

class Solution {
public:

void dfs(  map<pair<int,int>,int>&visited, map<pair<int,int>,vector<pair<int,int>>>&list,pair<int,int>p){

    if(visited[p]==1)return;
    visited[p]=1;
    for(auto v:list[p]){
         dfs(visited,list,v);

    }
    return;
}
    int removeStones(vector<vector<int>>& stones) {

        map<pair<int,int>,vector<pair<int,int>>>list;

        for(int i=0;i<stones.size();i++){
            for(int j=0;j<stones.size();j++){
                if( i!=j&& (stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]))
                list[{stones[i][0],stones[i][1]}].push_back({stones[j][0],stones[j][1]});
            }
        }

        int cnt=0;
        int n=list.size();

        map<pair<int,int>,int>visited;
        for(auto it:stones){
            visited[{it[0],it[1]}]=0;
        }

    for(int i=0;i<stones.size();i++){
       
        if(visited[{stones[i][0],stones[i][1]}]==0){
             cnt++;
            dfs(visited,list,{stones[i][0],stones[i][1]});
        }
      
    
    
    }

    return stones.size()-cnt;
        
    }
};