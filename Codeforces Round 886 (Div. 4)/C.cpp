// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
    

//     int t;
//     cin >> t;
//     while(t--)
//     {
//       long long n , k;
//       cin >> n  >> k;
//       long long array[n];
//       for(long long index = 0; index < n; index++) cin >> array[index];
//       sort(array, array+ n);
//       int index = 0;
//       long long result = 0;
//       while(index < n)
//       {
//         int two_ind = index + 1;
//         while(j < n){
//           if(array[j] - array[j - 1] > k){
//             break;
//           }
//           two_ind++;
//         }
//         long long two_res = two_ind - index;
//         result = max(result , two_res);
//         index = two_ind;
//       }
//       cout << n - result << endl;
//     }
// }
