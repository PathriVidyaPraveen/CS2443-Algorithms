# Instructions to run this file:
# python CS24BTECH11047.py <filename e.g. airline_distances.txt> <s> <t>
# or
# python CS24BTECH11047.py <s> <t>

import heapq
import sys

DEFAULT_FILE = "airline_distances.txt"
DEFAULT_S = 12087
DEFAULT_T = 3469

def load_graph(filename):
    graph = {}
    try:

        with open(filename,'r') as f:
            for line in f:
                if not line.strip():
                    continue
                u,v,w = [x.strip() for x in line.split(',')]
                u,v,w = int(u),int(v),float(w)
                if u not in graph:
                    graph[u] = []
                graph[u].append((v,w))
    except FileNotFoundError:
        graph = {}
    return graph

def dijkstra(graph,start,end):
    pq = [(0,start,[])]
    visited = {}

    while pq:
        dist,node,path = heapq.heappop(pq)

        if node in visited and visited[node] <=dist:
            continue

        visited[node] = dist
        path = path + [node]

        if node == end:
            return path,dist

        for neighbor,weight in graph.get(node,[]):
            heapq.heappush(pq,(dist + weight,neighbor,path))

    return None,float('inf')

def main():
    # Note : uses CLI and also user input can be given
    filename = None
    s = None
    t = None

    # CLI
    args = sys.argv[1:]

    if len(args) == 3:
        filename = args[0]
        s = int(args[1])
        t = int(args[2])
    elif len(args) == 2:
        filename = DEFAULT_FILE
        s = int(args[0])
        t = int(args[1])
    elif len(args) == 1:
        filename = args[0]

    if filename is None:
        line = sys.stdin.readline().strip()
        if line:
            filename = line

    if s is None:
        line = sys.stdin.readline().strip()
        if line:
            s = int(line)

    if t is None:
        line = sys.stdin.readline().strip()
        if line:
            t = int(line)

    if filename is None:
        filename = DEFAULT_FILE
    if s is None:
        s = DEFAULT_S
    if t is None:
        t = DEFAULT_T

    graph = load_graph(filename)
    path,dist = dijkstra(graph,s,t)

    if path:
        print(f"A shortest path is {', '.join(map(str,path))} with distance {int(dist)} km")
    else:
        print(f"No path found from {s} to {t}")

if __name__ == "__main__":
    main()