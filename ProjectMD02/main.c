#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Student students[50];
	Teacher teachers[50];
	int studentCount = 0;
	int teacherCount = 0;
	loadStudentFromFile(students, &studentCount);
	loadTeacherFromFile(teachers, &teacherCount);
	int choice;
	do{
		mainMenu();
        printf("\t\t Enter your choice:");
		scanf("%d", &choice);
		fflush;
		switch (choice){
		case 0 :
			system("cls");
			printf("Program exited!\n");
			printf("Thank you !!!\n");				
			break;
		case 1 :
			system("cls");
			do{
			adminMenu();
			printf("\t\t Enter your choice:");
			scanf("%d", &choice);
			fflush;
			switch (choice){
				case 0 :
					system("cls");
					printf("Program exited!\n");				
					break;
				case 1 :
					system("cls");
					do{
						studentMenu();
						printf("\t\t Enter your choice:");
						scanf("%d", &choice);
						fflush;
						switch (choice){
						case 0 :
							system("cls");
							printf("Program exited!\n");
							printf("Thank you !!!\n");				
							break;
						case 1 : // Them moi 1 hoc sinh
							system("cls");
							loadStudentFromFile(students, &studentCount);
							addStudent(students, &studentCount);
							break;
						case 2 : // Hien thi danh sach sinh vien
							system("cls"); 
							loadStudentFromFile(students, &studentCount);
							displayStudent(students, studentCount);
							break;
						case 3 : // Tim kiem sinh vien theo ten
							system("cls");
							loadStudentFromFile(students, &studentCount);
							searchStudentByName(students, studentCount);						
							break;
						case 4 : // Sua sinh vien theo ID nguoi dung nhap
							system("cls");
							loadStudentFromFile(students, &studentCount);
							editStudentByID(students, studentCount);
							break;
						case 5 : // Xoa 1 Sinh vien theo ID
							system("cls");
							loadStudentFromFile(students, &studentCount);
							deleteStudent(students, &studentCount);
							break;
						case 6 :  // Sap xep sinh vien theo ten
							system("cls");
							loadStudentFromFile(students, &studentCount);
							sortStudentByName(students, studentCount);
							break;
						default:
							system("cls");
							printf("\t\tYour choice is invalid\n");					
							break;
						}
						
					} while (choice != 0);
					break;
				case 2 :
					system("cls");
					do{
						teacherMenu();
						printf("\t\t Enter your choice:");
						scanf("%d", &choice);
						fflush;
						switch (choice){
						case 0 :
							system("cls");
							printf("Program exited!\n");
							printf("Thank you !!!\n");				
							break;
						case 1 : // Them moi 1 giao vien
							system("cls");
							loadTeacherFromFile(teachers, &teacherCount);
							addTeacher(teachers, &teacherCount);
							break;
						case 2 : // Hien thi danh sach giao vien
							system("cls");
							loadTeacherFromFile(teachers, &teacherCount);
							displayTeacher(teachers, teacherCount); 
							break;
						case 3 : // Tim kiem giao vien theo ten
							system("cls");
							loadTeacherFromFile(teachers, &teacherCount);	
							searchTeacherByName(teachers, teacherCount);				
							break;
						case 4 : // Sua thong tin giao vien theo ID nguoi dung nhap
							system("cls");
							loadTeacherFromFile(teachers, &teacherCount);
							editTeacherById(teachers, teacherCount);
							break;
						case 5 : // Xoa 1 giao vien theo ID
							system("cls");
							loadTeacherFromFile(teachers, &teacherCount);
							deleteTeacher(teachers, &teacherCount);
							break;
						case 6 :  // Sap xep giao vien theo ten
							system("cls");
							loadTeacherFromFile(teachers, &teacherCount);
							sortTeacherByName(teachers, teacherCount);
							break;
						default:
							system("cls");
							printf("\t\tYour choice is invalid\n");					
							break;
						}
					} while (choice != 0);
					break;
				case 3 :
					system("cls");
					printf("Update later!\n");
					waitAndClear();
					break;
				case 4 :
					system("cls");
					readFile("UserGuidline.txt");
					waitAndClear();
					break;
				case 5 :
					system("cls");
					readFile("AboutUs.txt");
					waitAndClear();
					break;
				default:
					system("cls");
					printf("\t\tYour choice is invalid\n");					
					break;
				}
			} while (choice != 0);
			break;
		case 2 :
			system("cls");
			printf("Update later!\n");
			waitAndClear();
			break;
		case 3 : 
			system("cls");
			printf("Update later!\n");
			waitAndClear();
			break;
		default:
			printf("\t\tYour choice is invalid\n");
			break;
		}	
	} while (choice != 0);
	
	return 0;
}
