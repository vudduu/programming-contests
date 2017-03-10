#include<string>
#include<iostream>
#include<sstream>
#include<assert.h>
#include<cstdio>
#include<map>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<queue>
#include<functional>
#include<set>
#include<sys/stat.h>
#include<numeric>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define for_each(q,s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
const bool ENABLE_MULTI_PROCESS = false;
using namespace std;

const char* conv= "yhesocvxduiglbkrztnwjpfmaq";
string solve(string s) {
    for (int i=0; i<s.length(); i++) {
        if (s[i] != ' ') {
            s[i] = conv[s[i]-'a'];
        }
    }
    return s;
}

int main(int argc, const char* argv[]) {
    int mode = 0;
    if(argc >= 2) sscanf(argv[1],"%d",&mode);
    if ( ( mode == 0 ) && ENABLE_MULTI_PROCESS ) {
        string inputfile = ".input";
        assert( system("cat > .input") );

        mode = 1;
        remove(".finished");
        cerr<<"--Multi process mode--"<<endl;
        //string inputfile = argv[2];
        string command = argv[0];
        command += " 2 < "+inputfile+" > .tem &";
        assert( system(command.c_str()) );
        assert( freopen(inputfile.c_str(),"r",stdin) );
    }

    int TestCases;
    cin>>TestCases;
    string s;
    getline(cin, s);
    for (int _i=1;_i<=TestCases;_i++) {
        getline(cin, s);
        if( (mode==0) || ( (mode!=2)== (_i*2<=TestCases) ) ) {            
            cerr<<"["<<_i<<" / "<<TestCases<<"]"<<endl;
            string r = solve(s);
            cout<<"Case #"<<_i<<": "<< r << endl;            
        }
        else if(mode!=2) break;
        assert(cin);
    }
    if(mode==2) {
        assert( system("echo done > .finished") );
    } else if(mode==1) {
        struct stat stFileInfo;
        while( stat(".finished",&stFileInfo)!=0);
        assert( system("cat .tem") );
    }
    return 0;
}
