#!/usr/bin/python3
import argparse
import os
import random
import subprocess
from typing import List


# consts
RED = '\u001b[31m'
GREEN = '\u001b[32m'
CYAN = '\u001b[36m'
MAGENTA = '\u001b[35m'
YELLOW = '\u001b[33m'
NC = '\u001b[0m'
POINT_DICT = {
    3: {
        'max': 3
    },
    5: {
        'max': 12
    },
    100: {
        'max': -1,
        'pts': [700, 900, 1100, 1300, 1500]
    },
    500: {
        'max': -1,
        'pts': [5500, 7000, 8500, 10000, 11500]
    }
}


# stack class, same as in the C version (keeping a size of the array is not pythonic but I can just copy code)
class Stack:
    def __init__(self, arr, size, empty):
        self.arr = arr
        self.size = size
        if empty:
            self.top = -1
        else:
            self.top = 0


# custom argpparse number type so that it raises an exception if an int arg is smaller than 1 or bigger than INT_MAX
def my_int_type(x: str):
    try:
        x = int(x)
    except ValueError:
        raise argparse.ArgumentTypeError("Amount has to be an integer.")
    if x < 1 or x > 2147483647:
        raise argparse.ArgumentTypeError("Minimum amount has to be greater than 0 and smaller than 2147483647.")
    return x


# custom argpparse number type so that it raises an exception if an int arg is smaller than INT_MIN or bigger than
# INT_MAX
def my_int_type_2(x: str):
    try:
        x = int(x)
    except ValueError:
        raise argparse.ArgumentTypeError("Amount has to be an integer.")
    if x < -2147483648 or x > 2147483647:
        raise argparse.ArgumentTypeError("Minimum amount has to be greater than -2147483649 and smaller than "
                                         "2147483648.")
    return x


# custom argpparse type representing a set
def set_type(x: str):
    int_lst = []
    lst = str(x).split()
    for elem in lst:
        try:
            elem = int(elem)
        except ValueError:
            raise argparse.ArgumentTypeError("Amount has to be an integer.")
        if elem < -2147483648 or elem > 2147483647:
            raise argparse.ArgumentTypeError("Minimum amount has to be greater than -2147483649 and smaller than "
                                             "2147483648.")
        if int(elem) in int_lst:
            raise argparse.ArgumentTypeError(f"Error: given set contains a duplicate ({elem}).")
        int_lst.append(elem)
    return x


# custom argparse type that checks if a specified file does exist and can be executed
def my_bin_type(x: str):
    if not os.path.exists(x) or not os.path.isfile(x):
        raise argparse.ArgumentTypeError(f"Binary '{x}' not found.")
    if not os.access(x, os.X_OK):
        raise argparse.ArgumentTypeError(f"Binary '{x}' is not executable.")
    return x


# shift an array to the right by one slot
def shift_down(arr: List):
    swp = [0, 0]
    i = 0
    swp_index = 0
    while i < len(arr):
        swp[(swp_index + 1) % 2] = arr[i]
        arr[i] = swp[swp_index % 2]
        i += 1
        swp_index += 1


# shift array to the left by one slot
def shift_up(arr: List):
    swp = [0, 0]
    i = len(arr) - 1
    swp_index = 0
    while i >= 0:
        swp[(swp_index + 1) % 2] = arr[i]
        arr[i] = swp[swp_index % 2]
        i -= 1
        swp_index += 1


# stack operations
# swap
def op_s(stack: Stack):
    if stack.top == -1 or stack.top > stack.size - 2:
        return
    swp = stack.arr[stack.top]
    stack.arr[stack.top] = stack.arr[stack.top + 1]
    stack.arr[stack.top + 1] = swp


# swap two stacks at the same time
def op_ss(stack_a: Stack, stack_b: Stack):
    op_s(stack_a)
    op_s(stack_b)


