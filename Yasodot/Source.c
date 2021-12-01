#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Structure of the employee
struct Job {
	char companyname[50];
	int phone;
	char jobname[50];
	char areajob[50];
	char requirement[50];
	char jobscope[50];
	char expereq[];

};
struct Job e;

// size of the structure
long int size = sizeof(e);

// In the start coordinates
// will be 0, 0
COORD cord = { 0, 0 };

// function to set the
// coordinates
void gotoxy(int x, int y)
{
	cord.X = x;
	cord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		cord);
}

FILE* fp, * ft;

// Function to add the records
void addrecord()
{
	system("cls");
	fseek(fp, 0, SEEK_END);
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter company name : ");
		scanf("%s", e.companyname);

		printf("\nEnter phone number : ");
		scanf("%d", &e.phone);

		printf("\nEnter job name : ");
		scanf("%s", &e.jobname);

		printf("\nEnter area job : ");
		scanf("%s", &e.areajob);

		printf("\nEnter requirement : ");
		scanf("%s", &e.requirement);

		printf("\nEnter job scope : ");
		scanf("%s", &e.jobscope);

		printf("\nEnter experience required : ");
		scanf("%s", &e.expereq);

		fwrite(&e, size, 1, fp);

		printf("\nWant to add another"
			" record (Y/N) : ");
		fflush(stdin);

		scanf("%c", &another);
	}
}

// Function to delete the records
void deleterecord()
{
	system("cls");
	char comname[50];
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter company "
			"name to delete : ");
		scanf("%s", comname);

		ft = fopen("temp.txt", "wb");
		rewind(fp);

		while (fread(&e, size,
			1, fp)
			== 1) {
			if (strcmp(e.companyname,
				comname)
				!= 0)
				fwrite(&e, size, 1, ft);
		}

		fclose(fp);
		fclose(ft);
		remove("data.txt");
		rename("temp.txt", "data.txt");
		fp = fopen("data.txt", "rb+");

		printf("\nWant to delete another"
			" record (Y/N) :");
		fflush(stdin);
		another = getche();
	}
}

// Function to display the record
void displayrecord()
{
	system("cls");

	// sets pointer to start
	// of the file
	rewind(fp);

	printf("\n========================="
		"==========================="
		"======");
	printf("\nNAME\tPHONE\tJOB\tAREA\t\REQUIREMENT\tSCOPE\tEXPERIENSE REQUIRED\n",
		e.companyname, e.phone, e.jobname, e.areajob, e.requirement, e.jobscope, e.expereq);

	printf("==========================="
		"==========================="
		"====\n");

	while (fread(&e, size, 1, fp) == 1)
		printf("\n%s\t%d\t%s\t%s\t%s\t\t%s\t%s", e.companyname, e.phone, e.jobname, e.areajob, e.requirement, e.jobscope, e.expereq);

	printf("\n\n\n\t");
	system("pause");
}

// Function to modify the record
void modifyrecord()
{
	system("cls");
	char comname[50];
	char another = 'y';

	while (another == 'y') {
		printf("\nEnter employee name"
			" to modify : ");
		scanf("%s", comname);

		rewind(fp);

		// While File is open
		while (fread(&e, size, 1, fp) == 1) {
			// Compare the employee name
			// with ename
			if (strcmp(e.companyname, comname) == 0) {
				printf("\nEnter new company name:");
				scanf("%s", e.companyname);
				printf("\nEnter new phone:");
				scanf("%d", &e.phone);
				printf("\nEnter new job name :");
				scanf("%s", &e.jobname);
				printf("\nEnter new area job:");
				scanf("%s", &e.areajob);
				printf("\nEnter new requirement:");
				scanf("%s", &e.requirement);
				printf("\nEnter new job scope:");
				scanf("%s", &e.jobscope);
				printf("\nEnter new experience required :");
				scanf("%s", &e.expereq);

				fseek(fp, -size, SEEK_CUR);
				fwrite(&e, size, 1, fp);
				break;
			}
		}

		// Ask for modifying another record
		printf("\nWant to modify another"
			" record (Y/N) :");
		fflush(stdin);
		scanf("%c", &another);
	}
}

// Driver code
int main()
{
	int choice;

	// opening the file
	fp = fopen("data.txt", "rb+");

	// showing error if file is
	// unable to open.
	if (fp == NULL) {
		fp = fopen("data.txt", "wb+");
		if (fp == NULL) {
			printf("\nCannot open file...");
			exit(1);
		}
	}

	system("Color 3F");
	printf("\n\n\n\n\t\t\t\t============="
		"============================="
		"===========");
	printf("\n\t\t\t\t~~~~~~~"
		"~~~~~~~~~~~"
		"~~~");
	printf("\n\t\t\t\t==================="
		"============================="
		"=====");
	printf("\n\t\t\t\t[|:::>:::>:::>::> "
		"JOB RECORD <::<:::<:::"
		"<:::|]\t");
	printf("\n\t\t\t\t==================="
		"============================="
		"=====");
	printf("\n\t\t\t\t~~~~~~~~"
		"~~~~~~~~~~"
		"~");
	printf("\n\t\t\t\t====================="
		"==============================\n");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t"
		"Developer : @Sushant_Gaurav"
		"\n\n\t\t\t\t");

	system("pause");

	while (1) {
		// Clearing console and asking the
		// user for input
		system("cls");
		gotoxy(30, 10);
		printf("\n1. ADD JOB\n");
		gotoxy(30, 12);
		printf("\n2. DELETE JOB\n");
		gotoxy(30, 14);
		printf("\n3. DISPLAY JOB\n");
		gotoxy(30, 16);
		printf("\n4. MODIFY JOB\n");
		gotoxy(30, 18);
		printf("\n5. EXIT\n");
		gotoxy(30, 20);
		printf("\nENTER YOUR CHOICE...\n");
		fflush(stdin);
		scanf("%d", &choice);

		// Switch Case
		switch (choice) {
		case 1:

			// Add the records
			addrecord();
			break;

		case 2:

			// Delete the records
			deleterecord();
			break;

		case 3:

			// Display the records
			displayrecord();
			break;

		case 4:

			// Modify the records
			modifyrecord();
			break;

		case 5:
			fclose(fp);
			exit(0);
			break;

		default:
			printf("\nINVALID CHOICE...\n");
		}
	}

	return 0;
}