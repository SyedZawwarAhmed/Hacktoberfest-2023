function topologicalSort(node, adjacencyList, visited, stack) {
    visited[node] = true;
    for (let child of adjacencyList[node]) {
        if (!visited[child]) {
            topologicalSort(child, adjacencyList, visited, stack);
        }
    }
    stack.push(node);
}

function main(adjacencyList) {

    // initially every node is unvisited
    let visited = new Array(adjacencyList.length).fill(false);

    let stack = [];
    let result = [];

    /* for each node 0 ... V do topological sort if that
       node is not visited. */
    for (let node = 0; node < visited.length; node ++) {
        if (!visited[node])
            topologicalSort(node, adjacencyList, visited, stack);
    }
    
    // pop out values from stack one by one
    while (stack.length > 0) {
        let node = stack.pop();
        result.push(node);
    }

    return result;
}

/* Example */

// example adjacency list - very famous
let adjacencyList = [
    [],
    [],
    [3],
    [1], 
    [0, 1],
    [0, 2]
];

console.log(main(adjacencyList));