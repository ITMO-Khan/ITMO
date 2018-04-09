#include <iostream>
#include <vector>
#include <string>

using namespace std;
void vivod (vector <int> a, vector <int> b, int n, int kol){
 for (int k = 0; k < n - 1; k++)
  for (int i = 0; i < n - k; i++)
   if (b[i] > b[i+1])
    {
     swap(b[i], b[i + 1]);
     swap(a[i], a[i + 1]);
    }
 int t = 1;
 for (int i = 1; i < n; i++)
  if (b[i] != b[i-1]) t++;

 if(kol == t) {
 cout << '(' << a[1];
 for (int i = 1; i < n; i++)
  if (b[i] != b[i - 1])
   cout <<") (" << a[i];
  else
   cout << ' ' << a[i];
  cout << ')' << endl;
 }
}
 vector<int> a, Prev, Next, Blok;
 int j, n, k, kol;
 vector<bool> Forw;

int main()
{
    cin >> n >> kol;
    for (int i = 0; i < n; i++){
        a.push_back(i);
        Blok.push_back(1);
        Forw.push_back(true);
    }
    Next.push_back(0);
    vivod(a,Blok,n,kol);
    j = n;
    while (j > 1){
    k = Blok[j];
    if (Forw[j]) {
      if (Next[k] == 0) {
        Next[k] = j;
        Prev[j] = k;
        Next[j] = 0;
      }
      if (Next[k] > j){
         Prev[j] = k;
         Next[j] = Next[k];
         Prev[Next[j]] = j;
         Next[k] = j;
      }
      Blok[j] = Next[k];
    }else {
      Blok[j] = Prev[k];
      if (k == j)
       if (Next[k] == 0)
         Next[Prev[k]] = 0;
       else {
         Next[Prev[k]] = Next[k];
         Prev[Next[k]] = Prev[k];
       }
    }
    vivod(a,Blok,n,kol);
    j = n;
    while ((j > 1) && ((Forw[j] && (Blok[j] == j)) || (!Forw[j] && (Blok[j] == 1)))){
        Forw[j] = !Forw[j];
        j = j - 1;
    }
    }
}
