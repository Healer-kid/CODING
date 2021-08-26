The member states of the UN are planning to send  people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

Example



There are  astronauts numbered  through . Astronauts grouped by country are  and . There are  pairs to choose from:  and .

Function Description

Complete the journeyToMoon function in the editor below.

journeyToMoon has the following parameter(s):

int n: the number of astronauts
int astronaut[p][2]: each element  is a  element array that represents the ID's of two astronauts from the same country
Returns
- int: the number of valid pairs

Input Format

The first line contains two integers  and , the number of astronauts and the number of pairs.
Each of the next  lines contains  space-separated integers denoting astronaut ID's of two who share the same nationality.

Constraints

Sample Input 0

5 3
0 1
2 3
0 4
Sample Output 0

6
Explanation 0

Persons numbered  belong to one country, and those numbered  belong to another. The UN has  ways of choosing a pair:


Sample Input 1

4 1
0 2
Sample Output 1

5
Explanation 1

Persons numbered  belong to the same country, but persons  and  don't share countries with anyone else. The UN has  ways of choosing a pair:










int findpar(int n,vector<int> &parent)
{
    if(n==parent[n])
     return n;
     
     return parent[n]=findpar(parent[n],parent);
    
}

void unionn(vector<int> &parent,vector<int> &rank,int u,int v){
  
  u=findpar(u,parent);
  v=findpar(v,parent);
  
  if(rank[u]<rank[v])  
    {
        parent[u]=v;
    }
    else if(rank[u]>rank[v])
    parent[v]=u;
    else
    {
        parent[u]=v;
        rank[v]++;
        
    }
    
    
    
    
}



int journeyToMoon(int n, vector<vector<int>> astronaut) {

vector<int> parent(n);
vector<int> rank(n,0);
for(int i=0;i<n;i++)
parent[i]=i;

for(auto x:astronaut)
{
   unionn(parent,rank,x[0],x[1]); 
    
    
}
int count=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++){
        if(i==j)
            continue;
            if(findpar(i,parent)!=findpar(j,parent))
            count++;
            
            
    }
    
}

return count/2;


}
