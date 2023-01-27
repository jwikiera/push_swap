import subprocess
import random
import sys

for i in range (1):
    num_lst = random.sample(range(1, 500), 100)
    instrs = ['./push_swap', ' '.join(map(str, num_lst)), '|', './checker', ' '.join(map(str, num_lst))]
    # print(f"running: {' '.join(instrs)}")
    res = subprocess.Popen(instrs,
                          shell=True, stdout=subprocess.PIPE)
    s = ""
    for c in iter(lambda: res.stdout.read(1), b""):
        sys.stdout.buffer.write(c)
        s += c
    print(s)
    #print(res.stdout.decode("utf-8"))
    #print(res.stdout)
    #if res.stderr:
    #    print("ERROR")