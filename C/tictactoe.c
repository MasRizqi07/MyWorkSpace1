#include <stdio.h>

char board[3][3];
int player = 1; // 1 untuk X, 2 untuk O

// Fungsi untuk menginisialisasi papan
void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Fungsi untuk menampilkan papan
void drawBoard() {
    printf("\n");
    printf("  0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) printf(" | ");
        }
        printf("\n");
        if (i < 2) printf("---------\n");
    }
    printf("\n");
}

// Fungsi untuk mengecek kemenangan
int checkWin() {
    // Cek baris
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') return 1;
    }
    // Cek kolom
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1;
    }
    // Cek diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1;
    
    return 0;
}

int main() {
    int row, col;
    char symbol;

    initBoard();
    printf("=== TIC-TAC-TOE ===\n");
    printf("Pemain 1: X | Pemain 2: O\n");
    printf("Masukkan baris (0-2) dan kolom (0-2).\n\n");

    while (1) {
        drawBoard();
        symbol = (player == 1) ? 'X' : 'O';
        
        printf("Giliran Pemain %c: ", symbol);
        scanf("%d %d", &row, &col);

        // Validasi input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Posisi tidak valid! Coba lagi.\n");
            continue;
        }

        board[row][col] = symbol;

        if (checkWin()) {
            drawBoard();
            printf("Pemain %c MENANG!\n", symbol);
            break;
        }

        // Cek seri (jika tidak ada lagi ' ')
        int draw = 1;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                if(board[i][j] == ' ') draw = 0;
        
        if(draw) {
            drawBoard();
            printf("Seri!\n");
            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    return 0;
}