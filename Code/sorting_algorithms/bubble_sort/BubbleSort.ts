/**
 * simple implementation for bubble sort in typescript.
 * Takes an array of numbers and returns array sorted in ascending order
 */


 export function bubbleSort(toSort: any[]): any[] {
   for (let outer = 0; outer < toSort.length - 1; outer++) {
       console.log(toSort);
     for (
       let innerIndex = 0;
       innerIndex < toSort.length - outer; // last index is already correctly sorted
       innerIndex++
     ) {
       if (toSort[innerIndex] >= toSort[innerIndex + 1]) {
         let helperVar = toSort[innerIndex];
         toSort[innerIndex] = toSort[innerIndex + 1];
         toSort[innerIndex + 1] = helperVar;
       }
     }
   }
   return toSort;
 }
 
 // Test case
 let list = [8, 23,5, 4, 67, 34];
 console.log(bubbleSort(list));
 