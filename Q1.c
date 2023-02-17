#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
   char name[50];
   int roll_number;
   int branch_id;
   float cgpa;
   struct student *link;
} *head, *lowgrade;
struct university
{
   int university_id;
   char university_name[50];
   char university_location[100];
   int year_of_start;
   struct university *link;
}*university_head;
struct branch
{
  int university_id;
  int branch_id;
  char branch_name[30];
  struct branch *link;
}*branch_head;
int Isunique(){
  struct student* p;
  p=head;
  int roll_number;
  scanf("%d",&roll_number);
  while (p!=NULL)
  {
    if(p->roll_number!=roll_number){
      p = p->link;
    }
    else
      {
      printf("already exist enter again :\n");
      Isunique();
      break;
      }
  }
  return roll_number;
}

void create(){
  struct student *q,*temp;
  struct university *w,*temp2;
  struct branch *e,*temp3;
  temp =  (struct student *)malloc(sizeof (struct student));
  temp2 = (struct university *)malloc(sizeof(struct university));
  temp3 = (struct branch *)malloc(sizeof(struct branch));
  printf("enter name : \n");
  fgets(temp->name, sizeof(temp->name), stdin);
  fgets(temp->name, sizeof(temp->name), stdin);
  printf("enter roll number: \n");
  temp->roll_number = Isunique();
  printf("enter branch id: \n");
  scanf("%d",&temp->branch_id);
  printf("enter cgpa : \n");
  scanf("%f",&temp->cgpa);
  printf("enter University ID : \n");
  scanf("%d", &temp2->university_id);
  printf("enter university name : \n");
  fgets(temp2->university_name, sizeof(temp2->university_name), stdin);
  fgets(temp2->university_name, sizeof(temp2->university_name), stdin);
  printf("enter university location : \n");
  fgets(temp2->university_location, sizeof(temp2->university_location), stdin);
  printf("enter year of start: \n");
  scanf("%d", &temp2->year_of_start);
  temp3->branch_id=temp->branch_id;
  temp3->university_id=temp2->university_id;
  printf("enter branch name : \n");
  fgets(temp3->branch_name, sizeof(temp3->branch_name), stdin);
  fgets(temp3->branch_name, sizeof(temp3->branch_name), stdin);
  temp->link=NULL;
  temp2->link = NULL;
  temp3->link = NULL;

  if(head==NULL){
    head=temp;
  }
  else
  {
    q=head;
    while (q->link!=NULL)
    {
      q=q->link;
    }
    q->link=temp; 
  }
  if (university_head == NULL)
  {
    university_head = temp2;
  }
  else
  {
    w = university_head;
    while (w->link != NULL)
    {
      w = w->link;
    }
    w->link = temp2;
  }
  if (branch_head == NULL)
  {
    branch_head= temp3;
  }
  else
  {
    e = branch_head;
    while (e->link != NULL)
    {
      e = e->link;
    }
    e->link = temp3;
  }
}
struct branch * find_Branch(struct student*q){
  struct branch *e;
  e=branch_head;
  while (e !=NULL)
  {
    if (q->branch_id==e->branch_id)
    {
      return e;
    }
    e=e->link;
  }
  
}

