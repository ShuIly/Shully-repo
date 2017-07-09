import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
	    int vineyard = Integer.parseInt(scan.nextLine());
	    double grapesForSquare = Double.parseDouble(scan.nextLine());
	    int neededLitersWine = Integer.parseInt(scan.nextLine());
	    int workers = Integer.parseInt(scan.nextLine());

	    double grapesProduced = vineyard * grapesForSquare;
	    double wineProduced = 0.4 * grapesProduced / 2.5;

	    if(wineProduced >= neededLitersWine){
	        double excessWine = wineProduced - neededLitersWine;
            System.out.printf("Good harvest this year! Total wine: %.0f liters.%n", Math.floor(wineProduced));
            System.out.printf("%.0f liters left -> %.0f liters per person.%n", Math.ceil(excessWine), Math.ceil(excessWine / workers));
        }else{
	        double shortageWine = neededLitersWine - wineProduced;
            System.out.printf("It will be a tough winter! More %.0f liters wine needed.%n", Math.floor(shortageWine));
        }

    }
}
