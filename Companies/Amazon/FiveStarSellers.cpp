// Given the number of five-star and total reviews for each product a company sells, as well as the threshold percentage,
// what is the minimum number of additional five-star reviews the company needs to become five star seller.

// For ex, there are 3 products (n=3) with productRatings =[[4,4],[1,2],[3,6]], percentage rating threshold = 77.
// [1,2] indicates => [1 (five star reviews) ,2 (total reviews)].
// We need to get the seller reach the threshold with minimum number of additional five star reviews.

// Before we add more five star reviews, the percentage for this seller is ((4/4) + (1/2) + (3/6))/3 = 66.66%
// If we add a five star review to 2nd product, ((4/4) + (2/3) + (3/6))/3 = 72.22%
// If we add another five star review to 2nd product, ((4/4) + (3/4) + (3/6))/3 = 75%
// If we add a five star review to 3rd product, ((4/4) + (3/4) + (4/7))/3 = 77.38%
// At this point, 77% (threshold) is met. Therefore, answer is 3 (because that is the minimum five star reviews we need to add, to get the seller reach the threshold).

// public static int fiveStarReviews(List<List<Integer>> productRatings, int ratingsThreshold){
// }

// Constraints:
// 1<= productRatings.size() <=200
// In product ratings, [fivestar, total], fivestar <=100, total<=100
// 1<=ratingsThreshold< 100
// productRatings contains only non negative integers.

double getMarginalGain(const vector<int>& curRating, const int& N)
{
    double five = curRating[0];
    double all = curRating[1];
    
    return (((five + 1) / (all + 1)) - (five / all)) / N;
}

int fiverStarsNeeded(vector<vector<int>>& ratings, int threshold)
{
    int N = ratings.size();
    if(N == 0)
        return 0;
    
    int result = 0;
    double thresholdPercent = threshold / 100.0;
    double curPercent = 0;
    
    // priority queue keeps track of product ratings that would give maximum percentage gain
    // for e.g. 0/1 -> 1/2 = 50% gain ; 1/2 -> 2/3 = 17% gain
    priority_queue<pair<double, int>> gainPq;
    
    for(int i = 0; i < N; i++)
    {
        gainPq.push({getMarginalGain(ratings[i], N), i});
        curPercent += (double) ratings[i][0] / ratings[i][1] / N;
    }
    
    // Add five star review to products which will give max gain and
    // then add them again to pq till threshold is reached
    while(curPercent < thresholdPercent)
    {
        double curProduct = gainPq.top().second;
        curPercent += gainPq.top().first;
        gainPq.pop();
        result++;
        ratings[curProduct][0]++;
        ratings[curProduct][1]++;
        gainPq.push({getMarginalGain(ratings[curProduct], N), curProduct});
    }
    
    return result;
}
    
int main() {
    vector<vector<int>> ratings = {{4,4}, {1,2}, {3,6}};
    int threshold = 77;
    cout<<fiverStarsNeeded(ratings, threshold)<<endl;
}