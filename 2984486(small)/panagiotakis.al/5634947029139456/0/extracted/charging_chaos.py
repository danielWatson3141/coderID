file_ = open('input.in')
cases = int(file_.readline())

for case in range(cases):
    n, l = [int(item) for item in file_.readline().split()]
    outlets = {int(item, 2) for item in file_.readline().split()}
    devices = {int(item, 2) for item in file_.readline().split()}

    correct_transforms = []
    for i in range((2 ** l) - 1):
        new_outlets = {item ^ i for item in outlets}
        if new_outlets == devices:
            correct_transforms.append(i)

    if correct_transforms:
        print('Case #{}: {}'.format(case + 1, min([bin(item).count('1') for item in correct_transforms])))
    else:
        print('Case #{}: NOT POSSIBLE'.format(case + 1))