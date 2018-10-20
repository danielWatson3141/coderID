from queue import Queue
def flip(state_set, i):
    new_state = set()
    for state in state_set:
        new_state.add(state[:i]+str(1-int(state[i]))+state[i+1:])
    return new_state
def cal(initial, target, L):
    if initial==target:
        return "0"
    waiting_list = Queue()
    have_occurred = list()
    waiting_list.put((-1,0,initial))
    while not waiting_list.empty():
        last, times, state = waiting_list.get_nowait()
        for i in range(L):
            if i!=last:
                new_state = flip(state, i)
                if new_state == target:
                    return str(times+1)
                if not new_state in have_occurred:
                    waiting_list.put((i, times+1, new_state))
                    have_occurred.append(new_state)
    return "NOT POSSIBLE"

input_file = open(input("input from: "), "r")
output_file = open(input("output to: "), "w")
T = int(input_file.readline().strip())
for i in range(T):
        N,L = [int(i) for i in input_file.readline().strip().split(' ')]
        initial = set(input_file.readline().strip().split(' '))
        target = set(input_file.readline().strip().split(' '))
        output_file.write("Case #{}: {}\n".format(i+1, cal(initial, target, L)))
        output_file.flush()
