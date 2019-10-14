/* Below program is for binary tree which performs operations Inorder Traversal, find leaves, 
 * generation, children, grand-children and siblings. */

#include<stdio.h>
#include<stdlib.h>

struct node
{
        struct node *left;
        char data;
        struct node *right;
	struct node *parent;
	int generation;
};
typedef struct node Binary_Tree;
Binary_Tree *root=NULL;
FILE *output_file;

/* Function to dynamically create Binary Tree nodes. */
Binary_Tree *create_node(Binary_Tree *parent, char data)
{
        Binary_Tree *temp;
        temp = (Binary_Tree *)malloc(sizeof(Binary_Tree));

        if(!temp)
        {
                fprintf(output_file, "\nError in memory allocation.\n");
                exit(0);
        }
        temp->left = NULL;
        temp->data = data;
        temp->right = NULL;
	temp->parent = parent;

        return temp;
}

/* Function to create Binary Tree on which operations will be performed. */
void createTree()
{
        root                                    = create_node(NULL, 'A');
        root->left                              = create_node(root, 'B');
        root->right                             = create_node(root, 'C');
        root->left->left                        = create_node(root->left, 'D');
        root->left->right                       = create_node(root->left, 'E');
        root->right->right                      = create_node(root->right, 'F');
        root->left->right->left                 = create_node(root->left->right, 'G');
        root->right->right->right               = create_node(root->right->right, 'H');
        root->left->right->left->left           = create_node(root->left->right->left, 'I');
        root->left->right->left->right          = create_node(root->left->right->left, 'J');
        root->right->right->right->left         = create_node(root->right->right->right, 'K');
        root->right->right->right->right        = create_node(root->right->right->right, 'L');
        root->left->right->left->left->right    = create_node(root->left->right->left->left, 'M');
        root->right->right->right->right->right = create_node(root->right->right->right->right, 'N');
}

/* Function to set generation numbers to all nodes in Binary Tree. */
void members_generation(Binary_Tree *root)
{
        if(root)
        {
		if(!root->parent)
			root->generation = 1;
		else
			root->generation = root->parent->generation + 1;
        }
}

/* Function to print Generation nodes of given node in Binary Tree. */
void print_generation(Binary_Tree *root, Binary_Tree *temp)
{
	if(root) 
	{
		if(root->generation == temp->generation)
			fprintf(output_file, "%c ", root->data);
		else
		{
			print_generation(root->left, temp);
			print_generation(root->right, temp);
	        }
	}
}

/* Recursive Function to perform Inorder Traversal on Binary Tree. */
void inorder(Binary_Tree *root)
{
	members_generation(root);
        if(root)
        {
                inorder(root->left);
                fprintf(output_file, "%c ", root->data);
                inorder(root->right);
        }
}

/* Recursive Function to find leaves in Binary Tree. */
void number_of_leaves(Binary_Tree *root)
{
        if(!root)
                return;

        if(!root->left && !root->right)
                fprintf(output_file, "%c ", root->data);

        number_of_leaves(root->left);
        number_of_leaves(root->right);
}

/* Recursive Function to find location of given input data in FILE. */
Binary_Tree *find_node(Binary_Tree *root, char key)
{
	Binary_Tree *found = NULL;

	if(root == NULL)
		return NULL;

        if(root->data == key)
                return root;

	found = find_node(root->left, key);
        if(found)
		return found;

        found = find_node(root->right, key);
	if(found)
		return found;

        return NULL;
}

/* Driver function to start the program. */ 
int main(int argc, char const *argv[])
{
        int test_case, inorder_flag=0, leaf_flag=0, num=1;
        char node_name;

        createTree();  // Calling function to create Binary Tree 

        FILE *input_file;
        input_file = fopen(argv[1], "r");
        if(!input_file)
        {
                fprintf(output_file, "\nError in opening file in read mode.\n");
                exit(0);
        }
        fscanf(input_file, "%d", &test_case);
	output_file = fopen(argv[2], "w+");

        while(test_case--)
        {
		fscanf(input_file, "%c", &node_name);
                fscanf(input_file, "%c", &node_name);
                		
		// Below code is to find Inorder Traversal
  		if(inorder_flag == 0)
                {
                        fprintf(output_file, "\nThe Inorder Traversal is : ");
                        inorder(root);
		        inorder_flag = 1;
                }

		// Below code is to find leaves in Binary Tree
                if(leaf_flag == 0)
                {
                        fprintf(output_file, "\nLeaf nodes are : ");
                        number_of_leaves(root);
                        leaf_flag = 1;
                }

		int flag=0;
		fprintf(output_file, "\n\nTestcase%d\n", num++);

		Binary_Tree *temp = find_node(root, node_name);    // Temp variable to store address of input data in Binary Tree.
		
		if(temp)
		{
			// Below code is to find generation of given node.
			fprintf(output_file, "\nGeneration of %c : %d", temp->data, temp->generation);
			fprintf(output_file, "\nMembers of Generation %d : ",temp->generation);
			print_generation(root, temp);

			// Below code is to find Children of given node.
			fprintf(output_file, "\nChildren of %c : ", temp->data);
			if(!temp->left && !temp->right)
			{
				fprintf(output_file, "%c is a leaf node.", temp->data);
				flag = 1;
			}
			if(temp->left)
				fprintf(output_file, "%c ", temp->left->data);
			if(temp->right)
				fprintf(output_file, "%c ", temp->right->data);

			// Below code is to find Grand-Children of given node.
	              	fprintf(output_file, "\nGrand Children of %c : ", temp->data);
			if(flag == 1)
				fprintf(output_file, "%c is a leaf node.", temp->data);

			if(temp->left)
			{
				if(temp->left->left)
				       	fprintf(output_file, "%c ", temp->left->left->data);
			        if(temp->left->right)
                                        fprintf(output_file, "%c ", temp->left->right->data);
			}
			if(temp->right)
			{
                                if(temp->right->left)
                                        fprintf(output_file, "%c ", temp->right->left->data);
			        if(temp->right->right)
                                        fprintf(output_file, "%c ", temp->right->right->data);
			}

			//Below code is to find sibling of given node.
			if(temp->parent)
			{
				if(temp->parent->right != temp && temp->parent->right)
					fprintf(output_file, "\nSibling of %c : %c", temp->data, temp->parent->right->data);
			        else if(temp->parent->left != temp && temp->parent->left)
					fprintf(output_file, "\nSibling of %c : %c", temp->data, temp->parent->left->data);
			        else
					fprintf(output_file, "\nNode %c has no sibling.", temp->data);
			}
			else
				fprintf(output_file, "\nNode %c is the root node. So, no sibling.", temp->data);
		}
		else
			fprintf(output_file, "\nNode %c is not present in Binary Tree.\n", node_name);
        }
	fclose(input_file);	
	fclose(output_file);

        return 0;
}
