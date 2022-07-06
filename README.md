# CpTasks
Overcoming "Lyadh" of storing solutions

### [KATHTHI spoj](https://www.spoj.com/problems/KATHTHI/)

1. if not equal char in map then add an edge with weight=1, else weight=0
2. check neighbours and apply 0-1 BFS to find path with min 1's
3. Alternative approach Dijkstra.

### [REVERSE Codechef](https://www.codechef.com/problems/REVERSE)

1. for given edge add 0 in x->y direction
2. add 1 in reverse y->x direction (not given edge)
3. apply 0-1 BFS to get a directed shortest path from 1 to n. 
