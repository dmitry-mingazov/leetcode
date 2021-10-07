#
# https://leetcode.com/problems/word-search/
#

from typing import List

class Solution:
    offsetX = [0, 1, 0, -1]
    offsetY = [-1, 0, 1, 0]

    def fn(self, board: List[List[str]], visited: List[tuple], curr: tuple, word: str) -> bool:
        if len(word) == 0:
            return True
        rows = len(board)
        cols = len(board[curr[0]])
        for i in range(0,4):
            newX = curr[0] + self.offsetX[i]
            newY = curr[1] + self.offsetY[i]
            if newX >= 0 and newX < rows and newY < cols and newY >= 0:
                if not((newX, newY) in visited):
                    if board[newX][newY] == word[0]:
                        tmp = visited[:]
                        tmp.append((newX, newY))
                        # self should be removed
                        if self.fn(self, board, tmp, (newX, newY), word[1:]):
                            return True
        return False

    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for k in range(len(board[i])):
                if(board[i][k] == word[0]):
                    # self should be removed
                    if self.fn(self, board,[(i,k)], [i,k], word[1:]):
                        return True
        return False

board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word = "ABCCED"
obj = Solution
print("Solution: " + str(obj.exist(obj, board, word)))