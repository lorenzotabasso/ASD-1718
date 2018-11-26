package ex2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

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

//    static int min(int x,int y ,int z) {
//        if (x <= y && x <= z) return x;
//        else if (y <= x && y <= z) return y;
//        else return z;
//    }

    static int min(int x,int y) {
        if (x <= y) return x;
        else return y;
    }

    static int editDistance(String str1 , String str2 , int m ,int n) {

        // If first string is empty, the only option is to
        // insert all characters of second string into first
        // if |s1| = 0 then editDistance(s1,s2) = |s2|
        if (m == 0) return n;

        // If second string is empty, the only option is to
        // remove all characters of first string
        // if |s2| = 0 then editDistance(s1,s2) = |s1|
        if (n == 0) return m;

        // If last characters of two strings are same, nothing
        // much to do. Ignore last characters and get count for
        // remaining strings.
        if (str1.charAt(0) == str2.charAt(0))
            return editDistance(str1.substring(m-(m-1)), str2.substring(n-(n-1)), m-1, n-1);

        // If last characters are not same, consider all three
        // operations on last character of first string, recursively
        // compute minimum cost for all three operations and take
        // minimum of three values.

        int dcanc = 1 + editDistance(str1, str2.substring(n-(n-1)), m, n-1); // Remove
        int dins = 1 + editDistance(str1.substring(m-(m-1)), str2, m-1, n);   // Insert

        // only for debug
        //System.out.println("CANC: " + dcanc);
        //System.out.println("INS: " + dins);

        return min(dcanc, dins);
    }

    static int editDistanceDyn(String str1, String str2, int m, int n) {

        // Create a table to store results of subproblems
        int dp[][] = new int[m+1][n+1];

        // Fill d[][] in bottom up manner
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                // If first string is empty, only option is to
                // isnert all characters of second string
                if (i==0) {
                    dp[i][j] = j; // Min. operations = j
                }
                    // If second string is empty, only option is to
                    // remove all characters of second string
                else if (j==0) {
                    dp[i][j] = i; // Min. operations = i
                }
                    // If last characters are same, ignore last char
                    // and recur for remaining string
                else if (str1.charAt(i-1) == str2.charAt(j-1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                    // If the last character is different, consider all
                    // possibilities and find the minimum
                else {
                    int dcanc = 1 + dp[i][j - 1]; // Remove
                    int dins = 1 + dp[i - 1][j]; // Insert
                    dp[i][j] = min(dcanc, dins);
                }
            }
        }

        return dp[m][n];
    }

    static void editDistanceOnText(String[] text, MyDictionary dictionary) {

        HashMap<String, Integer> finalED = new HashMap<String, Integer>();

        int [] EDA = null;
        int [] EDAllTest = null;
        int min = 0;
        int i = 0;

        for (String word: text) {
            EDA = new int[dictionary.getSection(word.charAt(0)).size()];

            i = 0;
            for (String wordInDictionary: dictionary.getWordsInSection(word.charAt(0))) {
                EDA[i] = editDistanceDyn(word, wordInDictionary, word.length(), wordInDictionary.length());
                i++;
            }

            for (int j = 0; j < EDA.length-1; j++) {
                min = min(EDA[j], EDA[j+1]);
            }

            finalED.put(word, min);
        }

        for (String word: text) {
            System.out.println("<" + word + " : "+ finalED.get(word) + " >");
        }

    }
}

