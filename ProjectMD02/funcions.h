#include "datatypes.h"
// Khai bao nguyen mau ham
void adminMenu();
void mainMenu();
void studentMenu();
void teacherMenu();
void waitAndClear();
void readFile(const char *filename);
// Student  
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

// Teacher
void addTeacher(Teacher teacher[], int *teacherCount);
void displayTeacher(Teacher teacher[], int teacherCount);
void saveTeacherToFile(Teacher teacher[], int teacherCount);
void loadTeacherFromFile(Teacher teacher[], int *teacherCount);
void editTeacherById(Teacher teacher[], int teacherCount);
void deleteTeacher(Teacher teacher[], int *teacherCount);
void sortTeacherByName(Teacher teacher[], int teacherCount);
void sortAscendingTeacher(Teacher teacher[], int teacherCount);
void sortDescendingTeacher(Teacher teacher[], int teacherCount);
void searchTeacherByName(Teacher teacher[], int teacherCount); 
// Khai bao nguyen mau ham kiem tra du lieu
// Student

int isDuplicateStudentId(Student student[], int studentCount, char id[]);
int isDuplicateEmail(Student student[], int studentCount, char email[]);
int isDuplicatePhone(Student student[], int studentCount, char phone[]);
int checkStudentIdValid(char studentId[]);

//Teacher
int isDuplicateTeacherId(Teacher teacher[], int teacherCount, char id[]);
int isDuplicateTeacherEmail(Teacher teacher[], int teacherCount, char email[]);
int isDuplicateTeacherPhone(Teacher teacher[], int teacherCount, char phone[]);
int checkTeacherIdValid(char teacherId[]);
// 
int isNotEmpty(char str[]); 
int checkNameValid(char name[]);
int checkGenderValid(int gender);
int checkEmailValid(char email[]);
int checkPhoneValid(char phone[]);
int checkPasswordValid(char password[]);
int checkDateValid(int day, int month, int year);
int checkClassroomIdValid(char classroomID[]);


