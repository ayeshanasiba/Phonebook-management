#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<stdlib.h>

int std_n=23;
      struct contact Add_A_New_Contact();

        struct contact All_contact();

          struct contact search_contact();

          struct contact edit_contact();

          struct contact delete_contact();



 struct contact

{

    char ph[20];

    char name[40];
    char email[30];

};



    struct contact Add_A_New_Contact()
{

FILE *fp=fopen("Vcontact.vcf","w");
  struct contact list1; char a;

      if(fp==NULL)
            {

              printf("\nFile opening error!!");
             _Exit(0);
            }

else{

            printf("Add a New Contact:\n\n");

            printf("Name:");

            scanf("%c",&a);
            gets(list1.name);

            fflush(stdin);

            printf("Phone:");

            scanf("%s",&list1.ph);

            fflush(stdin);

            printf("Email address:");

            gets(list1.email);

            printf("\n");

           fprintf(fp,"BEGIN:VCARD\nVERSION:2.1\nFN:%s\nTEL; CELL:%s\nEMAIL;HOME:%s\nEND:VCARD\n",list1.name,list1.ph,list1.email);

}
printf("\nContact Saved Successfully!\n");

        fclose(fp);
        getch();
         system("cls");
  main();

};


 struct contact All_contact()
 {
     struct contact list1[40];
     int i,l,L; char b;


      printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t\tE-mail ad.\n=================================================================\n\n");

     FILE *fp=fopen("student contact.txt","r");
     if(fp==NULL)
{
printf("\nfile opening error in listing :");

_Exit(0);
}
else{
         for(i=0;i<std_n;i++)
            {
             fflush(stdin);
            fgets(list1[i].name,40,fp);
            l=strlen(list1[i].name);
            list1[i].name[l-1]='\0';
            fflush(stdin);
            fscanf(fp,"%s",&list1[i].ph);
            fscanf(fp,"%c",&b);
            fflush(stdin);
            fgets(list1[i].email,30,fp);
             L=strlen(list1[i].email);
            list1[i].email[L-1]='\0';

            }
            for(i=0;i<std_n;i++)
                {
                    printf("\n..::Name\t: %s\n..::Phone\t: %s\n..::Email\t: %s\n",list1[i].name,list1[i].ph,list1[i].email);
                }

         }


fclose(fp);

 getch();
    system("cls");


        main();
 };

 struct contact search_contact()
 {
      system("cls");
      struct contact list1[40];
    FILE *fp=fopen("student contact.txt","r");
    char name[40];
    char b;
    int i,l,L,found=0;

        if(fp==NULL)
            {

              printf("\nFile opening error!!");
             _Exit(0);
            }

else{
      printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");
       fflush(stdin);
      scanf("%[^\n]",&name);

         system("cls");
       printf("\n\tDetail Information About %s\n\n",name);

          for(i=0;i<std_n;i++)
            {
            fflush(stdin);
            fgets(list1[i].name,40,fp);
            l=strlen(list1[i].name);
            list1[i].name[l-1]='\0';
            fflush(stdin);
            fscanf(fp,"%s",&list1[i].ph);
            fscanf(fp,"%c",&b);
            fflush(stdin);
            fgets(list1[i].email,30,fp);
             L=strlen(list1[i].email);
            list1[i].email[L-1]='\0';
            }

          for(i=0;i<std_n;i++){

                if(stricmp(list1[i].name,name)==0)
                {
                    printf("\n..::Name\t: %s\n..::Phone\t: %s\n..::Email\t: %s\n",list1[i].name,list1[i].ph,list1[i].email);
                    found++;
                    break;
                }
          }

                fflush(stdin);

            if(found!=0)
            {
                printf("\n%d Contact found\n",found);

            }
                else
                {
                   printf("Contact not found!\n");
                }
}

                fclose(fp);
                 getch();

                   main();

 }

 struct contact edit_contact()
 {
    struct contact list1[40]; char name[40];
    int i,l,L,flag=0; char b;
       FILE *fp=fopen("student contact.txt","r");

        if(fp==NULL)
            {

              printf("\nFile opening error!!");
             _Exit(0);
            }

else{

        fflush(stdin);

        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit: ");

        scanf("%[^\n]",name);

     for(i=0;i<std_n;++i)
            {
            fflush(stdin);
            fgets(list1[i].name,40,fp);
             l=strlen(list1[i].name);
            list1[i].name[l-1]='\0';
            fflush(stdin);
            fscanf(fp,"%s",&list1[i].ph);
            fscanf(fp,"%c",&b);
            fflush(stdin);
            fgets(list1[i].email,30,fp);
             L=strlen(list1[i].email);
            list1[i].email[L-1]='\0';

            }
 fclose(fp);

     for(i=0;i<std_n;++i)
        {

            if(stricmp(name,list1[i].name)==0)

        {
        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",name);

        printf("..::Name:");

        scanf("%[^\n]",&list1[i].name);

        fflush(stdin);

        printf("..::Phone:");

        scanf("%s",&list1[i].ph);

        fflush(stdin);

        printf("..::Email address:");

        gets(list1[i].email);

        printf("\n");
              flag=1;
              break;

     }
}
         fflush(stdin);
             FILE *fp=fopen("student contact.txt","w");
    for(i=0;i<std_n;++i)
        {
            fprintf(fp,"%s\n%s\n%s\n",list1[i].name,list1[i].ph,list1[i].email);
        }
            if(flag==1)
            {
                    printf("\nContact edited!!");
            }
            else
            {
                    printf(" \n Contact is not found!");

            }

}
            fclose(fp);

         getch();

            main();
 }

 struct contact delete_contact()
 {
    struct contact list1[40]; char name[40];
    int i,l,L,found=0; char b;


       FILE *fp=fopen("student contact.txt","r");

        if(fp==NULL)
            {

              printf("\nFile opening error!!");
             _Exit(0);
            }

else{

    system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

        scanf("%[^\n]",&name);

     for(i=0;i<std_n;++i)
            {
            fflush(stdin);
            fgets(list1[i].name,40,fp);
            l=strlen(list1[i].name);
            list1[i].name[l-1]='\0';
            fflush(stdin);
            fscanf(fp,"%s",&list1[i].ph);
            fscanf(fp,"%c",&b);
            fflush(stdin);
            fgets(list1[i].email,30,fp);
             L=strlen(list1[i].email);
            list1[i].email[L-1]='\0';
            }
 fclose(fp);
 fflush(stdin);
             FILE *fp=fopen("student contact.txt","w");
for(i=0;i<std_n;i++)
     {
         if (stricmp(name,list1[i].name)!=0)
         {
    fprintf(fp,"%s\n%s\n%s\n",list1[i].name,list1[i].ph,list1[i].email);
    found++;
         }

     }
std_n--;
 fclose(fp);
if(found!=0)
{
    printf(" Contact Deleted!!\n");
}
else
{
    printf("No Contact Found to Delete!!\n");
}


 fclose(fp);

         getch();

            main();

}
 };




int main()

{
     char name[40];

FILE *fp;

int ch;
struct contact list;


    printf("\n\t **** Welcome to Contact Management System ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    if(ch==0)
    {
        _Exit(0);
    }
    else if(ch==1)
    {
       list= Add_A_New_Contact();
    }
    else if(ch==2)
    {
       list= All_contact();
    }
    else if(ch==3)
    {
        list= search_contact();
    }
     else if(ch==4)
    {
        list= edit_contact();
    }
    else if(ch==5)
    {
        list= delete_contact();
    }

    return 0;
}



