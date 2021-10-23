def insertion_sort(array, left=0, right=None):
 2    if right is None:
 3        right = len(array) - 1
 4
 5    # Loop from the element indicated by
 6    # `left` until the element indicated by `right`
 7    for i in range(left + 1, right + 1):
 8        # This is the element we want to position in its
 9        # correct place
10        key_item = array[i]
11
12        # Initialize the variable that will be used to
13        # find the correct position of the element referenced
14        # by `key_item`
15        j = i - 1
16
17        # Run through the list of items (the left
18        # portion of the array) and find the correct position
19        # of the element referenced by `key_item`. Do this only
20        # if the `key_item` is smaller than its adjacent values.
21        while j >= left and array[j] > key_item:
22            # Shift the value one position to the left
23            # and reposition `j` to point to the next element
24            # (from right to left)
25            array[j + 1] = array[j]
26            j -= 1
27
28        # When you finish shifting the elements, position
29        # the `key_item` in its correct location
30        array[j + 1] = key_item
31
32    return array