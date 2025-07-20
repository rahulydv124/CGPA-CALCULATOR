#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Course {
    string name;
    float grade;
    int credits;
};

float calculateGPA(const vector<Course>& courses) {
    float totalGradePoints = 0;
    int totalCredits = 0;

    for (const Course& c : courses) {
        totalGradePoints += c.grade * c.credits;
        totalCredits += c.credits;
    }

    return (totalCredits == 0) ? 0 : totalGradePoints / totalCredits;
}

void displayCourses(const vector<Course>& courses) {
    cout << "\n----------------------------------------\n";
    cout << left << setw(20) << "Course Name" 
         << setw(10) << "Grade" 
         << setw(10) << "Credits" << "\n";
    cout << "----------------------------------------\n";

    for (const Course& c : courses) {
        cout << left << setw(20) << c.name
             << setw(10) << c.grade
             << setw(10) << c.credits << "\n";
    }

    cout << "----------------------------------------\n";
}

int main() {
    int numCourses;
    vector<Course> courses;

    cout << "🎓 Welcome to CGPA Calculator 🎓\n\n";
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    while (numCourses <= 0) {
        cout << "Number of courses should be positive. Try again: ";
        cin >> numCourses;
    }

    for (int i = 0; i < numCourses; ++i) {
        Course course;
        cout << "\nEnter details for course #" << i + 1 << ":\n";

        cout << "Course name: ";
        cin.ignore();  // clear newline from buffer
        getline(cin, course.name);

        cout << "Grade (out of 10): ";
        cin >> course.grade;
        while (course.grade < 0 || course.grade > 10) {
            cout << "Invalid grade! Enter between 0 and 10: ";
            cin >> course.grade;
        }

        cout << "Credit hours: ";
        cin >> course.credits;
        while (course.credits <= 0) {
            cout << "Credits should be greater than 0. Try again: ";
            cin >> course.credits;
        }

        courses.push_back(course);
    }

    displayCourses(courses);

    float cgpa = calculateGPA(courses);

    cout << fixed << setprecision(2);
    cout << "\n📌 Your CGPA is: ";
    if (cgpa >= 9) cout << "\033[1;32m"; // Green for 9+
    else if (cgpa >= 7) cout << "\033[1;33m"; // Yellow for 7–9
    else cout << "\033[1;31m"; // Red for below 7

    cout << cgpa << "\033[0m" << " / 10.0\n";

    cout << "\n🎉 Thank you for using the CGPA Calculator! 🎉\n";
    return 0;
}
