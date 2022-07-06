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

### [PRATA spoj](https://www.spoj.com/problems/PRATA/)

1. find minimum time when making p number of parathas is possible
2. so monotonic seq of F F F F T T ..... find the first true
3. set max as (p*(p+1)/2) * maximum val in array 
4. use BS with predicate function keeping number of parathas as constraint.

### [SNSOCIAL Codechef](https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/)

1. Try traversing from maximum value nodes (multisource BFS)
2. Count the number of levels until it exhausts
3. return level-1 (no of edges till deepest node reqd only)
