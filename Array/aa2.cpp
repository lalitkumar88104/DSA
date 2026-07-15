#include <bits/stdc++.h>
using namespace std;

// Function to return union of two vectors  

vector<int> unionn(vector<int> a, vector<int> b) {      // Brute force sol for union of two vector tc - O(n1 logn) + O(n2 logn) + O(n1 + n2);
  set <int> st;                                         // sc - O(n1 + n2)  + (O(n1 + n2) but this one is use for return the ans of array it didnt use for solving)
   for(int i = 0 ; i < a.size() ; ++i){
    st.insert(a[i]);
  }
  for(int i = 0 ; i < b.size() ; i++){
    st.insert(b[i]);
  }
  vector <int> arr;
  for (auto it : st){
    arr.push_back(it) ;
  }
  return arr;
}

vector<int> unionarray(vector <int> a , vector <int> b){  // optimal sol for union of two sorted vector; tc - O(n1 + n2); sc = (O(n1 + n2)for returning the ans not for solving)
  int i = 0;
  int j = 0;
  int n1 = a.size();
  int n2 = b.size();
  vector <int> result;
  while(i<n1 && j<n2){
    if (a[i] <= b[j]){
      if(result.empty() || a[i]!=result.back()){
        result.push_back(a[i]);
      }
      i++;
    }
    else {
      if(result.empty() || b[j] != result.back()){
      result.push_back(b[j]);
      }
      j++;
    }
  }
  while(i < n1){
    if(result.empty() ||a[i] != result.back()){
      result.push_back(a[i]);
    }
    i++;
  }
  while(j<n2){
    if(result.empty() || b[j] != result.back()){
      result.emplace_back(b[j]);
    }
    j++;
  }
  return result;
}

int main() {
    int n1, n2;
    cout << "Enter size of vector a: ";
    cin >> n1;
    vector<int> a(n1);
    cout << "Enter elements of vector a:\n";
    for (int i = 0; i < n1; i++) {
        cin >> a[i];
    }

    cout << "Enter size of vector b: ";
    cin >> n2;
    vector<int> b(n2);
    cout << "Enter elements of vector b:\n";
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
    }

    vector<int> result = unionarray(a, b);

    cout << "Union of vectors: ";
    for (int x : result) cout << x << " ";  // this is ranfe base for loop 
    return 0;
}
