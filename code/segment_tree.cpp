#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
  vector<int> tree; int n;
public:
  SegmentTree(vector<int>& safetyData) { n = safetyData.size(); tree.resize(4*n); build(safetyData,0,0,n-1); }
  void build(vector<int>& arr, int node, int start, int end) {
    if (start == end) tree[node] = arr[start];
    else {
      int mid = (start+end)/2; build(arr,2*node+1,start,mid); build(arr,2*node+2,mid+1,end);
      tree[node] = tree[2*node+1] + tree[2*node+2];
    }
  }
  int query(int node,int start,int end,int l,int r) {
    if (r < start || l > end) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid=(start+end)/2;
    return query(2*node+1,start,mid,l,r)+query(2*node+2,mid+1,end,l,r);
  }
  int rangeQuery(int l,int r){ return query(0,0,n-1,l,r); }
};

int main(){ vector<int> crimeRisk = {3,5,2,6,4,1}; SegmentTree st(crimeRisk);
  cout<<"Crime risk between location 1 and 4: "<<st.rangeQuery(1,4)<<endl;
  cout<<"Crime risk between location 2 and 5: "<<st.rangeQuery(2,5)<<endl; return 0; }
