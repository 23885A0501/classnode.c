class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def cartesian_tree_sort(arr):
    # Step 1: Construct Cartesian Tree
    root = build_cartesian_tree(arr)

    # Step 2: In-Order Traversal
    sorted_array = in_order_traversal(root)

    return sorted_array

def build_cartesian_tree(arr):
    root = None

    for element in arr:
        # Create a new node for the current element
        new_node = Node(element)

        # Insert the new node into the Cartesian tree
        root = merge(root, new_node)

    return root

def in_order_traversal(node):
    sorted_array = []

    if node is not None:
        # Traverse the left subtree
        sorted_array.extend(in_order_traversal(node.left))

        # Visit the current node
        sorted_array.append(node.value)

        # Traverse the right subtree
        sorted_array.extend(in_order_traversal(node.right))

    return sorted_array

# Additional function for merging two Cartesian trees
def merge(root1, root2):
    if root1 is None:
        return root2
    if root2 is None:
        return root1

    # Compare the root values to maintain the heap property
    if root1.value < root2.value:
        root1.right = merge(root1.right, root2)
        return root1
    else:
        root2.right = merge(root2.right, root1)
        return root2

# Example Usage
input_array = [8, 3, 1, 6, 4, 7, 10, 14, 13]
result = cartesian_tree_sort(input_array)
print("Input Array:", input_array)
print("Sorted Array:", result)
This Python code defines the Node class for representing nodes in the Cartesian tree and provides functions for building the Cartesian tree, performing in-order traversal, and merging two Cartesian trees. The example usage demonstrates how to apply Cartesian Tree Sorting to a sample input array.




User
result

ChatGPT
If you run the provided Python code with the example input array, you should get the following result:

plaintext
Copy code
Input Array: [8, 3, 1, 6, 4, 7, 10, 14, 13]
Sorted Array: [1, 3, 4, 6, 7, 8, 10, 13, 14]
The cartesian_tree_sort function takes the input array [8, 3, 1, 6, 4, 7, 10, 14, 13], applies the Cartesian Tree Sorting algorithm, and returns the sorted array [1, 3, 4, 6, 7, 8, 10, 13, 14]. The result demonstrates the elements arranged in ascending order, as expected from the Cartesian Tree Sorting algorithm.