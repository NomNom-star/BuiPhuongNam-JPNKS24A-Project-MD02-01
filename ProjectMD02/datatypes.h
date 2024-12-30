#include <stdbool.h>
// Cac kieu du lieu tu dinh nghia

typedef struct {
    int day, month, year;
} Date ;

typedef struct {
    char studentId[10];
    char classroomID[10];
    char name[50];
    Date dateOfBirth;
    bool gender;
    char email[50];
    char phone[20];
    char password[50];
} Student;

typedef struct {
    char classroomId[10];
    char teacherId[10];
    char classroomName[50];
    Student students[];
} Classroom ;

typedef struct {
    char teacherId[10];
    char classroomId[10];
    char name[50];
    Date dateOfBirth;
    bool gender;
    char email[50];
    char phone[20];
    char password[50];
    Classroom classrooms[];
} Teacher ;

