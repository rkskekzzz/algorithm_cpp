import java.util.ArrayList;
import java.util.Arrays;

class Point {
    int x;
    int y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
public class Main {
    static char[][] map;
    static boolean check;
    final static int ROW = 5;
    final static int COL = 5;
    final static int NUM_OF_ROOMS = 5;
    final static int DIREC = 4;
    final static int[] dx = {-1, 0, 1, 0}; // 위, 오른쪽, 아래, 왼쪽
    final static int[] dy = {0, 1, 0, -1};
    final static int SAFE_DIS = 2;
    public void check(int L, Point p, int[][] checkMap) {
        if (check)
            return ;
        if (L < SAFE_DIS){
            for (int i = 0; i < DIREC; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < ROW && ny >= 0 && ny < COL
                        && checkMap[nx][ny] == 0) {
                    if (map[nx][ny] == 'X')
                        return ;
                    else if (map[nx][ny] == 'P'){
                        check = true;
                        return ;
                    }
                    checkMap[nx][ny] = 1;
                    check(L + 1, new Point(nx, ny), checkMap);
                }
            }
        }
    }
    public int isSafe(ArrayList<Point> people){
        // 마지막 사람은 검사 안해도됨
        // 걸린다면 항상 쌍으로 존재하기 때문에, 코드 개선 가능
        check = false;
        for (Point person : people) {
            int[][] checkMap = new int[ROW][COL];
            checkMap[person.x][person.y] = 1;
            check(0,  person, checkMap);
            if (check)
                return (0);
        }
        return (1);
    }
    public int[] solution(String[][] places) {
        int[] answer = {};
        answer = new int[NUM_OF_ROOMS];
        map = new char[ROW][COL];
        int roomNum = 0;
        for (String[] room : places) {
            int rowNum = 0;
            map[rowNum] = new char[COL];
            // 방 1개 만들기
            ArrayList<Point> people = new ArrayList<>();
            for (String row : room) {
                int colNum = 0;
                for (char point : row.toCharArray()) {
                    map[rowNum][colNum++] = point;
                    if (point == 'P') {
                        people.add(new Point(rowNum, colNum - 1));
                    }
                }
                rowNum++;
            }
            // 시작
            answer[roomNum++] = isSafe(people);
        }
        return answer;
    }
    public static void main(String[] args) {
        Main t = new Main();
        String[][] places = {
                {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
                {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
        System.out.println(Arrays.toString(t.solution(places)));
    }
}
