def result(s, n) : 
  
    # set to store the strings 
    st = set(); 
  
    for i in range(len(s)) : 
  
        ans = ""; 
        for j in range(i, len(s)) :
  
            ans += s[j]; 
  
            # if the size of the string 
            # is equal to 1 then insert 
            if (len(ans) == n) :
  
                # inserting unique 
                # sub-string of length L 
                st.add(ans); 
                break; 
  
    # Printing the set of strings 
    for it in st :
        print(it, end = " "); 
  
# Driver Code 
if __name__ == "__main__" : 
  
    s = "abca"; 
    n = 3; 
  
    # Function calling 
    result(s, n); 
