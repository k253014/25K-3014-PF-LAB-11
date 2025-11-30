#include<stdio.h>
#include<string.h>
struct Student{
    char name[50];
    char rollNumber[10];
    int marks[3];
    float percentage;
    char grade[3];
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student students[n];

    for(int i=0;i<n;i++) {
        int totalMarks = 0;
        printf("Enter name for student %d: ", i+1);
        getchar();
        fgets(students[i].name, 50,stdin);
        students[i].name[strlen(students[i].name) - 1] = '\0';
        printf("Enter roll number for student %d: ", i+1);
        fgets(students[i].rollNumber, 10,stdin);
        students[i].rollNumber[strlen(students[i].rollNumber) - 1] = '\0';
        for(int j=0;j<3;j++) {
            int mark;
            while(1) {
                
                printf("Enter marks for subject %d: ", j+1);
                scanf("%d", &mark);

                if(mark >= 0 && mark <= 100) {
                    students[i].marks[j] = mark;
                    totalMarks+= mark;
                    break;
                }
                printf("Invalid input marks, try again!\n");
            }
        }
        float percentage = (totalMarks/300) * 100;
        students[i].percentage = percentage;
        if(percentage >=90 && percentage <=100) {
           strcpy(students[i].grade, "A+");
        }
        else if(percentage >= 80 && percentage < 90) {
            strcpy(students[i].grade, "A");
        }
        else if(percentage >= 70 && percentage < 80) {
            strcpy(students[i].grade, "B+");
        }
        else if(percentage >= 60 && percentage < 70) {
            strcpy(students[i].grade, "B");
        }
        else if(percentage >= 50 && percentage < 60) {
            strcpy(students[i].grade, "C");
        }
        else if(percentage < 50) {
            strcpy(students[i].grade, "F");
        }


    }

}