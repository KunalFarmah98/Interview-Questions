

import java.util.*;
import java.lang.*;

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

class Main {

    static int findPaths(Map<Integer,ArrayList<Integer>> m , int src, int dest){
        Queue<Integer> q = new LinkedList<>();
        boolean [] visited = new boolean [m.size()+1];
        q.add(src);
        visited[src]=true;
        q.add(null);
        int len=1;
        int shortest=0;
        int ans=0;
        while(q.size()>0){
            if(q.peek()==null){
                q.remove();
                len++;
                if(q.size()>0)
                    q.add(null);
                    //q.add(null);
                continue;
            }
            Integer curr = q.peek();
            visited[curr]=true;
            q.remove();
            for(Integer nbr : m.get(curr)) {
                if(visited[nbr])
                    continue;

                q.add(nbr);
                if (nbr == dest) {
                    if (shortest == 0) {
                        shortest = len;
                        ans++;
                    } else if (len == shortest) {
                        ++ans;
                    } else return ans;
                }
            }
        }

        return ans;

    }
    public static void main(String args[] ) throws Exception {

        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int m = s.nextInt();// Reading input from STDIN
        Map<Integer,ArrayList<Integer> >map = new HashMap<>();

        for(int i=0; i<m; i++){
            ArrayList<Integer> temp = new ArrayList<>();
            ArrayList<Integer> temp2 = new ArrayList<>();
            Integer src = s.nextInt();
            Integer d = s.nextInt();
            if(map.get(src)==null){
                temp.add(d);
                map.put(src,temp);

                if(map.get(d)==null){
                    temp2.add(src);
                    map.put(d,temp2);
                }
                else{
                    map.get(d).add(src);
                }
            }

            else if(map.get(d)==null) {
                temp2.add(src);
                map.put(d, temp2);
                if (map.get(src) == null) {
                    temp.add(d);
                    map.put(src, temp);
                }
                else{
                    map.get(src).add(d);
                }
            }
            else{
            //else if(map.get(src)!=null && map.get(d)!=null) {
                map.get(src).add(d);
                map.get(d).add(src);
            }
        }

        int q = s.nextInt();
        while(q>0){
            int src = s.nextInt();
            int dest = s.nextInt();
            int ans = findPaths(map,src,dest);
            System.out.println(ans);
            --q;
        }

    }
};
