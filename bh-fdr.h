/*  bh-fdr.h - Apply the Benjamini Hochberg procedure

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

#ifndef BH_FDR_H
#define BH_FDR_H

#include <vector>
#include <algorithm>

using namespace std;

//Takes a vector of p-values and alpha
//Returns the new p-value cutoff
//All p-values <= p are significant with FDR alpha.
double bh_fdr(std::vector<double> input_pval, float alpha) {
    std::sort(input_pval.begin(), input_pval.end(), std::greater<double>());
    double m = input_pval.size();
    uint32_t k = input_pval.size(); // This is the rank, doesn't need to be double.
    for (auto p_val : input_pval) {
        //cerr << endl << "p_val: " << p_val << " adjusted_p_val: " << (double)m/k * p_val;
        if (p_val <= (double)k/m * alpha) {
            cerr << endl << "all values below " << p_val << " are significant. index (1-based): " << k << endl;
            return p_val;
        }
        k--; //Decrease rank
    }
    return -1;
}

#endif
