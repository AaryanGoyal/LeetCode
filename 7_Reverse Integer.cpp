class Solution {
public:
    int reverse(int x) {
        int rev=0;
        while (x!=0){
            if ((rev==214748364 && x>=7) || (rev>214748364) || (rev<-214748364) || (rev==-214748364 && x<=-8)) return 0;
            rev*=10;
            rev+=x%10;
            x/=10;
        }
    return rev;
    }
};