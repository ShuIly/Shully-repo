import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	    Scanner scan = new Scanner(System.in);
	    double budget = Double.parseDouble(scan.nextLine());
	    String category = scan.nextLine();
	    int numPeople = Integer.parseInt(scan.nextLine());

	    if (numPeople >= 1 && numPeople <= 4) {
	        budget -= budget * 0.75;
        } else if (numPeople >= 5 && numPeople <= 9) {
	        budget -= budget * 0.6;
        } else if (numPeople >= 10 && numPeople <= 24) {
            budget -= budget * 0.5;
        } else if (numPeople >= 25 && numPeople <= 49) {
            budget -= budget * 0.4;
        } else {
            budget -= budget * 0.25;
        }



        if (category.equals("Normal")) {
	        double budgetNeeded = numPeople * 249.99;
	        if(budget >= budgetNeeded) {
                System.out.printf("Yes! You have %.2f leva left.%n", budget - budgetNeeded);
            } else {
                System.out.printf("Not enough money! You need %.2f leva.%n", budgetNeeded - budget);
            }
        } else if (category.equals("VIP")) {
	        double budgetNeeded = numPeople * 499.99;
            if(budget >= budgetNeeded) {
                System.out.printf("Yes! You have %.2f leva left.%n", budget - budgetNeeded);
            } else {
                System.out.printf("Not enough money! You need %.2f leva.%n", budgetNeeded - budget);
            }
        }
    }
}
