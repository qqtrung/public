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
    for (const int &i : ans) {
        cout << i << " "; 
    }
    cout << "\n"; 
}

void generate(vector<int> &ans, const int &n, bool &stop) {
    int idx = n - 1; 
    while (ans[idx] && idx >= 0) {
        ans[idx] = 0; 
        idx--; 
    }

    if (idx < 0)
        stop = true; 
    else   
        ans[idx] = 1; 
}

int main()
{
    int n;
    cin >> n; 

    bool stop = false; 
    vector<int> ans(n, 0); 

    while (!stop) {
    /*
        if (condition_of_ans(ans)) 
            show(ans); 
    */
        show(ans); 
        generate(ans, n, stop); 
    }
    ans.clear(); 

    return 0; 
}