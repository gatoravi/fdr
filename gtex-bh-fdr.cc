/*  test-bh-fdr.h - Test the Benjamini Hochberg procedure

    Copyright (c) 2016, Avi Ramu

    Author: Avi Ramu <avinash3003@yahoo.co.in>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.  */

#include <iostream>
#include <fstream>
#include <sstream>
#include "bh-fdr.h"

//From R:
/*
> source("generate_random_p.R")
[1] "pvalues"
0.001063732,0.003773763,0.006233452,0.006535265,0.01132544,0.01838011,0.01936604,0.02866878,0.03798249,0.03986961,0.04266445,0.04405806,0.05517378,0.05996954,0.07529589,0.08391378,0.08796254,0.09734611,0.1029043,0.1111793,0.1115418,0.1193652,0.1869531,0.1902924,0.3105688,
[1] "adjusted pvalues"
0.02659329,0.04084541,0.04084541,0.04084541,0.05662719,0.06916445,0.06916445,0.08958995,0.09178763,0.09178763,0.09178763,0.09178763,0.1061034,0.1070885,0.1254931,0.1293567,0.1293567,0.1327879,0.1327879,0.1327879,0.1327879,0.1356423,0.1982213,0.1982213,0.3105688,
[1] "a < 0.05"
TRUE,TRUE,TRUE,TRUE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,
*/

using namespace std;

int main(int argc, char* argv[]) {
    vector<double> v1;
    ifstream fin(argv[1]);
    if(!fin && argc > 1) {
        cerr << endl << "Unable to open " << argv[1];
    }
    string line;
    while(getline(fin, line)) {
        double p1;
        stringstream ss1(line);
        ss1 >> p1;
        v1.push_back(p1);
    }
    bh_fdr(v1, 0.05);
}
