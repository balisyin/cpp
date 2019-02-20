/* *
 * balisyin 20190211
 * all dynamic program algorithm
 * optimal substructure && overlap subproblem
 * */
#include<bits/stdc++>
using namespace std;

int max(int m, int n) {return (m>n) ? m:n}
int min2(int m, int n) {return (m>n) ? n:m}
int min3(int m, int n, int l) {return min2(min2(m, n), l)}

///DP1 LIS longest increase subsequence
int lis_int(int arr[], int n){
    int max_len = -1;
    int lis[n];
    memset(lis, 0, sizeof(int)*n);
    lis[0] = 1;
    for(int i = 1; i < n; ++i){
        lis[i] = 1;
        for(int j = 0; j < i; ++j){
            if(arr[j] < arr[i] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }
    for(i = 0; i < n; ++i){
        if(max_len < lis[i])
            max_len = lis[i];
    }
    return max_len;
}


///DP2 LCS longest common subsequence 
//if(arr1[m-1] == arr2[n-1]) len = lcs(arr1, arr2, m-1, n-1) + 1;
//else len = max(lcs(arr1, arr2, m-1, n), lcs(arr1, arr2, m, n-1))
int lcs(char arr1[], char arr2[], int m, int n){
    int lcs[m][n];
    memset(lcs, 0, sizeof(int) * m * n);
    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            if(arr1[i] == arr2[j]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } else{
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    return lcs[m-1][n-1];

}


///DP3 EditDistance insert/remove/replace
//if(arr1[m-1] == arr2[n-1]) len = edd(arr1, arr2, m-1, n-1)
//else len = 1 + min(edd(arr1, arr2, m-1, n), edd(arr1, arr2, m, n-1), edd(arr1, arr2, m-1, n-1))
int editDistance(string arr1, string arr2, int m, int n){
    int edd[m+1][n+1];
    memset(edd, 0, size(int)*m*n);
    for(int i = 0; i <= m; ++i){
        for(int j= 0; j <= n; ++j){
            if(i == 0)
                edd[i][j] = j;
            else if(j == 0)
                edd[i][j] = i;
            else{
                if(arr[i-1] == arr[j-1]){
                    edd[i][j] = edd[i-1][j-1];
                }else{
                    edd[i][j] = 1 + min(edd[i][j-1], edd[i-1][j], edd[i-1][j-1]);
                }
            }

            
        }
    }
    return edd[m][n];
}


///DP4 MinCostPath minCostPath(int arr[][], int m, int n)
//mcp(arr, m, n) = arr[i][j] + min(mcp(arr, i-1, j),mcp(arr, i, j-1), mcp(arr, i-1,j))
int mcp(int arr[][], int m, int n){
    int m = INT_MAX;
    int tmp[m][n];
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(i == 0 && j == 0){
                tmp[i][j] = arr[i][j];
            }else if(i == 0){
                tmp[i][j] = arr[i][j] + tmp[i][j-1];
            }else if(j == 0){
                tmp[i][j] = arr[i][j] + tmp[i-1][j];
            }else{
                tmp[i][j] = arr[i][j] + min(tmp[i-1][j], tmp[i][j-1], tmp[i][j]);
            }
        }
    }
    return tmp[m-1][n-1];
}


///DP5 CoinChange
//coinChange(int coins[], int n, int sum) = coinChange(coins, n-1, sum) + coinChange(coins, n, sum-coins[n-1])
int coinChange(int coins[], int n, int sum){
    int tmp[n][sum+1];
    int in, ex;

    for(int i = 0; i < n+1; ++i){
        for(int j = 0; j < sum; ++j){
            if(j == 0){ 
                tmp[i][j] = 1;
            }else{
                ex = (i>0) ? tmp[i-1][j] : 0;
                in = (j > coins[i]) ? tmp[i][j-coins[i]] : 0;
                tmp[i][j] = ex + in;
            }
        }
    }
    return tmp[n-1][sum];

}

///DP6 MatrixChainMultiplication
//mcm(int arr[], int l, int r) = mcm(arr, l, k) + mcm(arr, k+1, r) + arr[l-1]*arr[k]*arr[r];
int mcm(int arr[], int l, int r){
    int min_v = INT_MAX;
    int tmp;
    if(l == r)
        return 0;
    for(int i = l; i < r; ++i){
        tmp = mcm(arr, l, i) + mcm(arr, i+1, r) + arr[l-1]*arr[i]*arr[r];
        if(tmp < min_v)
            min_v = tmp;
    }

    return min_v;
}//recursion
int mcm(int arr[], int n){
    int tmp[n][n];
    int min;
    int i,j,k,len;
    
    for(i = 0; i < n; ++i){
        tmp[i][i] = 0;
    }
    for(len=2; len < n; ++len){
        for(i=1; i < n - len +1; ++i){
            j = i + len;
            int tmp[i][j] = INT_MAX;
            for(k = i; k < j; k++){
                min = tmp[i][k] + tmp[k+1][j] + arr[i-1]*arr[k]*arr[r];
                if(min < tmp[i][j]){
                    tmp[i][j] = min;
                }
            }
            
        }
    }
    return tmp[1][n-1];

}//loop


///DP7 BinomialCoefficient
//Selelct(n,k) = Select(n-1,k-1) + Select(n-1,k)
//if k==0||k==n Select(n,k) = 1;
int BinomialCoefficient(int n, int k){
    int tmp[k+1];
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j < min(i,k); ++j){
            if(j == 0 || j == i)
                tmp[j] += tmp[j-1]
        }
    }

    return tmp[k];
}


