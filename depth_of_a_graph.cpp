int depth_dfs(vvi g, int src, vector<bool> visited, int depth){
	visited[src]=true;
	ans = max(ans,depth);
	for(int nbr:g[src]){
		if(!visited[nbr]){
			visited[nbr]=true;
			depth_dfs(g,nbr,visited,depth+1);
		}
	}

	return ans;
}

// call it for every node in the graph in case of a forest