class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        # Bookkeeping sets to track used numbers in rows, columns and blocks
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        
        # Initialize sets with existing numbers on board
        for r in range(9):
            for c in range(9):
                if board[r][c] != '.':
                    num = board[r][c]
                    rows[r].add(num)
                    cols[c].add(num)
                    box_index = (r // 3) * 3 + (c // 3)
                    boxes[box_index].add(num)
        
        def backtrack(r=0, c=0):
            if r == 9:
                return True  # solved entire board
            if c == 9:
                return backtrack(r + 1, 0)  # move to next row
            
            if board[r][c] != '.':
                return backtrack(r, c + 1)  # skip filled cells
            
            box_index = (r // 3) * 3 + (c // 3)
            for num in map(str, range(1, 10)):
                if num not in rows[r] and num not in cols[c] and num not in boxes[box_index]:
                    # Place num tentatively
                    board[r][c] = num
                    rows[r].add(num)
                    cols[c].add(num)
                    boxes[box_index].add(num)
                    
                    if backtrack(r, c + 1):
                        return True
                    
                    # Backtrack
                    board[r][c] = '.'
                    rows[r].remove(num)
                    cols[c].remove(num)
                    boxes[box_index].remove(num)
            return False
        
        backtrack()
