//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int sn0=0, sn1=0;
        for(int i : students){
            if(i==1)
                sn1++;
            else
                sn0++;
        }
        for(int i=0 ; i<sandwiches.size() ; i++){
            if(sandwiches[i]==1){
                if(sn1>0)
                    sn1--;
                else
                    return sandwiches.size()-i;
            }
            else
                if(sn0>0)
                    sn0--;
                else
                    return sandwiches.size()-i;
        }
        return 0;
    }
};
