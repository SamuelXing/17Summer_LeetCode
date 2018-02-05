'''
An AVL Tree implementation
'''

class Node(object):
	def __init__(self, val):
		self.val = val
		self.__parent = None
		self.__left = None
		self.__right = None
		self.height = 0

	@property
	def right(self):
		return self.__right

	@right.setter
	def right(self, node):
		if node is not None:
			node.__parent = self
			self.__right = node

	@property
	def left(self):
		return self.__left

	@left.setter
	def left(self, node):
		if node is not None:
			node.__parent = self
			self.left = node

	@property
	def parent(self):
		return self.__parent

	@parent.setter
	def parent(self, node):
		if node is not None:
			self.__parent = node
			self.height = self.parent.height + 1
		else:
			self.height = 0


class AVL(object):
	def __init__(self):
		self.root = None
		self.size = 0

	def insert(self, val):
		node = Node(val)

		if self.root is None:
			self.root = node
			self.root.height = 0
			self.size = 1
		else:
			prevNode = None
			curNode = self.root

			while True:
				if curNode is not None:
					prevNode = curNode

					if node.val < curNode.val:
						curNode = curNode.left
					else:
						curNode = curNode.right
				else:
					node.height = prevNode.height
					prevNode.height += 1
					if node.val < prevNode.val:
						prevNode.left = node
					else:
						prevNode.right = node
					self.rebalance(node)
					self.size += 1
					break

	def rebalance(self, node):
		n = node

		while n is not None:
			heightRight = n.height
			heightLeft = n.height

			if n.right is not None:
				heightRight = n.right.height

			if n.left is not None:
				heightLeft = n.left.height

			if abs(heightLeft - heightRight) > 1:
				if heightLeft > heightRight:
					leftChild = n.left
					if leftChild is not None:
						hRight = (leftChild.right.height if (leftChild.right is not None) else 0)
						hLeft = (leftChild.left.height if (leftChild.left is not None) else 0)
					if hLeft > hRight:
						self.rotateLeft(n)
						break
					else:
						self.doubleRotateRight(n)
						break
				else:
					rightChild = n.right
					if rightChild is not None:
						hRight = (rightChild.right.height if (rightChild.right is not None) else 0)
						hLeft = (rightChild.left.height if (rightChild.left is not None) else 0)
					if hLeft > hRight:
						self.doubleRotateLeft(n)
						break
					else:
						self.rotateRight(n)
						break

			n = n.parent

	def rotateLeft(self, node):
		tmp = node.parent.val
		node.parent.val = node.val
		node.parent.right = Node(tmp)
		node.parent.right.height = node.parent.height + 1
		node.parent.left = node.right

	def rotateRight(self, node):
		tmp = node.parent.val
		node.parent.val = node.val
		node.parent.left = Node(tmp)
		node.parent.left.height = node.parent.height + 1
		node.parent.right = node.right

	def doubleRotateLeft(self, node):
		self.rotateRight(node.right.right)
		self.rotateLeft(node)

	def doubleRotateRight(self, node):
		self.rotateLeft(node.left.left)
		self.rotateRight(node)

	def empty(self):
		if self.root is None:
			return True
		return False

	def inOrder(self, curNode):
		if curNode is not None:
			self.inOrder(curNode.left)
			print(curNode.val, end=" ")
			self.inOrder(curNode.right)

	def postOrder(self, curNode):
		if curNode is not None:
			self.postOrder(curNode.left)
			self.postOrder(curNode.right)
			print(curNode.val, end=" ")


t = AVL()
t.insert(1)
t.insert(2)
t.insert(3)
t.inOrder(t.root)
print("\n")






















