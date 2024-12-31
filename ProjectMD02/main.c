#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Student students[50];
int studentCount = 0;
int main(int argc, char *argv[]) {
	loadStudentFromFile(students, &studentCount);
	int choice;
	do{
		mainMenu();
        printf("\t\t Enter your choice:");
		scanf("%d", &choice);
		fflush;
		switch (choice){
		case 0 :
			printf("Program exited!\n");
			break;
		case 1 :
				do{
				adminMenu();
				printf("\t\t Enter your choice:");
				scanf("%d", &choice);
				fflush;
				switch (choice){
				case 0 :
					printf("Program exited!\n");				
					break;
				case 1 :
					do{
						studentMenu();
						printf("\t\t Enter your choice:");
						scanf("%d", &choice);
						fflush;
						switch (choice){
						case 0 :
							printf("Program exited!\n");				
							break;
						case 1 : // Them moi 1 hoc sinh
							loadStudentFromFile(students, &studentCount);
							addStudent(students, &studentCount);
							break;
						case 2 : // Hien thi danh sach sinh vien 
							loadStudentFromFile(students, &studentCount);
							displayStudent(students, studentCount);
							break;
						case 3 : // Tim kiem sinh vien theo ten
							break;
						case 4 : // Sua sinh vien theo ID nguoi dung nhap
							loadStudentFromFile(students, &studentCount);
							editStudentByID(students, studentCount);
							break;
						case 5 : // Xoa 1 Sinh vien theo ID
							loadStudentFromFile(students, &studentCount);
							deleteStudent(students, &studentCount);
							break;
						case 6 :  // Sap xep sinh vien theo ten
							loadStudentFromFile(students, &studentCount);
							sortStudentByName(students, studentCount);
							break;
						default:
							printf("\t\tYour choice is invalid\n");					
							break;
						}
						
					} while (choice != 0);
					break;
				case 2 :
					break;
				case 3 :
					break;
				case 4 :
					break;
				case 5 :
					break;
				default:
					printf("\t\tYour choice is invalid\n");					
					break;
				}
			} while (choice != 0);
			break;
		case 2 :

			break;
		case 3 : 

			break;
		default:
			printf("\t\tYour choice is invalid\n");
			break;
		}	
	} while (choice != 0);
	
	return 0;
}
