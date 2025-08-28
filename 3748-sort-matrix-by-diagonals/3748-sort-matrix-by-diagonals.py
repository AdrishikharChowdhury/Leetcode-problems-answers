class Solution(object):
    def sortMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(grid)

        def get_diagonal(i, j):
            diagonal = []
            x, y = i, j
            while x < n and y < n:
                diagonal.append(grid[x][y])
                x += 1
                y += 1
            return diagonal

        def set_diagonal(i, j, diagonal):
            x, y = i, j
            for val in diagonal:
                grid[x][y] = val
                x += 1
                y += 1

        # Bottom-left triangle including main diagonal (i >= j): sort non-increasing
        for start_row in range(n):
            diag = get_diagonal(start_row, 0)
            diag.sort(reverse=True)
            set_diagonal(start_row, 0, diag)

        # Top-right triangle (j > i): sort non-decreasing
        for start_col in range(1, n):
            diag = get_diagonal(0, start_col)
            diag.sort()
            set_diagonal(0, start_col, diag)

        return grid
