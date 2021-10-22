func longestPalindrome(_ s: String) -> String {
		
    /*If Empty or equal to one we return*/
        if(s.count == 0){return ""} 
        if(s.count == 1){return s}
				
	/*Start and End represent the palindrome with the longest length. */
        var start = 0, end = start, stringArray = Array(s), max = 0
				
        for i in 0..<s.count{
				
	/*Left and Right  pointers move inward (Sandwich principle).*/
            var left = i, right = s.count-1, tempStart = left, tempEnd = right
						
            while(left<right){
	/*If values at the Left and Right index are equal then we temporarily store index if greater than max*/
                if(stringArray[left] == stringArray[right]){
                    if((right - left) > max){
                        max = (right - left)
                        tempStart = left
                        tempEnd = right
                    }
                    left+=1
                    right-=1
                }
                else{//Reset temp variables and the current max
                    left = i
                    right = tempEnd - 1
                    tempStart = left
                    tempEnd = right
                    max = 0
                }
            }
            if((tempEnd - tempStart) > (end - start)){//Store temp variables and continue loop
                end = tempEnd
                start = tempStart
            }
        }
        return (String(stringArray[start...end]).count > 1) ? String(stringArray[start...end]) : String(s.first!)
}
