import random
import sys

amount = 5
if len(sys.argv) > 1:
    amount = sys.argv[1]
num_lst = random.sample(range(int(0), int(amount)), int(amount))
print(' '.join(map(str, num_lst)))