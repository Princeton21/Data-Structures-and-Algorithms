// ES6
const factors = number => Array
    .from(Array(number + 1), (_, i) => i)
    .filter(i => number % i === 0)

// Test
console.log(factors(36));      // Output  ->  [1, 2, 3, 4, 6, 9, 12, 18, 36]
