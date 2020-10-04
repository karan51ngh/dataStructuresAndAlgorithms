

def attack(r, c, board):
    for i in range(len(board)):
        if board[i][c] != 0:
            board[i][c] = k


def free(i, c, board):


def placequeen(i, board, n):
    for c in range(n):
        if free(i, c, board):


if __name__ == "__main__":
    # initialize the board
    n = int(input("enter n"))
    board = []
    for i in range(n):
        board.append([])
        for j in range(n):
            board[i].append(0)
    placequeen(0, board, n)
