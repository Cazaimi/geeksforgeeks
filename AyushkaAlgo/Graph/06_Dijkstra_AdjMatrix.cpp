/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
    
#define loop(i,a,n) for(int i = a;i < n;i++)    
    
void dijkstra(int graph[MAX][MAX], int s,int V)
{
   //Your code here
   /* <weight, <u,v>> : min_heap */
   priority_queue < pair <int,int>, vector <pair <int,int> >, greater<pair <int,int> >  > pq;
   vector <int> visited(V);
   loop(i,0,V){ 
       pq.push(make_pair(0,s));
       //if(graph[s][i]) pq.push(make_pair(0+graph[s][i],i));
   }
   
   vector <int> weights(V);
   
   while(!pq.empty()){
       pair <int,int>  p = pq.top();
       
       int weight   = p.first;
       int currNode = p.second;
       
       //cout << "weight:" << weight << " currNode:" << currNode << endl;
       
       pq.pop();
       
        if(!visited[currNode]){
            loop(i,0,V){
                if(!visited[i] and graph[currNode][i]){
                    pq.push(make_pair(weight+graph[currNode][i],i));
                }
            }
            weights[currNode] = weight;
            //cout << weight << " ";
            visited[currNode] = 1;
        }
   }
   
   loop(i,0,V) cout << weights[i] << " ";
   //cout << endl;
}
