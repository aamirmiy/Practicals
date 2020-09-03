
#include <iostream>
using namespace std;
#define max 20
class Graph
{
	int vertices;
	int e;
	int cost;
	int adj[max][max];
	int v[max];
public:
	Graph()
	{
		for(int i=0;i<max;i++)
		{
			for(int j=0;j<max;j++)
				adj[i][j]=0;
		}
		vertices=0;
		e=0;
		cost=0;
	}
	void acceptGraph();
	void adjMatrix();
	int primsAlgo();
	int minCostIndex(int cost[],bool visited[]);
	void kruskal();
	friend class Edge;
	int check(int a[]);
	void sort(int p[3][3]);
};
class Edge
{
public:
	void sort();
};
void Graph::acceptGraph()
{
	char ch;


	cout<<"\nEnter the No of Vertices\n";
	cin>>vertices;

	for(int i=0;i<vertices;i++)
	{
		cout<<"\nEnter Vertex "<<i+1<<" : ";
		cin>>v[i];
	}
	for(int i=0;i<vertices;i++)
	{
		for(int j=i+1;j<vertices;j++)
		{
			cout<<"\nIs There any Telephone line between "<<v[i]<<"---"<<v[j]<<" (y/n) ";
			cin>>ch;
			if(ch=='y')
			{
				cout<<"\nEnter Its Cost \n";
				cin>>cost;
				adj[i][j]=cost;
				adj[j][i]=cost;
				e++;
			}
		}
	}

}

void Graph::adjMatrix()
{
	cout<<"\nAdjacency Matrix Becomes\n";

	for(int i=0;i<vertices;i++)
	{

		for(int j=0;j<vertices;j++)
		{
			cout<<adj[i][j]<<"  ";
		}
		cout<<endl;
	}
}
int Graph::minCostIndex(int cost_val[],bool visit[])
{
    int min=9999;
    int min_index;
    for(int i=0;i<vertices;i++)
    {

        if(visit[i]==0 && cost_val[i]<min)
        {
            min=cost_val[i];
            min_index=i;
        }

    }
    return min_index;
}
int Graph::primsAlgo()
{
    bool visit[max];
    int father[max];
    int cost_val[max];
    for(int i=0;i<vertices;i++)
    {
        cost_val[i]=9999;
        visit[i]=0;
    }
    cost_val[0]=0;
    father[0]=-1;
    for(int i=0;i<vertices-1;i++)
    {
        int k=minCostIndex(cost_val,visit);
        visit[k]=1;
        for(int j=0;j<vertices;j++)
        {

            if(adj[k][j]!=0 && visit[j]==0 && adj[k][j]<cost_val[j])
            {
                father[j]=v[k];
                cost_val[j]=adj[k][j];
            }
        }
    }
    cout<<"\nMinimum Cost Map Becomes\n";
    for(int i=1;i<vertices;i++)
    {
        cout<<father[i]<<"----"<<v[i]<<" = "<<cost_val[i]<<endl;
    }
    int min_cost=0;
    for(int i=1;i<vertices;i++)
        min_cost+=cost_val[i];
    return min_cost;
}
void Graph::kruskal()
{
    int B[e+(vertices-1)][3];
    int k=0,a;
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(adj[i][j]!=0)
            {
                B[k][0]=i;
                B[k][1]=j;
                B[k][2]=adj[i][j];
                k++;

            }
        }
    }
    sort(B);
    k=0;
    int z=e;
    int V[vertices];
    for(int i=0;i<vertices;i++)
        V[i]=i+1;
    while(k<e)
    {
        if(check(V)==0)
        break;
        if(V[B[k][0]]!=V[B[k][1]])
        {
            B[z][1]=B[k][1];
            B[z][0]=B[k][0];
            B[z][2]=B[k][2];
            z++;
            a=B[k][1];
            for(int i=0;i<vertices;i++)
            {
                if(V[i]==a)
                    V[i]=V[B[k][0]];
            }
        }
        k++;
    }
    k=0;
    cout<<"\nMinimum Spanning Tree Becomes\n";
    for(int i=e;i<e+(vertices-1);i++)
    {
        cout<<v[B[i][0]]<<"-----"<<v[B[i][1]]<<"    "<<B[i][2]<<endl;
        k=k+B[i][2];
    }
    cout<<"\nTotal Cost : "<<k;


}
void Graph::sort(int p[][3])
{
    for(int i=0;i<e;i++)
    {
        for(int j=i+1;j<e;j++)
        {
            if(p[i][2]>p[j][2])
                {
                    swap(p[i],p[j]);
                }
        }
    }
}
int Graph::check(int a[])
{
    for(int i=0;i<vertices-1;i++)
    {
        if(a[i]!=a[i+1])
            return 1;
    }
    return 0;
}

int main()
{
	int ch;
	Graph g;
	do
	{
		cout<<"\n\n1.Accept Graph\n2.Display Adjacency Matrix\n3.Prim's Algorithm\n4.Kruskal's Algorithm\n";
		cout<<"\nEnter Your Choice\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			g.acceptGraph();
			break;
		case 2:
			g.adjMatrix();
			break;
        case 3:
            cout<<"\nMinimum Cost is : "<<g.primsAlgo();
            break;
        case 4:
            g.kruskal();
            break;
		}
	}while(ch!=0);







	return 0;
}
