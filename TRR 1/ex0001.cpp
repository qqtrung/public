/*
procedure Generate
begin
    xây dựng cấu hình ban đầu 
    bool stop = false
    while (!stop) {
        đưa ra cấu hình đang có(); 
        sinh kế tiếp(); 
    }
end
*/


#include <iostream>
#include <vector>
using namespace std; 

bool condition_of_ans(const vector<int> &ans) {
    // kiem tra hoan vi dang co theo dieu kien de bai 
    return true; 
}

void show(const vector<int> &ans) {
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] << " "; 
    }
    cout << "\n"; 
}

void generate(vector<int> &ans, const int &n, const int &k, bool &stop) {
    int idx = k; 
    while (ans[idx] == n - k + idx) {
        idx--; 
    }
    
    if (idx == 0) 
        stop = true; // co the return cho nay luon 

    ans[idx] += 1;
    for (int j = idx + 1; j <= k; j++) {
        ans[j] = ans[idx] + j - idx; 
    }
}

void initialize(vector<int> &ans) {
    for (int i = 1; i <= ans.size(); i++) {
        ans[i] = i;
    }
}

int main()
{
    int n, k;
    cin >> n >> k; 

    bool stop = false; 
    vector<int> ans(k + 1); 
    initialize(ans); 

    while (!stop) {
    /*
        if (condition_of_ans(ans)) 
            show(ans); 
    */
        show(ans); 
        generate(ans, n, k, stop); 
    }
    ans.clear(); 

    return 0; 
}