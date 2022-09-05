/*

approach 1:
approximate time complexity: O(n)



See the below diagram for more clarity about execution of the recursive function maxDepth() for above example tree. 

            maxDepth('1') = max(maxDepth('2'), maxDepth('3')) + 1
                               = 1 + 1
                                  /    \
                                /         \
                              /             \
                            /                 \
                          /                     \
               maxDepth('2') = 1                maxDepth('3') = 0
= max(maxDepth('4'), maxDepth('5')) + 1
= 1 + 0   = 1         
                   /    \
                 /        \
               /            \
             /                \
           /                    \
 maxDepth('4') = 0     maxDepth('5') = 0

*/

/* Compute the "maxDepth" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int maxDepth(node* node)
{
    if (node == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

/*

Approach 2: Using Level Order Traversal
approximate time complexity: O(n)

*/
/*Function to find the height(depth) of the tree*/
 int height( Node* root){
 
    //Initialising a variable to count the
    //height of tree
    int height = 0;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        while(n--){ //n is the number of nodes in the current level
            Node* f = q.front();
            q.pop();
            if(f->left != NULL)
                q.push(f->left);
            if(f->right != NULL)
                q.push(f->right);
        }
        height++;
    }
    return height;

 
}
 

