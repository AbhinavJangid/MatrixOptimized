#include<iostream>
using namespace std;

class  Diagonal
{
	private:
		int *A, n;
		
	public:
		Diagonal()
		{
			cout<<"Enter the size of the matrix::";
			cin>>n;
			A=new int[n];
		}
		//Diagonal(int n);
		
		void create();
		void set(int i, int j, int x);
		int get(int i, int j);
		void Display();
		void Menu();
		~Diagonal();			
};

class LTMatrix
{
	private:
		int *A, n;
	
	public:
		LTMatrix()
		{
			cout<<"Enter the size of the matrix::";
			cin>>n;
			A=new int[n*(n+1)/2];
		}
		//LTMatrix(int n);
		void create();
		void set(int i, int j, int x);
		int get(int i, int j);
		void Display();
		void Menu();
		~LTMatrix();
};

class UTMatrix
{
	private:
		int *A, n;
	 public:
	 	UTMatrix()
	 	{
	 		cout<<"Enter the size of the matrix::";
			cin>>n;
			A=new int[n*(n+1)/2];
		 }
	 	//UTMatrix(int n);
		void create();
		void set(int i, int j, int x);
		int get(int i, int j);
		void Display();
		void Menu();
		~UTMatrix();	
};

/*Diagonal::Diagonal(int n)
{
	this->n=n;
	A=new int[n];
}*/
Diagonal::~Diagonal()
{
	delete []A;
}

void Diagonal::create()
{
	int i,j,x;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>x;
			if(i==j)
				A[i-1]=x;
		}
	}
}

int Diagonal::get(int i, int j)
{
	int z;
	if(i==j)	
		z=A[i-1];
	if(z!=0)
		return z;
	else 
		return 0;	
}

void Diagonal::set(int i, int j, int x)
{
	if(i==j)
		A[i-1]=x;
}

void Diagonal::Display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			
			if(i==j)
				cout<<A[i-1]<<" ";
			else
				cout<<"0"<<" ";
		}
		cout<<endl;
	}
}

void Diagonal::Menu()
{
	int i,j,x;
	
	int choice;
	cout<<"1. Add elements"<<endl;
	cout<<"2. Display elements"<<endl;
	cout<<"3. Get element at certain position"<<endl;
	cout<<"4. Set element at certain position"<<endl;
	cout<<endl<<"Enter your choice::";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			create();
			Menu();
			break;
		
		case 2:
			Display();
			Menu();
			break;
		 case 3:
		 	cout<<"Enter the position::";
		 	cin>>i>>j;
		 	cout<<"The element at position "<<i<<","<<j<<" is "<<get(i,j);
		 	Menu();
			break;
		
		case 4:
			cout<<"Enter the position followed by element::";
			cin>>i>>j>>x;
			set(i,j,x);
			Menu();
			break;
		
		default:
			cout<<"Please enter valid choice!!";
			Menu();
			break;		
	}
	
}

/*LTMatrix::LTMatrix(int n)
{
	this->n=n;
	A=new int[n*(n+1)/2];
}
*/
LTMatrix::~LTMatrix()
{
	delete []A;
}

void LTMatrix::create()
{
	int i, j, x;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>x;
			if(i>=j)
				A[i*(i-1)/2+j-1]=x;
		}
	}
}

int LTMatrix::get(int i, int j)
{
	int z;
	if(i>=0)
		z=A[i*(i-1)/2+j-1];
	if(z!=0)
		return z;
	else 
		return 0; 
}

void LTMatrix::set(int i, int j, int x)
{
	if(i>=0)
		A[i*(i-1)/2+j-1]=x;
}

void LTMatrix::Display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=0;j++)
		{
			if(i>=0)
				cout<<A[i*(i-1)/2+j-1]<<" ";
			else 
				cout<<"0 ";
		}
		cout<<endl;
	}
}

void LTMatrix::Menu()
{
	int i,j,x;
	
	int choice;
	cout<<"1. Add elements"<<endl;
	cout<<"2. Display elements"<<endl;
	cout<<"3. Get element at certain position"<<endl;
	cout<<"4. Set element at certain position"<<endl;
	cout<<endl<<"Enter your choice::";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			create();
			Menu();
			break;
		
		case 2:
			Display();
			Menu();
			break;
		 case 3:
		 	cout<<"Enter the position::";
		 	cin>>i>>j;
		 	cout<<"The element at position "<<i<<","<<j<<" is "<<get(i,j);
		 	Menu();
			break;
		
		case 4:
			cout<<"Enter the position followed by element::";
			cin>>i>>j>>x;
			set(i,j,x);
			Menu();
			break;
		
		default:
			cout<<"Please enter valid choice!!";
			Menu();
			break;		
	}
	
}

/*UTMatrix::UTMatrix(int n)
{
	this->n=n;
	A=new int[n*(n+1)/2];
}
*/
UTMatrix::~UTMatrix()
{
	delete []A;
}

void UTMatrix::create()
{
	int i, j, x;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>x;
			if(i<=j)
				A[j*(j-1)/2+i-1]=x;
		}
	}
}

int UTMatrix::get(int i, int j)
{
	int z;
	if(i<=j)
		z=A[j*(j-1)/2+i-1];
	if(z!=0)
		return z;
	else 
		return 0;
}

void UTMatrix::set(int i, int j, int x)
{
	if(i<=j)
		A[j*(j-1)/2+i-1]=x;
}

void UTMatrix::Display()
{
	int i, j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<=j)
				cout<<A[j*(j-1)/2+i-1]<<" ";
			else 
				cout<<"0 ";
		}
	}
}

void UTMatrix::Menu()
{
	int i,j,x;
	
	int choice;
	cout<<"1. Add elements"<<endl;
	cout<<"2. Display elements"<<endl;
	cout<<"3. Get element at certain position"<<endl;
	cout<<"4. Set element at certain position"<<endl;
	cout<<endl<<"Enter your choice::";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			create();
			Menu();
			break;
		
		case 2:
			Display();
			Menu();
			break;
		 case 3:
		 	cout<<"Enter the position::";
		 	cin>>i>>j;
		 	cout<<"The element at position "<<i<<","<<j<<" is "<<get(i,j);
		 	Menu();
			break;
		
		case 4:
			cout<<"Enter the position followed by element::";
			cin>>i>>j>>x;
			set(i,j,x);
			Menu();
			break;
		
		default:
			cout<<"Please enter valid choice!!";
			Menu();
			break;		
	}
	
}

int main()
{
	int choice,n;
	
	cout<<"---Select the type of matrix to work upon---"<<endl;
	cout<<"				1.Diagonal Matrix"<<endl;
	cout<<"			2.Lower Triangular Matrix"<<endl;
	cout<<"			3.Upper Triangular Matrix"<<endl;
	cin>>choice;
	
	
	switch(choice)
	{
		case 1:
			{
			
			Diagonal dx;
			dx.Menu();
			break;
		}
		case 2:
		{
			LTMatrix lx;
			lx.Menu();
			break;
		}
		case 3:
		{
			UTMatrix ux;
			ux.Menu();
			break;	
		}
	}
}
