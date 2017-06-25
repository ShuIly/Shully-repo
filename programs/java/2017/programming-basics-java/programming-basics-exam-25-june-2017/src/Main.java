import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        String fruit = scan.nextLine().toLowerCase();
        String coctailSize = scan.nextLine().toLowerCase();
        int coctailNumber = Integer.parseInt(scan.nextLine());

        double fruitPrise = 0;

        if(coctailSize.equals("small")) {
            if(fruit.equals("watermelon")){
                fruitPrise = 56;
            }else if (fruit.equals("mango")){
                fruitPrise = 36.66;
            }else if (fruit.equals("pineapple")){
                fruitPrise = 42.1;
            }else if (fruit.equals("raspberry")){
                fruitPrise = 20;
            }
        }else {
            if(fruit.equals("watermelon")){
                fruitPrise = 28.7;
            }else if (fruit.equals("mango")){
                fruitPrise = 19.6;
            }else if (fruit.equals("pineapple")){
                fruitPrise = 24.8;
            }else if (fruit.equals("raspberry")){
                fruitPrise = 15.2;
            }
        }

        double fullValue;

        if(coctailSize.equals("big")){
            fullValue = 5 * fruitPrise * coctailNumber;
        }else {
            fullValue = 2 * fruitPrise * coctailNumber;
        }

        if(fullValue > 1000){
            fullValue -= fullValue * 0.5;
        } else if (fullValue >= 400){
            fullValue -= fullValue * 0.15;
        }

        System.out.printf("%.2f lv.%n", fullValue);

    }
}
