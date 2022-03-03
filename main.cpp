#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[300];
    cin.getline(str,256);
    char *tmp;
    tmp = strtok (str, " ");
    while (tmp!=NULL){
        for (int i=strlen(tmp)-1; i>=0; i--){
            cout << tmp[i];
        }
        cout << " ";
        tmp = strtok(NULL," ");
    }
    cout << endl;
    cout << "test github";
    return 0;
}
