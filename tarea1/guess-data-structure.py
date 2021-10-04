import heapq
n = input()

st = []
pq = []
heapq.heapify(pq)
que = []

is_stack = True
is_pq = True
is_queue = True

i=0
while i < n:
    instruction = input()
    x = input()
    if instruction == 1:
        st.append(x)
        heapq.heappush(pq, x)
        que.append(x)
    if instruction == 2:
        if len(st) == 0:
            is_stack = False
        elif is_stack:
            is_stack = st[-1] == x;
            st.pop()

