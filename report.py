import os
import os.path


totalfiles = 0

for dirpath, dirnames, filenames in os.walk("."):
    for filename in [f for f in filenames if f.endswith(".cpp") or f.endswith(".py")]:
        totalfiles = totalfiles + 1
        print(os.path.join(dirpath, filename))


print("Total Files: " + str(totalfiles))
