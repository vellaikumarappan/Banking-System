#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int no_of_acc=0;
struct account{
    int acno;
    char acname[30];
    char userid[25];
    char password[25];
    char bname[30];
    float balance;
    int bac[99];
    int k;
};
typedef struct account pa;
pa p[100];
void accept(no_of_acc){
    printf("\n-------------------------------------------------------------------");
    printf("\n\t\tENTER ACCOUNTANT DETAILS\t\t\n");
    p[no_of_acc].acno=no_of_acc;   
    printf("\nEnter the account opener name : ");
    scanf("%s",p[no_of_acc].acname);
    printf("\nEnter the userid : ");
    scanf("%s",p[no_of_acc].userid);
    printf("\nEnter the password : ");
    scanf("%s",p[no_of_acc].password);
    strcpy(p[no_of_acc].bname,"Canara Bank");
    p[no_of_acc].balance=50.0;
    printf("\nA new account is created");
    p[no_of_acc].k=0;
    printf("\nYour account number is : %d",p[no_of_acc].acno);
    printf("\n\n-------------------------------------------------------------------");
}
void addbac(int b){
    if(b<no_of_acc){
        for(int i=0;i<no_of_acc;i++){
            if(p[i].acno==b){
                int x,y=0;
                printf("\nEnter the beneficiary account number to be added : ");
                scanf("%d",&x);
                if(x<no_of_acc && x!=b){
                    for(int j=0;j<no_of_acc;j++){
                        if(p[j].acno==x){
                            int o=0;
                            for(int z=0;z<=p[i].k;z++){
                                if(p[i].bac[z]==x && x!=0){
                                    printf("\nThe beneficiary account already exists");
                                    o=1;
                                }
                                if(p[i].bac[z]==0){
                                    y=y+1;
                                }
                            }
                            if(y==1 && x==0){
                                p[i].bac[p[i].k]=x;p[i].k++;
                                printf("\nBeneficiary account is added"); 
                            }
                            if(y>1 && x==0){
                                printf("\nBeneficiary account already exsits");
                            }
                            if(o==0 && x!=0){
                                p[i].bac[p[i].k]=x;p[i].k++;
                                printf("\nBeneficiary account is added");                                
                            }
                        }
                    }
                }
                else{
                    printf("\nEnter a valid beneficiary account number");
                }
            }
        }
    }else{
        printf("\nEnter a valid account number");
    }
    printf("\n\n-------------------------------------------------------------------");
}
void deletebeneficiary(int b){
    if(b<no_of_acc){
        for(int i=0;i<no_of_acc;i++){
            if(p[i].acno==b){
                int g,p1=0,l,m,n=0;
                printf("\nEnter the beneficiary account to be deleted : ");
                scanf("%d",&g);
                for(int a=0;a<=p[i].k;a++){
                    p1=p1+1;
                    if(p[i].bac[a]==g && g!=b  && p[i].k!=0){
                        n=1;
                        for(l=p1-1;l<=p[i].k;l++){
                            p[i].bac[l]=p[i].bac[l+1];
                        }
                        p[i].k--;
                        printf("\nThe beneficiary account is deleted");
                        break;
                    }
                }
                if(n==0){
                    printf("\nEnter a valid beneficiary account number");
                }
            }
        }
    }
    else{
        printf("\nEnter a valid account number");
    }
    printf("\n\n-------------------------------------------------------------------");
}
void fundtransfer(int b,float mon){
    int n=0,h=0;
    if(b<no_of_acc){
        for(int i=0;i<no_of_acc;i++){
            if(p[i].acno==b){
                int x;
                printf("\nEnter the account number to transfer : ");
                scanf("%d",&x);
                for(int a=0;a<=p[i].k;a++){
                    if(p[i].bac[a]==x && p[i].k!=0 && p[i].bac[0]!=x && p[i].k!=1){
                        h=1;
                        if(p[i].balance>=mon){
                            p[i].balance=(p[i].balance)-mon;
                            p[x].balance+=mon;
                            n=1;
                        }
                    }
                    if(p[i].bac[a]==x && p[i].bac[0]==x && p[i].k>1){
                        h=1;
                        if(p[i].balance>=mon){
                            p[i].balance=(p[i].balance)-mon;
                            p[x].balance+=mon;
                            n=1;
                        }
                        break;
                    }
                    if(p[i].bac[a]==x && p[i].k==1 && p[i].k!=0){
                        h=1;
                        if(p[i].balance>=mon){
                            p[i].balance=(p[i].balance)-mon;
                            p[x].balance+=mon;
                            n=1;
                        }
                    }
                }
                if(n==0 && h==1){
                    printf("\nThe fund is not sufficient");
                }
                if(h==0){
                    printf("\nEnter a valid beneficiary account number");
                }
                if(h==1 && n==1){
                    printf("\nThe fund is transferred");
                }
            }
        }
    }
    else{
        printf("\nEnter a valid account number");
    }
    printf("\n\n-------------------------------------------------------------------");
}
void displaybeneficiary(int b){
    if(b<no_of_acc){
        for(int i=0;i<no_of_acc;i++){
            if(p[i].acno==b){
                if(p[i].k!=0){
                    printf("\nThe beneficiary account numbers are : ");
                    for(int j=0;j<p[i].k;j++){
                        printf("%d ",p[i].bac[j]);
                    }
                }
                else{
                    printf("\nThe account %d has no beneficiary",p[i].acno);
                }
            }
        }
    }
    else{
        printf("\nEnter a valid account number");
    }
    printf("\n\n-------------------------------------------------------------------");
}
void displayaccountdetails(int x){
    printf("\n-------------------------------------------------------------------");
    if(x<no_of_acc){
        for(int i=0;i<no_of_acc;i++){
            if(i==x){
                printf("\n\t\tTHE ACCOUNT DETAILS OF A/C NO %d\t\t\n",x);
                printf("\nAccount holder name : %s",p[i].acname);
                printf("\nBank name : %s",p[i].bname);
                printf("\nAccount balance : %f",p[i].balance);
                printf("\n\n-------------------------------------------------------------------");
                break;
            }   
        }
    }
    else{
        printf("\nEnter a valid account number");
        printf("\n\n-------------------------------------------------------------------");
    }
}
int useridcheck(int x){
    char userid1[25];
    char password1[25];
    if(x<no_of_acc){
        for(int i=0;i<no_of_acc;i++){
            if(i==x){
                printf("\nEnter the userid : ");
                scanf("%s",userid1);
                if(strcmp(p[i].userid,userid1)==0){
                    printf("\nEnter the password : ");
                    scanf("%s",password1);
                    if(strcmp(p[i].password,password1)==0){
                        return 1;
                    }
                    else{
                        printf("\nPassword not matching!!!\n");
                    }
                }
                else{
                    printf("\nUserid not matching!!!\n");
                }
            }
        }
    }
    return 0;
}
void main(){
    int c=0;
    int x;
    int c1;
    printf("\nMenu");
    printf("\n1.Login");
    printf("\n2.Create a new account");
    printf("\n3.Exit\n");
    printf("\nEnter the option for the menu : ");
    scanf("%d",&c1);
    while(c1<3){
        switch(c1){
            case 1:{
                c=0;
                printf("\n-------------------------------------------------------------------");
                printf("\n                                 LOGIN     \n");
                printf("\nEnter the account number : ");
                scanf("%d",&x);
                while(useridcheck(x)==0){
                    printf("\nEnter the correct account number : ");
                    scanf("%d",&x);
                }
                while(c!=6){
                    printf("\nSub Menu\n");
                    printf("1.Display account details\n2.Add beneficiary\n3.Display beneficiary\n4.Delete beneficiary\n5.Fund transfer\n6.Log Out\n");
                    printf("\nEnter the option for menu : ");
                    scanf("%d",&c);
                    switch(c){
                        case 1:{
                            displayaccountdetails(x);
                            break;
                        }
                        case 2:{
                            printf("\n-------------------------------------------------------------------");
                            printf("\n\t\tADD BENEFICIARY\t\t\n");
                            addbac(x);
                            break;
                        }
                        case 3:{
                            printf("\n-------------------------------------------------------------------");
                            printf("\n\t\tDISPLAY BENEFICIARY\t\t\n");
                            displaybeneficiary(x);
                            break;
                        }
                        case 4:{
                            printf("\n-------------------------------------------------------------------");
                            printf("\n\t\tDELETE BENEFICIARY\t\t\n");
                            deletebeneficiary(x);
                            break;
                        }
                        case 5:{
                            printf("\n-------------------------------------------------------------------");
                            printf("\n\t\tFUND TRANSFER\t\t\n");
                            float m;
                            printf("\nEnter the amount : ");
                            scanf("%f",&m);
                            fundtransfer(x,m);
                            break;
                        }
                    }
                }
                break;
            }  
            case 2:{
                accept(no_of_acc);
                no_of_acc++;
                break;
            }
        }
        printf("\nMenu");
        printf("\n1.Login");
        printf("\n2.Create a new account\n");
        printf("3.Exit\n");
        printf("\nEnter the option for the menu : ");
        scanf("%d",&c1);
    }
}
