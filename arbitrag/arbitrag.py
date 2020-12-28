from collections import defaultdict
import math

def inp(graph, edges, n):
    for i in range(n):
        input()
    m = int(input())

    for i in range(m):
        v_1, rate, v_2 = input().split(" ")
        rate = float(rate)
        graph[v_1].append((v_2, rate))
        edges.append((v_1, v_2, rate))

def hasNegativeCycle(graph, edges, n):
    labels = list(graph.keys())
    best_rates = dict.fromkeys(labels, 0)
    st = labels[0]
    best_rates[st] = 1

    for _ in range(n + 5):
        for (v_1, v_2, rate) in edges:
            best_rates[v_2] = max(best_rates[v_1] * rate, best_rates[v_2])
    
    for (v_1, v_2, rate) in edges:
        if best_rates[v_1] * rate > best_rates[v_2]:
            return True
            
    return False
        


def main():
    
    cnt = 0    
    while True:
        cnt += 1
        n = int(input())
        if n == 0:
            break
        
        edges = []
        graph = defaultdict(list)
        inp(graph, edges, n)
        graph = dict(graph)

        ans = hasNegativeCycle(graph, edges, n)
        print("Case ", cnt, ": Yes" if ans else ": No", sep="")

        # consume trailing newline
        input()

main()