// Using Custom Comparator and Lower Bound in a Set

/*************************** Custom Comparator ***************************/
struct compare
{
	bool operator () (const pair<int, int>&a, const pair<int, int>&b) const
	{
		if (a.first == b.first)
			return a.second > b.second; // Decreasing
		else
			return a.first < b.first;	// Increasing
	}
};

set<pair<int, int>, compare> s;


/*************************** Lower Bound ***************************/
set<pair<int, int>> s;
auto itr = s.lower_bound({a, b}); // itr >= {a, b} (Wohi, Ya Usse Just Agla)

s.insert({3, 1});
s.insert({4, 7});
s.insert({7, 9});

// Case 1 : Available
auto itr = s.lower_bound({6, -1}); // itr >= {6, -1} => {7, 9}

// Case 2 : NOT Available
auto itr = s.lower_bound({8, -1}); // itr >= {8, -1} => {3, 0}
