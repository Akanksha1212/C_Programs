struct B
{
    int number;				// 4 bytes - no padding needed   
    short id;				// 2 bytes in memory
    char symbol;			// 1 byte in memory
	//char PADDING[1];		// 1 byte padding
};