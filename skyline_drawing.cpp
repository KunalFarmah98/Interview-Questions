class Solution {
public:
    class Bpt{
        public:
        int x,h;
        bool isstart;
        Bpt(int x,int h,bool isstart=true){
            this->x = x;
            this->h = h;
            this->isstart = isstart;
        }
    };
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
     vector<Bpt> points;
     for(auto v : buildings){
         points.push_back(Bpt(v[0],v[2]));
         points.push_back(Bpt(v[1],v[2],false));
     }   
     // lower x comes first
     // higher start is first
     // lower end is first
     // else start comes first
     sort(points.begin(),points.end(),[](Bpt a,Bpt b){
         if(a.x != b.x)
             return a.x<b.x;
        if(a.isstart && b.isstart)
            return a.h>b.h;
         else if(!a.isstart && !b.isstart)
             return a.h<b.h;
         return a.isstart;
     });
        
    map<int,int> m;
    m[0] = 1;
    int prev_max = 0;
    vector<vector<int>> ans;
        
    for(Bpt bpt : points){
      if(bpt.isstart)
         m[bpt.h]++;
      else{
            m[bpt.h]--;
          if(m[bpt.h] == 0)
              m.erase(bpt.h);
          
         }
      int cur_max = m.rbegin()->first;
      if(cur_max != prev_max)
         {
             ans.push_back({bpt.x,cur_max});
             prev_max = cur_max;
         }  
     }
        return ans;
    }
};