///DP8 0-1KnapSack
//knapSack(int cap, int wt[], int val[], int n)
// = max(knapSack(cap, wt, val, n-1), val[n-1] + knapSack(cap-wt[n-1],wt,val,n-1))
int knapSack(int cap, int wt[], int val[], int n){
    if(cap == 0 || n == 0)
        return 0;
    if(cap < wt[n-1])
        return knapSack(cap, wt, val, n-1);
    else
    {
        return max(knapSack(cap,wt,val,n-1), val[n-1] + knapSack(cap-wt[n-1], wt, val, n-1));
    }  
}//recursive

int knapSack(int cap, int wt[], int val[], int n){
    int tmp[cap][n];
    int i,j;
    for(i = 0; i < cap; ++i){
        for(j = 0; j < n; ++j){
            if(i = 0 || j = 0){
                tmp[i][j] = 0;
            }
            if(wt[j-1] > i)
                tmp[i][j] = tmp[i][j-1];
            else 
                tmp[i][j] = max(tmp[i][j-1], val[j-1] + tmp[i-wt[j-1]][j-1]);
        }
    }
    return tmp[cap][n];

}//iterate

///DP9 EggDropPuzzle




///DP


///DP m move to get longest same substring
///like str = "ababa" m = 2; get str="baaab"
#define ALPHA 26

int sameLen(int m, int n, int arr[]){
    if(m == n)
        return 0;
    if(m + 1 == n)
        return arr[n] - arr[m] - 1;
    else {
        return sameLen(m+1, n-1, arr) + arr[n] - arr[m] - (n - m);
    }
}

int getSameLen(string str, num) {
    int len = str.length();
    int matrix[len][ALPHA];
    int letter[ALPHA];
    int m[len];
    memset(arr, 0, sizeof(len*ALPHA)); 
    memset(letter, 0, ALPHA);
    memset(m, 0, len);
    int i,j,k;
    for(i = 0; i < len; ++i){
        matrix[i][str[i]-'a'] = 1;
    }
    for(j = 0; j < ALPHA; ++j){
        k = 0;
        for(i = 0; i < len; ++i){
            if(matrix[i][j] == 1)
                m[k++] = i;
        }
        if(k == 1){
            letter[j] = 1;
        } else {
            for(i = 0; i < k; ++i){
                for(int ii = i+1; ii < k; ++ii){
                    if(sameLen(i, ii, m) < num){
                        if(ii - i + 1 > tmp)
                            tmp = ii - i + 1;
                    }
                }
            }
        }
        letter[j] = tmp;
    }
    int max = -1;
    for(i = 0; i < ALPHA; ++i){
        if(letter[i] > max)
            max = letter[i];
    }

    retrun max;
}

///DP


int main(){



    return 0;
}