#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
#include <iostream> 
#include <map> 
#include <iterator> 
#include <iostream> 
#include <map> 
#include <iterator> 
  
using namespace std; 

using namespace std;
using std::vector;

double calculate_distance(vector<int> &x,vector<int> &y,int p1,int p2){
	return  sqrt(pow(x[p2] - x[p1], 2) + pow(y[p2] - y[p1], 2) * 1.0);
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  const double INF = 100000;
  vector<double> dist(x.size(),INF);
  vector<int> prev(x.size(),-1);
  dist[0] = 0;
  
  multimap<double,int> pq;
  for(int i = 0 ; i < x.size() ; i++){
  	pq.insert(pair<double, int> (dist[i],i));
  }
  
  
  while(!pq.empty()){
  	int u = pq.begin()->second;
  	pq.erase(pq.begin());
  	
  	multimap<double,int> :: iterator it;
  	for(it = pq.begin(); it != pq.end() ;){
  		int v = it->second;
  		double temp = calculate_distance(x,y,u,v);
  		if(dist[v] > temp){
  			dist[v] = temp;
  			prev[v] = u;
  			multimap<double,int> :: iterator cur = it;
  			it++;
  			pq.erase(cur);
  			pq.insert(pair<double,int> (temp,v));
		  }
		it++;
	}
  }
  
  for(int i = 0 ; i < prev.size() ; i++){
  	cout << prev[i] << endl;
  	if(prev[i] != -1){
  		result = result + calculate_distance(x,y,i,prev[i]);
	  }
  }
  
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