struct university * find_University(struct branch *e)
{
  struct university *w;
  w = university_head;
  while (w !=NULL)
  {
    if (w->university_id==e->university_id)
    {
      return w;
    }
    w = w->link;
  }
}
void display_student(){
  struct student *q;
  if (head == NULL)
  {
    printf("database is empty");
    return;
  }
  q = head;

  while (q != NULL)
  {
    printf("\n------------------\n");
    printf("\nname : ");
    puts(strupr(q->name));
    printf("Roll Number : %d\n", q->roll_number);
  }
  printf("------------------\n");
}
void display_university(){
  struct university *q;
  if (university_head == NULL)
  {
    printf("database is empty");
    return;
  }
  q = university_head;

  while (q != NULL)
  {
    printf("\n------------------\n");
    printf("\nUniversity Name: ");
    puts(strupr(q->university_name));
  }
  printf("------------------\n");
}
void display_branch()
{
  struct branch *q;
  if (branch_head == NULL)
  {
    printf("database is empty");
    return;
  }
  q = branch_head;

  while (q != NULL)
  {
    printf("\n------------------\n");
    printf("\nBranch Name: ");
    puts(strupr(q->branch_name));
  }
  printf("------------------\n");
}
void removeStudent(){
  struct student *temp,*t,*y;
  t=lowgrade;
  while (t!=NULL)
  {
    t=t->link;
  }
  if (head->cgpa>6.00)
  {
    temp=head;
    head=head->link;
    t=temp;
    return;
  }

  y=head;
  while (y->link!=NULL)
  {
    if (y->link->cgpa > 6.00)
    {
      temp = y->link;
      y->link = y->link->link;
      t = temp;
      return;
    }
    y=y->link;
  }
  
}
void display(){
  struct student *q;
  struct university *w;
  struct branch *e;
  if (head==NULL)
  {
    printf("database is empty");
    return;
  }
  q=head;

  while(q!=NULL)
  {
    printf("\n------------------\n");
    printf("\nname : ");
    puts(strupr(q->name));
    printf("Roll Number : %d\n", q->roll_number);
    printf("branch ID : %d\n",q->branch_id);
    printf("cgpa : \n");
    printf("%f\n",q->cgpa);
    e=find_Branch(q);
    w=find_University(e);
    printf("University Id: %d\n",w->university_id);
    puts(strupr(w->university_name));
    puts(w->university_location);
    printf("YEAR OF START : %d\n",w->year_of_start);
    puts(strupr(e->branch_name));
    q=q->link;
  }
  printf("------------------\n");
  
}
void modify(int roll_number){
   struct student *q,*w;
   struct student *temp;
   struct university *temp2;
   struct branch *temp3;
   if (head->roll_number==roll_number)
   {
    {
      printf("enter new name : \n");
      fgets(temp->name, sizeof(temp->name), stdin);
      fgets(temp->name, sizeof(temp->name), stdin);
      printf("enter new roll number: \n");
      temp->roll_number = Isunique();
      printf("enter new branch id: \n");
      scanf("%d", &temp->branch_id);
      printf("enter new cgpa : \n");
      scanf("%f", &temp->cgpa);
      q=head->link;
      free(head);
      head=temp;
      head->link=q;

    }
   }
   q=head;
   while (q!=NULL)
   {
    if (q->roll_number==roll_number)
    {
      
      printf("enter new name : \n");
      fgets(temp->name, sizeof(temp->name), stdin);
      fgets(temp->name, sizeof(temp->name), stdin);
      printf("enter new roll number: \n");
      temp->roll_number = Isunique();
      printf("enter new branch id: \n");
      scanf("%d", &temp->branch_id);
      printf("enter new cgpa : \n");
      scanf("%f", &temp->cgpa);
      w=q->link;
      q=temp;
      q->link=w;
    }
   }
   q=q->link;
   
}

int main()
{
  while (1)
  {
    printf("press 1.  to add a new student in a data base\n");

    printf("press 2. to display all details of students \n");

    printf("press 3. to display all students in database\n");

    printf("press 4. to display all students in database\n");

    printf("press 5. to display all students in database\n");

    printf("press 6. modify students in database\n");

    int a;
    scanf("%d",&a);

    switch (a)
    {
    case 1:
    {
       create();
       break;
    }
    case 2:
    {
      display();
      break;
    }
    case 3:
    {
      display_student();
      break;
    }
    case 4:
    {
      display_university();
      break;
    }
    case 5:
    {
      display_branch();
      break;
    }
    case 6:
    {
      printf("enter roll number");
      int n;
      scanf("%d",&n);
      modify(n);
      break;
    }

    default:
      break;
    }

  }
  


  return 0;
}

