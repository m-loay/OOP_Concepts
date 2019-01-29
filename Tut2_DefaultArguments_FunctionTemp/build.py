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
import argparse

myfile= 'debug'

parser = argparse.ArgumentParser()
parser.add_argument('-c', action="store", dest="clean",help ='Cleans the project')
parser.add_argument('-g', action="store", dest="gen",help ='generate make file')
parser.add_argument('-b', action="store", dest="build",help = 'builds the project according to platform type')
parser.add_argument('-r', action="store", dest="run",help = 'runs the project')
results = parser.parse_args()
   
if results.clean == "clean":
    print("---------Clean------------")
        ## Try to remove tree; if failed show an error using try...except on screen
    try:
        shutil.rmtree(myfile)
    except OSError, e:
        print ("Error: %s - %s." % (e.filename,e.strerror))

if results.gen == "gen":
    print("---------Genertae MakeFiles------------")
    ## Create a new directory
    if not os.path.exists(myfile):
        os.makedirs(myfile)
        
    print("---------Generate------------")
      
    if(platform.system() == 'Windows'):
        print("---------Generate Windows Makefile------------")
        subprocess.call('cd '+myfile+' & cmake .. -G "MinGW Makefiles" ',shell=True)
         
    elif (platform.system()=='Linux'):
        print("---------Build Linux--------------")
        cmd = 'cd '+os.path.abspath(myfile)
        subprocess.call(cmd+'&& cmake ..',shell=True)

    else:
        print("Platform Unknown")

if results.build == "build":
    print("---------Create New Build Directory------------")
    ## Create a new directory
    if not os.path.exists(myfile):
        os.makedirs(myfile)
        
    print("---------Build------------")
      
    if(platform.system() == 'Windows'):
        print("---------Build Windows------------")
        subprocess.call('cd '+myfile+'& mingw32-make',shell=True)
         
    elif (platform.system()=='Linux'):
        print("---------Build Linux--------------")
        cmd = 'cd '+os.path.abspath(myfile)
        subprocess.call(cmd+'make',shell=True)

    else:
        print("Platform Unknown")
       
if results.run == "run":
    print("---------Run Application------------")
  
    if(platform.system() == 'Windows'):
        print("-----------Run on Windows------------")
        subprocess.call('cd '+myfile+'& test.exe',shell=True)
        
    elif (platform.system()=='Linux'):
        print("---------Run on Linux--------------")
        cmd = 'cd '+os.path.abspath(myfile)
        subprocess.call(cmd+'&& ./test',shell=True)

    else:
        print("Platform Unknown")
  
if results.clean is None and results.build is None and results.run:
    print("Enter Valid Option")