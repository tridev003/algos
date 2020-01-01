#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>



struct student{
char id[18];
char name[15];
int  age[2];
char parname[15];
char Class[5];

};
struct student s1;

void clearWindow();
void drawRectangle();
void login();
void chng_passwd();
void add_std();
void search();
void edit();
void display();
void delete_rec();
void stop();
void start();
void main_window();


void clearWindow(){
int i,j;
for(i=37;i<78;i++){
for(j=7;j<24;j++){
gotoxy(i,j);
printf(" ");
}
}
return;
}

/*
int sort_function(const void *first,const void *scnd){
int *a=(int*)first;
int *b=(int*)scnd;
if(*a > *b)
return +1;
else if(*b > *a)
return -1;
else
return 0;
} */


void drawRectangle(){
int i,j;
textbackground(8);
textcolor(15);


 gotoxy(0,0);
cprintf("%c",201);
 for(i=0;i<78;i++)
 {gotoxy(i,0);
 cprintf("%c",205);
 }

 gotoxy(78,0);
 cprintf("%c",187);
 for(i=2;i<25;i++)
 {gotoxy(80,i);
 if(i==6){cprintf("%c",185);}
 else{cprintf("%c",186);  }
}

 gotoxy(80,24);
 cprintf("%c",188);
 for(i=79;i>0;i--)
 {gotoxy(i,24);
 if(i==35){cprintf("%c",202);}
 else{cprintf("%c",205);}
 }

gotoxy(1,24);
cprintf("%c",200);
for(i=23;i>1;i--){
gotoxy(1,i);
if(i==6){cprintf("%c",204);}
else{cprintf("%c",186);}
}

for(i=1;i<80;i++){
gotoxy(i,6);
if(i==35){cprintf("%c",203);}
else{cprintf("%c",205);}
}

for(i=7;i<24;i++){
gotoxy(35,i);
cprintf("%c",186);
}
gotoxy(1,6);
cprintf("%c",185);
}


void login(){
char usr_name[10],passwd[10],temp[10];
int i=0;
FILE *pwd;
clrscr();
//textbackground(8);
textcolor(12);
gotoxy(27,10);
cprintf("USERNAME :");
fflush(stdin);
textcolor(4);
scanf("%s",usr_name);
textcolor(12);
gotoxy(27,11);
cprintf("PASSWORD :");
fflush(stdin);
textcolor(4);
while(i<6){
passwd[i]=getch();
cprintf("*");
i++;}
passwd[i]='\0';
/*pwd = fopen("password.txt","w");
if(pwd==NULL){exit(0);}
else{fprintf(pwd,"%s",passwd);
fclose(pwd);  } */
pwd=fopen("password.txt","r");
/* while((temp=fgetc(pwd))!=EOF){
printf("\n%c",temp);
} */
if(pwd==NULL){exit(0);}
else{fscanf(pwd,"%s",temp);
fclose(pwd);}
if((strcmp(usr_name,"tridev")==0) && (strcmp(passwd,temp)==0)){

clrscr();
//cprintf("\nLogin Successfull");
    }
else{ textcolor(12);
gotoxy(27,18);
cprintf("LOGIN UNSUCCESSFULL");
sleep(2);
exit(0);}
}

void chng_passwd(){

char new_passwd[10],old_passwd[10],temp1[10];
FILE *pwd;
int x=37,i=0;
clearWindow();
textbackground(8);
textcolor(4);

gotoxy(x,10);cprintf("The Database is Password Protected");
textcolor(15);
gotoxy(x,12);cprintf("Enter Old Password : ");
while(i<6){
old_passwd[i]=getch();
cprintf("*");
i++;}
old_passwd[i]='\0';
i=0;
textcolor(4);
gotoxy(x,14);cprintf("NOTE : Password Must Be 6 Digit");
textcolor(15);
gotoxy(x,16);cprintf("Enter New Password : ");
while(i<6){
new_passwd[i]=getch();
cprintf("*");
i++;}
new_passwd[i]='\0';

pwd=fopen("password.txt","r");
if(pwd==NULL){exit(0);}
else{fscanf(pwd,"%s",temp1);
fclose(pwd);}

textcolor(4);
if(strcmp(old_passwd,temp1)==0)
{pwd = fopen("password.txt","w");
if(pwd==NULL){exit(0);}
else{fprintf(pwd,"%s",new_passwd);
fclose(pwd);
gotoxy(x,18);cprintf("Password Is Changed..!");  }

}
else{gotoxy(x,18);cprintf("Old Password Is Incorrect..!");
gotoxy(x,19);cprintf("Press 7 To Try Again..!");
}


}



