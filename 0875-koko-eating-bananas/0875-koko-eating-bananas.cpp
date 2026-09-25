class Solution {
public:
    int maxElement(vector<int>& piles){
        int maxE = piles[0];
        for(int i = 0; i < piles.size(); i++){
            maxE = max(maxE,piles[i]);
        }
        return maxE;
    }

    long long hours(vector<int>& piles,int hourly){
        long long total = 0;
        for(int i = 0; i < piles.size(); i++){
            total += ceil((double)piles[i]/ hourly);
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int end = maxElement(piles);
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st) / 2;
            long long totalHr = hours(piles,mid);

            if(totalHr <= h){
                ans = mid;
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }

        return ans;
    }
};