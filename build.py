import os

def system(command):
    if isinstance(command, list):
        for i in command:
            os.system(i)
    else:
        os.system(command)


if __name__=='__main__':
    path = os.getcwd() + "/build"

    if not os.path.isdir(path):
        os.mkdir(path)

    os.chdir(path)

    system(['rm CMakeCache.txt', 'cmake ../', 'make', './neural'])
