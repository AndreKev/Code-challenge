class Problem:
    def __init__(self):
        self.matrix : list[list] = []
        self.chains : dict       = {}
        self.next   : int        = 0
        self.directions : list[tuple[int, int]] = []

        # to be defined later
        self.R : int    # number of rows
        self.C : int    # number of columns

    def seek(self, i, j):
        for dx, dy in self.directions:
            if dx == dy == 0:
                self.chains[self.next] = self.chains.get(self.next, 0) + 1
                self.matrix[i][j] = 0
            else:
                if self.getval(i+dx, j+dy): self.seek(i+dx, j+dy)
    
    def getval(self, i, j):
        if not ((0<=i<self.R) and (0<=j< self.C)):
            return 0
        else:
            return self.matrix[i][j]
    
    def solve(self, matrix=None):
        if matrix:
            self.matrix = matrix
            self.R = len(matrix)
            self.C = len(matrix[0])
        else:
            self.init_matrix()
        self.directions = self.init_directions(2)
        #print(self.directions)

        for i in range(self.R):
            for j in range(self.C):
                if self.matrix[i][j]:
                    #print("1", end=" ")
                    self.next += 1
                    self.seek(i, j)
        print(self.chains)

    def init_matrix(self):
        self.R = int(input("Enter the number of rows of the matrix : "))
        self.C = int(input("Enter the number of columns of the matrix : "))
        self.matrix = [[int(number) for number in input()] for i in range(self.R)]
    
    def init_directions(self, n):
        if n == 1:
            return [[dd] for dd in range(-1, 2)]
        else:
            return [first + second for first in self.init_directions(1)
                                   for second in self.init_directions(n-1)]

(Problem().solve([[1,1,0,0,0], [0,1,1,0,0], [0,0,1,0,1], [1,0,0,0,1], [0,1,0,1,1]]))