//============================================================================
// Name        : Assignment6.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;

class Entry
{
	string word;
	string meaning;

public:
	Entry()
	{
		word='\0';
		meaning='\0';
	}
	friend class Dictionary;
};

class Dictionary
{
	Entry e[26];
	int count;
public:
	Dictionary()
	{
		for(int i=0;i<26;i++)
		{
			e[i].word="NULL";
			e[i].meaning="NULL";
		}
		count=0;
	}
	void insertWithout();
	int HashFunction(string s);
	void display();
	void search();
	void modify();
	void delete_word(string w);
	void insert_Again(string wor,string mean);
    void insert_WithReplacement();
    void delete_WithReplacement(string wor);
    void insert_Again_WithReplacement(string w,string m);
};
void Dictionary::insertWithout()
{
	char ans;
	string w,m;
	int hi;
	do
	{
		if(count>26)
		{
			cout<<"\nHash Table Is Full\n";
			break;
		}
		cout<<"\nEnter the Word : ";
		cin>>w;
		cout<<"\nEnter Its Meaning : ";
		cin>>m;
		hi=HashFunction(w);
		if(e[hi].word=="NULL")
		{e[hi].word=w;
		e[hi].meaning=m;
		}
		else
		{
			for(int i=(hi+1)%26;i!=hi;i=(i+1)%26)
			{
				if(e[i].word=="NULL")
				{
					e[i].word=w;
					e[i].meaning=m;
					break;

				}
			}
		}
		cout<<"\nInserted Successfully\n";
		count++;
		cout<<"\nDo You Want To Add Another (y/n)\n";
		cin>>ans;


	}while(ans=='y');
}
int Dictionary::HashFunction(string s)
{

	int sum=0;
	if(s[0]>='A'&&s[0]<='Z')
		sum=sum+s[0]-65;
	else
	sum=sum+s[0]-97;
	return (sum%26);


}
void Dictionary::display()
{
	cout<<"\nHash Table Becomes\n\n";
	cout<<"\nIndex\t\tWord\t\tMeaning\n";
	for(int i=0;i<26;i++)
	{
		cout<<"e["<<i<<"]\t\t"<<e[i].word<<"\t\t"<<e[i].meaning<<endl;
	}
}
void Dictionary::search()
{
	string key;
	int col=0;
	cout<<"\nEnter the Word To Be Searched\n";
	cin>>key;
	int hi=HashFunction(key);
	if(e[hi].word==key)
	{
		cout<<"\nWord Is Present At Index e["<<hi<<"]\n";
		cout<<"\nNumber of Collisions are : "<<col;
	}
	else
	{
		int i;
		for(i=(hi+1)%26;i!=hi;i=(i+1)%26)
		{
			col++;
			if(e[i].word==key)
			{
				cout<<"\nWord is present At Index e["<<i<<"]\n";
				cout<<"\nNumber of Collisions are : "<<col;
				break;
			}
		}
		if(i==hi)
		{
			cout<<"\nWord is Not Present in Hash Table\n";
		}
	}


}
void Dictionary::modify()
{
	string key,value;
	cout<<"\nEnter The Word whose meaning has to be modified\n";
	cin>>key;
	int x;
	int hi=HashFunction(key);
	if(e[hi].word==key)
		x=hi;
	else
	{
		for(int i=(hi+1)%26;i!=hi;i=(i+1)%26)
		{
			if(e[i].word==key)
			{
				x=i;
				break;
			}
		}
	}
	cout<<"\nEnter Its New Meaning\n";
	cin>>value;
	e[x].meaning=value;
	cout<<"\nThe New Meaning Is Successfully Inserted\n";
}

