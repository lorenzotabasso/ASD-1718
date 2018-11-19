/**
 * @author Lorenzo Tabasso
 * @author Andrea Malgaoli
 */
// paths
// /Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex2/correctme.txt
// /Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex2/dictionary.txt

// A Dynamic Programming based Java program to find minimum
// number operations to convert str1 to str2
public class EditDistance {

    String fileToCorrect[];

    static int min(int x,int y /*,int z*/) {
        if (x <= y /*&& x <= z*/) return x;
        else /*if (y <= x && y <= z) */ return y;
        //else return z;
    }

    static int editDistance(String str1 , String str2 , int m ,int n) {

        //System.out.println("Computing the edit distance between: " + str1 + ", " + str2);

        // If first string is empty, the only option is to
        // insert all characters of second string into first
        if (m == 0) return n;

        // If second string is empty, the only option is to
        // remove all characters of first string
        if (n == 0) return m;

        // If last characters of two strings are same, nothing
        // much to do. Ignore last characters and get count for
        // remaining strings.
        if (str1.charAt(m-1) == str2.charAt(n-1))
            return editDistance(str1, str2, m-1, n-1);

        // If last characters are not same, consider all three
        // operations on last character of first string, recursively
        // compute minimum cost for all three operations and take
        // minimum of three values.
        return 1 + min ( editDistance(str1, str2, m, n-1),    // Insert
                editDistance(str1, str2, m-1, n) /*,   // Remove
						editDistance(str1, str2, m-1, n-1) // Replace */
        );
    }

    static int editDistanceDyn(String str1, String str2, int m, int n) {

        // Create a table to store results of subproblems
        int dp[][] = new int[m+1][n+1];

        // Fill d[][] in bottom up manner
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                // If first string is empty, only option is to
                // isnert all characters of second string
                if (i==0)
                    dp[i][j] = j; // Min. operations = j

                    // If second string is empty, only option is to
                    // remove all characters of second string
                else if (j==0)
                    dp[i][j] = i; // Min. operations = i

                    // If last characters are same, ignore last char
                    // and recur for remaining string
                else if (str1.charAt(i-1) == str2.charAt(j-1))
                    dp[i][j] = dp[i-1][j-1];

                    // If the last character is different, consider all
                    // possibilities and find the minimum
                else
                    dp[i][j] = 1 + min(dp[i][j-1], // Insert
                            dp[i-1][j] /*, // Remove
									dp[i-1][j-1]*/); // Replace
            }
        }

        return dp[m][n];
    }

    public static void main(String args[]) {

        MyDictionary dict = new MyDictionary();
        dict.load("/Volumes/HDD/Lorenzo/Unito/2 Anno/ASD/Progetto/Progetto 2017-2018/laboratorio-algoritmi-2017-18/Datasets/ex2/dictionary.txt");

        String str1 = "casa";
        String str2 = "cassa";

        System.out.println("Computing the edit distance between: " + str1 + ", " + str2);
        System.out.println(editDistance( str1 , str2 , str1.length(), str2.length()));
        System.out.println(editDistanceDyn( str1 , str2 , str1.length(), str2.length()));

        String str3 = "casa";
        String str4 = "cara";

        System.out.println("Computing the edit distance between: " + str3 + ", " + str4);
        System.out.println(editDistance( str3 , str4 , str3.length(), str4.length()));

        String str5 = "tassa";
        String str6 = "passato";

        System.out.println("Computing the edit distance between: " + str5 + ", " + str6);
        System.out.println(editDistance( str5 , str6 , str5.length(), str6.length()));

        String str7 = "pioppo";
        String str8 = "pioppo";

        System.out.println("Computing the edit distance between: " + str7 + ", " + str8);
        System.out.println(editDistance( str7 , str8 , str7.length(), str8.length()));
    }

}

