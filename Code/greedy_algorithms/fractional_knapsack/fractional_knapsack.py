# this class will be used for dealing with items and their value and weights, and it's also going to store value per unit weight of each item

class ItemValue:

    """Item Value DataClass"""

    def __init__(self, wt, val, ind):
        self.wt = wt
        self.val = val
        self.ind = ind
        self.cost = val // wt

    def __lt__(self, other): # Inbuilt function used for choosing the sorting parameter
        return self.cost < other.cost # Declaring item cost as sorting parameter

# this function takes weight and value lists, as well as capacity of the sack as the arguments and returns the max value you can carry in the sack given the weights and values of each item
def getMaxValue(wt, val, capacity):
    """function to get maximum value """
    iVal = []
    for i in range(len(wt)):
        iVal.append(ItemValue(wt[i], val[i], i)) # Make iVal object and append it to list
    iVal.sort(reverse=True) # Sort the iVal objects list in decreasing order of cost

    # The whole procedure below is to calculate the max value that you can get in the knapsack
    totalValue = 0
    for i in iVal:
        curWt = int(i.wt)
        curVal = int(i.val)
        if capacity - curWt >= 0:
            capacity -= curWt
            totalValue += curVal
        else:
            fraction = capacity / curWt
            totalValue += curVal * fraction
            capacity = int(capacity - (curWt * fraction))
            break
    return totalValue

# The wt and val lists need to be corresponding to each other.
wt = [10, 40, 20, 30]
val = [60, 40, 100, 120]
capacity = 50
maxValue = getMaxValue(wt, val, capacity)
print("Maximum value in Knapsack =", maxValue)
