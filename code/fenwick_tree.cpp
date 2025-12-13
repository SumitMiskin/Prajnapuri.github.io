#include <bits/stdc++.h>
using namespace std;

class FenwickTree { vector<int> BIT; int n; public: FenwickTree(int size){ n=size; BIT.assign(n+1,0);} 
  void update(int i,int value){ while(i<=n){ BIT[i]+=value; i+=i&(-i);} }
  int query(int i){ int sum=0; while(i>0){ sum+=BIT[i]; i-=i&(-i);} return sum; }
  int rangeQuery(int l,int r){ return query(r)-query(l-1); }
};

int main(){ int locations=6; FenwickTree ft(locations); ft.update(1,2); ft.update(3,1); ft.update(5,3);
  cout<<"Incidents between location 1 and 4: "<<ft.rangeQuery(1,4)<<endl;
  cout<<"Incidents between location 2 and 6: "<<ft.rangeQuery(2,6)<<endl; return 0; }
