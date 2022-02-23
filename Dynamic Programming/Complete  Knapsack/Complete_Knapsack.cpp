#include <vector>
#include <algorithm>
#include <iostream>

void knapSack()
{
    std::vector<int> weight = {1, 3, 4};
    std::vector<int> value = {15, 20, 30};
    int bagW = 4; // The maximum weight of the bag

    std::vector<int> dp(bagW + 1, 0);       // dp[j] is the maximum value of bag size j
    for (int i = 0; i < weight.size(); i++) // Iterate the stuffs
    {
        for (int j = weight[i]; j <= bagW; j++) // Iterate the bags
        {
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    std::cout << dp[bagW];
}

int main()
{
    knapSack();

    return 0;
}