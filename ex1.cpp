// By: Gonçalo Leão
// With contributions by Eduardo Almeida

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int max_sum =0;
    i =0;
    j=0;
    for (unsigned int k = 0; k < n; ++k) {
        int currentSum =0;
        for(unsigned int l = k; l< n; l++){
            currentSum+=A[l];
            if(currentSum>=max_sum){
                max_sum = currentSum;
                i = k;
                j=l;
            }
        }
    }
    return max_sum;
}

// Alinea b) complexidade do algoritmo, com um array de tamanho n seria de 0(n^2), uma vez que temos 2 for loops, sendo um nested.

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP2_Ex1, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}