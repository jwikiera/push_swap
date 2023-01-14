#!/usr/bin/python3
import argparse
import os
import random


# consts
RED = '\u001b[31m'
GREEN = '\u001b[32m'
CYAN = '\u001b[36m'
NC = '\u001b[0m'


# custom argpparse number type so that it raises an exception if an int arg is smaller than 1 or bigger than INT_MAX
def my_int_type(x):
    try:
        x = int(x)
    except ValueError:
        raise argparse.ArgumentTypeError("Amount has to be an integer.")
    if x < 1 or x > 2147483647:
        raise argparse.ArgumentTypeError("Minimum amount has to be greater than 0 and smaller than 2147483647.")
    return x


# custom argpparse number type so that it raises an exception if an int arg is smaller than INT_MIN or bigger than
# INT_MAX
def my_int_type_2(x):
    try:
        x = int(x)
    except ValueError:
        raise argparse.ArgumentTypeError("Amount has to be an integer.")
    if x < -2147483647 or x > 2147483647:
        raise argparse.ArgumentTypeError("Minimum amount has to be greater than -2147483648 and smaller than "
                                         "2147483647.")
    return x


# custom argpparse type representing a set
def set_type(x):
    lst = str(x).split()

    try:
        x = int(x)
    except ValueError:
        raise argparse.ArgumentTypeError("Amount has to be an integer.")
    if x < 1 or x > 2147483647:
        raise argparse.ArgumentTypeError("Minimum amount has to be greater than 0 and smaller than 2147483647.")
    return x

# custom argparse type that checks if a specified file does exist and can be executed
def my_bin_type(x):
    if not os.path.exists(x) or not os.path.isfile(x):
        raise argparse.ArgumentTypeError(f"Binary '{x}' not found.")
    if not os.access(x, os.X_OK):
        raise argparse.ArgumentTypeError(f"Binary '{x}' is not executable.")
    return x


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-s", "--set", type=str, help="Set of numbers to test.")
    parser.add_argument("-n", "--numamount", type=my_int_type, help="Amount of numbers in test sets.")
    parser.add_argument("-t", "--testamount", type=my_int_type, help="Amount of tests.")
    parser.add_argument("-i", "--minnum", type=my_int_type_2, nargs="?", const=-15000, default=-15000,
                        help="Smallest possible number in a set.")
    parser.add_argument("-a", "--maxnum", type=my_int_type_2, nargs="?", const=15000, default=15000,
                        help="Biggest possible number in a set.")
    parser.add_argument("-b", "--binary", type=my_bin_type, nargs="?", const="push_swap",
                        default="push_swap", help="Location of the tested binary. Default: \"push_swap\".")
    args = parser.parse_args()
    print("testing push_swap...")
    nam = int(args.numamount)
    tam = int(args.testamount)
    for i in range(tam):
        # https://stackoverflow.com/a/22842411
        num_lst = None
        try:
            num_lst = random.sample(range(int(args.minnum), int(args.maxnum)), int(args.numamount))
        except ValueError:
            exit("Can not build a set of numbers large enough within the given range")



if __name__ == "__main__":
    main()
