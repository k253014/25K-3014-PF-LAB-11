#include<stdio.h>
#include<string.h>

struct student{
	char name[15];
	int roll_no;
	float marks[3];
	float percent;
	char grade[3];
};

void findbyGrade(int n, struct student s[]);
void displayStd(int n, struct student s[], float class_avg);
void SearchStd(int n, struct student s[]);
void displayRank(int n, struct student s[]);
int main(){
	int n, i, j, choice;
	float sum, class_sum=0, class_avg;
	char ch;
	
	printf(".....Student Record System.....\n\n");
	
	printf("Enter number of students:\n");
	scanf("%d", &n);
	struct student s[n];
	
	for(i=0; i<n; i++){
		printf("Enter name for student %d\n", i+1);
		scanf("%s", s[i].name);
		printf("Enter Roll number of student %d\n", i+1);
		scanf("%d", &s[i].roll_no);
		sum=0;
		for(j=0; j<3; j++){
			do{
				printf("Enter marks of subject %d for student %d\n", j+1, i+1);
				scanf("%f", &s[i].marks[j]);
				
				if(s[i].marks[j] < 0 || s[i].marks[j] > 100){
					printf("Invalid Marks, Enter again(0-100)!\n");
				}	
				
			}while(s[i].marks[j] < 0 || s[i].marks[j] > 100);
            		
			sum += s[i].marks[j];	
		}
		
		s[i].percent = (sum/300)*100;
		
		class_sum += s[i].percent;
		
		if(s[i].percent >=90 && s[i].percent <= 100){
			strcpy(s[i].grade, "A+");
		}
		else if(s[i].percent >= 80 && s[i].percent <=89){
			strcpy(s[i].grade, "A");
		}
		else if(s[i].percent >= 70 && s[i].percent <=79){
			strcpy(s[i].grade, "B+");
		}
		else if(s[i].percent >= 60 && s[i].percent <=69){
			strcpy(s[i].grade, "B");
		}
		else if(s[i].percent >= 50 && s[i].percent <=59){
			strcpy(s[i].grade, "C");
		}
		else{
			strcpy(s[i].grade, "F");
		}
	}
	
	class_avg = class_sum/n;
	
	do{
		printf("Choose an option:\n");
		printf("1.Find students by Grade.\n");
		printf("2.Class average and display students above and below average.\n");
		printf("3.Search students by roll number or name.\n");
		printf("4.Display student rank based on percentage.\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				findbyGrade(n, s);
				break;
			case 2:
            
				displayStd(n, s, class_avg);
				break;
			case 3:
				SearchStd(n, s);
				break;
			case 4:
				displayRank(n, s);
				break;
			default:
				printf("Invalid choice!\n");
		}
		
		printf("Do you want to continue?(Y/N)\n");
		scanf(" %c", &ch);
	}while(ch == 'Y' || ch == 'y');
	return 0;
}

void findbyGrade(int n, struct student s[]){
	int i;
	char ch[3];
	printf("Enter student's grade which you want to search for:\n");
	scanf("%s", ch);
	
	for(i=0; i<n; i++){
		if(strcmp(s[i].grade, ch) == 0){
			printf("Name: %s\n", s[i].name);
			printf("Roll number: %d\n", s[i].roll_no);
			printf("Grade: %s\n", s[i].grade);
			printf("Percentage: %.2f\n", s[i].percent);
		} 
	}	
}

void displayStd(int n, struct student s[], float class_avg){
	int i;
	printf("Class average: %.2f\n", class_avg);
	printf("Students above average:\n");
	for(i=0; i<n; i++){
		if(s[i].percent > class_avg){
			printf("Name: %s\n", s[i].name);
			printf("Percent: %.2f\n", s[i].percent);
		}
	}
	printf("Students below average:\n");
	for(i=0; i<n; i++){
		if(s[i].percent < class_avg){
			printf("Name: %s\n", s[i].name);
			printf("Percent: %.2f\n", s[i].percent);
		}
	}
}

void SearchStd(int n, struct student s[]){
	int i, ch, found, roll;
	char name[15];
	printf("1.Search by Roll number.\n");
	printf("2.Search by name.\n");
	scanf("%d", &ch);
	
	if(ch == 1){
		printf("Enter roll number:\n");
		scanf("%d", &roll);
		for(i=0; i<n; i++){
			if(roll == s[i].roll_no){
				printf("Name: %s\n", s[i].name);
				printf("Grade: %s\n", s[i].grade);
				printf("Percent: %.2f\n", s[i].percent);
				found = 1;
				break;
			}
		}
	}
	else if(ch == 2){
		printf("Enter name:\n");
		scanf("%s", name);
		for(i=0; i<n; i++){
			if(strcmp(name, s[i].name) == 0){
				printf("Roll number: %d\n", s[i].roll_no);
				printf("Grade: %s\n", s[i].grade);
				printf("Percent: %.2f\n", s[i].percent);
	
				found = 1;
				break;
			}
		}
	}
	if(!found){
		printf("Student not found!\n");
	}
}

void displayRank(int n, struct student s[]){
	int i, j;
	struct student temp;
	
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1; j++){
			if(s[j].percent < s[j+1].percent){
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
	
	printf("Student Ranking by percentage:\n");
	for(i=0; i<n; i++){
		printf("Name: %s\n", s[i].name);
		printf("Roll number: %d\n", s[i].roll_no);
		printf("Percentage: %.2f\n", s[i].percent);
		printf("Grade: %s\n", s[i].grade);
	}
}
