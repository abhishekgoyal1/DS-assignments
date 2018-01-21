class MAVLTree{

    public:
        MAVLTree();  //Initialize the ADT	
     	int size() const;	// number of elements
    	bool isEmpty() const;	// is the queue empty?
	void insert(const int k, string s);//insert key k,s into the tree
  	void delete(const int k);//remove k from the tree, if exists
   	string search(const int k);//search for key k in the tree
	void delete_by_place(int i); //Delete from the entry at the  ith place (as determined by the order of insertion)
        int get_place(int k);//Return the place (which is determined by the order of insertion), if x does not exist, return -1 
}
