#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(){
    // freopen("A-small-attempt0.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    vector<vector<int> > A, B;
    A = B = vector<vector<int> > (4, vector<int> (4));

    for(int p=1; p<=t ;p++) {
        printf("Case #%d: ", p);
        int a1, a2;
        cin >> a1; a1--;
        vector<int> sol;
        for(int i=0; i<4 ;i++) {
            for(int j=0; j<4 ;j++) {
                cin >> A[i][j];
            }
        }
        cin >> a2; a2--;
        for(int i=0; i<4 ;i++) {
            for(int j=0; j<4 ;j++) {
                cin >> B[i][j];
            }
        }
        for(int i=0; i<4 ;i++) {
            for(int j=0; j<4 ;j++) {
                if(A[a1][i] == B[a2][j])
                    sol.push_back(A[a1][i]);
            }
        }
        if(sol.size() > 1) cout << "Bad magician!" << endl;
        else if(sol.size() == 0) cout << "Volunteer cheated!" << endl;
        else cout << sol[0] << endl;
    }
}
