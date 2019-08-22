<p>
<img width="260" height="170" src="https://davidjohncoleman.com/wp-djc/wp-content/uploads/2017/06/HBTN-Borderless-CMYK-Logo-Vertical-Color-Black@1200ppi-300x236.png" align="right" >
</p>





# Shell Project

Our simple shell program produce output according to a format as described below.
                                                                                
       * when you type a command like /bin/ls                                   
       * when you type a command with argumenst like /binl/ls -la               
       * when you type a command like ls                                        
       * when you type a command with arguments like ls -la                     
       * when you type built-it commands                                        
       * when you type enviroment commands                                      
                                                                                
## Examples                                                                     
                                                                                
simpleshell$ /bin/ls                                                            
file1	     file2    file3    file4     file5     file6    file7    file8      
file1.c	     file2.c  file3.c  file4.c   file5.c   file6.c  file7.c  file8.c    
simpleshell$                                                                    
                                                                                
Example 2:
simpleshell$ /bin/ls -l
total 132
-rwxrwxr-x 1 yesid yesid  8558 ago 15 14:23 file1
-rwxrwxr-x 1 yesid yesid   208 ago 15 14:29 file1.c
-rwxrwxr-x 1 yesid yesid  8665 ago 17 16:00 file2
-rw-rw-r-- 1 yesid yesid   328 ago 16 09:22 file2.c
-rwxrwxr-x 1 yesid yesid  8764 ago 16 10:12 file3
-rwxrwxr-x 1 yesid yesid  8715 ago 16 10:23 file3.c
-rw-rw-r-- 1 yesid yesid   507 ago 16 10:23 fork4
-rw-rw-r-- 1 yesid yesid   377 ago 16 10:12 file4.c
-rwxrwxr-x 1 yesid yesid  8774 ago 15 15:49 file5
-rw-rw-r-- 1 yesid yesid   422 ago 15 15:48 file5.c
-rwxrwxr-x 1 yesid yesid  8718 ago 16 14:27 file6
-rw-rw-r-- 1 yesid yesid   357 ago 16 14:27 file6.c
-rwxrwxr-x 1 yesid yesid  8669 ago 15 11:26 file7
-rw-rw-r-- 1 yesid yesid   252 ago 15 11:26 file7.c
-rw-rw-r-- 1 yesid yesid    32 ago 17 13:49 file8
-rwxrwxr-x 1 yesid yesid 16889 ago 20 22:53 file8.c
-rwxrwxr-x 1 yesid yesid  2699 ago 20 23:35 file9
-rwxrwxr-x 1 yesid yesid  2737 ago 20 22:53 file9.c
simpleshell$                                                                    
## Prerequisites

for this simple shell you need knowledge about loops(if, else, else if, for, while)
 arrays, pointers, malloc, free, structs, typedef, argc-argv, PID PPID, fork, gietline
strtok, stat, PATH, getenv, wait, execve

### Installing

for have the code in your local machine you only need download the code files and put it into a directory and compile it with gcc compiler 
```
gcc -Wall -Werror -Wextra -pedantic  *.c -o simpleshell
```
## Built With

All the code was write under ubuntu 14.04 using the compiler version
gcc 4.84 for 64 bits

## Contributing

-- Jhonatan Galindo - Holberton Student                                         
-- Yesid Gutierrez - Holberton Student                                          

## Versioning

V 0.0 for manual review

## Authors

---Jhonatan Galindo   950@holbertonschool.com                                  
---Yesid Gutierrez  944@holbertonshcool.com                                    

## Tasks

| Task               | Description                              |
| ------------------ | ---------------------------------------- |
| Task 0 Mandatory   | Write a README, man page and Authors files |
| Task 1 Mandatory   | Write a beautiful code that passes the Betty checks |
| Task 2 Advanced    |  |
| Task 3 Mandatory   | Write a simple UNIX command line interpreter |
| Task 4 Advanced    |  |
| Task 5  Mandatory  | Handle command lines with arguments |
| Task 6 Advanced    |  |
| Task 7 Mandatory   | Handle the PATH |
| Task 8 Mandatory   | Implement exit built-in, that exit the shell |
| Task 9 Advanced    |  |
| Task 10 Advanced   |  |
| Task 11 Mandatory  | Inplement the env built-in|
| Task 12 Advanced   | Implemente the setenv and unsetenv |
| Task 13 Advanced   | Implement the built-in command cd|
| Task 14 Advanced   | handle the commands separator |
| Task 15 Advanced   | Handle the && and || shell logical operators|
| Task 16 Advanced   | Implement alias buil-in command|
| Task 17 Advanced   | Handle the variables replacement|
| Task 18 Advanced   | Handle comments (#)|
| Task 19 Advanced   | Implement the help built-in|
| Task 20 Advanced   | Implement the histroy buil-in, without any argument|
| Task 21 Advanced   | Implement simple_shell [filename]|
| Task 22 Advanced   | Write a blog that explain what happen when you type ls -l in the shell|
                                                                             
## Files

| File               | Description                              |
| ------------------ | ---------------------------------------- |
|         |  |
|         |  |
|         |  |
|         |  |
|         |  |
|         |  |
|         |  |
|         |  |
|         |  |
|         |  |
|         |  |
|         |  |
