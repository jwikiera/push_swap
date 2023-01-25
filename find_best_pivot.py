import os
import subprocess


NUM_AMOUNT = 10

print('==================================')
print(f"Finding best pivot for {NUM_AMOUNT} numbers:")
print('==================================')

best_pivot = 0
best_pivot_op_avg = -1
average_counts = []
for i in range(101):
    print(f'--------(pivot: {i})---------')
    subprocess.run(['make', 're_ps', f'pivot={i}'], stdout=subprocess.PIPE)
    result = subprocess.run(['./tester.py', '--disablecolor', '-t', '100', '-n', str(NUM_AMOUNT)], stdout=subprocess.PIPE)
    res_utf = result.stdout.decode("utf-8")
    index_of_average = res_utf.find('Average operation count: ') + len('Average operation count: ')
    end_index_of_average = res_utf[index_of_average:].find('.')
    avg_str = res_utf[index_of_average:index_of_average + end_index_of_average]
    # print("str is: " + avg_str)
    avg = int(avg_str)
    average_counts.append(avg)
    print(f"Average ops: {avg}")
    if best_pivot_op_avg == -1:
        best_pivot_op_avg = avg
    else:
        if avg < best_pivot_op_avg:
            best_pivot = i
            best_pivot_op_avg = avg

    #if i == 2:
     #   break
print(f"Best pivot is {best_pivot} with an average of {best_pivot_op_avg} instructions.")
print(average_counts)