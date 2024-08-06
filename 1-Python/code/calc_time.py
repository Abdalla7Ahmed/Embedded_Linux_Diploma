#! /usr/bin/python3

import time

number_list = list(range(1,10000001))
number_set = set(number_list)
#print(number_list)

start_time = time.time()
print(1000000 in number_list)
end_time = time.time()

print("time taken in search in list is ",end_time -  start_time , "seconds")


start_time = time.time()
print(1000000 in number_set)
end_time = time.time()

print("time taken in search in list is ",end_time -  start_time , "seconds")

'''
2024-06-09 20:19:02.089589
True
time taken in search in list is  0.006781339645385742 seconds
True
time taken in search in list is  4.76837158203125e-06 seconds    very small
'''