void add_std(){

  FILE *ptr;
  int x=37;
   clearWindow();
  ptr = fopen("student2.txt","ab+");
  if(ptr==NULL){textcolor(4);gotoxy(x,9);cprintf("File Not Found");}
  else{
   fflush(stdin);
   textcolor(9);
 gotoxy(x,10); cprintf("Id :     ");fflush(stdin);textcolor(9);  scanf("%s",s1.id);    //what problem does gets has with spaces
textcolor(9); gotoxy(x,11); cprintf("Name :     ");fflush(stdin);textcolor(9);  scanf("%s",s1.name);
textcolor(9); gotoxy(x,12); cprintf("Age :     ");fflush(stdin);textcolor(9); scanf("%s",s1.age);
textcolor(9); gotoxy(x,13); cprintf("Par_Name :     ");fflush(stdin);textcolor(9); scanf("%s",s1.parname);
textcolor(9); gotoxy(x,14); cprintf("Class :     ");fflush(stdin);textcolor(9);  scanf("%s",s1.Class);
  fwrite(&s1,sizeof(s1),1,ptr);
//  fprintf(ptr,"\n");
textcolor(4);
 gotoxy(40,18); cprintf("The Record Is Successfully Added");
  fclose(ptr);
 }
 }

void search(){

char id1[18], item_found=0;
int x=37;
//char str[60];
FILE *ptr;
  clearWindow();
  textcolor(4);
 gotoxy(x,10); cprintf("Enter The Id You Want To Search :");  fflush(stdin);
 scanf("%s",&id1);
ptr = fopen("student2.txt","rb");
while(fread(&s1,sizeof(s1),1,ptr)==1){
 if(strcmp(id1,s1.id)==0)
 {
  item_found=1;
// fgets(&str,MAX,ptr);
// printf("item found\n");
 break;
  }

}
if(item_found==1){
textcolor(14);
// gotoxy(x,11);printf(" id found\n");
 gotoxy(x,12);cprintf("Id : %s ",s1.id);
 gotoxy(x,13);cprintf("Name : %s ",s1.name);
 gotoxy(x,14);cprintf("Age : %s ",s1.age);
 gotoxy(x,15);cprintf("Par_Name : %s ",s1.parname);
 gotoxy(x,16);cprintf("Class : %s ",s1.Class);
//printf("im here\n");
//puts(str);
}
else{    textcolor(4);
 gotoxy(x,13);cprintf("Id Not Found");}

fclose(ptr);
 }

void edit(){

char id1[18];
 int item_found=0,x=37;
 FILE *ptr;
 clearWindow();
 textcolor(4);
 gotoxy(x,10); cprintf("Enter The Id You Want To Edit :");
 fflush(stdin);      //clears buffer memory
 scanf("%s",&id1);

 ptr = fopen("student2.txt","rb+");
 while(fread(&s1,sizeof(s1),1,ptr)==1){
 if(strcmp(id1,s1.id)==0){

 fseek(ptr,-57,SEEK_CUR);
 textcolor(9);              //-sizeof(s1) not working
 textcolor(9);  gotoxy(x,12);  cprintf("Id :");fflush(stdin);  scanf("%s",s1.id);    //what problem does gets has with spaces
 textcolor(9);  gotoxy(x,13); cprintf("Name :");fflush(stdin); scanf("%s",s1.name);
 textcolor(9);  gotoxy(x,14); cprintf("Age :");fflush(stdin);scanf("%s",s1.age);
 textcolor(9);  gotoxy(x,15); cprintf("Par_Name:");fflush(stdin);scanf("%s",s1.parname);
 textcolor(9);  gotoxy(x,16); cprintf("Class :");fflush(stdin); scanf("%s",s1.Class);


//  fseek(ptr,-sizeof(s1),SEEK_CUR);
  fwrite(&s1,sizeof(s1),1,ptr);
  item_found=1;

  break;
   }
   }
   textcolor(4);
   if(item_found==0){ gotoxy(x,12);cprintf("No Record Found");}
   else{ gotoxy(40,18);cprintf("Successfully Modified");}
 fclose(ptr);
}


