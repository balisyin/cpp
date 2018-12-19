#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>

using namespace std;
typedef unsigned long long uint64_t;

int main(int argc, char** argv) {

    string infile = "./zhongshan.txt";
    string outfile = "./zs_shift.txt";
    ifstream in_s(infile.c_str());
    ofstream out_s(outfile.c_str());
    if(!in_s) {
        cout<< "bad in file open" <<endl;
        return -1;
    }
    string line;
    while(getline(in_s, line)) {
        uint64_t line_u64 = strtoull(line.c_str(), NULL, 0);
        line_u64 <<= 32;
        out_s << line_u64 << "\t" << 8 << endl;

    }
    return 0;
}
