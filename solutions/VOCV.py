from collections import defaultdict


def inp(graph, n):
    for _ in range(n - 1):
        u, v = map(int, input().split(" "))
        graph[u].append(v)
        graph[v].append(u)


def sol(graph, cur, prev, costs):
    #  checks if costs has already been computed
    if cur in costs:
        return costs[cur]

    #  else calculates the cost
    descendants = graph[cur].copy()
    if prev in descendants:
        descendants.remove(prev)

    if not bool(descendants):
        costs[cur] = {"on": (1, 1), "off": (0, 1)}
        return costs[cur]
    else:
        on_cost, on_ways, off_cost, off_ways = 1, 1, 0, 1
        for d in descendants:
            dcost = sol(graph, d, cur, costs)

            child_on_cost, child_on_ways = dcost["on"]
            child_off_cost, child_off_ways = dcost["off"]

            on_cost += min(child_on_cost, child_off_cost)
            off_cost += child_on_cost
            off_ways *= child_on_ways
            off_ways %= 10007
            to_mult = 1

            if child_on_cost == child_off_cost:
                to_mult = child_off_ways + child_on_ways
            elif child_on_cost < child_off_cost:
                to_mult = child_on_ways
            else:
                to_mult = child_off_ways

            on_ways *= to_mult
            on_ways %= 10007

        return {"on": (on_cost, on_ways), "off": (off_cost, off_ways)}


def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        graph = defaultdict(list)
        inp(graph, n)

        costs = {}
        res = sol(graph, 1, 0, costs)
        on_cost, on_ways = res["on"]
        off_cost, off_ways = res["off"]

        cost, ways = 0, 1
        if on_cost < off_cost:
            cost = on_cost
            ways = on_ways
        elif on_cost > off_cost:
            cost = off_cost
            ways = off_ways
        else:
            cost = on_cost
            ways = on_ways + off_ways

        print(cost, ways)


main()
