class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int count0 = 0;
        int count10 = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                count0++;
            } else if (bills[i] == 10) {
                if (count0 > 0) {
                    count0--;
                    count10++;
                } else {
                    return false;
                }

            } else {
                if (count0 > 0 && count10 > 0) {
                    count0--;
                    count10--;
                } else if (count0 >= 3) {
                    count0 -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};