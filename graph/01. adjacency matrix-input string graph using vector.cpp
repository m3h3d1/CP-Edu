#include <iostream>
#include<vector>
#include<map>
using namespace std;

#define db(x) cout << (#x) <<" is "<< (x) << '\n'
typedef pair<int,int> PII;
vector<string> vertexNames;
map<string,int> vertexNumbers;
int main(){
    ios_base::sync_with_stdio(false);
    int vertex,edge,i,j;
    cin>>vertex>>edge;
    vector <PII> v[vertex];

    for(i=0;i<vertex;i++){
        string str;
        cin>>str;
        vertexNames.push_back(str);
        vertexNumbers[str]=i;
    }
    for(i=0;i<edge;i++){
        string str1,str2;
        cin>>str1>>str2;
        int source;
        PII p;
        source = vertexNumbers[str1];
        p.first=vertexNumbers[str2];
        cin>>p.second;
        v[source].push_back(p);
        int source2=p.first;
        p.first=source;
        v[source2].push_back(p);
    }
    for(i=0;i<vertex;i++){
        cout<<vertexNames[i]<<" -- ";
        for(j=0;j<v[i].size();j++){
            cout<<vertexNames[v[i][j].first]<<"-"<<v[i][j].second<<' ';
        }
        cout<<endl;
    }
    return 0;
}

/*
8 9
Rayerbag
Niketon
Mirpur
Dhanmondi
Jatrabari
Rampura
Badda
Gulshan
Rayerbag Dhanmondi 3
Rayerbag Jatrabari 6
Niketon Rampura 5
Niketon Badda 1
Mirpur Jatrabari 6
Dhanmondi Rampura 8
Rampura Badda 3
Rampura Gulshan 2
Badda Gulshan 6
*/