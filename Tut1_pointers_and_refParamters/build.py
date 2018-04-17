'''
Created on Apr 9, 2018

@author: modys
'''

if __name__ == '__main__':
    pass

import os
import shutil
import platform
import subprocess

myfile= 'debug'
print("--------Project Build System--------------")
print("clean --> Cleans the project")
print("build --> builds the project according to platform type")
print("run --> runs the project\n")

option  = str(raw_input("Enter valid option\n"))

print(option)

if option == "clean":
    print("---------Clean------------")
        ## Try to remove tree; if failed show an error using try...except on screen
    try:
        shutil.rmtree(myfile)
    except OSError, e:
        print ("Error: %s - %s." % (e.filename,e.strerror))
 
elif option == "build":
    print("---------Create New Build Directory------------")
    ## Create a new directory
    if not os.path.exists(myfile):
        os.makedirs(myfile)
        
    print("---------Build------------")
      
    if(platform.system() == 'Windows'):
        print("---------Build Windows------------")
        subprocess.call('cd Debug & cmake .. -G "MinGW Makefiles" & make',shell=True)
         
    elif (platform.system()=='Linux'):
        print("---------Build Linux--------------")
        cmd = 'cd '+os.path.abspath(myfile)
        subprocess.call(cmd+'&& cmake .. && make',shell=True)

    else:
        print("Platform Unknown")
       
elif option == "run":
    print("---------Run Application------------")
  
    if(platform.system() == 'Windows'):
        print("-----------Run on Windows------------")
        subprocess.call('cd Debug & test.exe',shell=True)
        
    elif (platform.system()=='Linux'):
        print("---------Run on Linux--------------")
        cmd = 'cd '+os.path.abspath(myfile)
        subprocess.call(cmd+'&& ./test',shell=True)

    else:
        print("Platform Unknown")
  
else:
    print("Enter Valid Option")