void Dictionary::delete_word(string w)
{
    int hi=HashFunction(w);
    int flag=0;
    if(e[hi].word==w)
    {
        cout<<"\nWord Deleted Successfully\n";
        e[hi].word="NULL";
        e[hi].meaning="NULL";
        flag=1;
    }
    else if(e[hi].word!=w)
    {
        for(int i=(hi+1)%26;i!=hi;i=(i+1)%26)
        {
            if(e[i].word==w)
            {
                cout<<"\nWord Deleted Successfully\n";
                e[i].word="NULL";
                e[i].meaning="NULL";
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"\nInvalid Word Entered\n";
    else
    {
        int j=0;
        string a[26],b[26];
        int size=0;
        for(int i=0;i<26;i++)
        {
            if(e[i].word!="NULL")
            {
                a[j]=e[i].word;
                b[j]=e[i].meaning;
                e[i].word="NULL";
                e[i].meaning="NULL";
                j++;
                size++;
            }
        }
        for(int i=0;i<size;i++)
        {
            insert_Again(a[i],b[i]);
        }
    }

}
void Dictionary::insert_Again(string w,string m)
{
    int hi=HashFunction(w);
    if(e[hi].word=="NULL")
    {
        e[hi].word=w;
        e[hi].meaning=m;

    }
    else if(e[hi].word!="NULL")
    {
        for(int i=(hi+1)%26;i!=hi;i=(i+1)%26)
        {
            if(e[i].word=="NULL")
            {
                e[i].word=w;
                e[i].meaning=m;
                break;
            }
        }
    }
}
void Dictionary::insert_WithReplacement()
{
    string w,m;
    char ans;
    int count_Replace=0;
    do
    {
        if(count_Replace>26)
        {
            cout<<"\nHash Table Is Full\n";
            break;
        }
        cout<<"\nEnter the Word : ";
        cin>>w;
        cout<<"\nEnter its Meaning : ";
        cin>>m;
        int hi=HashFunction(w);
        if(e[hi].word=="NULL")
        {
            e[hi].word=w;
            e[hi].meaning=m;
        }
        else
        {
             string word_temp,mean_temp;
            int index=HashFunction(e[hi].word);
            if(index!=hi)
            {

                word_temp=e[hi].word;
                mean_temp=e[hi].meaning;
                e[hi].word=w;
                e[hi].meaning=m;
                for(int i=(hi+1)%26;i!=hi;i=(i+1)%26)
                {
                    if(e[i].word=="NULL")
                    {
                        e[i].word=word_temp;
                        e[i].meaning=mean_temp;
                        break;
                    }
                }
            }
            else
            {
                for(int i=(hi+1)%26;i!=hi;i=(i+1)%26)
                {
                    if(e[i].word=="NULL")
                    {
                        e[i].word=w;
                        e[i].meaning=m;
                        break;
                    }
                }
            }

        }
        cout<<"\nInserted Successfully\n";
        count_Replace++;
        cout<<"\nDo You Want Another Data\n";
        cin>>ans;
    }while(ans=='y');
}
void Dictionary::delete_WithReplacement(string w)
{
    int hi=HashFunction(w);
    int flag=0;
    if(e[hi].word==w)
    {
        cout<<"\nWord Deleted Successfully\n";
        e[hi].word="NULL";
        e[hi].meaning="NULL";
        flag=1;
    }
    else if(e[hi].word!=w)
    {
        for(int i=(hi+1)%26;i!=hi;i=(i+1)%26)
        {
            if(e[i].word==w)
            {
                cout<<"\nWord Deleted Successfully\n";
                e[i].word="NULL";
                e[i].meaning="NULL";
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        cout<<"\nInvalid Word Entered\n";
    else
    {
        int j=0;
        string a[26],b[26];
        int size=0;
        for(int i=0;i<26;i++)
        {
            if(e[i].word!="NULL")
            {
                a[j]=e[i].word;
                b[j]=e[i].meaning;
                e[i].word="NULL";
                e[i].meaning="NULL";
                j++;
                size++;
            }
        }
        for(int i=0;i<size;i++)
        {
            insert_Again_WithReplacement(a[i],b[i]);
        }
    }

}
void Dictionary::insert_Again_WithReplacement(string w,string m)
{
    int hi=HashFunction(w);
    if(e[hi].word=="NULL")
        insert_Again(w,m);
    else if(e[hi].word!="NULL")
    {
        int index=HashFunction(e[hi].word);
        if(index==hi)
            insert_Again(w,m);
        else
        {
            string word_temp,mean_temp;
            word_temp=e[hi].word;
            mean_temp=e[hi].meaning;
            e[hi].word=w;
            e[hi].meaning=m;
            insert_Again(word_temp,mean_temp);
        }
    }

}
int main() {

	Dictionary d,r;
	int ch,ch1,ch2;
	string w;
	do
	{
		cout<<"\n1.Without Replacement\n2.With Replacement\n";
		cout<<"\nEnter your Choice\n";
		cin>>ch1;
		switch(ch1)
		{
		case 1:
			do
			{
				cout<<"\n**WITHOUT REPLACEMENT**\n1.Insert\n2.Display\n3.Search\n4.Modify\n5.Delete\n6.Exit";
				cout<<"\nEnter Your Choice\n";
				cin>>ch;
				switch(ch)
				{
				case 1:
					d.insertWithout();
					break;
				case 2:
					d.display();
					break;
				case 3:
					d.search();
					break;
				case 4:
					d.modify();
					break;
                case 5:
                    cout<<"\nEnter The Word To Be Deleted\n";
                    cin>>w;
                    d.delete_word(w);
                    break;
				}

			}while(ch!=6);
			break;
		case 2:
		    do
            {
                cout<<"\n**WITH REPLACEMENT**\n1.Insert Data\n2.Display\n3.Search\n4.Modify\n5.Delete\n6.Return Back\n";
                cout<<"\nEnter Your Choice\n";
                cin>>ch2;
                switch(ch2)
                {
                case 1:
                    r.insert_WithReplacement();
                    break;
                case 2:
                    r.display();
                    break;
                case 3:
                    r.search();
                    break;
                case 4:
                    r.modify();
                    break;
                case 5:
                    cout<<"\nEnter the Word TO Be Deleted\n";
                    cin>>w;
                    r.delete_WithReplacement(w);
                    break;
                }
            }while(ch2!=6);
			break;

		}
	}while(ch1!=0);




	return 0;
}
