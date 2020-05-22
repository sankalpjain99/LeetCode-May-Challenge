class Solution {
public:

    int findComplement(int num) {
        int n = log2(num)+1;
        int temp = pow(2,n)-1;
        return num^temp;
    }
};
