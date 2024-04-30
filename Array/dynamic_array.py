import ctypes

class MeraList:
    def __init__(self):
        self.size = 1
        self.n = 0
        # create a c type array with size = self.size
        self.A = self._make_array(self.size)

    def __len__(self):
        return self.n
    
    def __str__(self):
        result = ''
        for i in range(self.n):
            result =  result + str(self.a[i]) + ','
    
    def append(self, item):
        if self.n == self.size:
            # resize
            self._resize(self.size * 2)

        # append
        self.A[self.n] = item
        self.n = self.n + 1

    def _resize(self, new_capacity):
        # create a new array with new capacity
        B = self._make_array(new_capacity)
        self.size = new_capacity
        # copy the content of A to B
        for i in range(self.n):
            B[i] = self.A[i]
        # reassign A
        self.A = B

    def _make_array(self, capacity):
        # This code creates a C (fixed, referential) type array with size capacity
        return (capacity * ctypes.py_object)()

# Example usage
L = MeraList()

L.append('Hello')
L.append(3.4)
L.append(100)
L.append(True)

print(len(L))  # Output: 4
