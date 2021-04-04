# Tree Search

First, you will need the number of nodes for these tree searches.

The tree is represented with an array:
- each position represents a node
- each value represents the parent of the node at that position
- the root is the node which is its own parent (value at position i is equal to i)

# Heuristic Search

## Greedy Best-First Search

Greedy Best-first search is a search algorithm on graphs. It expands the node which seems like the best option at that moment, without previous knowledge or future predictions.

Some notes:
- the edges all have costs 
- the expansion of a node depends on the costs
- there is a goal node that we want to reach (in this case, with a minimal cost)
- an edge between i and j doesn't exist when a[i][j] is -1, else a[i][j] is the cost of the edge
- a priority queue and a stack were used to ensure that the nodes with the lowest cost are selected in order to reach the goal node
