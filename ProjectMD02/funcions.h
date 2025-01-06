#include "datatypes.h"
// Khai bao nguyen mau ham
void adminMenu();
void mainMenu();
void studentMenu();
void waitAndClear();
void addStudent(Student student[], int *studentCount);
void displayStudent(Student student[] ,int studentCount);
void saveStudentToFile(Student student[], int studentCount);
void loadStudentFromFile(Student student[], int *studentCount);
void editStudentByID(Student student[], int studentCount);
void deleteStudent(Student student[], int *studentCount);
void sortStudentByName(Student student[], int studentCount);
void sortAscending(Student student[], int studentCount);
void sortDescending(Student student[], int studentCount);
void searchByName(Student student[], int studentCount);


// Khai bao nguyen mau ham kiem tra du lieu
int isNotEmpty(char str[]); 
int isDuplicateStudentId(Student student[], int studentCount, char id[]);
int isDuplicateEmail(Student student[], int studentCount, char email[]);
int isDuplicatePhone(Student student[], int studentCount, char phone[]);
int checkStudentIdValid(char studentId[]);
int checkClassroomIdValid(char classroomID[]);
int checkNameValid(char name[]);
int checkGenderValid(int gender);
int checkEmailValid(char email[]);
int checkPhoneValid(char phone[]);
int checkPasswordValid(char password[]);
int checkDateValid(int day, int month, int year);


