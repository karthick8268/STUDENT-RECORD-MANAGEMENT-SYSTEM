#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include <cctype>
#include <iomanip>

using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string gender;
    string department;
    int yearOfStudy;
    string email;
    string phone;
    string city;
    float marks;
    char grade;
};

// ================= INPUT VALIDATION =================

int getPositiveInt(string message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            if (value > 0)
                return value;

            cout << "Invalid! Value must be greater than zero.\n";
        }
        else
        {
            cout << "Invalid input! Enter a whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int getAge()
{
    int age;

    while (true)
    {
        cout << "Enter Age (16-100): ";

        if (cin >> age)
        {
            if (age >= 16 && age <= 100)
                return age;

            cout << "Age must be between 16 and 100.\n";
        }
        else
        {
            cout << "Invalid age! Enter a whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int getYearOfStudy()
{
    int year;

    while (true)
    {
        cout << "Enter Year of Study (1-4): ";

        if (cin >> year)
        {
            if (year >= 1 && year <= 4)
                return year;

            cout << "Year must be between 1 and 4.\n";
        }
        else
        {
            cout << "Invalid year! Enter a whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

float getMarks()
{
    float marks;

    while (true)
    {
        cout << "Enter Marks (0-100): ";

        if (cin >> marks)
        {
            if (marks >= 0 && marks <= 100)
                return marks;

            cout << "Marks must be between 0 and 100.\n";
        }
        else
        {
            cout << "Invalid marks! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

char getGrade()
{
    char grade;

    while (true)
    {
        cout << "Enter Grade (A/B/C/D/F): ";

        if (cin >> grade)
        {
            grade = static_cast<char>(
                toupper(static_cast<unsigned char>(grade))
            );

            if (grade == 'A' || grade == 'B' ||
                grade == 'C' || grade == 'D' ||
                grade == 'F')
            {
                return grade;
            }

            cout << "Invalid grade! Enter A, B, C, D, or F.\n";
        }
        else
        {
            cout << "Invalid grade input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// ================= TEXT INPUT =================

string getText(string message)
{
    string value;

    while (true)
    {
        cout << message;
        getline(cin >> ws, value);

        if (!value.empty())
            return value;

        cout << "This field cannot be empty.\n";
    }
}

string getSingleWord(string message)
{
    string value;

    while (true)
    {
        cout << message;

        if (cin >> value)
            return value;

        cout << "Invalid input! Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ================= EMAIL VALIDATION =================

bool isValidEmail(const string& email)
{
    size_t at = email.find('@');

    if (at == string::npos || at == 0)
        return false;

    if (email.find('@', at + 1) != string::npos)
        return false;

    size_t dot = email.find('.', at + 1);

    if (dot == string::npos || dot == at + 1)
        return false;

    if (dot == email.size() - 1)
        return false;

    if (email.find(' ') != string::npos)
        return false;

    return true;
}

string getEmail()
{
    string email;

    while (true)
    {
        cout << "Enter Email Address: ";
        cin >> email;

        if (isValidEmail(email))
            return email;

        cout << "Invalid email! Example: student@gmail.com\n";
    }
}

// ================= INDIAN PHONE VALIDATION =================

bool isValidPhone(const string& phone)
{
    if (phone.length() != 10)
        return false;

    if (phone[0] < '6' || phone[0] > '9')
        return false;

    for (char digit : phone)
    {
        if (!isdigit(static_cast<unsigned char>(digit)))
            return false;
    }

    return true;
}

string getPhone()
{
    string phone;

    while (true)
    {
        cout << "Enter Indian Mobile Number (10 digits): ";
        cin >> phone;

        if (isValidPhone(phone))
            return phone;

        cout << "Invalid phone number!\n";
        cout << "Enter 10 digits starting with 6, 7, 8, or 9.\n";
    }
}

// ================= SAVE STUDENTS =================

bool saveStudents(const vector<Student>& students)
{
    ofstream file("students.csv");

    if (!file.is_open())
    {
        cout << "Error: Could not open students.csv for saving.\n";
        return false;
    }

    for (const Student& s : students)
    {
        file << s.id << ','
             << s.name << ','
             << s.age << ','
             << s.gender << ','
             << s.department << ','
             << s.yearOfStudy << ','
             << s.email << ','
             << s.phone << ','
             << s.city << ','
             << s.marks << ','
             << s.grade << '\n';
    }

    file.close();

    if (!file)
    {
        cout << "Error: Could not finish saving records.\n";
        return false;
    }

    return true;
}

// ================= LOAD STUDENTS =================

bool loadStudents(vector<Student>& students)
{
    ifstream file("students.csv");

    if (!file.is_open())
        return true;

    vector<Student> loadedStudents;
    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);
        string field;
        Student s;

        try
        {
            if (!getline(ss, field, ',')) continue;
            s.id = stoi(field);

            if (!getline(ss, s.name, ',')) continue;

            if (!getline(ss, field, ',')) continue;
            s.age = stoi(field);

            if (!getline(ss, s.gender, ',')) continue;
            if (!getline(ss, s.department, ',')) continue;

            if (!getline(ss, field, ',')) continue;
            s.yearOfStudy = stoi(field);

            if (!getline(ss, s.email, ',')) continue;
            if (!getline(ss, s.phone, ',')) continue;
            if (!getline(ss, s.city, ',')) continue;

            if (!getline(ss, field, ',')) continue;
            s.marks = stof(field);

            if (!getline(ss, field)) continue;
            if (field.empty()) continue;

            s.grade = field[0];

            loadedStudents.push_back(s);
        }
        catch (const exception&)
        {
            cout << "Warning: Skipping an invalid CSV record.\n";
        }
    }

    if (file.bad())
    {
        cout << "Error: Could not read records completely.\n";
        return false;
    }

    students = loadedStudents;
    return true;
}

// ================= DISPLAY STUDENT =================

void displayStudent(const Student& s)
{
    cout << "\n";
    cout << "==================================================\n";
    cout << "                 STUDENT DETAILS\n";
    cout << "==================================================\n";

    cout << left;
    cout << setw(20) << "Student ID" << ": " << s.id << '\n';
    cout << setw(20) << "Full Name" << ": " << s.name << '\n';
    cout << setw(20) << "Age" << ": " << s.age << '\n';
    cout << setw(20) << "Gender" << ": " << s.gender << '\n';
    cout << setw(20) << "Department" << ": " << s.department << '\n';
    cout << setw(20) << "Year of Study" << ": " << s.yearOfStudy << '\n';
    cout << setw(20) << "Email" << ": " << s.email << '\n';
    cout << setw(20) << "Phone" << ": " << s.phone << '\n';
    cout << setw(20) << "City" << ": " << s.city << '\n';
    cout << setw(20) << "Marks" << ": "
         << fixed << setprecision(2) << s.marks << '\n';
    cout << setw(20) << "Grade" << ": " << s.grade << '\n';

    cout << "==================================================\n";
}

// ================= GET STUDENT DETAILS =================

Student getStudentDetails(int id)
{
    Student s;

    s.id = id;
    s.name = getText("Enter Full Name: ");
    s.age = getAge();
    s.gender = getSingleWord("Enter Gender: ");
    s.department = getSingleWord("Enter Department: ");
    s.yearOfStudy = getYearOfStudy();
    s.email = getEmail();
    s.phone = getPhone();
    s.city = getText("Enter City: ");
    s.marks = getMarks();
    s.grade = getGrade();

    return s;
}

// ================= MAIN PROGRAM =================

int main()
{
    vector<Student> students;
    int choice;

    if (!loadStudents(students))
    {
        cout << "Unable to load records. Check students.csv.\n";
        return 1;
    }

    cout << "\n";
    cout << "==================================================\n";
    cout << "          STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "==================================================\n";
    cout << "  Saved student records loaded: "
         << students.size() << '\n';

    do
    {
        cout << "\n";
        cout << "==================================================\n";
        cout << "          STUDENT RECORD MANAGEMENT SYSTEM\n";
        cout << "==================================================\n\n";

        cout << "  [1]  Add New Student\n";
        cout << "  [2]  View All Students\n";
        cout << "  [3]  Search Student\n";
        cout << "  [4]  Update Student Details\n";
        cout << "  [5]  Delete Student Record\n";
        cout << "  [6]  Exit Application\n";

        cout << "\n--------------------------------------------------\n";
        cout << "  Enter your choice (1-6): ";

        if (!(cin >> choice))
        {
            cout << "\nInvalid input! Enter a number from 1 to 6.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // ADD STUDENT

        if (choice == 1)
        {
            int id = getPositiveInt("Enter Student ID: ");
            bool exists = false;

            for (const Student& s : students)
            {
                if (s.id == id)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "\nStudent ID already exists!\n";
            }
            else
            {
                Student s = getStudentDetails(id);
                students.push_back(s);

                if (saveStudents(students))
                {
                    cout << "\nStudent added and saved successfully!\n";
                }
                else
                {
                    students.pop_back();
                    cout << "Saving failed. Student was not added.\n";
                }
            }
        }

        // DISPLAY ALL STUDENTS

        else if (choice == 2)
        {
            if (students.empty())
            {
                cout << "\nNo student records found.\n";
            }
            else
            {
                cout << "\nTotal Students: "
                     << students.size() << '\n';

                for (const Student& s : students)
                    displayStudent(s);
            }
        }

        // SEARCH STUDENT

        else if (choice == 3)
        {
            int id = getPositiveInt("Enter Student ID to search: ");
            bool found = false;

            for (const Student& s : students)
            {
                if (s.id == id)
                {
                    cout << "\nStudent Found!\n";
                    displayStudent(s);
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nStudent not found.\n";
        }

        // UPDATE STUDENT

        else if (choice == 4)
        {
            int id = getPositiveInt("Enter Student ID to update: ");
            bool found = false;

            for (size_t i = 0; i < students.size(); i++)
            {
                if (students[i].id == id)
                {
                    cout << "\nEnter the updated details:\n";

                    Student updated = getStudentDetails(id);
                    Student original = students[i];

                    students[i] = updated;

                    if (saveStudents(students))
                    {
                        cout << "\nStudent details updated successfully!\n";
                    }
                    else
                    {
                        students[i] = original;
                        cout << "Saving failed. Original details restored.\n";
                    }

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nStudent not found.\n";
        }

        // DELETE STUDENT

        else if (choice == 5)
        {
            int id = getPositiveInt("Enter Student ID to delete: ");
            bool found = false;

            for (size_t i = 0; i < students.size(); i++)
            {
                if (students[i].id == id)
                {
                    Student deletedStudent = students[i];

                    students.erase(students.begin() + i);

                    if (saveStudents(students))
                    {
                        cout << "\nStudent deleted successfully!\n";
                    }
                    else
                    {
                        students.insert(
                            students.begin() + i,
                            deletedStudent
                        );

                        cout << "Saving failed. Student record restored.\n";
                    }

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nStudent not found.\n";
        }

        // EXIT

        else if (choice == 6)
        {
            cout << "\n==================================================\n";
            cout << "  Thank you for using Student Record Management!\n";
            cout << "==================================================\n";
        }

        else
        {
            cout << "\nInvalid choice! Enter a number from 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}