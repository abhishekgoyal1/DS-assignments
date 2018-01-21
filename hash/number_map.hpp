template <typename K, typename V>
  class Number_Map {					// map interface
  public:
    Number_Map(int capacity);			// constructor
    int size() const;				// number of entries in the map
    bool empty() const;				// is the map empty?
    E& find(const K& k) const;		// find entry with key k
    void put(const K& k, const V& v);	// insert/replace pair (k,v)
    void erase(const K& k)			// remove entry with key k
 };
