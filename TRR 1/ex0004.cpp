/*

CAU TRUC CUA CAC BAI NHANH CAN DO LA CHUNG TA DI TU VI TRI CUR VAO VI TRI I 
THI CHUNG TA SE TINH GIA TRI TOT NHAT SE LA 

"CHI PHI DEN CUR" + "CHI PHI DI TU CUR DEN I" + "CHI PHI TOT NHAT CO THE XAY RA KHI DI TU I DEN HET" 

NEU CAN DO THOA MAN THI TA DI VAO NHANH DO NGOAI RA THI TA KHONG DI VAO NHANH DO 

*/


#include <iostream>
#include <vector>
using namespace std;

#define MAX    100 
#define INF    10000

int a[MAX][MAX];
int numCity; 
int edgeMin = INF; 


int expen = INF; 

void init()
{
    cin >> numCity; 
    for (int i = 1; i <= numCity; i++) {
        for (int j = 1; j <= numCity; j++) {
            cin >> a[i][j]; 
            if (a[i][j] != 0)
                edgeMin = min(edgeMin, a[i][j]); 
        }
    }
}       


void backtrack(int expenCur, vector<int> visited, int k, int locationCur) 
{
    for (int i = 2; i <= numCity; i++) {
        if (!visited[i]) {

            int min_expen = expenCur + a[locationCur][i] + (numCity - (k + 1) + 1) * edgeMin; 
            if (min_expen < expen) {

                visited[i] = 1; 
                backtrack(expenCur + a[locationCur][i], visited, k + 1, i); 
                visited[i] = 0; 

                // {
                //     vector<int> tmp = visited; tmp[i] = 1; 
                //     backtrack(expenCur + a[locationCur][i], tmp, k + 1, i);
                // }

                // QUAY LUI 
                if (k + 1 == numCity) {
                    expen = min(expen, expenCur + a[locationCur][i] + a[i][1]); 
                }

            } 
        }
    }
}


void process()
{
    int expenCur = 0; 
    vector<int> visited(numCity + 1, 0); 
    int k = 1; 
    int locationCur = 1; 

    for (int i = 2; i <= numCity; i++) {
        if (!visited[i]) {

            int min_expen = expenCur + a[locationCur][i] + (numCity - (k + 1) + 1) * edgeMin; 

            if (min_expen < expen) {

                // CACH 1 XU LY NHUNG LUC SAU TA CAN GAN LAI 
                {
                    visited[i] = 1; 
                    backtrack(expenCur + a[locationCur][i], visited, k + 1, i); 
                    visited[i] = 0; 
                }
                
                // CACH NAY NHU BAI KNAPSACK O BEN TREN TA TRUYEN TAT CA CAC BIEN DEU COPY THI KHONG CAN GAN LAI
                // {
                //     vector<int> tmp = visited; tmp[i] = 1; 
                //     backtrack(expenCur + a[locationCur][i], tmp, k + 1, i);
                // }
            }
        }
    }

    cout << expen; 
}

int main()
{
    init(); 
    process(); 
    return 0; 
}