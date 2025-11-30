#include<stdio.h>
#include<string.h>

struct Date{
    int day;
    int month;
    int year;
};

struct Employee{
    int id;
    char name[30];
    char department[20];
    char designation[20];
    float salary;
    int yearsExperience;
    char phone[20];
    char email[40];
    struct Date joinDate;
};

void addEmployee(struct Employee emp[], int *count);
void display(struct Employee emp[], int count);
void calculateExperience(struct Employee emp[], int count);
void salaryStats(struct Employee emp[], int count);
void appraisal(struct Employee emp[], int count);
void search(struct Employee emp[], int count);
void promotion(struct Employee emp[], int count);

int main(){
	struct Employee emp[100];
    int count = 0, ch;

    do {
        printf("\n--- Employee Record System ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Calculate Experience\n");
        printf("4. Salary Statistics\n");
        printf("5. Annual Appraisal\n");
        printf("6. Search Employees\n");
        printf("7. Promotion Eligibility\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
				addEmployee(emp, &count);
				break;
            case 2: 
				display(emp, count); 
				break;
            case 3: 
				calculateExperience(emp, count); 
				break;
            case 4: 
				salaryStats(emp, count); 
				break;
            case 5: 
				appraisal(emp, count); 
				break;
            case 6: 
				search(emp, count); 
				break;
            case 7: 
				promotion(emp, count); 
				break;
            case 8: 
				printf("Exiting...\n"); 
				break;
            default: 
				printf("Invalid choice!\n");
        }
    } while(ch != 8);

    return 0;
}

void addEmployee(struct Employee emp[], int *count) {
    int i = *count;

    printf("Enter Employee ID: ");
    scanf("%d", &emp[i].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", emp[i].name);

    printf("Enter Department (IT/HR/Finance/Marketing/Operations): ");
    scanf("%s", emp[i].department);

    printf("Enter Designation (Intern/Junior/Senior/Manager/Director): ");
    scanf("%s", emp[i].designation);

    printf("Enter Salary: ");
    scanf("%f", &emp[i].salary);

    printf("Enter Date of Joining (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &emp[i].joinDate.day, &emp[i].joinDate.month, &emp[i].joinDate.year);


    printf("Enter Phone: ");
    scanf("%s", emp[i].phone);

    printf("Enter Email: ");
    scanf("%s", emp[i].email);

    emp[i].yearsExperience = 0;

    (*count)++;
    printf("Employee added successfully!\n");
}

void display(struct Employee emp[], int count) {
    int i;
    printf("\n--- All Employee Records ---\n");
    for(i = 0; i < count; i++) {
        printf("\nID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Dept: %s\n", emp[i].department);
        printf("Designation: %s\n", emp[i].designation);
        printf("Salary: %.2f\n", emp[i].salary);
        printf("Joining Date: %02d-%02d-%04d\n",emp[i].joinDate.day, emp[i].joinDate.month, emp[i].joinDate.year);
        printf("Experience: %d years\n", emp[i].yearsExperience);
        printf("Phone: %s\n", emp[i].phone);
        printf("Email: %s\n", emp[i].email);
    }
}
void calculateExperience(struct Employee emp[], int count) {
    int i, curYear = 2025, day, month, year;
    
    for(i = 0; i < count; i++) {
        emp[i].yearsExperience = curYear - emp[i].joinDate.year;
    }

    printf("\nExperience Updated Successfully!\n");
}

void salaryStats(struct Employee emp[], int count) {
    char dept[20];
    float sum = 0;
    int i, c = 0;

    printf("Enter department: ");
    scanf("%s", dept);

    for(i = 0; i < count; i++) {
        if(strcmp(emp[i].department, dept) == 0) {
            sum += emp[i].salary;
            c++;
        }
    }

    if(c == 0)
        printf("No employees in this department.\n");
    else
        printf("Average Salary in %s = %.2f\n", dept, sum/c);
}

void appraisal(struct Employee emp[], int count) {
    int i, id;
    float percent;

    printf("Enter Employee ID for appraisal: ");
    scanf("%d", &id);

    printf("Enter increment percentage (5-15): ");
    scanf("%f", &percent);

    for(i = 0; i < count; i++) {
        if(emp[i].id == id) {

            emp[i].salary += emp[i].salary * (percent / 100);
            printf("Salary updated!\n");
            return;
        }
    }

    printf("Employee not found.\n");
}

void search(struct Employee emp[], int count) {
    int i, ch;
    char word[20];

    printf("Search by:\n1. Department\n2. Designation\n3. Experience\n");
    scanf("%d", &ch);

    if(ch == 1) {
        printf("Enter Department: ");
        scanf("%s", word);

        for(i = 0; i < count; i++)
            if(strcmp(emp[i].department, word) == 0)
                printf("Found: %s\n", emp[i].name);
    }

    else if(ch == 2) {
        printf("Enter Designation: ");
        scanf("%s", word);

        for(i = 0; i < count; i++)
            if(strcmp(emp[i].designation, word) == 0)
                printf("Found: %s\n", emp[i].name);
    }

    else if(ch == 3) {
        int exp;
        printf("Enter minimum years of experience: ");
        scanf("%d", &exp);

        for(i = 0; i < count; i++)
            if(emp[i].yearsExperience >= exp)
                printf("Found: %s\n", emp[i].name);
    }
}

void promotion(struct Employee emp[], int count) {
	int i;
    printf("\nEmployees Eligible for Promotion (>3 years in same role):\n");

    for(i = 0; i < count; i++) {
        if(emp[i].yearsExperience > 3)
            printf("%s (%s) - Eligible\n", emp[i].name, emp[i].designation);
    }
}


