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
#include <algorithm>
#include <vector>
using namespace std; 

bool condition_of_ans(const vector<int> &ans) {
    // kiem tra hoan vi dang co theo dieu kien de bai 
    return true; 
}

void show(const vector<int> &ans) {
    int n = ans.size();
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " "; 
    }
    cout << "\n"; 
}

void generate(vector<int> &ans, bool &stop) {
    int n = ans.size(); 
    for (int i = n - 2; i >= 0; i--) {
        if(ans[i] < ans[i + 1]) {
            for (int j = n - 1; j > i; j--) {
                if (ans[j] > ans[i]) {
                    swap(ans[i], ans[j]); 
                    reverse(ans.begin() + i + 1, ans.end()); 
                    return; 
                }
            }
        }
    }
    stop = true; 
}

void initialize(vector<int> &ans) {
    int n = ans.size(); 
    for (int i = 0; i < n; i++) {
        ans[i] = i + 1;
    }
}

int main()
{
    int n; 
    cin >> n;

    bool stop = false; 
    vector<int> ans(n); 
    initialize(ans); 

    while (!stop) {
        show(ans); 
        generate(ans, stop); 
    }
    ans.clear(); 

    return 0; 
}