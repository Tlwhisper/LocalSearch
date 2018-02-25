#!/usr/bin/env python3

import sys
import matplotlib.pyplot as plt
import numpy as np

def main():
    values = []
    for line in sys.stdin:
        values.append(float(line))
        print(values[-1])

    plt.plot(values)
    plt.show()

main()