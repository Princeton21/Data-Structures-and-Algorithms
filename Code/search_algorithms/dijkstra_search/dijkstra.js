
// Dijkstra's algorithm implementation - done by @NeboCode on Github

// Sample dataGraph with node distances which we will use to implement Dijkstra's algorithm.

let DijkstraGraph = { startingPoint: {A: 5, B: 2}, A: {C: 1, D: 2}, B: {A: 8, D: 7}, C: {D: 2, finishPoint: 3},D: {finishPoint: 4}, E: {C:4, B:5, finishPoint:7}, F:{D:3, B:2,finishPoint:4}, finishPoint: {}};



// Function to find the node with the lowest weight, using a JS reducer.

function findLowestNode (weights, finishedNodes) {
    let knownNodes = Object.keys(weights)
    let lowestNode = knownNodes.reduce((lowest, node) => {
    if (lowest === null && !finishedNodes.includes(node)) {
     lowest = node;
     }
   if (weights[node] < weights[lowest] && !finishedNodes.includes(node)) {    
   lowest = node;
    }
   return lowest;
   }, null);
   
  return lowestNode
 };



// Dijkstra's algo implementation in JavaScript

function dijkstraAlgo(dataGraph) {

    let weights = Object.assign({finishPoint: Infinity}, dataGraph.startingPoint); 
    let parents = {finishPoint: null};  

    for (let child in dataGraph.startingPoint) {    
      parents[child] = 'startingPoint';  
     }

     // "caching" already visited nodes, so we don't come back to them!
    let finishedNodes = [];
    let node = findLowestNode(weights, finishedNodes);
       
    // finding the lowest weight, once the loop is done, we’ll have the lowest weight to reach the final point node
    while (node) {
    let weight = weights[node];
    let children = dataGraph[node]; 
    for (let n in children) {   
        let newWeight = weight + children[n];     
         if (!weights[n] || weights[n] > newWeight) { 
          weights[n] = newWeight; 
          parents[n] = node;
            }
         }
     finishedNodes.push(node);  
     node = findLowestNode(weights, finishedNodes);
    }
    let optimalPath = ['finishPoint'];
    let parent = parents.finishPoint;

while (parent) {
    optimalPath.unshift(parent);
    parent = parents[parent]; 
  }
  
  let result = { totalDistance: weights.finishPoint, optimalPath: optimalPath };

  return result;
};