void delete_rec(){

 char id1[18];
 int item_found=0,x=37;

 FILE *ptr, *ptr1;
 clearWindow();
 textcolor(4);
 gotoxy(x,10); cprintf("Enter The Id You Want To Delete :");fflush(stdin);

 scanf("%s",id1);
 ptr=fopen("student2.txt","rb");
 ptr1=fopen("temp.txt","wb");
 while(fread(&s1,sizeof(s1),1,ptr)==1){
 if(strcmp(id1,s1.id)==0){
 fseek(&s1,sizeof(s1),SEEK_CUR)
 ;
 item_found=1;
 continue;


  }
fwrite(&s1,sizeof(s1),1,ptr1);
 }
 textcolor(4);
 if(item_found==0){
  gotoxy(x,12);cprintf("No Record Found"); }
 fclose(ptr);
 fclose(ptr1);
 if(item_found==1){
 remove("student2.txt");
 rename("temp.txt","student2.txt");
 gotoxy(x,15); cprintf("The Record Is Successfully Deleted");
    }

}      /*

void sort(){
FILE *ptr;
int n=3, count=0;
clrscr();
struct s1 arr[n];
ptr=fopen("student.txt","rb");
//fread(&s1,sizeof(s1),1,ptr);
while(1)){
fread
arr[0].id=s1.id
arr[1].id=s1.id
//qsort((void *)s1.id,3,sizeof(s1),sort_function);
//printf("%s\t",s1.id);

}
fclose(ptr);
}
     */
void display(){
int x=37,y=11;
FILE *ptr;
char temp;
clearWindow();
fflush(stdin);

gotoxy(x,10);cprintf("ID     NAME     AGE     PARNAME     CLASS");
ptr= fopen("student2.txt","rb");

while(fread(&s1,sizeof(s1),1,ptr)){
// textcolor(2);
fflush(stdin);
 gotoxy(x,y);cprintf("%s    %s      %s      %s        %s",s1.id,s1.name,s1.age,s1.parname,s1.Class);
 y++;

}

fclose(ptr);
}
void stop(){
clearWindow();
textcolor(6);
gotoxy(50,14);
cprintf("VISIT AGAIN...!");
sleep(2);
exit(0);

}

void start(){
//textbackground(8);
textcolor(11);
gotoxy(28,2);
cprintf("STUDENT DATABASE SYSTEM");
gotoxy(24,3);
cprintf("Poornima University, Jaipur, Raj" );
gotoxy(25,4);
cprintf("Btech. CS(Data Science) IIISEM");

}

void main_window(){
int option ,x=4;
start();
//setcolor(78);
//textbackground(8);
while(1){
textcolor(11);
gotoxy(x,8);cprintf("1. Add Student");
gotoxy(x,9);cprintf("2. Edit Student  ");
gotoxy(x,10);cprintf("3. Search Student ");
gotoxy(x,11);cprintf("4. Display All Students ");
gotoxy(x,12);cprintf("5. Delete Record ");
gotoxy(x,13);cprintf("6. Clear Screen ");
gotoxy(x,14);cprintf("7. Change Password ");
//gotoxy(x,16);printf("8. Go to Login Page \n");
gotoxy(x,15);cprintf("8. Exit Database ");
//gotoxy(2,8);printf("8. Sort record \n");
//gotoxy(2,8);printf("9. Clear Screen \n");
gotoxy(x,17);cprintf("Choose The Option :  ");
scanf("%d",&option);

switch(option){                      //what does break and continue means while using switch statement in loop
case 1:add_std();
//continue;
break;
case 2:edit();
//continue;

break;
case 3:search();
break;
case 4:display();
break;
case 5:delete_rec();
break;
case 6:clearWindow();
break;
case 7:chng_passwd();
break;
case 8:stop();
break;
default:textcolor(4);gotoxy(4,18); cprintf("Oops Wrong Option..!");
break;
}
}
}




int main()
{clrscr();
//int gdriver=DETECT ,gmode;
//initgraph(&gdriver,&gmode,"C:\TURBOC3\BGI");
//setbkcolor(3);
textbackground(8);
//textcolor(3);

login();
//textcolor(3);
drawRectangle();
main_window();

return 0;
}
