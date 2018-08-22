#! /usr/bin/env python
#coding:utf-8


from __future__ import division
import random

def CountAvg(ScoreList, CourseNum, StudentNum):
    TotalEachStu = [sum(ScoreList[i]) for i in range(StudentNum)]
    AvgEachStu = [TotalEachStu[i]/CourseNum for i in range(StudentNum)]
    CourseLists = []
    for j in range(CourseNum):
        CourseList = []
        for i in range(StudentNum):
            CourseList.append(ScoreList[i][j])
        CourseLists.append(CourseList)

    TotalEachCourse = [sum(CourseLists[i]) for i in range(CourseNum)]
    AvgEachCourse = [TotalEachCourse[i]/StudentNum for i in range(CourseNum)]

    return (TotalEachStu, TotalEachCourse, AvgEachStu, AvgEachCourse)


if __name__ == "__main__":

    CourseList = ["Java", "C++", "SCala", "SQL", "Rust"]
    StudentNum = 20

    ScoreList = [[random.randint(0, 100) for j in range(len(CourseList))] for i in range(StudentNum)]
    for i in range(StudentNum):
        print("Student " + str(i) + ": ")
        line = str("")
        for j in range(len(CourseList)):
            line = line + str(ScoreList[i][j]) + str(", ")
        print(line)

    TotalEachStu, TotalEachCourse, AvgEachStu, AvgEachCourse = CountAvg(ScoreList, len(CourseList), StudentNum)
    print("Each Student's total grades:")
    print(TotalEachStu)

    print("Each Course's total grade:")
    print(TotalEachCourse)

    print("Each Student's Avg grade:")
    print(AvgEachStu)

    print("Each Course's Avg grade:")
    print(AvgEachCourse)



