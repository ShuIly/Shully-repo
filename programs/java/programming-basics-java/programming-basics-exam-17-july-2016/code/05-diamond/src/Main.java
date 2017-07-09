import java.util.Scanner;

public class Main {

    static String repeatStr(int count, String stringToRepeat){
        String endString = "";
        for (int i = 0; i < count; i++) {
            endString += stringToRepeat;
        }
        return endString;
    }

    public static void main(String[] args) {
	    Scanner scan = new Scanner(System.in);

	    int n = Integer.parseInt(scan.nextLine());
        
	    /* FIRST ROW */
	    String firstRowDot = repeatStr(n, ".");
	    String firstRowStar = repeatStr(n * 3, "*");
        System.out.printf("%s%s%s%n", firstRowDot, firstRowStar, firstRowDot);
        
        /*SECOND TO MIDDLE ROW*/
        for (int i = n - 1 ; i >= 1 ; --i){ // FIRST DOT SECTION TO STAR
            String secondDot = repeatStr(i, ".");
            String secondMiddleDot = repeatStr(n * 5 - 2 * i - 2, "." );
            System.out.printf("%s*%s*%s%n", secondDot, secondMiddleDot, secondDot);
        }

        /*MIDDLE ROW*/
        System.out.printf("%s%n", repeatStr(n * 5, "*"));

        /*MIDDLE TO BOTTOM ROW*/
        for (int i = 1 ; i <= n * 2 ; ++i){ // FIRST DOT SECTION TO STAR
            String middleLastDot = repeatStr(i, ".");
            String middledMiddleDot = repeatStr(n * 5 - 2 * i - 2, "." );
            System.out.printf("%s*%s*%s%n", middleLastDot, middledMiddleDot, middleLastDot);
        }

        /*LAST ROW*/
        String lastDot = repeatStr(n * 2 + 1, ".");
        String lastStar = repeatStr(n - 2, "*");
        System.out.printf("%s%s%s%n", lastDot, lastStar, lastDot);

    }
}
