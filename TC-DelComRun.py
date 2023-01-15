import os
import subprocess

MainCompileTarget = "TermColourExample.cpp"
OutputExecutableName = "TermColourExample"
AppendExeWithSystemName = True

print(os.name)

if (os.name == 'Linux') or (os.name == 'posix'):
    print("System: LINUX")
    if(AppendExeWithSystemName):
        OutputExecutableName = ''.join((OutputExecutableName, "Linux.exe"))
    else:
        OutputExecutableName = ''.join((OutputExecutableName, ".exe"))

    print("Deleting old executable!")
    os.system(''.join(("rm ./", OutputExecutableName)))

    print("Compiling new executable!")
    os.system(''.join(("g++ --std=c++23 ", MainCompileTarget, " -o ", OutputExecutableName)))

    print("Running program!")
    subprocess.call(''.join(("./", OutputExecutableName)))

elif (os.name == 'Windows') or (os.name == 'nt'):
    print("System: WINDOWS")
    if(AppendExeWithSystemName):
        OutputExecutableName = ''.join((OutputExecutableName, "Windows.exe"))
    else:
        OutputExecutableName = ''.join((OutputExecutableName, ".exe"))

    print("Deleting old executable!")
    os.system(''.join(("del .\\", OutputExecutableName)))

    print("Compiling new executable!")
    os.system(''.join(("g++ --std=c++23 ", MainCompileTarget, " -o ", OutputExecutableName)))

    print("Running program!")
    subprocess.call((''.join(("./", OutputExecutableName))))

