
def inp(labels, edges, n):
    
    for i in range(n):
        labels.append(input())
    m = int(input())

    for i in range(m):
        v_1, rate, v_2 = input().split(" ")
        rate = float(rate)
        edges.append((v_1, v_2, rate))

def hasNegativeCycle(labels, edges, n):
    best_rates = dict.fromkeys(labels, 0)
    st = labels[0]
    best_rates[st] = 1

    for _ in range(n):
        for (v_1, v_2, rate) in edges:
            best_rates[v_2] = max(best_rates[v_1] * rate, best_rates[v_2])
    
    found = False
    for (v_1, v_2, rate) in edges:
        if best_rates[v_1] * rate > best_rates[v_2]:
            found = True
            break
            
    return found


def main():
    
    cnt = 0
    while True:
        n = int(input())
        if n == 0:
            break
        
        cnt += 1
        edges = []
        labels = []
        inp(labels, edges, n)

        ans = hasNegativeCycle(labels, edges, n)
        print("Case ", cnt, ": Yes" if ans else ": No", sep="")

        input()

main()