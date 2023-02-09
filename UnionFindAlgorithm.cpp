// Union By Rank and Path Compression in Union-Find Algorithm (Disjoint Set)

const int MAX_SIZE = 10000;
int parent[MAX_SIZE];
int rank[MAX_SIZE];

// Initialize
void init()
{
	for(int i = 0; i < MAX_SIZE; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

// Find Parent
int find(int x)
{
	// Without Path Compression
	if(parent[x] == x)
		return x;
	else
		return find(parent[x]);
	
	// With Path Compression
	if(parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}

// Union By Rank
void union(int a, int b)
{
	int x = find(a); // Parent of 'a'
	int y = find(b); // Parent of 'b'
	
	if(x == y) // Both have same parent
		return;
	
	// More Rank => Make It Parent
	if(rank[x] < rank[y])
		parent[x] = y;
	else if (rank[y] < rank[x])
		parent[y] = x;
	
	else // rank[y] == rank[x]
	{
		parent[y] = x;
		rank[x]++;
	}
}
