#! /usr/bin/env python
#coding:utf-8

from __future__ import division
import random



if __name__ == "__main__":
    score = [random.randint(0, 100) for i in range(40)]
    total_score = sum(score)
    avg_score = total_score/40
    print(str("Average Score: ") + str(avg_score))
    lessThanAvg = [i for i in score if i < avg_score]
    print("Printing out scores less than average: ")
    print(lessThanAvg)
    print("Sorting the scores from high to low: ")
    print(sorted(score, reverse = True))