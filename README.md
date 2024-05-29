# to-do.list
_This is a simple implementation of a popular productivity tool "to-do list" using C as a project of ***Introduction-to-Programming*** subject. To-do is text-based program, where user can add and modify their tasks within the terminal._
## 1. Setting Up
To compile and run the program, follow these steps:
   1. Clone the repository on terminal (or download the source code).
      ```
      git clone https://github.com/hongloan2k5/to-do.list.git
      ```
   2. Open the terminal or command prompt and navigate the project directory.

   3. Compile and output the code into binary object using gcc.
      ```
      gcc -o to-do main.c to-do.c
      ```
   4. Run the executable.
      ```
      ./to-do
      ```
   5. Add path directory.
      ```
      export PATH=$PATH:"/home/user_name/to-do/"
      ```
Here's a video following these steps:

[Screencast from 29-05-2024 12:11:19.webm](https://github.com/hongloan2k5/to-do.list/assets/169520839/b7d867f0-68ca-46a2-ac94-354f691dea9c)

## 2. How it Work
* Tasks is always showed at the display for better visibility and modification.
* There are four command keys (**add, edit, delete, quit**) to navigate within the program.
* Each command entered will further more ask user to input more specicific modification.
* The program will refresh itself after being modified.
* User input  data will be saved into a local file so the program won't lose its data after being closed.

## 3. Demo
Here's a screenshot of the program:

![Screenshot from 2024-05-29 11-49-59](https://github.com/hongloan2k5/to-do.list/assets/169520839/439e1da4-a3c6-46db-a6bd-b466f440423b)

Here's a video show casing of how it being used:

[Screencast from 29-05-2024 12:22:18.webm](https://github.com/hongloan2k5/to-do.list/assets/169520839/a5ae9128-b5d4-47e2-b1a6-56d27f47d110)


