#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;
void check1();
char exp[100];
int word=0,c=0;
int flag=0,len=0;
char str[100],first[20][100];
void Sleep(int ms)
{
clock_t goal=ms+clock();
while(goal>clock());
return;
}

class link
{
	char w[100];
	int t;
	link *head ,*next;
	public:
		link()
		{
			head=NULL;
		}
		void add(char d[])    
        {
        	word++;
             link *newLink = new link;
             strcpy(newLink->w,d);
             newLink->t=word;
             newLink->next = NULL;
             if(head==NULL)
             {
                 head = newLink;
                 return;
             }
             link *z=head;
             while(z->next!=NULL)
             z=z->next;
             z->next=newLink;
             return;
        }
        const char* del(int o)
	    {
	    	char x[100];
	    	link *t=head;
			if(head==NULL)
	    	{
	    		strcpy(x,"Error");
	    	}
	    	else
	    	{
	    		while(t->next!=NULL&&t->t!=o)
	    		    t=t->next;
	    		strcpy(x,t->w);
	    	}
	    	return x;
	    }
	    void re(int o)
	    {
	    	link *t=head;
	    	while(t->next!=NULL&&t->t!=o)
	    	t=t->next;
	    	strcpy(t->w,str);
	    	return;
	    }
	    void display()
	    {
	    	link *t=head;
	    	while(t->next!=NULL)
	    	{
	    		cout<<t->w<<"("<<t->t<<")"<<" ";
	    		t=t->next;
	    	}
	    	cout<<t->w<<"("<<t->t<<")"<<".";
	    	return;
	    }
	    void display1()
	    {
	    	link *t=head;
	    	while(t->next!=NULL)
	    	{
	    		cout<<t->w<<" ";
	    		t=t->next;
	    	}
	    	cout<<t->w<<".";
	    	return;
	    }
}e;

class stack
{
	char s[100];
    stack *top,*next;
    public:
    	stack()
    	{
    		top=NULL;
    	}
    	
    	void push(char a[])
    	{
    		stack *t=new stack;
    		strcpy(t->s,a);
    		if(top==NULL)
    	    {
    	    	t->next=NULL;
    	    	top=t;
    	    	return;
    	    }
    	    t->next=top;
    	    top=t;
    	    return;
    	
	    }
	    
	    const char* pop()
	    {
	    	char x[100];
	    	stack *t=top;
			if(top==NULL)
	    	{
	    		strcpy(x,"Error");
	    		delete(t);
	    	}
	    	else
	    	{
	    		strcpy(x,top->s);
	    		top=top->next;
	    		delete(t);
	    	}
	    	return x;
	    }
	    
}x;

void check(char a)
{
	HANDLE hConsole;
	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	char str2[100];
	char str1[100],p[100];
	FILE *f;
	strcpy(exp,"\0");
	int i=len,ind=0,c=0;
	int b=a;
	if(b>=48 && b<=64)
	{
	    strcpy(str,first[(b-48)]);
	    check1();
	    return;
    }
	if(a=='\b')
	{
		strcpy(p,x.pop());
		if(strcmp(p,"Error")==0)
		{
			system("cls");
			len=0;
			cout<<"Your Word:";
			return;
		}
		else
		{
			strcpy(str,p);
			len=strlen(p);
			str[len]='\0';
			c=0;
			goto q;
		}
	}
    str[i++]=a;
	str[i]='\0';
	x.push(str);
	q:f=fopen("first.txt","r");
	system("cls");
	while(!feof(f))
	{
		i=strlen(str);
		fscanf(f,"%s",str1);
		int r=0,j=0,k=0;
		while(r<i)
		{
			str2[j++]=str1[k++];
			str2[j]='\0';
			r++;
		}  
		if(strcmp(str,str2)==0)
		{ 
		    c++;
		    //cout<<endl<<first[ind-1]<<endl<<endl;
		    if(c<=10)
		    {
		    	strcpy(first[ind++],str1);
		    	if(c==1)
		    	{
		    		strcpy(exp,str1);
		             SetConsoleTextAttribute
	                 (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			         cout<<c-1<<" "<<str1<<endl;
			         continue;
		        }
		       SetConsoleTextAttribute
	           (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				 cout<<c-1<<" "<<str1<<endl; 
	        }
        }
    }
	fclose(f);
	if(c<=10)
	{
	f=fopen("final.txt","r");
	while(!feof(f))
	{
		i=strlen(str);
		fscanf(f,"%s",str1);
		int r=0,j=0,k=0;
		while(r<i)
		{
			str2[j++]=str1[k++];
			str2[j]='\0';
			r++;
		}  
		if(strcmp(str,str2)==0)
		{ 
		    c++;
		    if(c<=10)
		    {
		    	strcpy(first[ind++],str1);
		    	/*if(c==1)
		    	{
		             SetConsoleTextAttribute
	                 (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			         cout<<c-1<<str1<<endl;
			         continue;
		        }*/
		       SetConsoleTextAttribute
	           (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
				 cout<<c-1<<" "<<str1<<endl; 
	        }
		} 
	}
    }
    fclose(f);
    if(c==0)
    flag=1;
    cout<<"Your Word:"<<str; 
	return;
} 
void check1()
{
	if(strcmp(exp,"\0")!=0)
	strcpy(str,exp);
	if(flag==1)
	{
    	FILE *f;
		system("cls");
	    cout<<endl<<"Adding to the dictionary."<<endl;
	    f=fopen("final.txt","r+");
		fprintf(f,"%s\n",str);
		fclose(f);
	    flag=0; 
		c=0;
		len=0;
		cout<<"Word ADDED!"<<endl;
		Sleep(500);
    }
	char a;
	int choice;
	e.add(str);
	h:system("cls");
	cout<<"Your sentence"<<endl;
	e.display1();
	cout<<endl<<"Your Choice:1.Continue 2.Edit 3.Exit:";
	cin>>choice;
	if(choice==2)
	{
		system("cls");
		static int l;
		cout<<"Your sentence"<<endl;
		e.display();	
		cout<<endl;
		cout<<"Enter the number of the word:";
		cin>>l;
		strcpy(str,e.del(l));
		system("cls");
		strcpy(str,"\0");
		cout<<"Your Word:";
		a=_getch();
		while(a!=' '&&a!='.')
	    {
	    	len=strlen(str);
         	check(a);
         	a=_getch();
        }
        //strcpy(str,first);
		e.re(l);
		len=0;
		goto h;
	}
	else if(choice==1)
	{
		system("cls");
		cout<<"Your Word:";
		strcpy(str,"\0");
		len=0;
	}
	else 
	 exit(1);
	return;
}


int main()
{
	strcpy(str,"\0");
	//system("COLOR FC");
	char a;
	cout<<"Your Word:(Press ` to exit)";
	a=_getch();
	while(a!='`')
	{
		if(a==' '|| a=='.')
	    check1();
	    else if(a=='\b')
	    check(a);
	    else
	    {
	    	len=strlen(str);
	    	check(a);
	    	c=0;
	    }
	    a=_getch();
	}
	return 0;
}
