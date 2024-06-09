#! /usr/bin/python3
import psutil

# Get CPU usage percentage
print("CPU Usage:", psutil.cpu_percent())

# Get memory usage statistics
memory = psutil.virtual_memory()
print("Total Memory: ", memory.total/1000000000, "G")
print("Available Memory:", memory.available/1000000000, "G")
print("Used Memory:", memory.used/1000000000, "G")
print("Memory Usage Percentage:", memory.percent)

# Get disk usage statistics
disk = psutil.disk_usage('/')
print("Total Disk Space:", disk.total/1000000000, "G")
print("Used Disk Space:", disk.used/1000000000, "G")
print("Free Disk Space:", disk.free/1000000000, "G")
print("Disk Usage Percentage:", disk.percent)
