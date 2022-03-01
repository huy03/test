#include <iostream>
#include <string.h>

using namespace std;

void row (int a[][4])
{
    int index;
    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            index=1;
            if (a[i][j]==0) continue;
            while (a[i][j+index]==0 && j+index<3){
                index++;
            }
            if (a[i][j]==a[i][j+index]){
                a[i][j] = a[i][j] + a[i][j+index];
                a[i][j+index] = 0;
            }
        }
    }
}

void col (int a[][4])
{
    int index;
    for (int j=0; j<4; j++){
        for (int i=0; i<3; i++){
            index=1;
            while (a[i+index][j]==0 && i+index<3){
                index++;
            }
            if (a[i+index][j]==a[i][j]){
                a[i][j] = a[i][j] + a[i+index][j];
                a[i+index][j] = 0;
            }
        }
    }
}

int main()
{
    int n=4;
    int a[4][4];
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            cin >> a[i][j];
        }
    }
    char direct;
    cin >> direct;

    if (direct=='L'){
        row(a);
        for (int i=0; i<4; i++){
            n=4;
            for (int j=0; j<n; j++){
                if (a[i][j]==0){
                    for (int k=j; k<n; k++){
                        if (k==n-1) a[i][k]=0;
                        else a[i][k] = a[i][k+1];
                    }
                    n--; j--;
                }
            }
        }
    }
    else if (direct=='R'){
        row(a);
        for (int i=0; i<4; i++){
            int k=0;
            for (int j=n-1; j>=k; j--){
                if (a[i][j]==0){
                    for (int k=j; k>=0; k--){
                        if (k==0) a[i][k]=0;
                        else a[i][k] = a[i][k-1];
                    }
                    k++; j++;
                }
            }
        }
    }
    else if (direct=='U'){
        col(a);
        for (int j=0; j<4; j++){
            n=4;0
            for (int i=0; i<n; i++){
                if (a[i][j]==0){
                    for (int k=i; k<n; k++){
                        if (k==n-1) a[k][j]=0;
                        else a[k][j] = a[k+1][j];
                    }
                    n--; i--;
                }
            }
        }
    }
    else {
        col(a);
        for (int j=0; j<4; j++){
            int k=0;
            for (int i=n-1; i>=k; i--){
                if (a[i][j]==0){
                    for (int k=i; k>=0; k--){
                        if (k==0) a[k][j]=0;
                        else a[k][j] = a[k-1][j];
                    }
                    k++; i++;
                }
            }
        }
    }

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
