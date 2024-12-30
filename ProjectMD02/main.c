#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcions.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Student students[50];
int studentCount = 0;
int main(int argc, char *argv[]) {
	loadStudentsFromFile(students, &studentCount);
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
				studentMenu();
				printf("\t\t Enter your choice:");
				scanf("%d", &choice);
				fflush;
				switch (choice){
				case 0 :
					printf("Program exited!\n");				
					break;
				case 1 :
					addStudent(students, &studentCount);
					break;
				case 2 :
					displayStudents(students, studentCount);
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
