#Benjamin Niccum 1002111609

import os
import stat

def dir_size(path):
    total_size = 0
    for dir_entry in os.scandir(path):
        if dir_entry.is_dir():
            total_size += dir_size(dir_entry.path)  #Object is directory, recursively calls new path
        elif dir_entry.is_file():
            total_size += os.stat(dir_entry.path).st_size #Object is a file, adds size to running sum
    return total_size

if __name__ == "__main__":
    path = "."
    size = dir_size(path)  #First call to function
    print(size)