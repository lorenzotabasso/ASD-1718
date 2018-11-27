package ex2;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 */

public class EditDistanceTests {

    public static void main(String args[]) {
        String str1 = "casa";
        String str2 = "cassa";

        System.out.println("Computing the edit distance between: " + str1 + ", " + str2);
        System.out.println(EditDistance.editDistance( str1 , str2));
        System.out.println("DYN: " + EditDistance.editDistanceDynTopDown(str1 , str2));

        String str3 = "casa";
        String str4 = "cara";

        System.out.println("Computing the edit distance between: " + str3 + ", " + str4);
        System.out.println(EditDistance.editDistance(str3 , str4));
        System.out.println("DYN: " + EditDistance.editDistanceDynTopDown(str3 , str4));

        String str5 = "tassa";
        String str6 = "passato";

        System.out.println("Computing the edit distance between: " + str5 + ", " + str6);
        System.out.println(EditDistance.editDistance(str5 , str6));
        System.out.println("DYN: " + EditDistance.editDistanceDynTopDown(str5 , str6));

        String str7 = "pioppo";
        String str8 = "pioppo";

        System.out.println("Computing the edit distance between: " + str7 + ", " + str8);
        System.out.println(EditDistance.editDistance(str7 , str8));
        System.out.println("DYN: " + EditDistance.editDistanceDynTopDown(str7 , str8));
    }
}
