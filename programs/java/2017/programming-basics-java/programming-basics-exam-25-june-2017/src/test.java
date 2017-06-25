import java.util.Scanner;

public class test {
    private static String repeatChar(int n, char s){
        String returnString = "";
        for (int i = 0; i < n; i++) {
            returnString += s;
        }
        return returnString;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = Integer.parseInt(scan.nextLine());

        /*TOP*/
        System.out.printf("%s%n", repeatChar(4 * n + 1, '#'));

        /*TO MIDDLE*/
        int whenToStopToMiddle = n * 2;
        int whenToInsertEye = n / 2 + 1;
        for (int i = 1, j = 1, k = 1; i < whenToStopToMiddle; i += 2, j++, k += 2) {
            String toMiddleHash = repeatChar(n * 2 - i, '#');
            String toMiddleDot = repeatChar(j, '.');
            if(j != whenToInsertEye) {
                String toMiddleSpace = repeatChar(k, ' ');
                System.out.printf("%s%s%s%s%s%n", toMiddleDot, toMiddleHash, toMiddleSpace, toMiddleHash, toMiddleDot);
            } else {
                String toMiddleSpaceSide = repeatChar((k - 3) / 2, ' ');
                String eye = "(@)";
                System.out.printf("%s%s%s%s%s%s%s%n", toMiddleDot, toMiddleHash, toMiddleSpaceSide, eye, toMiddleSpaceSide, toMiddleHash, toMiddleDot);
            }
        }

        /*TO BOTTOM*/
        int whenToStopToBottom = n * 2 - 1;
        for(int i = n + 1, j = whenToStopToBottom ; j > 0 ; ++i, j -= 2){
            String toBottomHash = repeatChar(j, '#');
            String toBottomDot = repeatChar(i, '.');
            System.out.printf("%s%s%s%n", toBottomDot, toBottomHash, toBottomDot);
        }
    }
}