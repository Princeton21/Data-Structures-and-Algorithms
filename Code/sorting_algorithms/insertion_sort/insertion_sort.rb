def insertion_sort(array)
    for i in 1...(array.length)  # Step 1
        j = i # Step 2
        while j > 0 # Step 3
            if array[j-1] > array[j] # Step 4
                temp = array[j]
                array[j] = array[j-1]
                array[j-1] = temp
            else
                break
            end
            j = j - 1 # Step 5
        end
    end
    return array
end

unsorted_array = [11,5,7,6,15]
p insertion_sort(unsorted_array)