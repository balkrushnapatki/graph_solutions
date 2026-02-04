//basically diameter of a graph is farest distance between two nodes 

// here one clue is that by choosing any node and calculating the farest distance of choosen node to other node ,the other 
// node is fix one end of diameter 


//so my statergy is
//1 choose randaom node 
// 2 apply diajekastra find farest distance from randamly choosed node 
// from that node again apply diajekastra and find other farest node simple



class Solution {
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        typedef pair<int,int>p;
        map<int,vector<int>>list;
        for(int i=0;i<edges.size();i++){
            list[edges[i][0]].push_back(edges[i][1]);
             list[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>ans(V,INT_MAX);
        
        priority_queue<p,vector<p>,greater<p>>q;
        ans[0]=0;
        q.push({0,0});
        
        while(!q.empty()){
            
            int a=q.top().first;
            int b=q.top().second;
            q.pop();
            
            if(ans[b]<a)continue;
            
            for(auto v:list[b]){
                
              
              if( ans[v]>a+1)
              {  ans[v]=a+1;
                q.push({ans[v],v});
              }
            }
            
        }
        
        int first_end=max_element(ans.begin(),ans.end())-ans.begin();
        
        vector<int>ans2(V,INT_MAX);
        
         ans2[first_end]=0;
        q.push({0,first_end});
        
         while(!q.empty()){
            
            int a=q.top().first;
            int b=q.top().second;
            q.pop();
            
            if(ans2[b]<a)continue;
            
            for(auto v:list[b]){
                
              
              if( ans2[v]>a+1)
              {  ans2[v]=a+1;
                q.push({ans2[v],v});
              }
            }
            
        }
        
         int diameter=*max_element(ans2.begin(),ans2.end());
        
      return diameter;
        
    }
};
