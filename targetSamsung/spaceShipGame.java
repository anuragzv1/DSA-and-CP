import java.util.Scanner;

class spaceShipGame {

    private static void bombMatrix(int arr[][], int row) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                if (arr[i][j] == 2)
                    arr[i][j] = 0;
            }
        }
    }

    private static int spaceShip(int map[][], int row, int col, boolean bombUsed) {
        if (row < 0 || row >= map.length || col < 0 || col >= map[0].length) {
            return 0;
        }

        int straightMove = spaceShip(map, row - 1, col, false);
        int leftMove = spaceShip(map, row - 1, col + 1, false);
        int rightMove = spaceShip(map, row - 1, col - 1, false);

        if (map[row][col] == 1) {
            return 1 + Math.max(straightMove, Math.max(leftMove, rightMove));
        } else if (map[row][col] == 0) {
            return Math.max(straightMove, Math.max(leftMove, rightMove));
        } else {
            if (bombUsed == true) {
                return 0;
            } else {
                bombMatrix(map, row);
                straightMove = spaceShip(map, row - 1, col, true);
                leftMove = spaceShip(map, row - 1, col + 1, true);
                rightMove = spaceShip(map, row - 1, col - 1, true);
                return Math.max(straightMove, Math.max(leftMove, rightMove));

            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int map[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        int ans = Math.max(spaceShip(map, n - 1, 1, false),
                Math.max(spaceShip(map, n - 1, 2, false), spaceShip(map, n - 1, 3, false)));
        sc.close();
        System.out.println(ans);

    }
}

// 0 1 0 2 0
// 0 2 2 2 1
// 0 2 1 1 1
// 1 0 1 0 0
// 0 0 1 2 2
// 1 1 0 0 1

// x x S x x