#include "datatypes.h"
// Khai bao nguyen mau ham
void adminMenu();
void mainMenu();
void studentMenu();
void addStudent(Student student[], int *studentCount);
void displayStudent(Student student[] ,int studentCount);
void saveStudentToFile(Student student[], int studentCount);
void loadStudentFromFile(Student student[], int *studentCount);
void editStudentByID(Student student[], int studentCount);
void deleteStudent(Student student[], int *studentCount);
void sortStudentByName(Student student[], int studentCount);
void sortAscending(Student student[], int studentCount);
void sortDescending(Student student[], int studentCount);
