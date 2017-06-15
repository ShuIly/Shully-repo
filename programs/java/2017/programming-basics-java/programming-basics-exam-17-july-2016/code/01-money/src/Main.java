import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
	    double bitcoins = Double.parseDouble(scan.nextLine());
	    double yuan = Double.parseDouble(scan.nextLine());
	    double commission = Double.parseDouble(scan.nextLine());
        double leva = 0;
        double euro;
        double dollars;

        dollars = yuan * 0.15; // converting yuan to dollars
        leva += dollars * 1.76; // converting dollars to leva
        leva += bitcoins * 1168; // converting bitcoins to leva
        euro = leva / 1.95; // getting euro from leva
        euro -= euro * commission / 100; // 0-5% commission
        System.out.printf("%.2f", euro);
    }
}