# push
def op_p(stack_src: Stack, stack_dst: Stack):
    if stack_src.top == -1:
        return
    if stack_dst.top == -1:
        stack_dst.arr[stack_dst.size - 1] = stack_src.arr[stack_src.top]
    else:
        stack_dst.arr[stack_dst.top - 1] = stack_src.arr[stack_src.top]
    if stack_dst.top == -1:
        stack_dst.top = stack_dst.size - 1
    else:
        stack_dst.top -= 1
    if stack_src.top == stack_src.size - 1:
        stack_src.top = -1
    else:
        stack_src.top += 1


# rotate
def op_r(stack: Stack):
    if stack.top == -1:
        return
    swp = stack.arr[stack.top]
    shift_up(stack.arr)
    stack.arr[stack.size - 1] = swp


# rotate two stacks
def op_rarb(stack_a: Stack, stack_b: Stack):
    op_r(stack_a)
    op_r(stack_b)


# reverse rotate
def op_rr(stack: Stack):
    if stack.top == -1:
        return
    swp = stack.arr[stack.size - 1]
    shift_down(stack.arr)
    stack.arr[stack.top] = swp


# reverse rotate two stacks
def op_rrr(stack_a: Stack, stack_b: Stack):
    op_rr(stack_a)
    op_rr(stack_b)


def check_sort(set_: str, instructions: List[str]):
    set_ = set_.strip()
    nums_str = set_.split()
    nums = []
    for num in nums_str:
        nums.append(int(num))
    stack_a = Stack(nums, len(nums), False)
    stack_b = Stack([0] * len(nums), len(nums), True)
    for instruction in instructions:
        if instruction == 'ss':
            op_ss(stack_a, stack_b)
        elif instruction == 'sa':
            op_s(stack_a)
        elif instruction == 'sb':
            op_s(stack_b)
        elif instruction == 'pa':
            op_p(stack_b, stack_a)
        elif instruction == 'pb':
            op_p(stack_a, stack_b)
        elif instruction == 'ra':
            op_r(stack_a)
        elif instruction == 'rb':
            op_r(stack_b)
        elif instruction == 'rr':
            op_rarb(stack_a, stack_b)
        elif instruction == 'rra':
            op_rr(stack_a)
        elif instruction == 'rrb':
            op_rr(stack_b)
        elif instruction == 'rrr':
            op_rrr(stack_a, stack_b)
    prev = None
    for x in stack_a.arr:
        if prev is None:
            prev = x
        else:
            if prev > x:
                return False
    return True


