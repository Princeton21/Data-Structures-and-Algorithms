start_node = 'start'
end_node = 'finish'

# Sample adjacency list of a Directed Acyclic Graph
graph = {
    start_node: {'A': 5, 'B': 2},
    'A': {'C': 1, 'D': 2},
    'B': {'A': 8, 'D': 7},
    'C': {'D': 2, end_node: 3},
    'D': {end_node: 4},
    'E': {'C': 4, 'B': 5, end_node:7},
    'F': {'D': 3, 'B': 2, end_node:4},
    end_node: {}
}


def find_lowest_node(weights, visited_nodes):
    known_nodes = weights.keys()
    lowest = None
    for node in known_nodes:
        if (lowest is None) and (node not in visited_nodes):
            lowest = node
        if (
            (lowest is not None) and (weights[node] < weights[lowest])
            and (node not in visited_nodes)
        ):
            lowest = node
    return lowest


def dijkstra(graph):
    weights = graph[start_node]  # start with children of start node
    weights[end_node] = float("inf")
    parents = {end_node: None}

    for child in graph[start_node]:
        parents[child] = start_node
    
    visited_nodes = []
    node = find_lowest_node(weights, visited_nodes)

    while node:
        weight = weights[node]
        children = graph[node]
        for n in children:
            new_weight = weight + children[n]
            if n not in weights:
                weights[n] = new_weight
                parents[n] = node
                continue
            if weights[n] > new_weight:
                weights[n] = new_weight
                parents[n] = node
        visited_nodes.append(node)
        node = find_lowest_node(weights, visited_nodes)
    optimal_path = [end_node]
    parent = parents[end_node]

    while parent:
        optimal_path.insert(0, parent)
        if parent in parents:
            parent = parents[parent]
        else:
            parent = None
    
    result = {
        'total_distance': weights[end_node],
        'optimal_path': optimal_path
    }

    return result
