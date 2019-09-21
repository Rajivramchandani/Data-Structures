#include<stdio.h>
struct student{
char name[15];
int prn;
char branch[15];
float score;}s[100];
int main()
{
 int ch, n, i , p, len=0, loc;
 printf("Enter number of students:\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("Enter name:\nprn:\nbranch:\nscore:\n");
 scanf("%s%d%s%f",&s[i].name,&s[i].prn,&s[i].branch,&s[i].score);
 len++;
 }
 printf("Choose:\n1.Create:\n2.Modify:\n3.Delete:\n4.Search:\n5.Print\n");
 scanf("%d",&ch);
 switch (ch)
 {case 1:
  {printf("Enter name:\nprn:\nbranch:\nscore:\n");
      scanf("%s%d%s%f",&s[i].name,&s[i].prn,&s[i].branch,&s[i].score);
      printf("New user created.");
      len++;
      for(i=0;i<len;i++)
      {printf("Name:%s\nPrn:%d\nBranch:%s\nScore:%f\n",s[i].name,s[i].prn,s[i].branch,s[i].score);
      }
  }break;
 case 2:
  {printf("Enter location to be modified:");
  scanf("%d",&loc);
  loc=loc-1;
  for(i=0;i<len;i++)
  {if(loc==i)
  {printf("Enter new data:\nname:\nPrn:\nbranch:\nscore:\n");
  scanf("%s%d%s%f",&s[i].name,&s[i].prn,&s[i].branch,&s[i].score);}
  }
  for(i=0;i<len;i++)
        {printf("Changes\nName:%s\nPRN:%d\nBranch:%s\nScore:%f\n",s[i].name,s[i].prn,s[i].branch,s[i].score);
  }}break;
    case 3:
        {
         printf("Enter location to delete\n");
         scanf("%d",&loc);
         loc=loc-1;
            for(int c=loc;c<n;c++)
                 {
                   s[c]=s[c+1];
                 }
         printf("Deleted!\n");
         printf("-------------------------------------------------------");
         for(i=0;i<n-1;i++)
            printf("\nName:%s\nPrn:%d\nBranch:%s\nScore:%f\n",s[i].name,s[i].prn,s[i].branch,s[i].score);
        }break;
    case 4:
        {
            printf("Enter prn to be searched\n");
            scanf("%d",&loc);
            for(i=0;i<n;i++)
            {
                if(loc==s[i].prn)
                    printf("\nName:%s\nPrn:%d\nBranch:%s\nScore:%f",s[i].name,s[i].prn,s[i].branch,s[i].score);
            }
        }break;
    case 5:
        {
          for(i=0;i<len;i++)
      {printf("%s\n%d\n%s\n%f",s[i].name,s[i].prn,s[i].branch,s[i].score);
        }
  }break;
 }
}
