#include "bits/stdc++.h"
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define nl "\n"
void dfs(vi edges[], int start, set<int> &visited, stack<int> &finishStack) {
	visited.insert(start);
	for (int i = 0; i < edges[start].size(); i++) {
		int adjacent = edges[start][i];
		if (visited.count(adjacent) == 0) {
			dfs(edges, adjacent, visited, finishStack);
		}
	}
	finishStack.push(start);
}

void dfs2(vi edges[], int start, set<int> &component, set<int> &visited) {
	visited.insert(start);
	component.insert(start);
	for (int i = 0; i < edges[start].size(); i++) {
		int adjacent = edges[start][i];
		if (visited.count(adjacent) == 0) {
			dfs2(edges, adjacent, component, visited);
		}
	}
}

set<set<int>> getSCC(vi edges[], vi edgesT[], int n) {
	set<int> visited;
	stack<int> finishedVertices;
	for (int i = 0; i < n; i++) {
		if (visited.count(i) == 0) {
			dfs(edges, i, visited, finishedVertices);
		}
	}
	set<set<int>> output;
	visited.clear();
	while (finishedVertices.size() != 0) {
		int element = finishedVertices.top();
		finishedVertices.pop();
		if (visited.count(element) != 0) {
			continue;
		}
		set<int> component;
		dfs2(edgesT, element, component, visited);
		output.insert(component);
	}
	return output;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    freopen("error.in","w",stderr);
    #endif
	int n;
	cin >> n;
	vi edges[n],edgesT[n];
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int j, k;
		cin >> j >> k;
		edges[j - 1].push_back(k - 1);
		edgesT[k - 1].push_back(j - 1);
	}
	set<set<int>> components = getSCC(edges, edgesT, n);
    //the code will give all the strongly connected components
    return 0;
}