const checkPalindrome = (str) => { 
    // Split's the string to an array of characters and then, reverses them - then joins them back to a string
    let str1 = str.split('').reverse().join('');
    // This check if the original string is equal to the reversed string, example - 'madam' is also equal to 'madam'
    // even if we reverse it will still be true, but this won't be true for 'hello' as when we reverse it will be 'olleh'
    // which is not true for 'hello' as a palindrome
    if(str1 === str){
        console.log(`'${str}' is a palindrome`);
    } 
    else{
        console.log(`'${str}' is not a palindrome`);
    }
}
// This calls the function and passes the string as an argument, which in our case is 'madam'
checkPalindrome("madam");