#include <bits/stdc++.h>
using namespace std;

// this class will be used for dealing with items and their value and weights,
// and it's also going to store value per unit weight of each item

struct Item {
    int wt;
    int val;
    int ind;
    int cost;
};

bool compare_item(Item const& lhs, Item const& rhs) {
    return lhs.cost < rhs.cost;
}

// Takes weight and value lists, as well as capacity of the sack
// as the arguments and returns the max value you can carry
// in the sack given the weights and values of each item.
float get_max_value(vector<int> wt, vector<int> val, int capacity) {
    // function to get maximum value
    vector<Item> i_val;
    for (unsigned int i = 0; i < wt.size(); i++) {
        Item it;
        it.wt = wt[i];
        it.val = val[i];
        it.ind = i;
        it.cost = (int) it.val / it.wt;
        i_val.push_back(it);
    }
    // Sort the i_val vector in decreasing order of cost
    sort(i_val.begin(), i_val.end(), &compare_item);
    reverse(i_val.begin(), i_val.end());

    // Max value that you can get in the knapsack
    float total_value = 0;
    for (Item i : i_val) {
        int curr_wt = (int) i.wt;
        int curr_val = (int) i.val;
        if (capacity - curr_wt >= 0) {
            capacity -= curr_wt;
            total_value += curr_val;
        } else {
            float fraction = (float) capacity / (float) curr_wt;
            total_value += curr_val * fraction;
            capacity = (int) capacity - (curr_wt * fraction);
            break;
        }
    }
    return total_value;
}


int main()
{
    vector<int> wt = {10, 40, 20, 30};
    vector<int> val = {60, 40, 100, 120};
    int capacity = 50;
    float max_value = get_max_value(wt, val, capacity);
    cout << "Maximum value in Knapsack = " << max_value << "\n";
    return 0;
}
