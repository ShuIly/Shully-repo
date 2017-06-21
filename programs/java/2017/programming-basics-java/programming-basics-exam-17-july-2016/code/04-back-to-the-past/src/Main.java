import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	    Scanner scan = new Scanner(System.in);

	    double inheritedMoney = Double.parseDouble(scan.nextLine());
	    int finalYear = Integer.parseInt(scan.nextLine());

	    int age = 18;
	    int yearlyExpense = 12000;
        int overallExpense = 0;

        for (int i = 1800; i <= finalYear; i++, age++) {
            if (i % 2 == 0){
                overallExpense += yearlyExpense;
            } else {
                overallExpense += yearlyExpense + 50 * age;
            }
        }

        if (inheritedMoney - overallExpense >= 0){
            System.out.printf("Yes! He will live a carefree life and will have %.2f dollars left.", inheritedMoney - overallExpense);
        } else {
            System.out.printf("He will need %.2f dollars to survive.", overallExpense - inheritedMoney);
        }
    }
}