# test a given set
def do_test(args, set_: str):
    red_ = RED if not args.disablecolor else ''
    yellow_ = YELLOW if not args.disablecolor else ''
    cyan_ = CYAN if not args.disablecolor else ''
    magenta_ = MAGENTA if not args.disablecolor else ''
    green_ = GREEN if not args.disablecolor else ''
    nc_ = NC if not args.disablecolor else ''

    result = subprocess.run([os.path.abspath(args.binary), set_], stdout=subprocess.PIPE)
    res = None
    if result.stderr is not None:
        pass
        # print(f'{RED}{result.stderr}{NC}')
    elif result.stdout is not None:
        res = result.stdout.decode("utf-8").strip()
        instructions = res.split('\n')
        # print(res)
        # print(check_sort(set_, instructions))
        if check_sort(set_, instructions):
            operation_count = len(instructions)
            categories = list(POINT_DICT.keys())
            category = categories[0]
            set_len = len(set_.strip().split())
            for i in range(len(categories)):
                if set_len > category and set_len <= categories[i]:
                    category = categories[i]
            if set_len > categories[len(categories) - 1]:
                category = categories[len(categories) - 1]
            # print(f'Category: {category}')
            if POINT_DICT[category]['max'] != -1:
                if operation_count > POINT_DICT[category]['max']:
                    print(f'{red_}KO{nc_} - Operations: {magenta_}{operation_count}{nc_} '
                          f'(Maximum operations for category {cyan_}{category}{nc_} allowed is {cyan_}'
                          f'{POINT_DICT[category]["max"]}{nc_}.')
                    if args.errordisplay or args.errorabort:
                        print(set_)
                    if args.errorabort:
                        print("Aborting, --errorabort was specified.")
                        exit(0)
                else:
                    print(f'{green_}OK{nc_} - Operations: {magenta_}{operation_count}{nc_}.')
            else:
                if operation_count <= POINT_DICT[category]['pts'][0]:
                    print(f'{green_}OK{nc_} - Operations: {magenta_}{operation_count}{nc_}.')
                else:
                    index = 0
                    for i in range(len(POINT_DICT[category]['pts'])):
                        if operation_count > POINT_DICT[category]['pts'][index] and operation_count\
                                <= POINT_DICT[category]['pts'][i]:
                            index = i
                    points = len(POINT_DICT[category]['pts']) - index
                    if operation_count > POINT_DICT[category]['pts'][len(POINT_DICT[category]['pts']) - 1]:
                        points = 0
                    print(f'{yellow_}OK{nc_} - Operations: {magenta_}{operation_count}{nc_}. Points: '
                          f'{magenta_}{points}{nc_}.')

                    if args.errordisplay or args.pointsfatal:
                        print(set_)
                    if args.pointsfatal:
                        print("Aborting, --pointsfatal was specified.")
                        exit(0)

            # print(f'number of operations: {operation_count}')
        else:
            print(f'{RED}KO{NC}')
            if args.errordisplay or args.pointsfatal:
                print(set_)
            elif args.errorabort:
                print(set_)
                print("Aborting, --errorabort was specified.")
                exit(0)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-s", "--set", type=set_type, nargs="?", help="Set of numbers to test.")
    parser.add_argument("-n", "--numamount", type=my_int_type, help="Amount of numbers in test sets.")
    parser.add_argument("-t", "--testamount", type=my_int_type, help="Amount of tests.")
    parser.add_argument("-e", "--errordisplay", action="store_true", help="Display erroring sets.")
    parser.add_argument("-r", "--errorabort", action="store_true", help="Abort testing when an error has occured.")
    parser.add_argument("-f", "--pointsfatal", action="store_true", help="Not achieving all points is a fatal error.")
    parser.add_argument("-i", "--minnum", type=my_int_type_2, nargs="?", const=-15000, default=-15000,
                        help="Smallest possible number in a set.")
    parser.add_argument("-a", "--maxnum", type=my_int_type_2, nargs="?", const=15000, default=15000,
                        help="Biggest possible number in a set.")
    parser.add_argument("-b", "--binary", type=my_bin_type, nargs="?", const="push_swap",
                        default="push_swap", help="Location of the tested binary. Default: \"push_swap\".")
    parser.add_argument("--disablecolor", action="store_true", help="Disable colors in the output.")
    parser.add_argument("--debug", action="store_true", help="Shows set before feeding it into the sorter.")
    args = parser.parse_args()

    if args.set is None:
        if args.numamount is None or args.testamount is None:
            parser.error("If no set is specified, both --numamount and --testamount are required.")
            exit(2)

    if args.set is not None:
        print("testing using given set...")
        do_test(args, args.set)
    else:
        nam = int(args.numamount)
        tam = int(args.testamount)
        print(f"testing using {tam} tests of random sets of {nam} numbers ranging between {args.minnum} "
              f"and {args.maxnum}...")
        for i in range(tam):
            # https://stackoverflow.com/a/22842411
            num_lst = None
            try:
                num_lst = random.sample(range(int(args.minnum), int(args.maxnum)), int(args.numamount))
            except ValueError:
                exit("Can not build a set of numbers large enough within the given range")
            if args.debug:
                print(f'DEBUG: {" ".join(map(str, num_lst))}')
            do_test(args, ' '.join(map(str, num_lst)))


if __name__ == "__main__":
    main()
