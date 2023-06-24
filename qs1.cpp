#include<iostream>
using namespace std;
class mazee
{
	private:
		
		char **m;
		int i,j,rows,column,val1,val2,a; 
	
	public: 
	
	mazee()
	{
		m=NULL;
		i=0; 
		j=0;
		rows=0;
		column=0;
		val1=0;
		val2=0;
		a=0;
	}
	mazee(int rows,int column)
	{
		(*this).rows=rows;
		(*this).column=column;
	 	m= new char *[rows];
	    for(i=0;i<rows;i++)
	    {
		m[i]=new char[column];
	    }
	    i=0;
		j=0;
		rows=0;
		column=0;
		val1=0;
		val2=0;
		a=0;
    }
    void input()
    {
    cout<<"Enter the number of rows: ";
	cin>>rows;
	cout<<"Enter the number of columns: ";
	cin>>column;
	m= new char *[rows];
	for(i=0;i<rows;i++)
	{
		m[i]=new char[column];
	}
	cout<<"Enter layout: "<<endl;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<column;j++)
		{
	    cin>>m[i][j];
	    }    
	}
    }
    void startpath()
    {
    for(i=0;i<rows;i++)
	{
		for(j=0;j<column;j++)
		{
			if((m[i][j]=='s')||(m[i][j]=='S'))
			{
				val1=i;
				val2=j;
				cout<<endl<<val1<<","<<val2<<endl;
			}
		}
	}
	path(m,val1,val2,a);
	}
	
	void path(char **m,int val1,int val2,int a)
    {
    	if((m[val1][val2-1]=='e')||(m[val1][val2-1]=='E'))//left
    	{
    		m[val1][val2]='!';
    		val2--;
    		cout<<val1<<","<<val2<<endl;
		}
		else if((m[val1+1][val2]=='e')||(m[val1+1][val2]=='E'))//down
    	{
    		m[val1][val2]='!';
    		val1++;
    		cout<<val1<<","<<val2<<endl;
		}
		else if(m[val1][val2+1]=='-') //right
		{
			m[val1][val2]='!';	
			val2++;
			cout<<val1<<","<<val2<<endl;
			path(m,val1,val2,a);
		}
		else if(m[val1+1][val2]=='-') //down
		{
			m[val1][val2]='!';	
			val1++;
			cout<<val1<<","<<val2<<endl;
			path(m,val1,val2,a);
		}
		else if(m[val1-1][val2]=='-') //up
		{
			m[val1][val2]='!';	
			val1--;
			cout<<val1<<","<<val2<<endl;
			path(m,val1,val2,a);
		}
		else if(m[val1][val2-1]=='-') //left
		{
			m[val1][val2]='!';
			val2--;
			cout<<val1<<","<<val2<<endl;
			path(m,val1,val2,a);
		}
		else 
		{
			cout<<"Unable to find any way";
		}
	}

	~mazee()
    {
	if(m!=0)
	{
	for(int i=0;i<rows;i++)
	  	{
	  		delete m[i];
	  		m[i]=0;
		}
	delete []m;
	m=0;
	}
	delete m;
    }
};

int main()
{
	mazee mg;
	mg.input();
	mg.startpath();
	return 0;
}
