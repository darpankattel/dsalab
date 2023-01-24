class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class LinkedList:
    def __init__(self, head=None):
        self.head = head

    def get_node(self, data):
        return Node(data)

    def insert(self, data, *args, **kwargs):
        at_index = kwargs.get('at_index')
        at_rear = kwargs.get('at_rear', True)
        new_node = self.get_node(data)
        temp = self.head
        if at_index:
            count = 0
            if (temp == None):
                self.head = new_node
                return True
            while (temp.next != None):
                if (count == at_index):
                    new_node.next = temp
                    new_node.prev = temp.prev
                    temp.prev.next = new_node
                    new_node.next.prev = new_node
                    return True
                temp = temp.next
                count += 1
            return False
        if at_rear:
            if (temp == None):
                self.head = new_node
                return True
            while(temp.next != None):
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp
            return True
        else:
            if (temp == None):
                self.head = new_node
                return True
            new_node.next = temp
            temp.prev = new_node
            return True

    def delete(self, *args, **kwargs):
        at_index = kwargs.get('at_index')
        at_rear = kwargs.get('at_rear', True)
        temp = self.head
        if at_index:
            count = 0
            if (temp == None):
                return False
            while (temp.next != None):
                if (count == at_index):
                    temp.prev.next = temp.next
                    temp.next.prev = temp.prev
                    del temp
                    return True
                count += 1
                temp = temp.next
            return False
        if at_rear:
            return True
        else:
            return True
        return True

    def print(self):
        temp = self.head
        while(temp != None):
            print(temp.data, end=" ")
            temp = temp.next
        print("")


my_list = LinkedList()
my_list.insert(11)
my_list.insert(12)
my_list.print()
