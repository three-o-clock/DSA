// 1 -> preorder
// 2 -> inorder
// 3 -> postorder

class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			//your code goes here
			if(a == b) return false;

			if((a == 1 && b == 3) || (a == 3 && b == 1)) return false;

			return true;
		}
};