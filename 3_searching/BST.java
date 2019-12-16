//here I use symbol table, each key is associated with a value.
import java.io.*; 

public class BST
{
    private static  Node root; 
    public  BST()
    { this.root=null;}
    private class Node
    {
        private int key;
        private String val;
        private Node left, right;
        public Node(int key, String val)
        {
            this.key=key;
            this.val=val;  
            left=null;
            right=null;
        }
    }
    public void put(int key, String val)
    {
        root=put(root, key, val);
    }
    public static  String get(int key)
    {
        Node x=root;
        while(x!=null)
        {
            if(key<x.key)
                x=x.left;
            else if(key>x.key)
                x=x.right;
            else
                return x.val;
        }
        return null;
    }
    public boolean delete(int key)
    {
        Node parent = root;
        Node current = root;
        boolean isLeftChild = false;
        while(current.key!=key)
        {
            parent = current;
            if(key<current.key)
            {
                isLeftChild = true;
                current=current.left;
            }
            else if(key>current.key)
            {
                isLeftChild = false;
                current=current.right;
            }
            if(current==null)
                return false;
        }
        //Case 1: if node to be deleted has no children
        if(current.left==null && current.right==null)
        {
			if(current==root)
				root = null;
			if(isLeftChild ==true)
				parent.left = null;
			else
				parent.right = null;
		}
		//Case 2 : if node to be deleted has only one child
		else if(current.right==null)
		{
			if(current==root)
				root = current.left;
			else if(isLeftChild)
				parent.left = current.left;
			else
				parent.right = current.left;
		}
		else if(current.left==null)
		{
			if(current==root)
				root = current.right;
			else if(isLeftChild)
				parent.left = current.right;
			else
				parent.right = current.right;
		}
		//Case 3 : if node to be deleted has two child
		//we have found the minimum element in the right sub tree which called successpor
		else if(current.left!=null && current.right!=null)
		{
			Node successor = getSuccessor(current);
			if(current==root)
				root = successor;
			else if(isLeftChild)
				parent.left = successor;
			else
				parent.right = successor;
			successor.left = current.left;
		}		
		return true;		
	}
	public void travel(Node root)
	{
		if(root!=null)
		{
			travel(root.left);
			System.out.println(root.key+" : "+root.val);
			travel(root.right);
		}
	}
	public Node getSuccessor(Node deleleNode)
	{
		Node successsor =null;
		Node successsorParent =null;
		Node current = deleleNode.right;
		while(current!=null)
		{
			successsorParent = successsor;
			successsor = current;
			current = current.left;
		}
		if(successsor!=deleleNode.right)
		{
			successsorParent.left = successsor.right;
			successsor.right = deleleNode.right;
		}
		return successsor;
	}
	
	public Node put(Node x, int key, String val)
    {
        if(x==null) return new Node(key, val);
        if(key<x.key)
            x.left=put(x.left, key, val);
        else if(key>x.key)
            x.right=put(x.right, key, val);
        else
            x.val=val;
        return x;
    }
    
	public static void main(String args[])
	{
	    BST bst= new BST();
	    bst.put(3,"c");
	    bst.put(2,"b");
	    bst.put(5,"e");
	    bst.put(4,"d");
	    bst.put(1,"a");
		System.out.println("key : value");
	    bst.travel(root);
	    System.out.println("get key 3: "+bst.get(3));
	    System.out.println("delete key 3");
	    bst.delete(3);
	    System.out.println("get key 3: "+bst.get(3));
	    
	}
}

//reference : https://algorithms.tutorialhorizon.com/binary-search-tree-complete-implementation/