🎓 Student Record Management System

A console-based Student Record Management System developed using C++. This project helps users manage student information through a simple, menu-driven interface.

📌 About the Project

The Student Record Management System is a beginner-friendly C++ project designed to perform basic student record operations. It allows users to add, view, search, update, and delete student records.

The application also saves student information in a CSV file, allowing records to remain available even after the program is closed and reopened.

✨ Features

- Add Student: Add new student records with personal and academic details.
- View All Students: Display the records of all students.
- Search Student: Find a student using their unique Student ID.
- Update Student: Modify existing student information.
- Delete Student: Remove a student record.
- Data Persistence: Save and load student records using a CSV file.
- Input Validation: Validate student ID, age, year of study, marks, grade, email, and phone number.
- Professional Console Interface: Navigate through the application using a simple menu.

🛠️ Technologies Used

- Programming Language: C++
- File Handling: C++ file streams ("fstream")
- Data Storage: CSV file
- Compiler: GCC (g++)

📋 Student Information

Each student record contains the following details:

- Student ID
- Full Name
- Age
- Gender
- Department
- Year of Study
- Email Address
- Phone Number
- City
- Marks
- Grade

⚙️ How to Run the Project

Prerequisites

- A C++ compiler, such as GCC ("g++")
- Visual Studio Code or another C++ development environment

Step 1: Clone the Repository
https://github.com/karthick8268/STUDENT-RECORD-MANAGEMENT-SYSTEM



Step 2: Open the Project Folder

Open the downloaded project folder in Visual Studio Code.

Step 3: Compile the Program

Open the terminal in the project folder and run:

g++ main.cpp -o studentcsv.exe

Step 4: Run the Application

On Windows PowerShell, run:

.\studentcsv.exe

💾 Data Storage

The application stores student records in a file named "students.csv".

- Records are saved when changes are successfully written to the file.
- Previously saved records are loaded when the application starts.
- Student information remains available after restarting the application, provided the CSV file is retained.

Important: Keep "students.csv" in the appropriate project folder so the application can access saved records.

🎯 Learning Outcomes

Through this project, I practised:

- C++ structures and vectors
- Functions and modular programming
- Conditional statements and loops
- Input validation and error handling
- File handling and data persistence
- Searching, updating, and deleting records
- Organizing a console-based application

🚀 Future Improvements

- Add a graphical user interface.
- Develop a website version of the application.
- Add student performance reports.
- Calculate grades automatically based on marks.
- Improve data validation and CSV handling.

👨‍💻 Author

Karthick B

First-Year Computer Science and Engineering Student

📌 Project Status

The console-based version is implemented, and its main features have been tested.

---

⭐ If you find this project useful, feel free to explore the code and share feedback!

Copyright and Usage

© 2026 Project Author. All rights reserved.

This project is shared publicly for learning, demonstration, and portfolio purposes.

Viewing the source code does not grant permission to reuse, modify, redistribute, or publish it as part of another project.

If you would like to reuse or adapt this project, please contact the author and obtain permission first.

Author: Karthick B.
Project: Student Record Management System (C++)