#include "datatypes.h"
// Khai bao nguyen mau ham

void mainMenu();
void studentMenu();
void addStudent(Student student[], int *studentCount);
void displayStudents (Student student[] ,int studentCount);
void saveStudentsToFile(Student student[], int studentCount);
void loadStudentsFromFile(Student student[], int *studentCount);
void editStudent(Student student[], int *studentCount);

